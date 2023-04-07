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

#include <stdio.h>
#include "pico/stdlib.h"

#include <stdexcept>

#include "settings.h"
#include "comms.h"
#include "statemachine.h"
#include "battery.h"
#include "pack.h"

using namespace std;


// FIXME move somewhere else

struct repeating_timer statusPrintTimer;

bool status_print(struct repeating_timer *t) {
    extern Battery battery;
    battery.print();
    return true;
}

void enable_status_print() {
    add_repeating_timer_ms(5000, status_print, NULL, &statusPrintTimer);
}


//// ----
//
// Polling the modules for voltage and temperature readings
//
//// ----

struct can_frame pollModuleFrame;

struct repeating_timer pollModuleTimer;

// Send request to each pack to ask for a data update
bool poll_packs_for_data(struct repeating_timer *t) {
    extern Battery battery;
    battery.request_data();
    return true;
}

void enable_module_polling() {
    add_repeating_timer_ms(1000, poll_packs_for_data, NULL, &pollModuleTimer);
}


//// ----
//
// status messages
//
//// ----

// CAN frame to hold status message sent out to rest of car
// bit 0-4 = state (0=standby, 1=drive, 2=charging, 3=overTempFault, 4=underVoltageFault ) 
struct can_frame statusFrame;

struct repeating_timer statusMessageTimer;

// https://openinverter.org/wiki/CAN_table_CAN_STD

bool send_status_message(struct repeating_timer *t) {

    extern State state;
    extern MCP2515 mainCAN;

    statusFrame.can_id = STATUS_MSG_ID;
    statusFrame.can_dlc = 8;

    statusFrame.data[0] = 50; // FIXME soc

    if ( state == state_standby ) {
        statusFrame.data[1] = 0x00 << 4;
    } else if ( state == state_drive ) {
        statusFrame.data[1] = 0x01 << 4;
    } else if ( state == state_charging ) {
        statusFrame.data[1] = 0x02 << 4;
    } else if ( state == state_batteryEmpty ) {
        statusFrame.data[1] = 0x03 << 4;
    } else if ( state == state_fault ) {
        statusFrame.data[1] = 0x04 << 4;
    } else {
        //
    }
    // do pack dead check

    mainCAN.sendMessage(&statusFrame);
    return true;
}

void enable_status_messages() {
    add_repeating_timer_ms(1000, send_status_message, NULL, &statusMessageTimer);
}


//// ----
// 
// send charge limits message (id = 0x102)
//
//// ----

// CAN frame to hold charge limits message
// byte 0 = 0x0
// byte 1 = DC voltage limit MSB
// byte 2 = DC voltage limit LSB
// byte 3 = DC current set point
// byte 4 = 1 == enable charging
// byte 5 = SoC
// byte 6 = 0x0
// byte 7 = 0x0
// From https://openinverter.org/wiki/Tesla_Model_S/X_GEN2_Charger
struct can_frame chargeLimitsFrame;

struct repeating_timer chargeLimitsMessageTimer;

bool send_charge_limits_message(struct repeating_timer *t) {

    extern Battery battery;

    chargeLimitsFrame.can_id = 0x102;
    chargeLimitsFrame.can_dlc = 8;

    // byte 0
    chargeLimitsFrame.data[0] = 0x0;
    // byte 1 -- DC voltage limit MSB
    chargeLimitsFrame.data[1] = 0x0; //fixme
    // byte 2 -- DC voltage limit LSB
    chargeLimitsFrame.data[2] = 0x0; //fixme
    // byte 3 -- DC current set point
    chargeLimitsFrame.data[3] = (__u8)battery.get_max_charging_current();
    // byte 4 -- 1 == enable charging
    chargeLimitsFrame.data[4] = 0x0; //fixme
    // byte 5 -- SoC
    chargeLimitsFrame.data[5] = 0x0; //fixme
    // byte 6 -- 0x0
    chargeLimitsFrame.data[6] = 0x0;
    // byte 7 -- 0x0
    chargeLimitsFrame.data[7] = 0x0;

    return true;
}

void enable_charge_limits_messages() {
    add_repeating_timer_ms(1000, send_charge_limits_message, NULL, &chargeLimitsMessageTimer);
}

void disable_charge_limits_messages() {
      //
}


//// ----
//
// Inbound message handlers
//
//// ----

struct can_frame mainCANInbound;
struct repeating_timer handleMainCANMessageTimer;

bool handle_main_CAN_messages(struct repeating_timer *t) {

    extern MCP2515 mainCAN;

    if ( mainCAN.readMessage(&mainCANInbound) == MCP2515::ERROR_OK ) {
        if ( mainCANInbound.can_id == CAN_ID_ISA_SHUNT_WH ) {
            // process Wh data
        } else if ( mainCANInbound.can_id == CAN_ID_ISA_SHUNT_AH ) {
            // process Ah data
        }
    }

    return true;
}

void enable_handle_main_CAN_messages() {
    add_repeating_timer_ms(10, handle_main_CAN_messages, NULL, &handleMainCANMessageTimer);
}



struct repeating_timer handleBatteryCANMessagesTimer;

bool handle_battery_CAN_messages(struct repeating_timer *t) {
    extern Battery battery;
    battery.read_message();
    return true;
}

void enable_handle_battery_CAN_messages() {
    add_repeating_timer_ms(10, handle_battery_CAN_messages, NULL, &handleBatteryCANMessagesTimer);
}

