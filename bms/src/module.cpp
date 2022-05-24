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


// Temperature

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
