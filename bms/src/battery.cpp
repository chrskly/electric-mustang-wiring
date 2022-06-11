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

#include "battery.h"
#include "pack.h"

void initialiseBattery(Battery *battery) {
	// Create the packs
	for ( int i = 0; i < 2; i++ ) {
		BatteryPack pack;
		pack.battery = battery;
	}
}


//// ----
//
// Voltage
//
//// ----

// Return the voltage of the whole battery
float getVoltage(Battery *battery) {
	return battery->voltage;
}

void updateVoltage(Battery *battery) {
	float voltage = getVoltage(battery->packs[0]);
	for ( int i = 1; i < NUM_PACKS; i++ ) {
		if ( getVoltage(battery->packs[i]) > voltage ) {
			voltage = getVoltage(battery->packs[i]);
		}
	}
	battery->voltage = voltage;
}

void updateCellVoltage(Battery *battery, int packIndex, int moduleIndex, int cellIndex, float newCellVoltage) {
	updateCellVoltage(battery->packs[packIndex], moduleIndex, cellIndex, newCellVoltage);
}

// Low cells

float getLowestCellVoltage(Battery *battery) {
	return battery->lowestCellVoltage;
}

void updateLowestCellVoltage(Battery *battery) {
	float lowestCellVoltage = getLowestCellVoltage(battery->packs[0]);
	for ( int i = 0; i < 2; i++ ) {
		if ( getLowestCellVoltage(battery->packs[i]) < lowestCellVoltage ) {
			lowestCellVoltage = getLowestCellVoltage(battery->packs[i]);
		}
	}
	battery->lowestCellVoltage = lowestCellVoltage;
}

// High cells

float getHighestCellVoltage(Battery *battery) {
	return battery->highestCellVoltage;
}

void updateHighestCellVoltage(Battery *battery) {
	float highestCellVoltage = getHighestCellVoltage(battery->packs[0]);
	for ( int i = 0; i < 2; i++ ) {
		if ( getHighestCellVoltage(battery->packs[i]) < highestCellVoltage ) {
			highestCellVoltage = getHighestCellVoltage(battery->packs[i]);
		}
	}
	battery->highestCellVoltage = highestCellVoltage;
}

bool hasCellOverVoltage(Battery *battery) {
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( hasCellOverVoltage(battery->packs[p]) ) {
			return true;
		}
	}
	return false;
}

// Return the largest voltage difference between any two packs in this battery.
float voltageDeltaBetweenPacks(Battery *battery) {
	float highestPackVoltage = -10000;
	float lowestPackVoltage = 10000;
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		float packVoltage = getVoltage(battery->packs[p]);
		if ( packVoltage > highestPackVoltage ) {
			highestPackVoltage = packVoltage;
		}
		if ( packVoltage < lowestPackVoltage ) {
			lowestPackVoltage = packVoltage;
		}
	}
	return highestPackVoltage - lowestPackVoltage;
}

BatteryPack* getPackWithHighestVoltage(Battery *battery) {
	BatteryPack* pack = battery->packs[0];
	for ( int p = 1; p < NUM_PACKS; p++ ) {
		if ( battery->packs[p]->voltage > pack->voltage ) {
			pack = battery->packs[p];
		}
	}
	return pack;
}


//// ----
//
// Temperature
//
//// ----

bool hasCellOverTemp(Battery *battery) {
	for ( int i = 0; i < NUM_PACKS; i++ ) {
		if ( hasCellOverTemp(battery->packs[i]) ){
			return true;
		}
	}
	return false;
}


int getMaxChargingCurrent(Battery *battery) {
	int maxChargeCurrent = CHARGE_CURRENT_MAX;
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( getMaxChargingCurrent(battery->packs[p]) < maxChargeCurrent ) {
			maxChargeCurrent = getMaxChargingCurrent(battery->packs[p]);
		}
	}
	return maxChargeCurrent;
}

float getLowestTemperature(Battery *battery) {
	float lowestTemperature = 1000;
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( getLowestTemperature(battery->packs[p]) < lowestTemperature ) {
			lowestTemperature = getLowestTemperature(battery->packs[p]);
		}
	}
	return lowestTemperature;
}

bool tooColdToCharge(Battery *battery) {
	if ( getLowestTemperature(battery) < CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD ) {
		return true;
	}
	return false;
}


//// ----
//
// Contactor control
//
//// ----

void closeContactors(Battery *battery) {

	// Check that the voltage difference between the packs in the battery is
	// a small, safe value.
	if ( voltageDeltaBetweenPacks(battery) < SAFE_VOLTAGE_DELTA_BETWEEN_PACKS ) {
		for ( int p = 0; p < NUM_PACKS; p++ ) {
			closeContactors(battery->packs[p]);
		}
	}

	// The pack voltages differ too much. We can only use one pack. Figure out
	// which pack is fuller (has higher voltage) and close the contactors for
	// just that pack.
	else {
		closeContactors(getPackWithHighestVoltage(battery));
	}

}

void openContactors(Battery *battery) {
	// wait?
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		openContactors(battery->packs[p]);
	}
}
