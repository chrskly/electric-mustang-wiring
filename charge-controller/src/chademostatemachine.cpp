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

#include "chademostatemachine.h"

using namespace std;

/*
 * State : DC-A
 *  - Vehicle unconnected
 */
void chademo_state_A(ChademoEvent event) {
    //
}

/*
 * State : DC-B1
 *  - Connector plugged in
 *  - Wake up of DCCCF and VCCF
 *  - Communicaton data initialisation
 *  - Communication established, parameters exchanged, and compatability checked
 *
 * Charging station sends:
 *  - Control protocol number
 *  - Available output voltage
 *  - Available output current
 *  - Battery incompatability
 *
 * Car sends:
 *  - Control protocol number
 *  - Rated capacity of battery
 *  - Maximum battery voltage
 *  - Maximum charging time
 *  - Target battery voltage
 *  - Vehicle charging enabled
 */
void chademo_state_B1(ChademoEvent event) {
    //
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



