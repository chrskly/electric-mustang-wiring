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

#include "chademostatemachine.h"

#include "chademocomms.h"
#include "chademo.h"

using namespace std;

extern Chademo chademo;
extern ChademoState state;
extern ChademoStation station;

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
            if ( chademo.in1_is_active() ) {
                chademo.station.reinitialise();
                // being sending messages needed for handshaking
                enable_send_outbound_CAN_messages();
                chademo.state = chademo_state_handshaking;
                break;
            }

        case E_IN1_ACTIVATED:
            if ( chademo.plug_is_in() ) {
                chademo.station.reinitialise();
                // being sending messages needed for handshaking
                enable_send_outbound_CAN_messages();
                chademo.state = chademo_state_handshaking;
                break;
            }

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

    extern ChademoStation station;
    extern ChademoState state;

    switch (event) {

        case E_EVSE_CAPABILITIES_UPDATED:
            if ( station.initial_parameter_exchange_complete() ) {
                state = chademo_state_charge_prep;
            }
            break;

        case E_EVSE_INCOMPATIBLE:
            state = chademo_state_error;

        case E_EVSE_STATUS_UPDATED:
            if ( station.initial_parameter_exchange_complete() ) {
                state = chademo_state_charge_prep;
            }
            break;

        case E_PLUG_REMOVED:
            state = chademo_state_idle;
            break;

        default:
            printf("WARNING : received invalid event\n");
    }
}



/*
 * State : charge_prep
 *
 */
void chademo_state_charge_prep(ChademoEvent event) {

    switch (event) {
        case E_PLUG_REMOVED:
            break;
    }
}



/*
 * State : error
 *
 */
void chademo_state_error(ChademoEvent event) {
    switch (event) {
        case E_PLUG_REMOVED:
            state = chademo_state_idle;
    }
}





/*
 * State : DC-B1
 *  - Connector plugged in
 *  - Wake up of DCCCF and VCCF
 *  - Communicaton data initialisation
 *  - Communication established, parameters exchanged, and compatability checked
 *

 *
 * Transitions
 *  - ...
 */
void chademo_state_B1(ChademoEvent event) {

    switch (event) {

        case E_EVSE_CAPABILITIES_UPDATED:
            chademo.station.initial_parameter_exchange_complete();
            break;

        case E_EVSE_STATUS_UPDATED:
            break;

        default:
            printf("Received unknown event");

    }
}

/*
 * State : DC-B2
 *  - Connector locked
 *
 * Charging station sends:
 *  - Vehicle connector lock
 */
void chademo_state_B2(ChademoEvent event) {
    //
}

/*
 * State : DC-B3
 *  - Insulation test for d.c. power line
 *  - pre-charge
 *
 * Charging station sends:
 *  - Charging system malfunction
 */
void chademo_state_B3(ChademoEvent event) {
    //
}

/*
 * State : DC-C
 *  - Vehicle side contactors closed
 *  - Charging by current demand (for CCC)
 *  - Current suppression
 *
 * Charging station sends:
 *  - Station status
 *  - Output voltage
 *  - Output current
 *  - Remaining charging time
 *  - Station malfunction
 *  - Charging system malfunction
 *  - Charging stop control
 *
 * Car sends:
 *  - Charging current request
 *  - Charging system fault
 *  - Vehicle shift lever position
 *  - Vehicle charging enabled
 */
void chademo_state_C(ChademoEvent event) {
    //
}

/*
 * State : DC-D
 *  - Vehicle side contactors closed
 *  - Charging by current demand (for CVC)
 *  - Current suppression
 *
 * Charging station sends:
 *  - Station status
 *  - Output voltage
 *  - Output current
 *  - Remaining charging time
 *  - Station malfunction
 *  - Charging system malfunction
 *  - Charging stop control
 *
 * Car sends:
 *  - Charging current request
 *  - Charging system fault
 *  - Vehicle shift lever position
 *  - Vehicle charging enabled
 */
void chademo_state_D(ChademoEvent event) {
    //
}

/*
 * State : Bprime1
 *  - Zero current confirmed
 *  - Current suppression
 *  - Welding detection (vehicle)
 *
 * Charging station sends:
 *  - Station status
 *  - Charging system malfunction
 *  - Charging stop control
 *  - Output voltage
 *  - Output current
 *  - Charging syste mmalfunction
 *
 * Car sends:
 *  - Vehicle charging enabled
 */
void chademo_state_Bprime1(ChademoEvent event) {
    //
}

/*
 * State : Bprime2
 *  - Welding detection (vehicle)
 *  - Vehicle side contactors open
 *  - DC power line voltage verification
 *
 * Charging station sends:
 *  - Output voltage
 */
void chademo_state_Bprime2(ChademoEvent event) {
    //
}

/*
 * State : Bprime3
 *  - Connector unlocked
 *
 * Charging station sends:
 *  - Vehicle connector lock
 */
void chademo_state_Bprime3(ChademoEvent event) {
    //
}

/*
 * State : Bprime4
 *  - End of charge at communication level
 */
void chademo_event_Bprime4(ChademoEvent event) {
    //
}



