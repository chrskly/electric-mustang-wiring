
#include "battery.h"
#include "pack.h"

void initialiseBattery(Battery *battery) {
	// Create the packs
	for ( int i = 0; i < 2; i++ ) {
		BatteryPack pack;
		pack.battery = battery;
	}
}

void batteryOpenContactors(Battery *battery) {
	return;
}

// Voltage

float getBatteryVoltage(Battery *battery) {
	return battery->voltage;
}

void updateBatteryVoltage(Battery *battery) {
	float packVoltage = getPackVoltage(battery->packs[0]);
	for ( int i = 1; i < NUM_PACKS; i++ ) {
		if ( getPackVoltage(battery->packs[i]) > packVoltage ) {
			packVoltage = getPackVoltage(battery->packs[i]);
		}
	}
	battery->voltage = packVoltage;
}

void updateBatteryCellVoltage(Battery *battery, int packIndex, int moduleIndex, int cellIndex, float newCellVoltage) {
	updatePackCellVoltage(battery->packs[packIndex], moduleIndex, cellIndex, newCellVoltage);
}

// Low cells

float getBatteryLowestCellVoltage(Battery *battery) {
	return battery->lowestCellVoltage;
}

void updateBatteryLowestCellVoltage(Battery *battery) {
	float newBatteryLowestCellVoltage = getPackLowestCellVoltage(battery->packs[0]);
	for ( int i = 0; i < 2; i++ ) {
		if ( getPackLowestCellVoltage(battery->packs[i]) < newBatteryLowestCellVoltage ) {
			newBatteryLowestCellVoltage = getPackLowestCellVoltage(battery->packs[i]);
		}
	}
	battery->lowestCellVoltage = newBatteryLowestCellVoltage;
}

// High cells

float getBatteryHighestCellVoltage(Battery *battery) {
	return battery->highestCellVoltage;
}

void updateBatteryHighestCellVoltage(Battery *battery) {
	float newBatteryHighestCellVoltage = getPackHighestCellVoltage(battery->packs[0]);
	for ( int i = 0; i < 2; i++ ) {
		if ( getPackHighestCellVoltage(battery->packs[i]) < newBatteryHighestCellVoltage ) {
			newBatteryHighestCellVoltage = getPackHighestCellVoltage(battery->packs[i]);
		}
	}
	battery->highestCellVoltage = newBatteryHighestCellVoltage;
}

bool batteryHasCellOverVoltage(Battery *battery) {
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( packHasCellOverVoltage(battery->packs[p]) ) {
			return true;
		}
	}
	return false;
}



// Temperature

bool batteryHasCellOverTemp(Battery *battery) {
	for ( int i = 0; i < NUM_PACKS; i++ ) {
		if ( packHasCellOverTemp(battery->packs[i]) ){
			return true;
		}
	}
	return false;
}


int batteryGetMaxChargingCurrent(Battery *battery) {
	int maxChargeCurrent = CHARGE_CURRENT_MAX;
	for ( int p = 0; p < NUM_PACKS; p++ ) {
		if ( packGetMaxChargingCurrent(battery->packs[p]) < maxChargeCurrent ) {
			maxChargeCurrent = packGetMaxChargingCurrent(battery->packs[p]);
		}
	}
	return maxChargeCurrent;
}
