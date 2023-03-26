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

#include "chademostation.h"

using namespace std;

ChademoStation::ChademoStation() {}

/*
 * When kicking off the charging process, we initialise these variables to zero
 * to ensure we get fresh values from the charging station.
 */
void ChademoStation::reinitialise() {
    controlProtocolNumber = 0;
    maximumVoltageAvailable = 0;
    availableCurrent = 0;
}

/*
 * Have we received the initial params from the station?
 *
 * According to the spec the initial params we need to see from the station
 * before we can switch from B1->B2 are:
 *   - controlProtocolNumber
 *   - maximumVoltageAvailable
 *   - availableCurrent
 *   - batteryIncompatability
 */
bool ChademoStation::initial_parameter_exchange_complete() {
    return ( controlProtocolNumber != 0 && \
             maximumVoltageAvailable != 0 && \
             availableCurrent != 0 );
}
