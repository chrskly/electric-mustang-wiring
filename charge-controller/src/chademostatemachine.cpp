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

#include "chademostatemachine.h"
#include "chademocomms.h"
#include "charger.h"


extern Charger charger;

/*
 * State : idle
 *  - plug out
 *
 * Transitions:
 *  => handshaking
 *     - plug must be inserted
 *     - IN1 must be active (high)
 */
void chademo_state_idle(ChademoEvent event) {

    switch (event) {

        case E_PLUG_INSERTED:
            charger.chademo.state = chademo_state_handshaking;
            break;

        default:
            printf("WARNING : received invalid event\n");

    }
}

/*
 * Wait for go-ahead from station
 */
void chademo_plug_in(ChademoEvent event) {

    switch (event) {

        case E_IN1_ACTIVATED:
            charger.chademo.station.reinitialise();
            // begin sending messages needed for handshaking
            enable_send_outbound_CAN_messages();            
            charger.chademo.state = chademo_state_handshaking;
            break;

        default:
            printf("WARNING : received invalid event\n");

    }
}

/*
 * State : handshaking
 *  - exchanging params with evse
 *
 * Charging station sends:
 *  - Control protocol number (0x109)
 *  - Available output voltage (0x108)
 *  - Available output current (0x108)
 *  - Battery incompatability (0x109)
 *
 * Car sends:
 *  - Control protocol number (0x102)
 *  - Rated capacity of battery (0x101)
 *  - Maximum battery voltage (0x100)
 *  - Maximum charging time (0x101)
 *  - Target battery voltage (0x102)
 *  - Vehicle charging enabled (0x102)
 *
 * Transitions:
 *  => idle
 *     - plug removed
 */
void chademo_state_handshaking(ChademoEvent event) {

    switch (event) {

        case E_EVSE_CAPABILITIES_UPDATED:

            // Can the charger provide us with enough voltage?
            if ( ! charger.chademo.car_and_station_voltage_compatible() ) {
                printf("ERROR : Insufficient voltage available at station. Stopping\n");
                // FIXME what to do here?
            }

            // If we have received all of the params we need from the station, move to the next step
            if ( charger.chademo.station.initial_parameter_exchange_complete() ) {
                // Activate OUT1/CP3 to indicate to station that we can proceed
                charger.chademo.activate_out1();
                charger.chademo.state = chademo_await_connector_lock;
            }

            break;

        case E_EVSE_STATUS_UPDATED:

            // Check for control protocol compatibility
            if ( ! charger.chademo.car_and_station_protocol_compatible() ) {
                printf("ERROR : chademo protocol version mismatch. Stopping\n");
                // FIXME what to do here?
            }

            // Fail out if the charging station has reported a malfunction
            if ( charger.chademo.station.is_reporting_malfunction() ) {
                printf("ERROR : station reports malfunction. Stopping\n");
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a battery incompatability
            if ( charger.chademo.station.is_reporting_battery_incompatibility() ) {
                printf("ERROR : station reports battery incompatible. Stopping\n");
                charger.chademo.state = chademo_state_error;
            }

            // Check for station malfunction
            if ( charger.chademo.station.charging_system_malfunction() ) {
                printf("ERROR : station reports malfunction. Stopping\n");
                // FIXME what do do here?
            }

            if ( charger.chademo.station.initial_parameter_exchange_complete() ) {
                // Activate OUT1/CP3 to indicate to station that we can proceed
                charger.chademo.activate_out1();
                charger.chademo.state = chademo_await_connector_lock;
            }
            break;

        case E_EVSE_INCOMPATIBLE:
            charger.chademo.state = chademo_state_error;

        case E_PLUG_REMOVED:
            charger.chademo.state = chademo_state_idle;
            break;

        default:
            printf("WARNING : received invalid event\n");
    }
}

/*
 * State : await_lock
 */
void chademo_await_connector_lock(ChademoEvent event) {

    switch (event) {

        case E_EVSE_CAPABILITIES_UPDATED:
            break;

        case E_EVSE_STATUS_UPDATED:
            // check if lock is complete
            if ( charger.chademo.station.connector_is_locked() ) {
                charger.chademo.state = chademo_await_insulation_test;
            }
            break;

        case E_PLUG_REMOVED:
            charger.chademo.state = chademo_state_idle;
            break;

        default:
            printf("WARNING : received invalid event\n");

    }
}



/*
 * State : chademo_await_insulation_test
 *
 */
void chademo_await_insulation_test(ChademoEvent event) {

    switch (event) {

        case E_PLUG_REMOVED:
            break;

        default:
            printf("WARNING : received invalid event\n");

    }
}

/*
 * State : energy_transfer
 */
void chademo_energy_transfer(ChademoEvent event) {

    switch (event) {

        case E_PLUG_REMOVED:
            break;

        default:
            printf("WARNING : received invalid event\n");

    }

}


/*
 * State : error
 *
 */
void chademo_state_error(ChademoEvent event) {
    switch (event) {
        // Only way out of error is to remove the plug and start over
        case E_PLUG_REMOVED:
            charger.chademo.state = chademo_state_idle;
    }
}





