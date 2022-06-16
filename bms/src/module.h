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


void initialise_module(BatteryModule *module, BatteryPack *pack);

// Voltage
float get_voltage(BatteryModule *module);
float get_lowest_cell_voltage(BatteryModule *module);
bool has_cell_under_voltage(BatteryModule *module);
float get_highest_cell_voltage(BatteryModule *module);
bool has_temperature_sensor_over_max(BatteryModule *module);
void update_cell_voltage(BatteryModule *module, int cellIndex, float newCellVoltage);
bool has_cell_over_voltage(BatteryModule *module);

// Temperature
void update_temperature(BatteryModule *module, int tempSensorId, float newTemperature);
float get_highest_temperature(BatteryModule *module);
float get_lowest_temperature(BatteryModule *module);
bool temperature_at_warning_level(BatteryModule *module);

// Charging
int get_max_charging_current(BatteryModule *module);


