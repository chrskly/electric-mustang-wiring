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

#include "pack.h"
#include "module.h"

#include "settings.h"

using namespace std;

BatteryPack::BatteryPack (int packId, int CANCSPin, int contactorPin, int numModules, int numCellsPerModule, int numTemperatureSensorsPerModule) {

	printf("Initialising BatteryPack %d\n", packId);

    this->packId = packId;
    this->numModules = numModules;
	this->numCellsPerModule = numCellsPerModule;
	this->numTemperatureSensorsPerModule = numTemperatureSensorsPerModule;

	// Initialise modules
	for ( int m = 0; m < this->numModules; m++ ) {
		static BatteryModule module(this, this->numCellsPerModule, this->numTemperatureSensorsPerModule);
		this->modules[m] = &module;
	}

    // Set up CAN port
    printf("Creating CAN port [%d, %d, %d, %d, %d]", SPI_PORT, CANCSPin, SPI_MISO, SPI_MOSI, SPI_CLK);
	static MCP2515 CAN(SPI_PORT, CANCSPin, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
	CAN.reset();
    CAN.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    CAN.setNormalMode();
	this->CAN = &CAN;
	/*
	this->CAN->reset();
    this->CAN->setBitrate(CAN_1000KBPS, MCP_8MHZ);
    this->CAN->setNormalMode();
    */

    printf("Sending test message for pack %d\n", packId);
    struct can_frame fr;
    fr.can_id = 0x001;
    fr.can_dlc = 1;
    fr.data[0] = 0x01;
    this->CAN->sendMessage(&fr);

    // Set last update time to now
	this->lastUpdate = get_absolute_time();

	this->voltage = 0;

	// Set up contactor control. Default to contactors open.
	printf("Setting up contactor control\n");
	this->contactorsClosed = false;
	this->contactorPin = contactorPin;
	gpio_init(this->contactorPin);
	gpio_set_dir(this->contactorPin, GPIO_OUT);
    gpio_put(this->contactorPin, 0);

    // balanceStatus not needed?

    // Set next balance time to 10 seconds from now
    this->nextBalanceTime = delayed_by_us(get_absolute_time(), 10000);

    this->msgcycle = 0;
    this->nextmsg = 0;
    this->testCycle = 0;

    // internal counters
    this->pollMessageId = 0;

    printf("Pack %d setup complete\n", packId);
}

//void BatteryPack::set_CAN_port(MCP2515* port) {
//	printf("pack::set_CAN_port : %p\n", port);
//	this->CAN = port;
//}

void BatteryPack::print() {
	printf("--------------------------------------------------------------------------------\n");
	printf("Pack ID                : %d\n", this->packId);
	printf("Pack voltage           : %d\n", this->voltage);
	printf("Pack contactors closed : %d\n", this->contactorsClosed);
	printf("Pack CAN port          : %p\n", this->CAN);
	printf("--------------------------------------------------------------------------------\n");
}

/*
CRC8 crc8;
uint8_t checksum;
const uint8_t finalxor [12] = {0xCF, 0xF5, 0xBB, 0x81, 0x27, 0x1D, 0x53, 0x69, 0x02, 0x38, 0x76, 0x4C};
*/

uint8_t BatteryPack::getcheck(can_frame &msg, int id) {
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

void BatteryPack::request_data() {

	printf("Requesting pack data\n");

	can_frame pollModuleFrame;

	/*
	  if ( pack->pollMessageId == 6 ) {
		    pack->pollMessageId = 0;
		    pack->msgcycle++;

		    if ( pack->testcycle < 4 ) {
			      pack->testcycle++;
		    }

		    if ( pack->msgcycle == 0xF ) {
			      pack->msgcycle = 0;
			      if ( ! pack_is_due_to_be_balanced(pack) ) {
			      	  reset_balance_timer(pack);
			      }
		    }
	  }
	  */

    printf("a\n");
	// Set the Id and length of the CAN frame
	pollModuleFrame.can_id = 0x080 | (this->pollMessageId);
	//printf("pollMessageId %d\n", this->pollMessageId);
	//pollModuleFrame.can_id = 0x080;
	pollModuleFrame.can_dlc = 8;

    printf("b\n");
	if ( this->pack_is_due_to_be_balanced() ) {
		printf("bb\n");
		//uint16_t lowestCellVoltage = ( uint16_t(get_lowest_cell_voltage(pack)) * 1000 ) + 5;
		//uint16_t lowestCellVoltage = this->get_lowest_cell_voltage() * 1000;
		float lowestCellVoltage = this->get_lowest_cell_voltage();
		printf("lowestCellVoltage %f\n", lowestCellVoltage);
		printf("bbb\n");
	    //pollModuleFrame.data[0] = lowestCellVoltage & 0x00FF;          // low byte
	    printf("bbbb\n");
	    //pollModuleFrame.data[1] = ( lowestCellVoltage >> 8 ) & 0x00FF; // high byte
	    printf("bbbbb\n");
	}
	else {
		printf("-b-\n");
	    pollModuleFrame.data[0] = 0xC7;
	    pollModuleFrame.data[1] = 0x10;
	}

    printf("c\n");

	pollModuleFrame.data[2] = 0x00; // balancing bits
	pollModuleFrame.data[3] = 0x00; // balancing bits

	if ( this->testCycle < 3 ) {
	    pollModuleFrame.data[4] = 0x20;
	    pollModuleFrame.data[5] = 0x00;
	}
	else {
	    if ( this->pack_is_due_to_be_balanced() ) {
		      pollModuleFrame.data[4] = 0x48;
	    }
	    else {
		      pollModuleFrame.data[4] = 0x40;
	    }
	    pollModuleFrame.data[5] = 0x01;
	}

    printf("d\n");

	pollModuleFrame.data[6] = this->msgcycle << 4;

	if ( this->testCycle == 2 ) {
	    pollModuleFrame.data[6] = pollModuleFrame.data[6] + 0x04;
	}

	pollModuleFrame.data[7] = getcheck(pollModuleFrame, this->pollMessageId);

    //printf("Sending poll message on CAN bus 1\n");
    //extern MCP2515 mainCAN;
	//mainCAN.sendMessage(&pollModuleFrame);

    //printf("Sending poll message on CAN bus 2\n");
	//extern MCP2515 batt2CAN;
	//batt2CAN.sendMessage(&pollModuleFrame);
    
    //extern MCP2515 CANPorts[NUM_PACKS];
	this->send_message(&pollModuleFrame);
	//CANPorts[packId].sendMessage(&pollModuleFrame);

    printf("e\n");
	++this->pollMessageId;

	//if (bms.checkstatus() == true) {
	//    resetbalancedebug();
	//}
	printf("Request_pack_data complete\n");
}

void BatteryPack::read_message() {

	can_frame frame;

	if ( this->CAN->readMessage(&frame) == MCP2515::ERROR_OK ) {

		// Temperature messages
		if ( ( frame.can_id & 0xFF0 ) == 0x180 ) {
			  this->decode_temperatures(&frame);
		}

		// Voltage messages
		else if (frame.can_id > 0x99 && frame.can_id < 0x180) {
			  this->decode_voltages(&frame);
		}

	}
}




bool BatteryPack::pack_is_alive() {
	absolute_time_t now = get_absolute_time();
	int64_t timeSinceLastUpdate = absolute_time_diff_us(this->lastUpdate, now);
	if ( timeSinceLastUpdate >= PACK_ALIVE_TIMEOUT ) {
		return false;
	}
	return true;
}

void BatteryPack::set_pack_error_status(int newErrorStatus) {
	this->errorStatus = newErrorStatus;
}

int BatteryPack::get_pack_error_status() {
	return this->errorStatus;
}

void BatteryPack::set_pack_balance_status(int newBalanceStatus) {
	this->balanceStatus = newBalanceStatus;
}

int BatteryPack::get_pack_balance_status() {
	return this->balanceStatus;
}

// Return true if it's time for the pack to be balanced.
bool BatteryPack::pack_is_due_to_be_balanced() {
	return ( absolute_time_diff_us(get_absolute_time(), this->nextBalanceTime) < 0 );
}

void BatteryPack::reset_balance_timer() {
	this->nextBalanceTime = delayed_by_us(get_absolute_time(), BALANCE_INTERVAL);
}


//// ----
//
// Voltage
//
//// ----

// Return the voltage of the whole pack
float BatteryPack::get_voltage() {
	return this->voltage;
}

// Update the pack voltage value by summing all of the cell voltages
void BatteryPack::update_voltage() {
	float voltage = 0;
	for ( int m = 0; m < this->numModules; m++ ) {
		voltage += this->modules[m]->get_voltage();
	}
	this->voltage = voltage;
}

// Return the voltage of the lowest cell in the pack
float BatteryPack::get_lowest_cell_voltage() {
	printf("inside battery::get_lowest_cell_voltage\n");
	float lowestCellVoltage = 100;
	for ( int m = 0; m < this->numModules; m++ ) {
		printf("Getting lowestCellVoltage for module %d\n", m);
		if ( this->modules[m]->get_lowest_cell_voltage() < lowestCellVoltage ) {
			lowestCellVoltage = this->modules[m]->get_lowest_cell_voltage();
		}
	}
	return lowestCellVoltage;
}

// Return true if any cell in the pack is under min voltage
bool BatteryPack::has_cell_under_voltage() {
	for ( int m = 0; m < this->numModules; m++ ){
		if ( this->modules[m]->has_cell_under_voltage() ) {
			return true;
		}
	}
	return false;
}

// Return the voltage of the highest cell in the pack
float BatteryPack::get_highest_cell_voltage() {
	float highestCellVoltage = 0;
	for ( int m = 0; m < this->numModules; m++ ) {
		if ( this->modules[m]->get_highest_cell_voltage() < highestCellVoltage ) {
			highestCellVoltage = this->modules[m]->get_highest_cell_voltage();
		}
	}
	return highestCellVoltage;
}

// Return true if any cell in the pack is over max voltage
bool BatteryPack::has_cell_over_voltage() {
	for ( int m = 0; m < this->numModules; m++ ){
		if ( this->modules[m]->has_cell_over_voltage() ) {
			return true;
		}
	}
	return false;
}

// Update the value for the voltage of an individual cell in a pack
void BatteryPack::update_cell_voltage(int moduleId, int cellIndex, float newCellVoltage) {
	this->modules[moduleId]->update_cell_voltage(cellIndex, newCellVoltage);
}

void BatteryPack::decode_voltages(can_frame *frame) {
	int messageId = (frame->can_id & 0x0F0);
	int moduleId = (frame->can_id & 0x00F) + 1;

	switch (messageId) {
	    case 0x000:
	        // error = msg.buf[0] + (msg.buf[1] << 8) + (msg.buf[2] << 16) + (msg.buf[3] << 24);
	        set_pack_error_status(frame->data[0] + (frame->data[1] << 8) + (frame->data[2] << 16) + (frame->data[3] << 24));
	        // balstat = (frame.data[5] << 8) + frame.data[4];
	        set_pack_balance_status( (frame->data[5] << 8) + frame->data[4] );
	        break;
		case 0x020:
		    this->modules[moduleId]->update_cell_voltage(0, float(frame->data[0] + (frame->data[1] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(1, float(frame->data[2] + (frame->data[3] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(2, float(frame->data[4] + (frame->data[5] & 0x3F) * 256) / 1000);
		    break;
	    case 0x30:
		    this->modules[moduleId]->update_cell_voltage(3, float(frame->data[0] + (frame->data[1] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(4, float(frame->data[2] + (frame->data[3] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(5, float(frame->data[4] + (frame->data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x40:
		    this->modules[moduleId]->update_cell_voltage(6, float(frame->data[0] + (frame->data[1] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(7, float(frame->data[2] + (frame->data[3] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(8, float(frame->data[4] + (frame->data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x50:
		    this->modules[moduleId]->update_cell_voltage(9, float(frame->data[0] + (frame->data[1] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(10, float(frame->data[2] + (frame->data[3] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(11, float(frame->data[4] + (frame->data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x60:
		    this->modules[moduleId]->update_cell_voltage(12, float(frame->data[0] + (frame->data[1] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(13, float(frame->data[2] + (frame->data[3] & 0x3F) * 256) / 1000);
		    this->modules[moduleId]->update_cell_voltage(14, float(frame->data[4] + (frame->data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x70:
		    this->modules[moduleId]->update_cell_voltage(15, float(frame->data[0] + (frame->data[1] & 0x3F) * 256) / 1000);
	        break;
	    default:
	        break;
	}

}


//// ----
//
// Temperature
//
//// ----

// Return true if any cell in the pack is over max temperature
bool BatteryPack::has_temperature_sensor_over_max() {
	for ( int m = 0; m < this->numModules; m++ ) {
		if ( this->modules[m]->has_temperature_sensor_over_max() ) {
			return true;
		}
	}
	return false;
}

// Return the maximum current we can charge the pack with.
int BatteryPack::get_max_charging_current() {
	int maxChargeCurrent = 0;
	for ( int m = 0; m < this->numModules; m++ ) {
		if ( this->modules[m]->get_max_charging_current() < maxChargeCurrent ) {
			maxChargeCurrent = this->modules[m]->get_max_charging_current();
		}
	}
	return maxChargeCurrent;
}

// return the temperature of the lowest sensor in the pack
float BatteryPack::get_lowest_temperature() {
	float lowestModuleTemperature = 1000;
	for ( int m = 0; m < this->numModules; m++ ) {
		if ( this->modules[m]->get_lowest_temperature() < lowestModuleTemperature ) {
			lowestModuleTemperature = this->modules[m]->get_lowest_temperature();
		}
	}
	return lowestModuleTemperature;
}

// Extract temperature sensor readings from CAN frame and update stored values
void BatteryPack::decode_temperatures(can_frame *temperatureMessageFrame) {
	int moduleId = (temperatureMessageFrame->can_id & 0x00F) + 1;
	for ( int t = 0; t < this->numTemperatureSensorsPerModule; t++ ) {
		this->modules[moduleId]->update_temperature(t, temperatureMessageFrame->data[t] - 40);
	}
}


//// ----
//
// Contactors
//
//// ----


bool BatteryPack::close_contactors() {
	gpio_put(this->contactorPin, 1);
	return true;
}

bool BatteryPack::open_contactors() {
	gpio_put(this->contactorPin, 0);
	return true;
}



