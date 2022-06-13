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

void initialiseBattery(Battery *battery);

// Voltage
float getVoltage(Battery *battery);
void updateVoltage(Battery *battery);
void updateCellVoltage(Battery *battery, int packIndex, int moduleIndex, int cellIndex, float newCellVoltage);
float getLowestCellVoltage(Battery *battery);
void updateLowestCellVoltage(Battery *battery);
bool hasCellUnderVoltage(Battery *battery);
float getHighestCellVoltage(Battery *battery);
void updateHighestCellVoltage(Battery *battery);
bool hasCellOverVoltage(Battery *battery);
float voltageDeltaBetweenPacks(Battery *battery);
BatteryPack* getPackWithHighestVoltage(Battery *battery);

// Temperature
bool hasCellOverTemp(Battery *battery);
int getMaxChargingCurrent(Battery *battery);
float getLowestTemperature(Battery *battery);
bool tooColdToCharge(Battery *battery);

// Contactors
void closeContactors(Battery *battery);
void openContactors(Battery *battery);


