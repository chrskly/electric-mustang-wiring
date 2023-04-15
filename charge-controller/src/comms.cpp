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

using namespace std;

#include <stdio.h>
#include "pico/stdlib.h"

#include "mcp2515/mcp2515.h"
#include "settings.h"
#include "car.h"
#include "charger.h"

extern MCP2515 mainCAN;
extern Car car;
extern Charger charger;


struct can_frame mainCANInboundFrame;
struct repeating_timer handleMainCANMessageTimer;

/*
 * Process inbound messages on the main CANbus
 */
bool handle_main_CAN_message(struct repeating_timer *t) {

    if ( mainCAN.readMessage(&mainCANInboundFrame) == MCP2515::ERROR_OK ) {

        switch ( mainCANInboundFrame.can_id ) {

            case BMS_LIMITS_MESSAGE_ID:
                car.maximumBatteryVoltage = mainCANInboundFrame.data[0] | mainCANInboundFrame.data[1] << 8;
                car.maximumChargeCurrent = mainCANInboundFrame.data[2] | mainCANInboundFrame.data[3] << 8;
                car.maximumDischargeCurrent = mainCANInboundFrame.data[4] | mainCANInboundFrame.data[5] << 8;
                car.minimumBatteryVoltage = mainCANInboundFrame.data[6] | mainCANInboundFrame.data[7] << 8;
                charger.bms_heartbeat();
                break;

            case BMS_SOC_MESSAGE_ID:
                car.soc = mainCANInboundFrame.data[0] | mainCANInboundFrame.data[1] << 8;
                break;

            case BMS_STATUS_MESSAGE_ID:            
                car.batteryVoltage = mainCANInboundFrame.data[0] | mainCANInboundFrame.data[1] << 8;
                car.batteryCurrent = mainCANInboundFrame.data[2] | mainCANInboundFrame.data[3] << 8;
                car.batteryTemperature = mainCANInboundFrame.data[4] | mainCANInboundFrame.data[5] << 8;
                charger.bms_heartbeat();
                break;

            case BMS_ALARM_MESSAGE_ID:
                car.highCellAlarm = (mainCANInboundFrame.data[0] & ( 1 << 2 )) >> 2;
                car.lowCellAlarm = (mainCANInboundFrame.data[0] & ( 1 << 4 )) >> 4;
                car.highTempAlarm = (mainCANInboundFrame.data[0] & ( 1 << 6 )) >> 6;
                car.lowTempAlarm = mainCANInboundFrame.data[1];
                car.cellDeltaAlarm = mainCANInboundFrame.data[3];
                car.highCellWarn = (mainCANInboundFrame.data[4] & ( 1 << 2 )) >> 2;
                car.lowCellWarn = (mainCANInboundFrame.data[4] & ( 1 << 4 )) >> 4;
                car.highTempWarn = (mainCANInboundFrame.data[4] & ( 1 << 6 )) >> 6;
                car.lowTempWarn = mainCANInboundFrame.data[5];
                charger.bms_heartbeat();
                break;

            default:
                break;

        }
    }

    return true;
}

void enable_handle_main_CAN_messages() {
    add_repeating_timer_ms(10, handle_main_CAN_message, NULL, &handleMainCANMessageTimer);
}

