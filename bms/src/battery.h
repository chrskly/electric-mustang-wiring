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

#include "structs.h"

void initialise_battery(Battery *battery);

// Voltage
float get_voltage(Battery *battery);
void update_voltage(Battery *battery);
void update_cell_voltage(Battery *battery, int packIndex, int moduleIndex, int cellIndex, float newCellVoltage);
float get_lowest_cell_voltage(Battery *battery);
void update_lowest_cell_voltage(Battery *battery);
bool has_cell_under_voltage(Battery *battery);
float get_highest_cell_voltage(Battery *battery);
void update_highest_cell_voltage(Battery *battery);
bool has_cell_over_voltage(Battery *battery);
float voltage_delta_between_packs(Battery *battery);
BatteryPack* get_pack_with_highest_voltage(Battery *battery);

// Temperature
bool has_temperature_sensor_over_max(Battery *battery);
int get_max_charging_current(Battery *battery);
float get_lowest_temperature(Battery *battery);
bool too_cold_to_charge(Battery *battery);

// Contactors
void close_contactors(Battery *battery);
void open_contactors(Battery *battery);


