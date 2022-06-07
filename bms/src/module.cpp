/*

*/

#include "structs.h"


void initialiseModule(BatteryModule *module, BatteryPack *pack) {
	module->pack = pack;
}



// Voltage

float getModuleVoltage(BatteryModule *module) {
	float moduleVoltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE ; i++ ) {
		moduleVoltage += module->cellVoltage[i];
	}
	return moduleVoltage;
}

float getModuleLowestCellVoltage(BatteryModule *module) {
	float moduleLowestCellVoltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellVoltage[i] < moduleLowestCellVoltage ) {
			moduleLowestCellVoltage = module->cellVoltage[i];
		}
	}
	return moduleLowestCellVoltage;
}

float getModuleHighestCellVoltage(BatteryModule *module) {
	float moduleHighestCellVoltage = module->cellVoltage[0];
	for ( int i = 1; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellVoltage[i] > moduleHighestCellVoltage ) {
			moduleHighestCellVoltage = module->cellVoltage[i];
		}
	}
	return moduleHighestCellVoltage;
}

void updateModuleCellVoltage(BatteryModule *module, int cellIndex, float newCellVoltage) {
	module->cellVoltage[cellIndex] = newCellVoltage;
}

bool moduleHasCellOverVoltage(BatteryModule *module) {
	for ( int c = 0; c < CELLS_PER_MODULE; c++ ) {
		if ( module->cellVoltage[c] > CELL_OVER_VOLTAGE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}


// Temperature

float moduleGetHighestCellTemperature(BatteryModule *module) {
	float highestCellTemperature;
	highestCellTemperature = module->cellTemperature[0];
	for ( int t = 1; t < TEMPS_PER_MODULE; t++ ) {
		if ( module->cellTemperature[t] > highestCellTemperature ) {
			highestCellTemperature = module->cellTemperature[t];
		}
	}
	return highestCellTemperature;
}

/*
float getModuleLowestTemperature(BatteryModule *module) {
	return module->lowestTemperature;
}

float getModuleHighestTemperature(BatteryModule *module) {
	return module->highestTemperature;
}
*/

// returns true when any temperature sensor in this module is over the warning
// level, but below the critical level.
bool moduleTemperatureAtWarningLevel(BatteryModule *module) {
	for ( int i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellTemperature[i] >= CELL_OVER_TEMPERATURE_WARNING_THRESHOLD and 
			 module->cellTemperature[i] < CELL_OVER_TEMPERATURE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}

// 
bool moduleTemperatureDisalllowsDriving(BatteryModule *module) {
	for ( int i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellTemperature[i] >= CELL_OVER_TEMPERATURE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}

bool moduleTemperatureDisallowsCharging(BatteryModule *module) {
	for ( int i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module->cellTemperature[i] <= CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}

// Charging

int moduleGetMaxChargingCurrent(BatteryModule *module) {
    float highestCellTemperature = moduleGetHighestCellTemperature(module);
    if ( highestCellTemperature > CHARGE_THROTTLE_TEMP_LOW ) {
    	float degreesOver = highestCellTemperature - CHARGE_THROTTLE_TEMP_LOW;
    	float scaleFactor = 1 - ( degreesOver / ( CHARGE_THROTTLE_TEMP_HIGH - CHARGE_THROTTLE_TEMP_LOW ) );
    	float chargeCurrent = ( scaleFactor * ( CHARGE_CURRENT_MAX - CHARGE_CURRENT_MIN ) ) + CHARGE_CURRENT_MIN;
    	return (int)chargeCurrent;
    } else {
    	return (int)CHARGE_CURRENT_MAX;
    }
}





