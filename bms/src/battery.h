
#include "structs.h"

void initialiseBattery(Battery *battery);
float getBatteryVoltage(Battery *battery);
float getBatteryLowestCellVoltage(Battery *battery);
float getBatteryHighestCellVoltage(Battery *battery);

float getBatteryLowestTemperature(Battery *battery);
float getBatteryHighestTemperature(Battery *battery);
bool batteryHasCellOverTemp(Battery *battery);
