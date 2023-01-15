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

#ifndef PACK_H
#define PACK_H

#include "hardware/timer.h"
#include "mcp2515/mcp2515.h"

#include "module.h"
//#include "battery.h"
#include "settings.h"
#include "CRC8.h"

class Battery;
class BatteryModule;

const uint8_t finalxor[12] = { 0xCF, 0xF5, 0xBB, 0x81, 0x27, 0x1D, 0x53, 0x69, 0x02, 0x38, 0x76, 0x4C };

class BatteryPack {

    public:

        int id;
        
        BatteryPack ();
        BatteryPack (int _id, int CANCSPin, int _contactorPin, int _numModules, int _numCellsPerModule, int _numTemperatureSensorsPerModule);

        void set_battery(Battery* battery) { this->battery = battery; }

        void print();
        uint8_t getcheck(can_frame &msg, int id);
        void request_data();
        void read_message();

        bool pack_is_alive();

        //void send_message(can_frame *frame) { (*this->CAN).sendMessage(frame); }
        void send_message(can_frame *frame);

        void set_pack_error_status(int newErrorStatus);
        int get_pack_error_status();
        void set_pack_balance_status(int newBalanceStatus);
        int get_pack_balance_status();
        bool pack_is_due_to_be_balanced();
        void reset_balance_timer();

        // Voltage
        float get_voltage();
        void update_voltage();
        float get_lowest_cell_voltage();
        void update_cell_delta();
        bool has_empty_cell();
        float get_highest_cell_voltage();
        bool has_full_cell();
        void update_cell_voltage(int moduleIndex, int cellIndex, float newCellVoltage);
        int get_index_of_high_pack();
        int get_index_of_low_pack();
        void decode_voltages(can_frame *frame);

        // Temperature
        bool has_temperature_sensor_over_max();
        int get_max_charging_current();
        float get_lowest_temperature();
        void decode_temperatures(can_frame *temperatureMessageFrame);

        void enable_inhibit_contactor_close();
        void disable_inhibit_contactor_close();
        bool contactors_are_inhibited();

        // Contactors
        bool close_contactors();
        bool open_contactors();

    private:

        MCP2515 CAN;                                     // CAN bus connection to this pack
        absolute_time_t lastUpdate;                      // Time we received last update from BMS
        int numModules;                                  //
        int numCellsPerModule;                           //
        int numTemperatureSensorsPerModule;              //
        Battery* battery;                                // The parent Battery that contains this BatteryPack
        float voltage;                                   // Voltage of the total pack
        float cellDelta;                                 // Difference in voltage between high and low cell
        bool contactorsClosed;                           //
        int contactorPin;                                // Pin on the pico which controls contactors for this pack
        int balanceStatus;                               //
        int errorStatus;
        absolute_time_t nextBalanceTime;                 // Time that the next balance should occur.
        uint8_t msgCycle;                                //
        uint8_t nextmsg;                                 //
        uint8_t testCycle;                               //
        uint8_t pollMessageId;                           //
        bool initialised;
        BatteryModule modules[MODULES_PER_PACK];         // The child modules that make up this BatteryPack        
        CRC8 crc8;

        bool inStartup;
        uint8_t modulePollingCycle;
        can_frame pollModuleFrame;

        bool contactorsAreInhibited;                     // Is the
        

};

#endif

