/*
 * This file is part of the ev mustang bms project.
 *
 * Copyright (C) 2022 Christian Kelly <chrskly@chrskly.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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