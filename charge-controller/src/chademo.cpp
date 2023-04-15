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
#include <algorithm>

#include "hardware/gpio.h"

#include "chademo.h"
#include "charger.h"
#include "car.h"
#include "chademostatemachine.h"
#include "settings.h"

extern Car car;
extern Charger charger;


Chademo::Chademo() {
    state = &chademo_state_idle;
    reinitialise();
}

void Chademo::reinitialise() {
    // Start at zero. We only recalculate this during energy transfer.
    chargingCurrentRequest = 0;

    targetBatteryVoltage = car.get_voltage_from_soc(BATTERY_FAST_CHARGE_DEFAULT_SOC_MAX);
}

/*
 * Calculate a new value for the charge current (chargingCurrentRequest) that we
 * are asking the station to provide us with. Factor in the limits the BMS is
 * requiring, the maximum current the station can provide right now, and the
 * maximum rate at which the the current request may change (ramp rate).
 */
void Chademo::recalculate_charging_current_request() {

    // Our new max current target will be whichever is less between what the BMS
    // allows or what the station can provide.
    uint8_t chargingCurrentCeiling = min(car.targetChargingCurrent, station.availableCurrent);

    // No change required. Hold at the current level.
    if ( chargingCurrentRequest == chargingCurrentCeiling ) {
        return;
    }

    clock_t now = get_clock();

    // We need to ramp up the current request
    if ( chargingCurrentRequest < chargingCurrentCeiling ) {

        // Enough time has passed that we can bump up the current request
        if ( lastCurrentRequestChange > ( now + CHADEMO_RAMP_INTERVAL ) ) {
            // Next step would be more than max, so just increment by max
            if ( ( chargingCurrentCeiling - chargingCurrentRequest ) > CHADEMO_RAMP_RATE ) {
                chargingCurrentRequest += CHADEMO_RAMP_RATE;
                lastCurrentRequestChange = now;
                return;
            }
            // Next step is less than max, so go directly
            else {
                chargingCurrentRequest = chargingCurrentCeiling;
                lastCurrentRequestChange = now;
                return;
            }
        }

        // Need to wait longer before we can bump up further
        else {
            return;
        }
    }

    // We need to ramp down the current requests
    else if ( chargingCurrentRequest > chargingCurrentCeiling ) {

        // Enough time has passed that we can reduce the current request
        if ( lastCurrentRequestChange > ( now + CHADEMO_RAMP_INTERVAL ) ) {
            // Next step would be more than max, so just decrement by max
            if ( ( chargingCurrentRequest - chargingCurrentCeiling ) > CHADEMO_RAMP_RATE ) {
                chargingCurrentRequest -= CHADEMO_RAMP_RATE;
                lastCurrentRequestChange = now;
                return;
            }
            // Next step is less than max, so go directly
            else {
                chargingCurrentRequest = chargingCurrentCeiling;
                lastCurrentRequestChange = now;
                return;
            }
        }

        // Need to wait longer before we can reduce further
        else {
            return;
        }
    }

}

uint8_t Chademo::get_charging_current_request() {
    return chargingCurrentRequest;
}


/*
 * Generate byte 4 (battery status) sent in the car status message.
 *
 * bit 0 : battery over voltage. 0:normal, 1:fault
 * bit 1 : battery under voltage. 0:normal, 1:fault
 * bit 2 : Battery current deviation error. 0:normal, 1:fault
 * bit 3 : High battery temperature. 0:normal, 1:fault
 * bit 4 : Battery voltage deviation error. 0:normal, 1:fault
 *
 * FIXME : current deviation error
 * 
 */
uint8_t Chademo::generate_battery_status_byte() {
    return ( 0x00 | car.highCellAlarm | car.lowCellAlarm << 1 | car.highTempAlarm << 3 | car.cellDeltaAlarm << 4 );
}

/*
 * Generate byte 5 (vehicle status) sent in the car status message.
 *
 * bit 0 : Vehicle charging enabled. 0:disabled, 1:enabled
 * bit 1 : Vehicle shift lever position. 0:Parking, 1:other
 * bit 2 : Charging system fault. 0:normal, 1:fault
 * bit 3 : Vehicle contactor status. 0:closed (or weld detect running), 1: open (or weld detect finished)
 * bit 4 : Normal stop request before charging. 0:no request, 1:request to stop
 *
 * FIXME : vehicle charging enabled flag
 * FIXME : charging system fault
 * FIXME : stop request
 *
 */
uint8_t Chademo::generate_vehicle_status_byte() {
    return ( 0x00 | contactors_are_closed() << 3 );
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

bool Chademo::contactors_are_closed() {
    return ( in1_is_active() && in2_is_active() );
}

// OUT1 (CP3)

void Chademo::activate_out1() {
    gpio_put(CHADEMO_OUT1_PIN, 1);
}

void Chademo::deactivate_out1() {
    gpio_put(CHADEMO_OUT1_PIN, 0);
}

// OUT2 (contactor relay)

void Chademo::activate_out2() {
    gpio_put(CHADEMO_OUT2_PIN, 1);
}

void Chademo::deactivate_out2() {
    gpio_put(CHADEMO_OUT2_PIN, 0);
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

// capabilities

bool Chademo::car_and_station_voltage_compatible() {
    return ( car.maximumBatteryVoltage < station.maximumVoltageAvailable );
}

// status

bool Chademo::car_and_station_protocol_compatible() {
    return ( CHADEMO_PROTOCOL_VERSION >= station.controlProtocolNumber );
}

bool Chademo::station_malfunction() {
    return ( station.stationMalfunction );
}

bool Chademo::battery_incompatible() {
    return ( station.batteryIncompatability );
}



