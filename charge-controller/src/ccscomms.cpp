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


struct can_frame cssCANInbound;
struct repeating_timer handleCssCANMessageTimer;

bool handle_css_CAN_messages(struct repeating_timer *t) {

    extern MCP2515 cssCAN;

    if ( cssCAN.readMessage(&cssCANInbound) == MCP2515::ERROR_OK ) {
        switch ( cssCANInbound.can_id ) {
            case EVSE_CAPABILITIES_MESSAGE_ID:
                //
            break;
        }
    }

    return true;
}

void enable_handle_ccs_CAN_messages() {
    add_repeating_timer_ms(10, handle_css_CAN_messages, NULL, &handleCssCANMessageTimer);
}