
#include "battery.h"

void initialiseBattery(Battery *battery) {
	// Create the packs
	for ( i = 0; i < 2; i++ ) {
		BatteryPack pack;
		pack.battery = battery;
	}
}

// Voltage

float getBatteryVoltage(Battery *battery) {
	return battery.voltage;
}

void updateBatteryVoltage(Battery *battery) {
	float packVoltage = getPackVoltage(battery.packs[0]);
	for ( i = 1; i < NUM_PACKS; i++ ) {
		if ( getPackVoltage(battery.packs[i]) > packVoltage ) {
			packVoltage = getPackVoltage(battery.packs[i]);
		}
	}
	battery.voltage = packVoltage;
}

void updateBatteryCellVoltage(Battery *battery, int packIndex, int moduleIndex, int cellIndex, float newCellVoltage) {
	updatePackCellVoltage(battery.packs[packIndex], int moduleIndex, int cellIndex, float newCellVoltage)
}

// Low cells

float getBatteryLowestCellVoltage(Battery *battery) {
	return battery.lowestCellVoltage;
}

void updateBatteryLowestCellVoltage(Battery *battery) {
	float newBatteryLowestCellVoltage = getPackLowestCellVoltage(battery.pack[0]);
	for ( i = 0; i < 2; i++ ) {
		if ( getPackLowestCellVoltage(battery.pack[i]) < newBatteryLowestCellVoltage ) {
			newBatteryLowestCellVoltage = getPackLowestCellVoltage(battery.pack[i]);
		}
	}
	battery.lowestCellVoltage = newBatteryLowestCellVoltage;
}

// High cells

float getBatteryHighestCellVoltage(Battery *battery) {
	return battery.highestCellVoltage;
}

void updateBatteryHighestCellVoltage(Battery *battery) {
	float newBatteryHighestCellVoltage = getPackHighestCellVoltage(battery.pack[0]);
	for ( i = 0; i < 2; i++ ) {
		if ( getPackHighestCellVoltage(battery.pack[i]) < newBatteryHighestCellVoltage ) {
			newBatteryHighestCellVoltage = getPackHighestCellVoltage(battery.pack[i]);
		}
	}
	battery.highestCellVoltage = newBatteryHighestCellVoltage;
}




// Temperature

float getBatteryLowestTemperature(Battery *battery) {
	return battery.lowestCellTemperature;
}

float getBatteryHighestTemperature(Battery *battery) {
	return battery.highestCellTemperature;
}

bool batteryHasCellOverTemp(Battery *battery) {
	for ( i = 0; i < NUM_PACKS; i++ ) {
		if ( packHasCellOverTemp(battery.packs[i]); ){
			return true;
		}
	}
	return false;
}
