
#include "hardware/timer.h"
#include "mcp2515/mcp2515.h"

#include "structs.h"

void initialisePack(BatteryPack *pack);

bool packIsAlive(BatteryPack *pack);

float getPackVoltage(BatteryPack *pack);
void updatePackVoltage(BatteryPack *pack);
float getPackLowestCellVoltage(BatteryPack *pack);
float getPackHighestCellVoltage(BatteryPack *pack);
void updatePackCellVoltage(BatteryPack *pack, int moduleIndex, int cellIndex, float newCellVoltage);
float getPackLowestTemperature(BatteryPack *pack);
float getPackHighestTemperature(BatteryPack *pack);
bool packHasCellOverTemp(BatteryPack *pack);

int packGetMaxChargingCurrent(BatteryPack *pack);
bool packHasCellOverVoltage(BatteryPack *pack);