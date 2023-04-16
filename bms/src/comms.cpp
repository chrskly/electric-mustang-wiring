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

extern MCP2515 mainCAN;
extern Battery battery;

// FIXME move somewhere else

struct repeating_timer statusPrintTimer;

bool status_print(struct repeating_timer *t) {
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

//struct can_frame pollModuleFrame;

struct repeating_timer pollModuleTimer;

// Send request to each pack to ask for a data update
bool poll_packs_for_data(struct repeating_timer *t) {
    battery.request_data();
    return true;
}

void enable_module_polling() {
    add_repeating_timer_ms(1000, poll_packs_for_data, NULL, &pollModuleTimer);
}


//// ----
//
// Outbound status messages
//
//// ----

/*
 * Send CAN messages to ISA shunt to tell it to reset. Resets the kw/ah
 * counters.
 */
void send_ISA_reset_message() {
    struct can_frame ISAResetFrame;
    ISAResetFrame.can_id = 0x411;
    ISAResetFrame.can_dlc = 8;
    ISAResetFrame.data[0] = 0x3F;
    ISAResetFrame.data[1] = 0x00;
    ISAResetFrame.data[2] = 0x00;
    ISAResetFrame.data[3] = 0x00;
    ISAResetFrame.data[4] = 0x00;
    ISAResetFrame.data[5] = 0x00;
    ISAResetFrame.data[6] = 0x00;
    ISAResetFrame.data[7] = 0x00;
    mainCAN.sendMessage(&ISAResetFrame);
}


/*
 * Limits message 0x351
 *
 * Follows the SimpBMS format.
 *
 * byte 0 = Charge voltage LSB, scale 0.1, unit V
 * byte 1 = Charge voltage MSB, scale 0.1, unit V
 * byte 2 = Charge current LSB, scale 0.1, unit A
 * byte 3 = Charge current MSB, scale 0.1, unit A
 * byte 4 = Discharge current LSB, scale 0.1, unit A
 * byte 5 = Discharge current MSB, scale 0.1, unit A
 * byte 6 = Discharge voltage LSB, scale 0.1, unit V
 * byte 7 = Discharge voltage MSB, scale 0.1, unit V
 */

struct can_frame limitsFrame;

struct repeating_timer limitsMessageTimer;

bool send_limits_message(struct repeating_timer *t) {

    limitsFrame.can_id = BMS_LIMITS_MSG_ID;
    limitsFrame.can_dlc = 8;

    limitsFrame.data[0] = ( (int)battery.get_max_voltage() && 0xFF ) * 10;
    limitsFrame.data[1] = ( (int)battery.get_max_voltage() >> 8 ) * 10;
    limitsFrame.data[2] = ( (int)battery.get_max_charge_current() && 0xFF ) * 10;
    limitsFrame.data[3] = ( (int)battery.get_max_charge_current() >> 8 ) * 10 ;
    limitsFrame.data[4] = ( (int)battery.get_max_discharge_current() && 0xFF ) * 10;
    limitsFrame.data[5] = ( (int)battery.get_max_discharge_current() >> 8 ) * 10;
    limitsFrame.data[6] = ( (int)battery.get_min_voltage() && 0xFF ) * 10;
    limitsFrame.data[7] = ( (int)battery.get_min_voltage() >> 8 ) * 10;

    mainCAN.sendMessage(&limitsFrame);

    return true;
}

void enable_limits_messages() {
    add_repeating_timer_ms(1000, send_limits_message, NULL, &limitsMessageTimer);
}

void disable_limits_messages() {
      //
}


/*
 * SoC message 0x355
 *
 * Follows the SimpBMS format.
 *
 * byte 0 = SoC LSB, scale 1, unit %
 * byte 1 = SoC MSB, scale 1, unit %
 * byte 2 = SoH LSB, scale 1, unit %
 * byte 3 = SoH MSB, scale 1, unit %
 * byte 4 = SoC LSB, scale 0.01, unit %
 * byte 5 = SoC MSB, scale 0.01, unit %
 * byte 6 = unused
 * byte 7 = unused
 */

struct can_frame socFrame;

struct repeating_timer socMessageTimer;

bool send_soc_message(struct repeating_timer *t) {

    socFrame.can_id = BMS_SOC_MSG_ID;
    socFrame.can_dlc = 8;

    socFrame.data[0] = battery.get_soc() && 0xFF;
    socFrame.data[1] = (int)battery.get_soc() >> 8;
    socFrame.data[2] = 0x00; // not implemented
    socFrame.data[3] = 0x00; // not implemented
    socFrame.data[4] = ( battery.get_soc() && 0xFF ) * 100;
    socFrame.data[5] = ( (int)battery.get_soc() >> 8 ) * 100;
    socFrame.data[6] = 0x00; // unused
    socFrame.data[7] = 0x00; // unused

    mainCAN.sendMessage(&socFrame);
    return true;
}

void enable_soc_messages() {
    add_repeating_timer_ms(1000, send_soc_message, NULL, &socMessageTimer);
}


/*
 * Status message 0x356
 *
 * Follows the SimpBMS format.
 *
 * byte 0 = Voltage LSB, scale 0.01, unit V
 * byte 1 = Voltage MSB, scale 0.01, unit V
 * byte 2 = Current LSB, scale 0.1, unit A
 * byte 3 = Current MSB, scale 0.1, unit A
 * byte 4 = Temperature LSB, scale 0.1, unit C
 * byte 5 = Temperature MSB, scale 0.1, unit C
 * byte 6 = unused
 * byte 7 = unused
 */

struct can_frame statusFrame;

struct repeating_timer statusMessageTimer;

bool send_status_message(struct repeating_timer *t) {

    statusFrame.can_id = BMS_STATUS_MSG_ID;
    statusFrame.can_dlc = 8;

    statusFrame.data[0] = battery.get_voltage() && 0xFF;
    statusFrame.data[1] = (int)battery.get_voltage() >> 8;
    statusFrame.data[2] = 0x00; // FIXME get from shunt
    statusFrame.data[3] = 0x00; // FIXME get from shunt
    statusFrame.data[4] = battery.get_highest_cell_temperature() && 0xFF;
    statusFrame.data[5] = (int)battery.get_highest_cell_temperature() >> 8;
    statusFrame.data[6] = 0x00; // unused
    statusFrame.data[7] = 0x00; // unused

    mainCAN.sendMessage(&statusFrame);
    return true;
}

void enable_status_messages() {
    add_repeating_timer_ms(1000, send_status_message, NULL, &statusMessageTimer);
}


/*
 * Alarms message 0x35A
 *
 * Follows the SimpBMS format. Note the docs disagree with the code. So,
 * following the code.
 *
 * First 4 bytes are alarms, second 4 bytes are warnings.
 *
 * byte 0
 *   bit 0
 *   bit 1
 *   bit 2 = high cell alarm
 *   bit 3
 *   bit 4 = low cell alarm
 *   bit 5
 *   bit 6 = high temp alarm
 *   bit 7
 * byte 1
 *   bit 0 = low temp alarm
 * byte 2
 * byte 3
 *   bit 0 = cell delta alarm
 * byte 4
 *   bit 0
 *   bit 1
 *   bit 2 = high cell warn
 *   bit 3
 *   bit 4 = low cell warn
 *   bit 5
 *   bit 6 = high temp warn
 * byte 5
 *   bit 0 = low temp warn
 * byte 6
 * byte 7
 */

struct can_frame alarmFrame;

struct repeating_timer alarmMessageTimer;

bool send_alarm_message(struct repeating_timer *t) {

    alarmFrame.can_id = BMS_ALARM_MSG_ID;
    alarmFrame.can_dlc = 3;

    alarmFrame.data[0] = 0x00;

    // Set undervolt bit (3)
    if ( battery.has_empty_cell() ) {
        alarmFrame.data[0] |= 0x04;
    }

    // Set overvolt bit (4)
    if ( battery.has_full_cell() ) {
        alarmFrame.data[0] |= 0x08;
    }

    alarmFrame.data[1] = 0x00;

    // Set over temp bit (7)
    if ( battery.has_temperature_sensor_over_max() ) {
        alarmFrame.data[1] |= 0x40;
    }

    alarmFrame.data[2] = 0x00;
    alarmFrame.data[3] = 0x00;
    alarmFrame.data[4] = 0x00;
    alarmFrame.data[5] = 0x00;
    alarmFrame.data[6] = 0x00;
    alarmFrame.data[7] = 0x00;

    mainCAN.sendMessage(&alarmFrame);
    return true;
}

void enable_alarm_messages() {
    add_repeating_timer_ms(1000, send_alarm_message, NULL, &alarmMessageTimer);
}





//// ----
//
// Inbound message handlers
//
//// ----


struct can_frame m;
struct repeating_timer handleMainCANMessageTimer;


bool handle_main_CAN_messages(struct repeating_timer *t) {

    if ( mainCAN.readMessage(&m) == MCP2515::ERROR_OK ) {

        switch ( m.can_id ) {

            // ISA shunt amps
            case 0x521:
                battery.amps = (long)( (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]) );
                break;

            // ISA shunt voltage 1
            case 0x522:
                battery.shuntVoltage1 = (long)( (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]) ) / 1000.0f;
                break;

            // ISA shunt voltage 2
            case 0x523:
                battery.shuntVoltage2 = (long)( (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]) ) / 1000.0f;
                break;

            // ISA shunt voltage 3
            case 0x524:
                battery.shuntVoltage3 = (long)( (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]) ) / 1000.0f;
                break;

            // ISA shunt temperature
            case 0x525:
                battery.shuntTemperature = (long)( (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]) ) / 10;
                break;

            // ISA shunt kilowatts
            case 0x526:
                battery.watts = (long)( (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]) ) / 1000.0f;
                break;

            // ISA shunt amp-hours
            case 0x527:
                battery.ampSeconds = (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]);
                break;

            // ISA shunt kilowatt-hours
            case 0x528:
                battery.wattHours = (long)( (m.data[5] << 24) | (m.data[4] << 16) | (m.data[3] << 8) | (m.data[2]) );
                break;

            default:
                break;

        }
    }

    return true;
}

void enable_handle_main_CAN_messages() {
    add_repeating_timer_ms(10, handle_main_CAN_messages, NULL, &handleMainCANMessageTimer);
}



struct repeating_timer handleBatteryCANMessagesTimer;

bool handle_battery_CAN_messages(struct repeating_timer *t) {
    battery.read_message();
    return true;
}

void enable_handle_battery_CAN_messages() {
    add_repeating_timer_ms(10, handle_battery_CAN_messages, NULL, &handleBatteryCANMessagesTimer);
}


// https://openinverter.org/wiki/CAN_table_CAN_STD