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

#include "hardware/timer.h"
#include "mcp2515/mcp2515.h"

#include "structs.h"

void initialise_pack(BatteryPack *pack);
bool pack_is_alive(BatteryPack *pack);
void set_pack_error_status(BatteryPack *pack, int newErrorStatus);
int get_pack_error_status(BatteryPack *pack);
void set_pack_balance_status(BatteryPack *pack, int newBalanceStatus);
int get_pack_balance_status(BatteryPack *pack);
bool pack_is_due_to_be_balanced(BatteryPack *pack);
void reset_balance_timer(BatteryPack *pack);

// Voltage
float get_voltage(BatteryPack *pack);
void update_voltage(BatteryPack *pack);
float get_lowest_cell_voltage(BatteryPack *pack);
bool has_cell_under_voltage(BatteryPack *pack);
float get_highest_cell_voltage(BatteryPack *pack);
bool has_cell_over_voltage(BatteryPack *pack);
void update_cell_voltage(BatteryPack *pack, int moduleIndex, int cellIndex, float newCellVoltage);
void decode_voltages(BatteryPack *pack, can_frame voltageFrame);

// Temperature
bool has_cell_over_temp(BatteryPack *pack);
int get_max_charging_current(BatteryPack *pack);
float get_lowest_temperature(BatteryPack *pack);
void decode_temperatures(BatteryPack *pack, can_frame *temperatureMessageFrame);

// Contactors
bool close_contactors(BatteryPack *pack);
bool open_contactors(BatteryPack *pack);