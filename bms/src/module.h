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

#ifndef MODULE_H
#define MODULE_H

#include "settings.h"

class BatteryPack;

class BatteryModule {

    private:

        int numCells;                            // Number of cells in this module
        int numTemperatureSensors;               // Number of temperature sensors in this module
        float cellVoltage[CELLS_PER_MODULE];     // Voltages of each cell
        float cellTemperature[TEMPS_PER_MODULE]; // Temperatures of each cell
        BatteryPack *pack;                       // The parent BatteryPack that contains this module

    public:

        BatteryModule (BatteryPack *pack, int numCells, int numTemperatureSensors);

        // Voltage
        float get_voltage();
        float get_lowest_cell_voltage();
        bool has_cell_under_voltage();
        float get_highest_cell_voltage();
        bool has_temperature_sensor_over_max();
        void update_cell_voltage(int cellIndex, float newCellVoltage);
        bool has_cell_over_voltage();

        // Temperature
        void update_temperature(int tempSensorId, float newTemperature);
        float get_highest_temperature();
        float get_lowest_temperature();
        bool temperature_at_warning_level();

        // Charging
        int get_max_charging_current();


};

#endif
