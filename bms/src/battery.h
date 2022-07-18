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

#ifndef BATTERY_H
#define BATTERY_H

#include "pack.h"

class Battery {
    private:
        BatteryPack *packs[NUM_PACKS];
        int numPacks;
        float voltage;
        float lowestCellVoltage;
        float highestCellVoltage;
        float lowestCellTemperature;
        float highestCellTemperature;
    public:
        Battery (int numPacks);
        int print();

        void request_data();
        void read_message();
        void send_test_message();

        // Voltage
        float get_voltage();
        void set_voltage(float voltage) { this->voltage = voltage; }
        void update_voltage();
        void update_cell_voltage(int packIndex, int moduleIndex, int cellIndex, float newCellVoltage);
        float get_lowest_cell_voltage();
        void update_lowest_cell_voltage();
        bool has_cell_under_voltage();
        float get_highest_cell_voltage();
        void update_highest_cell_voltage();
        bool has_cell_over_voltage();
        float voltage_delta_between_packs();
        BatteryPack* get_pack_with_highest_voltage();

        // Temperature
        bool has_temperature_sensor_over_max();
        int get_max_charging_current();
        float get_lowest_temperature();
        bool too_cold_to_charge();

        // Contactors
        void close_contactors();
        void open_contactors();
};

#endif

