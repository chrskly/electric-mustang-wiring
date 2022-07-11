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


void initialise_pack(BatteryPack *pack, int packId) {

    // Set last update time to now
	pack->lastUpdate = get_absolute_time();

	// Create the modules
	printf("Initialising modules : ");
	for ( int m = 0; m < 16; m++ ) {
		BatteryModule module;
		printf("%d, ", m);
		initialise_module(&module, pack);
		pack->modules[m] = &module;
	}
	printf("\n");

	pack->voltage = 0;

	// Set up contactor control. Default to contactors open.
	printf("Setting up contactor control\n");
	pack->contactorsClosed = false;
	pack->contactorPin = CONTACTOR_PINS[packId];
	gpio_init(pack->contactorPin);
	gpio_set_dir(pack->contactorPin, GPIO_OUT);
    gpio_put(pack->contactorPin, 0);

    // errorStatus not needed?

    // balanceStatus not needed?

    // Set next balance time to 10 seconds from now
    pack->nextBalanceTime = delayed_by_us(get_absolute_time(), 10000);

    pack->msgcycle = 0;
    pack->nextmsg = 0;
    pack->testcycle = 0;

    // internal counters
    pack->pollMessageId = 0;

    printf("Pack %d setup complete\n", packId);
}

void print_pack_status(BatteryPack *pack, int packId) {
	printf("--------------------------------------------------------------------------------\n");
	printf("Pack ID                : %d\n", packId);
	printf("Pack voltage           : %d\n", pack->voltage);
	printf("Pack contactors closed : %d\n", pack->contactorsClosed);
	printf("--------------------------------------------------------------------------------\n");
}

bool pack_is_alive(BatteryPack *pack) {
	absolute_time_t now = get_absolute_time();
	int64_t timeSinceLastUpdate = absolute_time_diff_us(pack->lastUpdate, now);
	if ( timeSinceLastUpdate >= PACK_ALIVE_TIMEOUT ) {
		return false;
	}
	return true;
}

void set_pack_error_status(BatteryPack *pack, int newErrorStatus) {
	pack->errorStatus = newErrorStatus;
}

int get_pack_error_status(BatteryPack *pack) {
	return pack->errorStatus;
}

void set_pack_balance_status(BatteryPack *pack, int newBalanceStatus) {
	pack->balanceStatus = newBalanceStatus;
}

int get_pack_balance_status(BatteryPack *pack) {
	return pack->balanceStatus;
}

// Return true if it's time for the pack to be balanced.
bool pack_is_due_to_be_balanced(BatteryPack *pack) {
	printf("Inside pack_is_due_to_be_balanced\n");
	return ( absolute_time_diff_us(get_absolute_time(), pack->nextBalanceTime) < 0 );
}

void reset_balance_timer(BatteryPack *pack) {
	pack->nextBalanceTime = delayed_by_us(get_absolute_time(), BALANCE_INTERVAL);
}


//// ----
//
// Voltage
//
//// ----

// Return the voltage of the whole pack
float get_voltage(BatteryPack *pack) {
	return pack->voltage;
}

// Update the pack voltage value by summing all of the cell voltages
void update_voltage(BatteryPack *pack) {
	float voltage = get_voltage(pack->modules[0]);
	for ( int i = 1; i < MODULES_PER_PACK; i++ ) {
		voltage += get_voltage(pack->modules[i]);
	}
	pack->voltage = voltage;
}

// Return the voltage of the lowest cell in the pack
float get_lowest_cell_voltage(BatteryPack *pack) {
	printf("Inside get_lowest_cell_voltage (pack)\n");
	float lowestCellVoltage = get_lowest_cell_voltage(pack->modules[0]);
	for ( int m = 1; m < MODULES_PER_PACK; m++ ) {
		if ( get_lowest_cell_voltage(pack->modules[m]) < lowestCellVoltage ) {
			lowestCellVoltage = get_lowest_cell_voltage(pack->modules[m]);
		}
	}
	printf("get_lowest_cell_voltage : returning %f\n", lowestCellVoltage);
	return lowestCellVoltage;
}

// Return true if any cell in the pack is under min voltage
bool has_cell_under_voltage(BatteryPack *pack) {
	for ( int m = 0; m < MODULES_PER_PACK; m++ ){
		if ( has_cell_under_voltage(pack->modules[m]) ) {
			return true;
		}
	}
	return false;
}

// Return the voltage of the highest cell in the pack
float get_highest_cell_voltage(BatteryPack *pack) {
	float highestCellVoltage = get_highest_cell_voltage(pack->modules[0]);
	for ( int i = 1; i < MODULES_PER_PACK; i++ ) {
		if ( get_highest_cell_voltage(pack->modules[i]) < highestCellVoltage ) {
			highestCellVoltage = get_highest_cell_voltage(pack->modules[i]);
		}
	}
	return highestCellVoltage;
}

