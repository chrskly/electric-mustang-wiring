/*

*/

void initialiseModule(BatteryModule *module, BatteryPack *pack) {
	module.pack = pack;
}



// Voltage

float getModuleVoltage(BatteryModule *module) {
	float moduleVoltage = module.cellVoltage[0];
	for ( i = 1; i < CELLS_PER_MODULE ; i++ ) {
		moduleVoltage += module.cellVoltage[i];
	}
	return moduleVoltage;
}

float getModuleLowestCellVoltage(BatteryModule *module) {
	float moduleLowestCellVoltage = module.cellVoltage[0];
	for ( i = 1; i < 16; i++ ) {
		if ( module.cellVoltage[i] < moduleLowestCellVoltage ) {
			moduleLowestCellVoltage = module.cellVoltage[i];
		}
	}
	return moduleLowestCellVoltage;
}

float getModuleHighestCellVoltage(BatteryModule *module) {
	return module.highestCellVoltage;
}

void updateModuleCellVoltage(BatteryModule *module, int cellIndex, float newCellVoltage) {
	module.cellVoltage[cellIndex] = newCellVoltage;
}


// Temperature


float getModuleLowestTemperature(BatteryModule *module) {
	return module.lowestTemperature;
}

float getModuleHighestTemperature(BatteryModule *module) {
	return module.highestTemperature;
}

bool moduleHasCellOverTemp(BatteryModule *module) {
	for ( i = 0; i < CELLS_PER_MODULE; i++ ) {
		if ( module.cellTemperature[i] >= CELL_OVER_TEMPERATURE_FAULT_THRESHOLD ) {
			return true;
		}
	}
	return false;
}

