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

/*

    MODULE

*/

#include <stdio.h>

#include "structs.h"


void initialise_module(BatteryModule *module, BatteryPack *pack) {
	module->pack = pack;
	// voltages
	for ( int c = 0; c < CELLS_PER_MODULE; c++ ) {
		module->cellVoltage[c] = 0;
	}
	// temps
	for ( int t = 0; t < TEMPS_PER_MODULE; t++ ) {
		module->cellTemperature[t] = 0;
	}
}


//// ----
//
// Voltage
//
//// ----

// Return total module voltage by summing the cell voltages
float get_voltage(BatteryModule *module) {
	float voltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE ; i++ ) {
		voltage += module->cellVoltage[i];
	}
	return voltage;
}

// Return the voltage of the lowest cell voltage in the module
float get_lowest_cell_voltage(BatteryModule *module) {
	printf("Inside get_lowest_cell_voltage (module)\n");
	//float lowestCellVoltage = module->cellVoltage[0];
	float lowestCellVoltage = 1000;
	for ( int c = 0; c < CELLS_PER_MODULE; c++ ) {
		printf("Checking cell %d\n", c);
		if ( module->cellVoltage[c] < lowestCellVoltage ) {
			lowestCellVoltage = module->cellVoltage[c];
		}
		printf("bbb\n");
	}
	printf("Returning lowestCellVoltage %f (module)\n", lowestCellVoltage);
	return lowestCellVoltage;
}

// Return true if any of the cells in the module are under min voltage
bool has_cell_under_voltage(BatteryModule *module) {
	for ( int c = 0; c < CELLS_PER_MODULE; c++ ) {
		if ( module->cellVoltage[c] < CELL_UNDER_VOLTAGE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}

// Return the voltage of the highest cell in the module
float get_highest_cell_voltage(BatteryModule *module) {
	float highestCellVoltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellVoltage[i] > highestCellVoltage ) {
			highestCellVoltage = module->cellVoltage[i];
		}
	}
	return highestCellVoltage;
}

// Update the voltage for a single cell
void update_cell_voltage(BatteryModule *module, int cellIndex, float newCellVoltage) {
	module->cellVoltage[cellIndex] = newCellVoltage;
}

// Return true if any of the cells in the module are over max voltage
bool has_cell_over_voltage(BatteryModule *module) {
	for ( int c = 0; c < CELLS_PER_MODULE; c++ ) {
		if ( module->cellVoltage[c] > CELL_OVER_VOLTAGE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}


//// ----
//
// Temperature
//
//// ----

// Update the value for one of the temperature sensors
void update_temperature(BatteryModule *module, int tempSensorId, float newTemperature) {
	module->cellTemperature[tempSensorId] = newTemperature;
}

// Return the temperature of the hottest sensor in the module
float get_highest_temperature(BatteryModule *module) {
	float highestTemperature;
	highestTemperature = module->cellTemperature[0];
	for ( int t = 1; t < TEMPS_PER_MODULE; t++ ) {
		if ( module->cellTemperature[t] > highestTemperature ) {
			highestTemperature = module->cellTemperature[t];
		}
	}
	return highestTemperature;
}

// Return true if any temperature sensor is over the max temperature
bool has_temperature_sensor_over_max(BatteryModule *module) {
	return ( get_highest_temperature(module) > CELL_OVER_TEMPERATURE_FAULT_THRESHOLD );
}

// Return the temperature of the coldest sensor in the module
float get_lowest_temperature(BatteryModule *module) {
	float lowestTemperature = 1000;
	for ( int t = 0; t < TEMPS_PER_MODULE; t++ ) {
		if ( module->cellTemperature[t] < lowestTemperature ) {
			lowestTemperature = module->cellTemperature[t];
		}
	}
	return lowestTemperature;
}

// returns true when any temperature sensor in this module is over the warning
// level, but below the critical level.
bool temperature_at_warning_level(BatteryModule *module) {
	for ( int i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellTemperature[i] >= CELL_OVER_TEMPERATURE_WARNING_THRESHOLD and 
			 module->cellTemperature[i] < CELL_OVER_TEMPERATURE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}


//// ----
//
// Charging
//
//// ----

// Return the maximum current the charger may push into the module
int get_max_charging_current(BatteryModule *module) {
    float highestTemperature = get_highest_temperature(module);
    if ( highestTemperature > CHARGE_THROTTLE_TEMP_LOW ) {
    	float degreesOver = highestTemperature - CHARGE_THROTTLE_TEMP_LOW;
    	float scaleFactor = 1 - ( degreesOver / ( CHARGE_THROTTLE_TEMP_HIGH - CHARGE_THROTTLE_TEMP_LOW ) );
    	float chargeCurrent = ( scaleFactor * ( CHARGE_CURRENT_MAX - CHARGE_CURRENT_MIN ) ) + CHARGE_CURRENT_MIN;
    	return (int)chargeCurrent;
    } else {
    	return (int)CHARGE_CURRENT_MAX;
    }
}





