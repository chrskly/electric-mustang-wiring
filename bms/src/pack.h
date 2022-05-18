
#include "mcp2515/mcp2515.h"
#include "module.h"

typedef struct BatteryPack {
	MCP2515 CAN;               // CAN bus connection to this pack
	int lastUpdate;            // number of seconds elapsed since the last data read
	BatteryModule modules[16]; // 
} BatteryPack;

