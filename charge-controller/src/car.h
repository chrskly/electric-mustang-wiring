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
        uint16_t targetBatteryVoltage;
        bool vehicleChargingEnabled;
        bool highBatteryTemperature;

    public:
        // Received from BMS
        uint16_t soc;                     // Battery SoC, received from BMS
        uint16_t maximumBatteryVoltage;   // 'Full' battery voltage from BMS
        uint16_t maximumChargeCurrent;    // Maximum charge current allowed by BMS
        uint16_t maximumDischargeCurrent; // Maximum discharge current allowed by BMS
        uint16_t minimumBatteryVoltage;   // 'Empty' battery voltage from BMS

        // Charging current to request from EVSE. Derived from what the BMS
        // and the station allow.
        uint8_t targetChargingCurrent;

        // Rated capacity of the battery (kWh). Send to station.
        uint16_t batteryCapacity;  // 0.11 kWh/bit

        Car();
        uint8_t calculate_charging_time_minutes(uint8_t current);
        uint8_t calculate_max_charging_time_minutes(uint8_t current);

};

#endif