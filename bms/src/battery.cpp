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

#include "battery.h"
#include "pack.h"

#include "settings.h"


using namespace std;

Battery::Battery (int _numPacks) {

    voltage = 0;
    lowestCellVoltage = 0;
    highestCellVoltage = 0;
    lowestCellTemperature = 0;
    highestCellTemperature = 0;
    numPacks = _numPacks;

}

void Battery::initialise () {
    printf("Initialising battery with %d packs\n", numPacks);
    for ( int p = 0; p < numPacks; p++ ) {
        printf("Initialising battery pack %d (cs:%d, cp:%d, mpp:%d, cpm:%d, tpm:%d)\n", p, CS_PINS[p], CONTACTOR_PINS[p], MODULES_PER_PACK, CELLS_PER_MODULE, TEMPS_PER_MODULE);
        packs[p] = BatteryPack(p, CS_PINS[p], CONTACTOR_PINS[p], MODULES_PER_PACK, CELLS_PER_MODULE, TEMPS_PER_MODULE);
        printf("Initialisation of battery pack %d complete\n", p);
        packs[p].set_battery(this);
    }   
}

int Battery::print () {
    for ( int p = 0; p < numPacks; p++ ) {
        packs[p].print();
    }
    return 0;
}

void Battery::request_data() {
    for ( int p = 0; p < numPacks; p++ ) {
        packs[p].request_data();
    }
}

void Battery::read_message() {
    for ( int p = 0; p < numPacks; p++ ) {
        packs[p].read_message();
    }
}

void Battery::send_test_message() {
    for ( int p = 0; p < numPacks; p++ ) {
        printf("Sending test message to pack %d\n", p);
        can_frame fr;
        fr.can_id = 0x000;
        fr.can_dlc = 3;
        fr.data[0] = 0x7E;
        fr.data[1] = 0x57;
        fr.data[2] = p;
        packs[p].send_message(&fr);
    }
}


//// ----
//
// Voltage
//
//// ----

// Return the voltage of the whole battery
float Battery::get_voltage() {
    return voltage;
}

// Recompute and store the battery voltage based on current cell voltages
void Battery::update_voltage() {
    float newVoltage = 0;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].get_voltage() > newVoltage ) {
            newVoltage = packs[p].get_voltage();
        }
    }
    voltage = newVoltage;
}

// Update the value we have stored for an individual cell in the pack
void Battery::update_cell_voltage(int packIndex, int moduleIndex, int cellIndex, float newCellVoltage) {
    packs[packIndex].update_cell_voltage(moduleIndex, cellIndex, newCellVoltage);
}

// Low cells

// Return the voltage of the lowest cell in the battery
float Battery::get_lowest_cell_voltage() {
    return lowestCellVoltage;
}

// Recompute the lowest cell voltage
void Battery::update_lowest_cell_voltage() {
    float newLowestCellVoltage = 1000;
    for ( int p = 1; p < numPacks; p++ ) {
        if ( packs[p].get_lowest_cell_voltage() < newLowestCellVoltage ) {
            newLowestCellVoltage = packs[p].get_lowest_cell_voltage();
        }
    }
    lowestCellVoltage = newLowestCellVoltage;
}

// Return true if any cell in the battery is below the minimum voltage level
bool Battery::has_cell_under_voltage() {
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].has_cell_under_voltage() ) {
            return true;
        }
    }
    return false;
}

// High cells

// Return the voltage of the highest cell in the battery
float Battery::get_highest_cell_voltage() {
    return highestCellVoltage;
}

// Recompute the highest cell voltage
void Battery::update_highest_cell_voltage() {
    float newHighestCellVoltage = 0;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].get_highest_cell_voltage() < newHighestCellVoltage ) {
            newHighestCellVoltage = packs[p].get_highest_cell_voltage();
        }
    }
    highestCellVoltage = newHighestCellVoltage;
}

// Return true if any cell in the battery is below the minimum voltage level
bool Battery::has_cell_over_voltage() {
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].has_cell_over_voltage() ) {
            return true;
        }
    }
    return false;
}

// Return the largest voltage difference between any two packs in this battery.
float Battery::voltage_delta_between_packs() {
    float highestPackVoltage = -10000;
    float lowestPackVoltage = 10000;
    for ( int p = 0; p < numPacks; p++ ) {
        float packVoltage = packs[p].get_voltage();
        if ( packVoltage > highestPackVoltage ) {
            highestPackVoltage = packVoltage;
        }
        if ( packVoltage < lowestPackVoltage ) {
            lowestPackVoltage = packVoltage;
        }
    }
    return highestPackVoltage - lowestPackVoltage;
}

// return the battery pack which has the highest voltage
BatteryPack* Battery::get_pack_with_highest_voltage() {
    BatteryPack* pack = &packs[0];
    for ( int p = 1; p < numPacks; p++ ) {
        if ( packs[p].get_voltage() > pack->get_voltage() ) {
            pack = &packs[p];
        }
    }
    return pack;
}


//// ----
//
// Temperature
//
//// ----

// Return true if any sensor in the pack is over the max temperature
bool Battery::has_temperature_sensor_over_max() {
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].has_temperature_sensor_over_max() ){
            return true;
        }
    }
    return false;
}

int Battery::get_max_charging_current() {
    int maxChargeCurrent = CHARGE_CURRENT_MAX;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].get_max_charging_current() < maxChargeCurrent ) {
            maxChargeCurrent = packs[p].get_max_charging_current();
        }
    }
    return maxChargeCurrent;
}

float Battery::get_lowest_temperature() {
    float lowestTemperature = 1000;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].get_lowest_temperature() < lowestTemperature ) {
            lowestTemperature = packs[p].get_lowest_temperature();
        }
    }
    return lowestTemperature;
}

bool Battery::too_cold_to_charge() {
    if ( get_lowest_temperature() < CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD ) {
        return true;
    }
    return false;
}




//// ----
//
// Contactor control
//
//// ----

void Battery::close_contactors() {

    // Check that the voltage difference between the packs in the battery is
    // a small, safe value.
    if ( voltage_delta_between_packs() < SAFE_VOLTAGE_DELTA_BETWEEN_PACKS ) {
        for ( int p = 0; p < numPacks; p++ ) {
            packs[p].close_contactors();
        }
    }

    // The pack voltages differ too much. We can only use one pack. Figure out
    // which pack is fuller (has higher voltage) and close the contactors for
    // just that pack.
    else {
        get_pack_with_highest_voltage()->close_contactors();
    }

}

void Battery::open_contactors() {
    // wait?
    for ( int p = 0; p < numPacks; p++ ) {
        packs[p].open_contactors();
    }
}
