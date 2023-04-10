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

#include "hardware/gpio.h"

#include "chademo.h"
#include "car.h"
#include "chademostatemachine.h"
#include "settings.h"

extern Car car;


Chademo::Chademo() {
    state = &chademo_state_idle;
}

/*
 * Return true if plug is inserted in car.
 */
bool Chademo::plug_is_in() {
    return ( gpio_get(CHADEMO_CS_PIN) == 0 );
}

/*
 * Return true if IN1 signal is active (high)
 */
bool Chademo::in1_is_active() {
    return ( gpio_get(CHADEMO_IN1_PIN) == 1 );
}

/*
 * Return true if IN2 signal is active (low)
 */
bool Chademo::in2_is_active() {
    return ( gpio_get(CHADEMO_IN2_PIN) == 0 );
}

bool Chademo::battery_over_voltage() {
    //
    return false;
}

bool Chademo::battery_under_voltage() {
    //
    return false;
}

bool Chademo::battery_voltage_deviation_error() {
    //
    return false;
}

bool Chademo::battery_current_deviation_error() {
    //
    return false;
}

////----
//
// Handshaking checks
//
////----


bool Chademo::car_and_station_protocol_compatible() {
    return ( car.chademoControlProtocolNumber >= station.controlProtocolNumber );
}


bool Chademo::car_and_station_voltage_compatible() {
    return ( car.maximumBatteryVoltage < station.outputVoltage );
}




