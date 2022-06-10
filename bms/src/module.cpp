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

#include "structs.h"


void initialiseModule(BatteryModule *module, BatteryPack *pack) {
	module->pack = pack;
}


//// ----
//
// Voltage
//
//// ----

// Return total module voltage by summing the cell voltages
float getVoltage(BatteryModule *module) {
	float voltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE ; i++ ) {
		voltage += module->cellVoltage[i];
	}
	return voltage;
}

// Return the voltage of the lowest cell voltage in the module
float getLowestCellVoltage(BatteryModule *module) {
	float lowestCellVoltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellVoltage[i] < lowestCellVoltage ) {
			lowestCellVoltage = module->cellVoltage[i];
		}
	}
	return lowestCellVoltage;
}

// Return the voltage of the highest cell voltage in the module
float getHighestCellVoltage(BatteryModule *module) {
	float highestCellVoltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellVoltage[i] > highestCellVoltage ) {
			highestCellVoltage = module->cellVoltage[i];
		}
	}
	return highestCellVoltage;
}

// Update the voltage for a single cell
void updateCellVoltage(BatteryModule *module, int cellIndex, float newCellVoltage) {
	module->cellVoltage[cellIndex] = newCellVoltage;
}

// Return true if any of the cells in the module are over max voltage
bool hasCellOverVoltage(BatteryModule *module) {
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

// Return the temperature of the hottest sensor in the module
float getHighestCellTemperature(BatteryModule *module) {
	float highestCellTemperature;
	highestCellTemperature = module->cellTemperature[0];
	for ( int t = 1; t < TEMPS_PER_MODULE; t++ ) {
		if ( module->cellTemperature[t] > highestCellTemperature ) {
			highestCellTemperature = module->cellTemperature[t];
		}
	}
	return highestCellTemperature;
}


// returns true when any temperature sensor in this module is over the warning
// level, but below the critical level.
bool temperatureAtWarningLevel(BatteryModule *module) {
	for ( int i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellTemperature[i] >= CELL_OVER_TEMPERATURE_WARNING_THRESHOLD and 
			 module->cellTemperature[i] < CELL_OVER_TEMPERATURE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}

// 
bool temperatureDisalllowsDriving(BatteryModule *module) {
	for ( int i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellTemperature[i] >= CELL_OVER_TEMPERATURE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}

bool temperatureDisallowsCharging(BatteryModule *module) {
	for ( int i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellTemperature[i] <= CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD ) {
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
int getMaxChargingCurrent(BatteryModule *module) {
    float highestCellTemperature = getHighestCellTemperature(module);
    if ( highestCellTemperature > CHARGE_THROTTLE_TEMP_LOW ) {
    	float degreesOver = highestCellTemperature - CHARGE_THROTTLE_TEMP_LOW;
    	float scaleFactor = 1 - ( degreesOver / ( CHARGE_THROTTLE_TEMP_HIGH - CHARGE_THROTTLE_TEMP_LOW ) );
    	float chargeCurrent = ( scaleFactor * ( CHARGE_CURRENT_MAX - CHARGE_CURRENT_MIN ) ) + CHARGE_CURRENT_MIN;
    	return (int)chargeCurrent;
    } else {
    	return (int)CHARGE_CURRENT_MAX;
    }
}





