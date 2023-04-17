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
        // Voltage to charge up to
        uint16_t targetBatteryVoltage;

        bool vehicleChargingEnabled;
        bool highBatteryTemperature;

    public:
        // Below are all received from BMS
        uint16_t soc;                     // Battery SoC
        uint16_t maximumBatteryVoltage;   // 'Full' battery voltage
        uint16_t maximumChargeCurrent;    // Maximum charge current allowed by BMS
        uint16_t maximumDischargeCurrent; // Maximum discharge current allowed by BMS
        uint16_t minimumBatteryVoltage;   // 'Empty' battery voltage
        uint16_t batteryVoltage;          // Actual voltage of battery right now
        uint16_t batteryCurrent;          // Current (amps) in/out of the battery right now
        uint16_t batteryTemperature;      // Temperature of hottest cell
        bool highCellAlarm;               // 
        bool lowCellAlarm;                // 
        bool highTempAlarm;               // 
        bool lowTempAlarm;                // 
        bool cellDeltaAlarm;              // 
        bool highCellWarn;                // 
        bool lowCellWarn;                 // 
        bool highTempWarn;                // 
        bool lowTempWarn;                 // 

        // This is the current (amps) to request from the station. This value
        // only factors in any limits placed on us by the BMS.
        uint8_t targetChargingCurrent;

        // Rated capacity of the battery (kWh). Send to station.
        uint16_t batteryCapacity;  // 0.11 kWh/bit

        Car();
        uint8_t calculate_charging_time_minutes(uint8_t current);
        uint8_t calculate_max_charging_time_minutes(uint8_t current);
        uint8_t get_voltage_from_soc(uint8_t soc);

};

#endif