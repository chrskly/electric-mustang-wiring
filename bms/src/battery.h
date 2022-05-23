
#define NUM_PACKS         2  // The total number of paralleled packs in this battery
#define CELLS_PER_MODULE 16  // The number of cells in each module
#define MODULES_PER_PACK  6  // The number of modules in each pack

typedef struct Battery {
	BatteryPack packs[2];
	float voltage;
	float lowestCellVoltage;
	float highestCellVoltage;
	float lowestCellTemperature;
	float highestCellTemperature;
} Battery;


void initialiseBattery(Battery *battery);
float getBatteryVoltage(Battery *battery);
float getBatteryLowestCellVoltage(Battery *battery);
float getBatteryHighestCellVoltage(Battery *battery);

float getBatteryLowestTemperature(Battery *battery);
float getBatteryHighestTemperature(Battery *battery);
bool batteryHasCellOverTemp(Battery *battery);
