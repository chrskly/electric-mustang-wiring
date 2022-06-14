/*
 * This file is part of the ev mustang bms project.
 *
 * Copyright (C) 2022 Christian Kelly <chrskly@chrskly.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include "pico/stdlib.h"

#include "settings.h"
#include "comms.h"
#include "statemachine.h"
#include "battery.h"
#include "pack.h"
#include "structs.h"

/*
CRC8 crc8;
uint8_t checksum;
const uint8_t finalxor [12] = {0xCF, 0xF5, 0xBB, 0x81, 0x27, 0x1D, 0x53, 0x69, 0x02, 0x38, 0x76, 0x4C};
*/

uint8_t getcheck(can_frame &msg, int id) {
	  return 0x00;
}

/*
  unsigned char canmes [11];
  int meslen = msg.len + 1; //remove one for crc and add two for id bytes
  canmes [1] = msg.id;
  canmes [0] = msg.id >> 8;

  for (int i = 0; i < (msg.len - 1); i++)
  {
    canmes[i + 2] = msg.buf[i];
  }
  return (crc8.get_crc8(canmes, meslen, finalxor[id]));
}
*/

//// ----
//
// Polling the modules for voltage and temperature readings
//
//// ----

struct can_frame pollModuleFrame;

struct repeating_timer pollModuleTimer;

/*
 * pollMessageId : loops from 0 to 5. Sets the Id of the CAN message.
 * mescycle      : loops from 0 to 0xF. Incremented when pollMessageId wraps.
 *
 * Contents of message
 *   byte 0 : balance data
 *   byte 1 : balance data
 *   byte 2 : 0x00
 *   byte 3 : 0x00
 *   byte 4 : 
 *   byte 5 : 0x01
 *   byte 6 :
 *   byte 7 : checksum
 */

void requestPackData(BatteryPack *pack) {

	  if ( pack->pollMessageId == 6 ) {
		    pack->pollMessageId = 0;
		    pack->msgcycle++;

		    if ( pack->testcycle < 4 ) {
			      pack->testcycle++;
		    }

		    if ( pack->msgcycle == 0xF ) {
			      pack->msgcycle = 0;
			      if ( ! packIsDueToBeBalanced(pack) ) {
			      	  resetBalanceTimer(pack);
			      }
		    }
	  }

    // Set the Id and length of the CAN frame
	  pollModuleFrame.can_id = 0x080 | (pack->pollMessageId);
	  pollModuleFrame.can_dlc = 8;

	  if ( packIsDueToBeBalanced(pack) ) {
	  	  uint16_t lowestCellVoltage = ( uint16_t(getLowestCellVoltage(pack)) * 1000 ) + 5;
		    pollModuleFrame.data[0] = lowestCellVoltage & 0x00FF;          // low byte
		    pollModuleFrame.data[1] = ( lowestCellVoltage >> 8 ) & 0x00FF; // high byte
	  }
	  else {
		    pollModuleFrame.data[0] = 0xC7;
		    pollModuleFrame.data[1] = 0x10;
	  }

	  pollModuleFrame.data[2] = 0x00; // balancing bits
	  pollModuleFrame.data[3] = 0x00; // balancing bits

	  if (pack->testcycle < 3) {
		    pollModuleFrame.data[4] = 0x20;
		    pollModuleFrame.data[5] = 0x00;
	  }
	  else {
		    if ( packIsDueToBeBalanced(pack) ) {
			      pollModuleFrame.data[4] = 0x48;
		    }
		    else {
			      pollModuleFrame.data[4] = 0x40;
		    }
		    pollModuleFrame.data[5] = 0x01;
	  }

	  pollModuleFrame.data[6] = pack->msgcycle << 4;

	  if ( pack->testcycle == 2 ) {
		    pollModuleFrame.data[6] = pollModuleFrame.data[6] + 0x04;
	  }

	  pollModuleFrame.data[7] = getcheck(pollModuleFrame, pack->pollMessageId);

	  pack->CAN.sendMessage(&pollModuleFrame);
	  pack->pollMessageId++;

	  //if (bms.checkstatus() == true) {
		//    resetbalancedebug();
	  //}
}

// Send request to each pack to ask for a data update
bool pollPacksForData(struct repeating_timer *t) {
		for ( int p = 0; p < NUM_PACKS; p++ ) {
			  requestPackData(battery->packs[p]);
		}
		return true;
}

void enableModulePolling() {
    add_repeating_timer_ms(1000, pollPacksForData, NULL, &pollModuleTimer);
}

