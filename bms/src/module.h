/*

*/

#include "pack.h"


#define CELL_UNDER_VOLTAGE_WARNING_THRESHOLD = 3.7
#define CELL_UNDER_VOLTAGE_FAULT_THRESHOLD = 3.6
#define CELL_OVER_VOLTAGE_WARNING_THRESHOLD = 4.0
#define CELL_OVER_VOLTAGE_FAULT_THRESHOLD = 4.1
#define CELL_OVER_TEMPERATURE_WARNING_THRESHOLD = 55  // degrees
#define CELL_OVER_TEMPERATURE_FAULT_THRESHOLD = 65    // degrees


struct BatteryModule {
	float cellVoltage[CELLS_PER_MODULE];     // Voltages of each cell
	float cellTemperature[CELLS_PER_MODULE]; // Temperatures of each cell
	BatteryPack pack;                        // The parent BatteryPack the contains this module
};

void initialiseModule(BatteryModule *module, BatteryPack *pack);
float getModuleVoltage(BatteryModule *module);
float getModuleLowestCellVoltage(BatteryModule *module);
float getModuleHighestCellVoltage(BatteryModule *module);
void updateModuleCellVoltage(BatteryModule *module, int cellIndex, float newCellVoltage);

float getModuleLowestTemperature(BatteryModule *module);
float getModuleHighestTemperature(BatteryModule *module);
bool moduleHasCellOverTemp(BatteryModule *module);

