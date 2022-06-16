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

void initialise_battery(Battery *battery) {
	// Create the packs
	for ( int i = 0; i < NUM_PACKS; i++ ) {
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
float get_voltage(Battery *battery) {
	return battery->voltage;
}

// Recompute and store the battery voltage based on current cell voltages
void update_voltage(Battery *battery) {
	float voltage = get_voltage(battery->packs[0]);
	for ( int i = 1; i < NUM_PACKS; i++ ) {
		if ( get_voltage(battery->packs[i]) > voltage ) {
			voltage = get_voltage(battery->packs[i]);
		}
	}
	battery->voltage = voltage;
}

// Update the value we have stored for an individual cell in the pack
void update_cell_voltage(Battery *battery, int packIndex, int moduleIndex, int cellIndex, float newCellVoltage) {
	update_cell_voltage(battery->packs[packIndex], moduleIndex, cellIndex, newCellVoltage);
}

// Low cells

// Return the voltage of the lowest cell in the battery
float get_lowest_cell_voltage(Battery *battery) {
	return battery->lowestCellVoltage;
}

// Recompute the lowest cell voltage
void update_lowest_cell_voltage(Battery *battery) {
	float lowestCellVoltage = get_lowest_cell_voltage(battery->packs[0]);
	for ( int p = 1; p < NUM_PACKS; p++ ) {
		if ( get_lowest_cell_voltage(battery->packs[p]) < lowestCellVoltage ) {
			lowestCellVoltage = get_lowest_cell_voltage(battery->packs[p]);
		}
	}
	battery->lowestCellVoltage = lowestCellVoltage;
}

// Return true if any cell in the battery is below the minimum voltage level
bool has_cell_under_voltage(Battery *battery) {
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( has_cell_under_voltage(battery->packs[p]) ) {
			return true;
		}
	}
	return false;
}

// High cells

// Return the voltage of the highest cell in the battery
float get_highest_cell_voltage(Battery *battery) {
	return battery->highestCellVoltage;
}

// Recompute the highest cell voltage
void update_highest_cell_voltage(Battery *battery) {
	float highestCellVoltage = get_highest_cell_voltage(battery->packs[0]);
	for ( int p = 1; p < NUM_PACKS; p++ ) {
		if ( get_highest_cell_voltage(battery->packs[p]) < highestCellVoltage ) {
			highestCellVoltage = get_highest_cell_voltage(battery->packs[p]);
		}
	}
	battery->highestCellVoltage = highestCellVoltage;
}

// Return true if any cell in the battery is below the minimum voltage level
bool has_cell_over_voltage(Battery *battery) {
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( has_cell_over_voltage(battery->packs[p]) ) {
			return true;
		}
	}
	return false;
}

// Return the largest voltage difference between any two packs in this battery.
float voltage_delta_between_packs(Battery *battery) {
	float highestPackVoltage = -10000;
	float lowestPackVoltage = 10000;
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		float packVoltage = get_voltage(battery->packs[p]);
		if ( packVoltage > highestPackVoltage ) {
			highestPackVoltage = packVoltage;
		}
		if ( packVoltage < lowestPackVoltage ) {
			lowestPackVoltage = packVoltage;
		}
	}
	return highestPackVoltage - lowestPackVoltage;
}

// return the battery pack which has the highest voltage
BatteryPack* get_pack_with_highest_voltage(Battery *battery) {
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

// Return true if any sensor in the pack is over the max temperature
bool has_temperature_sensor_over_max(Battery *battery) {
	for ( int i = 0; i < NUM_PACKS; i++ ) {
		if ( has_temperature_sensor_over_max(battery->packs[i]) ){
			return true;
		}
	}
	return false;
}

int get_max_charging_current(Battery *battery) {
	int maxChargeCurrent = CHARGE_CURRENT_MAX;
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( get_max_charging_current(battery->packs[p]) < maxChargeCurrent ) {
			maxChargeCurrent = get_max_charging_current(battery->packs[p]);
		}
	}
	return maxChargeCurrent;
}

float get_lowest_temperature(Battery *battery) {
	float lowestTemperature = 1000;
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( get_lowest_temperature(battery->packs[p]) < lowestTemperature ) {
			lowestTemperature = get_lowest_temperature(battery->packs[p]);
		}
	}
	return lowestTemperature;
}

bool too_cold_to_charge(Battery *battery) {
	if ( get_lowest_temperature(battery) < CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD ) {
		return true;
	}
	return false;
}




//// ----
//
// Contactor control
//
//// ----

void close_contactors(Battery *battery) {

	// Check that the voltage difference between the packs in the battery is
	// a small, safe value.
	if ( voltage_delta_between_packs(battery) < SAFE_VOLTAGE_DELTA_BETWEEN_PACKS ) {
		for ( int p = 0; p < NUM_PACKS; p++ ) {
			close_contactors(battery->packs[p]);
		}
	}

	// The pack voltages differ too much. We can only use one pack. Figure out
	// which pack is fuller (has higher voltage) and close the contactors for
	// just that pack.
	else {
		close_contactors(get_pack_with_highest_voltage(battery));
	}

}

void open_contactors(Battery *battery) {
	// wait?
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		open_contactors(battery->packs[p]);
	}
}