//// ----
//
// status messages
//
//// ----

// CAN frame to hold status message sent out to rest of car
// bit 0-4 = state (0=standby, 1=drive, 2=charging, 3=overTempFault, 4=underVoltageFault ) 
struct can_frame statusFrame;

struct repeating_timer statusMessageTimer;

bool sendStatusMessage(struct repeating_timer *t) {
	extern State state;
	extern MCP2515 mainCAN;
	statusFrame.can_id = STATUS_MSG_ID;
	statusFrame.can_dlc = 1;
	if ( state == state_standby ) {
		statusFrame.data[0] = 0x00 << 4;
	} else if ( state == state_drive ) {
		statusFrame.data[0] = 0x01 << 4;
	} else if ( state == state_charging ) {
		statusFrame.data[0] = 0x02 << 4;
	} else if ( state == state_overTempFault ) {
		statusFrame.data[0] = 0x03 << 4;
	} else if ( state == state_underVoltageFault ) {
		statusFrame.data[0] = 0x04 << 4;
	} else {
		//
	}
	// do pack dead check

	mainCAN.sendMessage(&statusFrame);
	return true;
}

void enableStatusMessages() {
	add_repeating_timer_ms(1000, sendStatusMessage, NULL, &statusMessageTimer);
}


//// ----
// 
// send charge limits message (id = 0x102)
//
//// ----

// CAN frame to hold charge limits message
// byte 0 = 0x0
// byte 1 = DC voltage limit MSB
// byte 2 = DC voltage limit LSB
// byte 3 = DC current set point
// byte 4 = 1 == enable charging
// byte 5 = SoC
// byte 6 = 0x0
// byte 7 = 0x0
// From https://openinverter.org/wiki/Tesla_Model_S/X_GEN2_Charger
struct can_frame chargeLimitsFrame;

struct repeating_timer chargeLimitsMessageTimer;

bool sendChargeLimitsMessage(struct repeating_timer *t) {
	extern Battery battery;
	chargeLimitsFrame.can_id = 0x102;
	chargeLimitsFrame.can_dlc = 8;
	// byte 0
	chargeLimitsFrame.data[0] = 0x0;
	// byte 1 -- DC voltage limit MSB
	chargeLimitsFrame.data[1] = 0x0; //fixme
	// byte 2 -- DC voltage limit LSB
	chargeLimitsFrame.data[2] = 0x0; //fixme
	// byte 3 -- DC current set point
	chargeLimitsFrame.data[3] = (__u8)getMaxChargingCurrent(&battery);
	// byte 4 -- 1 == enable charging
	chargeLimitsFrame.data[4] = 0x0; //fixme
	// byte 5 -- SoC
	chargeLimitsFrame.data[5] = 0x0; //fixme
	// byte 6 -- 0x0
	chargeLimitsFrame.data[6] = 0x0;
	// byte 7 -- 0x0
	chargeLimitsFrame.data[7] = 0x0;

    return true;
}

void enableChargeLimitsMessages() {
	add_repeating_timer_ms(1000, sendChargeLimitsMessage, NULL, &chargeLimitsMessageTimer);
}

void disableChargeLimitsMessages() {
	//
}


//// ----
//
// Inbound message handlers
//
//// ----

struct can_frame mainCANInbound;

void handleMainCANMessages() {

	  extern MCP2515 mainCAN;

	  if ( mainCAN.readMessage(&mainCANInbound) == MCP2515::ERROR_OK ) {
        if ( mainCANInbound.can_id == CAN_ID_ISA_SHUNT_WH ) {
          	// process Wh data
        } else if ( mainCANInbound.can_id == CAN_ID_ISA_SHUNT_AH ) {
        	  // process Ah data
        }
        // ...
    }
}

struct can_frame batteryCANInbound;

// 
void handleBatteryCANMessages() {

	  extern Battery battery;

	  for ( int p = 0; p < NUM_PACKS; p++ ) {
	    	if ( battery.packs[p]->CAN.readMessage(&batteryCANInbound) == MCP2515::ERROR_OK ) {

	    		  // Temperature messages
	    		  if ( ( batteryCANInbound.can_id & 0xFF0 ) == 0x180 ) {
	    		  	  decodeTemperatures(battery.packs[p], &batteryCANInbound);
	    		  }

	    		  // Voltage messages
	    		  else if (batteryCANInbound.can_id > 0x99 && batteryCANInbound.can_id < 0x180) {
	    		  	  decodeVoltages(battery.packs[p], batteryCANInbound);
	    		  }

	    	}
  	}
}





