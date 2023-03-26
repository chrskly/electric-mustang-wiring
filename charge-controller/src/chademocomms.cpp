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

#include <stdio.h>
#include "pico/stdlib.h"

#include "mcp2515/mcp2515.h"
#include "settings.h"
#include "chademo.h"
#include "chademostation.h"
#include "car.h"

using namespace std;


/*
 * byte 4 + 5 : maximum battery voltage (V). 1 V/bit
 * byte 6     : Charging rate indication (%). 1% bit, 100%
 */
void chademo_send_100() {

    extern ChademoStation station;
    extern Car car;
    extern MCP2515 chademoCAN;

    struct can_frame frame;

    frame.can_id = 0x100;
    frame.can_dlc = 8;
    frame.data[0] = 0x00;
    frame.data[1] = 0x00;
    frame.data[2] = 0x00;
    frame.data[3] = 0x00;
    frame.data[4] = BATTERY_MAX_VOLTAGE & 0xFF;
    frame.data[5] = BATTERY_MAX_VOLTAGE >> 8;
    frame.data[6] = car.soc;
    frame.data[7] = 0x00;

    chademoCAN.sendMessage(&frame);

}



/*
 * Send charging time data to charging station.
 #
 * byte 1     : Maximum charging time permitted by EV (seconds). 10 s/bit (0 -> 2540s)
 * byte 2     : Maximum charging time permitted by EV (minutes). 1 min/bit (0 -> 255min)
 * byte 3     : Estimated charging time remaining.  1 min/bit (0 -> 254min)
 * byte 5 + 6 : capacity of battery (kWh). 0.11 kWh/bit
 */
void chademo_send_101() {

    extern ChademoStation station;
    extern Car car;
    extern MCP2515 chademoCAN;

    struct can_frame frame;

    frame.can_id = 0x101;
    frame.can_dlc = 8;
    frame.data[0] = 0x00; // unused
    frame.data[1] = 0xFF; // Don't declare max charge time in seconds
    frame.data[2] = car.calculate_max_charging_time_minutes(station.availableCurrent);
    frame.data[3] = car.calculate_charging_time_minutes(station.availableCurrent);
    frame.data[4] = 0x00; // unused
    frame.data[5] = car.batteryCapacity & 0xFF; // lsb
    frame.data[6] = car.batteryCapacity >> 8;  // msb
    frame.data[7] = 0x00; // unused

    chademoCAN.sendMessage(&frame);

}



/*
 * byte 0     : Control protocol number, (0 -> 255)
 * byte 1 + 2 : Target battery voltage. 1 V/bit (0 -> 600V)
 * byte 3     : Charging current request. 1 A/bit (0 -> 255A)
 * byte 4
 *   bit 0    : battery over voltage. 0:normal, 1:fault
 *   bit 1    : battery under voltage. 0:normal, 1:fault
 *   bit 2    : Battery current deviation error. 0:normal, 1:fault
 *   bit 3    : High battery temperature. 0:normal, 1:fault
 *   bit 4    : Battery voltage deviation error. 0:normal, 1:fault
 * byte 5
 *   bit 0    : Vehicle charging enabled. 0:disabled, 1:enabled
 *   bit 1    : Vehicle shift lever position. 0:Parking, 1:other
 *   bit 2    : Charging system fault. 0:normal, 1:fault
 *   bit 3    : Vehicle contactor status. 0:closed (or weld detect running), 1: open (or weld detect finished)
 *   bit 4    : Normal stop request before charging. 0:no request, 1:request to stop
 * byte 6     : Charging rate. 1 %/bit (0% -> 100%)
 */
void chademo_send_102() {
    struct can_frame frame;
    frame.can_id = 0x102;
    frame.can_dlc = 8;
    frame.data[0] = 1;    // protocol version 0.9
    frame.data[1] = 0x00; // target voltage lsb
    frame.data[2] = 0x00; // target voltage msb
    frame.data[3] = 0x00; // current request
    frame.data[4] = 0x00; // battery status
    frame.data[5] = 0x00; // vehicle status
    frame.data[6] = 0x00; // charging rate
    frame.data[7] = 0x00; // unused

}


struct repeating_timer outboundCANMessageTimer;

bool send_outbound_CAN_messages(struct repeating_timer *t) {
    chademo_send_100();
    chademo_send_101();
    chademo_send_102();
    return true;
}

void enable_send_outbound_CAN_messages() {
    add_repeating_timer_ms(100, send_outbound_CAN_messages, NULL, &outboundCANMessageTimer);
}



//// ----
//
// Handler for inbound messages on ChaDeMo CAN bus
//
//// ----

struct can_frame chademoInboundFrame;
struct repeating_timer handleChademoCANMessageTimer;

bool handle_chademo_CAN_messages(struct repeating_timer *t) {

    extern MCP2515 chademoCAN;
    //extern ChademoState chademoState;
    extern Chademo chademo;
    //extern ChademoStation station;

    if ( chademoCAN.readMessage(&chademoInboundFrame) == MCP2515::ERROR_OK ) {

        switch ( chademoInboundFrame.can_id ) {

            case EVSE_CAPABILITIES_MESSAGE_ID:
                chademo.station.weldDetectionSupported = chademoInboundFrame.data[0];
                // 1V/bit (0 to 600V)
                chademo.station.maximumVoltageAvailable = chademoInboundFrame.data[1] + chademoInboundFrame.data[2] << 8;
                // 1A/bit (0 to 255A)
                chademo.station.availableCurrent = chademoInboundFrame.data[3];
                // 1V/bit (0 to 600V)
                chademo.station.thresholdVoltage = chademoInboundFrame.data[4] + chademoInboundFrame.data[5] << 8;

                chademo.state(E_EVSE_CAPABILITIES_UPDATED);

            case EVSE_STATUS_MESSAGE_ID:
                chademo.station.controlProtocolNumber = chademoInboundFrame.data[0]; // chademo protocol version
                // 1V/bit (0 to 600V)
                chademo.station.outputVoltage = chademoInboundFrame.data[1] + chademoInboundFrame.data[2] << 8;
                // 1A/bit (0 to 255A)
                chademo.station.outputCurrent = chademoInboundFrame.data[3];
                // 10s/bit (0 to 2540s)
                chademo.station.timeRemainingSeconds = chademoInboundFrame.data[6];
                // 1min/bit (0 to 255min)
                chademo.station.timeRemainingMinutes = chademoInboundFrame.data[7];
                chademo.station.stationStatus = chademoInboundFrame.data[5] & 1;                             // bit 0
                chademo.station.stationMalfunction = (chademoInboundFrame.data[5] & ( 1 << 1 )) >> 1;        // bit 1
                chademo.station.vehicleConnectorLock = (chademoInboundFrame.data[5] & ( 1 << 2 )) >> 2;      // bit 2
                chademo.station.batteryIncompatability = (chademoInboundFrame.data[5] & ( 1 << 3 )) >> 3;    // bit 3
                chademo.station.chargingSystemMalfunction = (chademoInboundFrame.data[5] & ( 1 << 4 )) >> 4; // bit 4
                chademo.station.chargerStopControl = (chademoInboundFrame.data[5] & ( 1 << 5 )) >> 5;        // bit 5

                chademo.state(E_EVSE_STATUS_UPDATED);

            break;

        }
    }

    return true;
}

void enable_handle_chademo_CAN_messages() {
    add_repeating_timer_ms(10, handle_chademo_CAN_messages, NULL, &handleChademoCANMessageTimer);
}


