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

#include "pack.h"
#include "module.h"


void initialisePack(BatteryPack *pack) {
	// Create the modules
	for ( int m = 0; m < 16; m++ ) {
		BatteryModule module;
		initialiseModule(&module, pack);
		pack->modules[m] = &module;
	}
	// Set up contactor control. Default to contactors open.
	gpio_init(pack->contactorPin);
	gpio_set_dir(pack->contactorPin, GPIO_OUT);
    gpio_put(pack->contactorPin, 0);
}

bool packIsAlive(BatteryPack *pack) {
	absolute_time_t now = get_absolute_time();
	int64_t timeSinceLastUpdate = absolute_time_diff_us(pack->lastUpdate, now);
	if ( timeSinceLastUpdate >= PACK_ALIVE_TIMEOUT ) {
		return false;
	}
	return true;
}


//// ----
//
// Voltage
//
//// ----

// Return the voltage of the whole pack
float getVoltage(BatteryPack *pack) {
	return pack->voltage;
}

// Update the pack voltage value by summing all of the cell voltages
void updateVoltage(BatteryPack *pack) {
	float voltage = getVoltage(pack->modules[0]);
	for ( int i = 1; i < MODULES_PER_PACK; i++ ) {
		voltage += getVoltage(pack->modules[i]);
	}
	pack->voltage = voltage;
}

// Return the voltage of the lowest cell in the pack
float getLowestCellVoltage(BatteryPack *pack) {
	float lowestCellVoltage = getLowestCellVoltage(pack->modules[0]);
	for ( int m = 1; m < MODULES_PER_PACK; m++ ) {
		if ( getLowestCellVoltage(pack->modules[m]) < lowestCellVoltage ) {
			lowestCellVoltage = getLowestCellVoltage(pack->modules[m]);
		}
	}
	return lowestCellVoltage;
}

// Return the voltage of the highest cell in the pack
float getHighestCellVoltage(BatteryPack *pack) {
	float highestCellVoltage = getHighestCellVoltage(pack->modules[0]);
	for ( int i = 1; i < MODULES_PER_PACK; i++ ) {
		if ( getHighestCellVoltage(pack->modules[i]) < highestCellVoltage ) {
			highestCellVoltage = getHighestCellVoltage(pack->modules[i]);
		}
	}
	return highestCellVoltage;
}

// Return true if any cell in the pack is over max voltage
bool hasCellOverVoltage(BatteryPack *pack) {
	for ( int m = 0; m < MODULES_PER_PACK; m++ ){
		if ( hasCellOverVoltage(pack->modules[m]) ) {
			return true;
		}
	}
	return false;
}

// Update the value for the voltage of an individual cell in a pack
void updateCellVoltage(BatteryPack *pack, int moduleIndex, int cellIndex, float newCellVoltage) {
	updateCellVoltage(pack->modules[moduleIndex], cellIndex, newCellVoltage);
}


//// ----
//
// Temperature
//
//// ----

// Return true if any cell in the pack is over max temperature
bool hasCellOverTemp(BatteryPack *pack) {
	for ( int i = 0; i < MODULES_PER_PACK; i++ ) {
		if ( hasCellOverTemp(pack->modules[i]) ) {
			return true;
		}
	}
	return false;
}

// Return the maximum current we can charge the pack with.
int getMaxChargingCurrent(BatteryPack *pack) {
	int maxChargeCurrent = getMaxChargingCurrent(pack->modules[0]);
	for ( int m = 1; m < MODULES_PER_PACK; m++ ) {
		if ( getMaxChargingCurrent(pack->modules[m]) < maxChargeCurrent ) {
			maxChargeCurrent = getMaxChargingCurrent(pack->modules[m]);
		}
	}
	return maxChargeCurrent;
}

float getLowestTemperature(BatteryPack *pack) {
	float lowestModuleTemperature = 1000;
	for ( int m = 0; m < MODULES_PER_PACK; m++ ) {
		if ( getLowestTemperature(pack->modules[m]) < lowestModuleTemperature ) {
			lowestModuleTemperature = getLowestTemperature(pack->modules[m]);
		}
	}
	return lowestModuleTemperature;
}


//// ----
//
// Contactors
//
//// ----

bool closeContactors(BatteryPack *pack) {
	gpio_put(pack->contactorPin, 1);
	return true;
}

bool openContactors(BatteryPack *pack) {
	gpio_put(pack->contactorPin, 0);
	return true;
}



