
#include "hardware/timer.h"

#include "mcp2515/mcp2515.h"
#include "module.h"

#define PACK_ALIVE_TIMEOUT 5   // If we have not seen an update from the BMS in
                               // PACK_ALIVE_TIMEOUT seconds, then mark the pack
                               // as dead.

typedef struct BatteryPack {
	MCP2515 CAN;                // CAN bus connection to this pack
	absolute_time_t lastUpdate; // Time we received last update from BMS
	BatteryModule modules[16];  // The child modules that make up this BatteryPack
	Battery battery;            // The parent Battery that contains this BatteryPack
	float voltage;              // Voltage of the total pack
	bool interrupt;             //
} BatteryPack;

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