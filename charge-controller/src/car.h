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

#ifndef CAR_H
#define CAR_H

class Car {

    private:
        uint8_t chademoControlProtocolNumber;
        uint16_t maximumBatteryVoltage;
        uint8_t maximumChargingTimeMinutes;
        uint8_t maximumChargingTimeSeconds;
        uint16_t targetBatteryVoltage;
        bool vehicleChargingEnabled;
        bool highBatteryTemperature;

    public:
        uint16_t batteryCapacity;  // 0.11 kWh/bit
        uint8_t soc; // Battery SoC, received from BMS

        Car();
        uint8_t calculate_charging_time_minutes(uint8_t current);
        uint8_t calculate_max_charging_time_minutes(uint8_t current);

};

#endif