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
void batteryOpenContactors(Battery *battery);

float getVoltage(Battery *battery);
float getLowestCellVoltage(Battery *battery);
float getHighestCellVoltage(Battery *battery);

float getLowestTemperature(Battery *battery);
float getHighestTemperature(Battery *battery);
bool hasCellOverTemp(Battery *battery);

int getMaxChargingCurrent(Battery *battery);
bool hasCellOverVoltage(Battery *battery);

void closeContactors(Battery *battery);
void openContactors(Battery *battery);