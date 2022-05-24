
#include "pack.h"
#include "module.h"

void initialisePack(BatteryPack *pack) {
	// Create the modules
	for ( int i = 0; i < 16; i++ ) {
		BatteryModule module;
		initialiseModule(&module, pack);
		pack->modules[i] = &module;
	}
}

bool packIsAlive(BatteryPack *pack) {
	absolute_time_t now = get_absolute_time();
	int64_t timeSinceLastUpdate = absolute_time_diff_us(pack->lastUpdate, now);
	if ( timeSinceLastUpdate >= PACK_ALIVE_TIMEOUT ) {
		return false;
	}
	return true;
}

// Voltage

float getPackVoltage(BatteryPack *pack) {
	return pack->voltage;
}

void updatePackVoltage(BatteryPack *pack) {
	float newPackVoltage = getModuleVoltage(pack->modules[0]);
	for ( int i = 1; i < MODULES_PER_PACK; i++ ) {
		newPackVoltage += getModuleVoltage(pack->modules[i]);
	}
	pack->voltage = newPackVoltage;
}

float getPackLowestCellVoltage(BatteryPack *pack) {
	float packLowestCellVoltage = getModuleLowestCellVoltage(pack->modules[0]);
	for ( int i = 1; i < MODULES_PER_PACK; i++ ) {
		if ( getModuleLowestCellVoltage(pack->modules[i]) < packLowestCellVoltage ) {
			packLowestCellVoltage = getModuleLowestCellVoltage(pack->modules[i]);
		}
	}
	return packLowestCellVoltage;
}

/*
float getPackHighestCellVoltage(BatteryPack *pack) {
	return pack.highestCellVoltage;
}
*/

void updatePackCellVoltage(BatteryPack *pack, int moduleIndex, int cellIndex, float newCellVoltage) {
	updateModuleCellVoltage(pack->modules[moduleIndex], cellIndex, newCellVoltage);
}

// Temperature

/*
float getPackLowestTemperature(BatteryPack *pack) {
	return pack.lowestTemperature;
}

float getPackHighestTemperature(BatteryPack *pack) {
	return pack.highestTemperature;
}
*/

bool packHasCellOverTemp(BatteryPack *pack) {
	for ( int i = 0; i < MODULES_PER_PACK; i++ ) {
		if ( moduleHasCellOverTemp(pack->modules[i]) ) {
			return true;
		}
	}
	return false;
}

