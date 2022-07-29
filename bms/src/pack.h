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

class Battery;
class BatteryModule;

class BatteryPack {

    private:
        int packId;
        MCP2515* CAN;                                    // CAN bus connection to this pack
        absolute_time_t lastUpdate;                      // Time we received last update from BMS
        int numModules;                                  //
        int numCellsPerModule;                           //
        int numTemperatureSensorsPerModule;              //
        Battery* battery;                                // The parent Battery that contains this BatteryPack
        float voltage;                                   // Voltage of the total pack
        bool contactorsClosed;                           //
        int contactorPin;                                // Pin on the pico which controls contactors for this pack
        int balanceStatus;                               //
        int errorStatus;
        absolute_time_t nextBalanceTime;                 // Time that the next balance should occur.
        uint8_t msgcycle;                                //
        uint8_t nextmsg;                                 //
        uint8_t testCycle;                               //
        int pollMessageId;                               //
        bool initialised;
        BatteryModule* modules[];                         // The child modules that make up this BatteryPack        

    public:
        
        BatteryPack (int packId, int CANCSPin, int contactorPin, int numModules, int numCellsPerModule, int numTemperatureSensorsPerModule);
        void set_battery(Battery *battery) { this->battery = battery; }

        //int get_poll_message_id() { return this->pollMessageId; }
        //void set_poll_message_id(int pollMessageId) { this->pollMessageId = pollMessageId; }
        //void increment_poll_message_id() { ++this->pollMessageId; }

        //int get_test_cycle() { return this-> testCycle; }
        //void set_test_cycle(int testCycle) { this->testCycle = testCycle; }
        //void increment_test_cycle() { ++this->testCycle; }

        //int get_msg_cycle() { return this->msgcycle; }
        //void set_msg_cycle(int msgcycle) { this->msgcycle = msgcycle; }
        //void increment_msg_cycle() { ++this->msgcycle; }

        //void set_CAN_port(MCP2515 *port);

        void print();
        uint8_t getcheck(can_frame &msg, int id);
        void request_data();
        void read_message();

        bool pack_is_alive();

        void send_message(can_frame *frame) { (*this->CAN).sendMessage(frame); }

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
        bool has_cell_under_voltage();
        float get_highest_cell_voltage();
        bool has_cell_over_voltage();
        void update_cell_voltage(int moduleIndex, int cellIndex, float newCellVoltage);
        void decode_voltages(can_frame *rame);

        // Temperature
        bool has_temperature_sensor_over_max();
        int get_max_charging_current();
        float get_lowest_temperature();
        void decode_temperatures(can_frame *temperatureMessageFrame);

        // Contactors
        bool close_contactors();
        bool open_contactors();

};

#endif

