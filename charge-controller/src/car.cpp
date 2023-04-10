/*
 * This file is part of the ev mustang charge controller project.
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

using namespace std;

#include <stdio.h>

#include "car.h"
#include "util.h"

#include "settings.h"


Car::Car() {
    maximumBatteryVoltage = BATTERY_MAX_VOLTAGE;
    maximumChargeCurrent = BATTERY_MAX_CURRENT;
}

/*
 * Based on our SoC and a given charge current, calculate how many minutes we
 * think it will take to charge to 100% SoC.
 *
 * FIXME : this is not correct
 */
uint8_t Car::calculate_charging_time_minutes(uint8_t current) {
    uint16_t batteryCapacityInWattMinutes = batteryCapacity * 0.11 * 1000 * 60;
    uint32_t chargingWatts = current * targetBatteryVoltage;
    return batteryCapacityInWattMinutes / chargingWatts;
}

/*
 * Calculate max charging time based on estimated charging time.
 */
uint8_t Car::calculate_max_charging_time_minutes(uint8_t current) {
    return calculate_charging_time_minutes(current);
}