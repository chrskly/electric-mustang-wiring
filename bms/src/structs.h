
#ifndef STRUCTS_H
#define STRUCTS_H

#include "mcp2515/mcp2515.h"
#include "settings.h"

struct BatteryPack;

struct Battery {
	struct BatteryPack *packs[2];
	float voltage;
	float lowestCellVoltage;
	float highestCellVoltage;
	float lowestCellTemperature;
	float highestCellTemperature;
};

struct BatteryPack {
	MCP2515 CAN;                // CAN bus connection to this pack
	absolute_time_t lastUpdate; // Time we received last update from BMS
	struct BatteryModule *modules[16];  // The child modules that make up this BatteryPack
	struct Battery *battery;            // The parent Battery that contains this BatteryPack
	float voltage;              // Voltage of the total pack
	bool interrupt;             //
	bool contactorsClosed;      // 
};

struct BatteryModule {
	float cellVoltage[CELLS_PER_MODULE];     // Voltages of each cell
	float cellTemperature[TEMPS_PER_MODULE]; // Temperatures of each cell
	struct BatteryPack *pack;                        // The parent BatteryPack the contains this module
	uint8_t msgcycle;
	uint8_t nextmsg;
	uint8_t testcycle;
};

#endif