// Return true if any cell in the pack is over max voltage
bool has_cell_over_voltage(BatteryPack *pack) {
	for ( int m = 0; m < MODULES_PER_PACK; m++ ){
		if ( has_cell_over_voltage(pack->modules[m]) ) {
			return true;
		}
	}
	return false;
}

// Update the value for the voltage of an individual cell in a pack
void update_cell_voltage(BatteryPack *pack, int moduleId, int cellIndex, float newCellVoltage) {
	update_cell_voltage(pack->modules[moduleId], cellIndex, newCellVoltage);
}

void decode_voltages(BatteryPack *pack, can_frame frame) {
	int messageId = (frame.can_id & 0x0F0);
	int moduleId = (frame.can_id & 0x00F) + 1;

	switch (messageId) {
	    case 0x000:
	        // error = msg.buf[0] + (msg.buf[1] << 8) + (msg.buf[2] << 16) + (msg.buf[3] << 24);
	        set_pack_error_status(pack, frame.data[0] + (frame.data[1] << 8) + (frame.data[2] << 16) + (frame.data[3] << 24));
	        // balstat = (frame.data[5] << 8) + frame.data[4];
	        set_pack_balance_status(pack, (frame.data[5] << 8) + frame.data[4]);
	        break;
		case 0x020:
		    update_cell_voltage(pack, moduleId, 0, float(frame.data[0] + (frame.data[1] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 1, float(frame.data[2] + (frame.data[3] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 2, float(frame.data[4] + (frame.data[5] & 0x3F) * 256) / 1000);
		    break;
	    case 0x30:
		    update_cell_voltage(pack, moduleId, 3, float(frame.data[0] + (frame.data[1] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 4, float(frame.data[2] + (frame.data[3] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 5, float(frame.data[4] + (frame.data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x40:
		    update_cell_voltage(pack, moduleId, 6, float(frame.data[0] + (frame.data[1] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 7, float(frame.data[2] + (frame.data[3] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 8, float(frame.data[4] + (frame.data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x50:
		    update_cell_voltage(pack, moduleId, 9, float(frame.data[0] + (frame.data[1] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 10, float(frame.data[2] + (frame.data[3] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 11, float(frame.data[4] + (frame.data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x60:
		    update_cell_voltage(pack, moduleId, 12, float(frame.data[0] + (frame.data[1] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 13, float(frame.data[2] + (frame.data[3] & 0x3F) * 256) / 1000);
		    update_cell_voltage(pack, moduleId, 14, float(frame.data[4] + (frame.data[5] & 0x3F) * 256) / 1000);
	        break;
	    case 0x70:
		    update_cell_voltage(pack, moduleId, 15, float(frame.data[0] + (frame.data[1] & 0x3F) * 256) / 1000);
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
bool has_temperature_sensor_over_max(BatteryPack *pack) {
	for ( int i = 0; i < MODULES_PER_PACK; i++ ) {
		if ( has_temperature_sensor_over_max(pack->modules[i]) ) {
			return true;
		}
	}
	return false;
}

// Return the maximum current we can charge the pack with.
int get_max_charging_current(BatteryPack *pack) {
	int maxChargeCurrent = get_max_charging_current(pack->modules[0]);
	for ( int m = 1; m < MODULES_PER_PACK; m++ ) {
		if ( get_max_charging_current(pack->modules[m]) < maxChargeCurrent ) {
			maxChargeCurrent = get_max_charging_current(pack->modules[m]);
		}
	}
	return maxChargeCurrent;
}

// return the temperature of the lowest sensor in the pack
float get_lowest_temperature(BatteryPack *pack) {
	float lowestModuleTemperature = 1000;
	for ( int m = 0; m < MODULES_PER_PACK; m++ ) {
		if ( get_lowest_temperature(pack->modules[m]) < lowestModuleTemperature ) {
			lowestModuleTemperature = get_lowest_temperature(pack->modules[m]);
		}
	}
	return lowestModuleTemperature;
}

// Extract temperature sensor readings from CAN frame and update stored values
void decode_temperatures(BatteryPack *pack, can_frame *temperatureMessageFrame) {
	int moduleId = (temperatureMessageFrame->can_id & 0x00F) + 1;
	for ( int t = 0; t < TEMPS_PER_MODULE; t++ ) {
		update_temperature(pack->modules[moduleId], t, temperatureMessageFrame->data[t] - 40);
	}
}


//// ----
//
// Contactors
//
//// ----


bool close_contactors(BatteryPack *pack) {
	gpio_put(pack->contactorPin, 1);
	return true;
}

bool open_contactors(BatteryPack *pack) {
	gpio_put(pack->contactorPin, 0);
	return true;
}



