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
#include "settings.h"



class Battery {

    private:
        BatteryPack packs[NUM_PACKS];
        int numPacks;
        float voltage;
        float lowestCellVoltage;
        float highestCellVoltage;
        float lowestCellTemperature;
        float highestCellTemperature;

        float maxChargeCurrent;
        float maxDischargeCurrent;

        // Outputs
        bool heaterEnabled;            // Indicates that the battery heater is currently enabled
        bool inhibitCharge;            // Indicates that the BMS INHIBIT_CHARGE signal is enabled
        bool inhibitDrive;             // Indicates that the BMS INHIBIT_DRIVE signal is enabled

        // Inputs
        bool ignitionOn;
        bool chargeEnable;             // Charger is asking to charge

        float soc;

    public:
        // Readings from ISA shunt
        long amps;
        long shuntVoltage1;
        long shuntVoltage2;
        long shuntVoltage3;
        long shuntTemperature;
        long watts;
        long ampSeconds;
        long wattHours;

        Battery (int _numPacks);
        void initialise();
        int print();

        void request_data();
        void read_message();
        void send_test_message();

        float get_soc();
        void recalculate_soc();
        
        // Voltage
        float get_voltage();
        void set_voltage(float voltage) { this->voltage = voltage; }
        void update_voltage();
        float get_max_voltage();
        float get_min_voltage();

        void update_cell_voltage(int packIndex, int moduleIndex, int cellIndex, float newCellVoltage);
        int get_index_of_high_pack();
        int get_index_of_low_pack();
        float get_lowest_cell_voltage();
        void update_lowest_cell_voltage();
        bool has_empty_cell();
        float get_highest_cell_voltage();
        void update_highest_cell_voltage();
        bool has_full_cell();
        float voltage_delta_between_packs();
        BatteryPack* get_pack_with_highest_voltage();
        bool packs_are_imbalanced();
        long get_amps();
        float get_highest_cell_temperature();

        // Temperature
        bool has_temperature_sensor_over_max();
        void update_max_charge_current();
        void update_max_discharge_current();
        float get_lowest_temperature();
        bool too_cold_to_charge();

        bool charge_enable_is_on();
        bool heater_enabled();
        void enable_heater();
        void disable_heater();
        void enable_inhibit_charge();
        void disable_inhibit_charge();
        float get_max_charge_current();
        float get_max_discharge_current();
        void enable_inhibit_drive();
        void disable_inhibit_drive();
        bool drive_is_inhibited();
        void disable_inhibit_for_drive();
        void disable_inhibit_for_charge();
        bool ignition_is_on();
        bool ignition_is_off();

        // Contactors
        void inhibit_contactor_close();
        bool one_or_more_contactors_inhibited();
        void close_contactors();
        void open_contactors();
};

#endif

