/*

*/

//#include "pack.h"


void initialiseModule(BatteryModule *module, BatteryPack *pack);
float getModuleVoltage(BatteryModule *module);
float getModuleLowestCellVoltage(BatteryModule *module);
float getModuleHighestCellVoltage(BatteryModule *module);
void updateModuleCellVoltage(BatteryModule *module, int cellIndex, float newCellVoltage);

float getModuleLowestTemperature(BatteryModule *module);
float getModuleHighestTemperature(BatteryModule *module);
bool moduleHasCellOverTemp(BatteryModule *module);

int moduleGetMaxChargingCurrent(BatteryModule *module);
bool moduleHasCellOverVoltage(BatteryModule *module);

