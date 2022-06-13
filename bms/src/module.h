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


void initialiseModule(BatteryModule *module, BatteryPack *pack);

// Voltage
float getVoltage(BatteryModule *module);
float getLowestCellVoltage(BatteryModule *module);
bool hasCellUnderVoltage(BatteryModule *module);
float getHighestCellVoltage(BatteryModule *module);
bool hasCellOverTemp(BatteryModule *module);
void updateCellVoltage(BatteryModule *module, int cellIndex, float newCellVoltage);
bool hasCellOverVoltage(BatteryModule *module);

// Temperature
void updateTemperature(BatteryModule *module, int tempSensorId, float newTemperature);
float getHighestTemperature(BatteryModule *module);
float getLowestTemperature(BatteryModule *module);
bool temperatureAtWarningLevel(BatteryModule *module);

// Charging
int getMaxChargingCurrent(BatteryModule *module);


