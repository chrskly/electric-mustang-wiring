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
#include <string>

#include "battery.h"
#include "pack.h"
#include "statemachine.h"

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
        printf("Initialising battery pack %d (cs:%d, cp:%d, mpp:%d, cpm:%d, tpm:%d)\n", p, CS_PINS[p], INHIBIT_CONTACTOR_PINS[p], MODULES_PER_PACK, CELLS_PER_MODULE, TEMPS_PER_MODULE);
        packs[p] = BatteryPack(p, CS_PINS[p], INHIBIT_CONTACTOR_PINS[p], MODULES_PER_PACK, CELLS_PER_MODULE, TEMPS_PER_MODULE);
        printf("Initialisation of battery pack %d complete\n", p);
        packs[p].set_battery(this);
    }

    // Set up DRIVE_INHIBIT output
    gpio_init(DRIVE_INHIBIT_PIN);
    gpio_set_dir(DRIVE_INHIBIT_PIN, GPIO_OUT);
    disable_inhibit_drive();

    // Set up heater control
    gpio_init(HEATER_ENABLE_PIN);
    gpio_set_dir(HEATER_ENABLE_PIN, GPIO_OUT);
    disable_heater();

    // Set up CHARGE_INHIBIT ouput
    gpio_init(CHARGE_INHIBIT_PIN);
    gpio_set_dir(CHARGE_INHIBIT_PIN, GPIO_OUT);
    disable_inhibit_charge();

}

int Battery::print () {
    extern State state;
    printf("--------------------------------------------------------------------------------\n");
    printf("BMS status : %s\n", state);
    for ( int p = 0; p < numPacks; p++ ) {
        packs[p].print();
    }
    printf("--------------------------------------------------------------------------------\n");
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
        //printf("Sending test message to pack %d\n", p);
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
// SoC
//
//// ----

float Battery::get_soc() {
    return soc;
}

/*
 * Recalculate the SoC based on the latest data from the ISA shunt.
 *
 * 0 khw/ah == 100% charged. Value goes negative as we draw energy from the pack.
 *
 */
void Battery::recalculate_soc() {
    if ( CALCULATE_SOC_FROM == 0 ) {
        soc = 100 * ( BATTERY_CAPACITY_AS + ampSeconds ) / BATTERY_CAPACITY_AS;
    }
    else {
        soc = 100 * ( BATTERY_CAPACITY_WH + wattHours ) / BATTERY_CAPACITY_WH;
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

// Return the maximum allowed voltage of the pack(s)
float Battery::get_max_voltage() {
    float max_voltage = packs[0].get_max_voltage();
    for ( int p = 1; p < numPacks; p++ ) {
        if ( packs[p].get_max_voltage() < max_voltage ) {
            max_voltage = packs[p].get_max_voltage();
        }
    }
    return max_voltage;
}

// Return the minimum allowed voltage of the pack(s)
float Battery::get_min_voltage() {
    float min_voltage = packs[0].get_min_voltage();
    for ( int p = 1; p < numPacks; p++ ) {
        if ( packs[p].get_min_voltage() > min_voltage ) {
            min_voltage = packs[p].get_min_voltage();
        }
    }
    return min_voltage;
}

// Update the value we have stored for an individual cell in the pack
void Battery::update_cell_voltage(int packIndex, int moduleIndex, int cellIndex, float newCellVoltage) {
    packs[packIndex].update_cell_voltage(moduleIndex, cellIndex, newCellVoltage);
}

// Return the id of the pack that has the highest voltage
int Battery::get_index_of_high_pack() {
    int high_pack_index = 0;
    float high_pack_voltage = 0.0f;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].get_voltage() > high_pack_voltage ) {
            high_pack_index = p;
            high_pack_voltage = packs[p].get_voltage();
        }
    }
    return high_pack_index;
}

// Return the id of the pack that has the lowest voltage
int Battery::get_index_of_low_pack() {
    int low_pack_index = 0;
    float low_pack_voltage = 1000.0f;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[0].get_voltage() < low_pack_voltage ) {
            low_pack_index = p;
            low_pack_voltage = packs[p].get_voltage();
        }
    }
    return low_pack_index;
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
bool Battery::has_empty_cell() {
    // override while testing with partial pack
    return false;

    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].has_empty_cell() ) {
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
bool Battery::has_full_cell() {
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].has_full_cell() ) {
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

// Return true if the voltage difference between any two packs is too high and
// therefore it's unstafe to close the contactors.
bool Battery::packs_are_imbalanced() {
    return ( voltage_delta_between_packs() >= SAFE_VOLTAGE_DELTA_BETWEEN_PACKS );
}

//// ----
//
// Current
//
//// ----

long Battery::get_amps() {
    return amps;
}


//// ----
//
// Temperature
//
//// ----

float Battery::get_highest_cell_temperature() {
    return highestCellTemperature;
}

// Return true if any sensor in the pack is over the max temperature
bool Battery::has_temperature_sensor_over_max() {
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].has_temperature_sensor_over_max() ){
            return true;
        }
    }
    return false;
}

void Battery::update_max_charge_current() {
    int _maxChargeCurrent = CHARGE_CURRENT_MAX;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].get_max_charge_current() < _maxChargeCurrent ) {
            _maxChargeCurrent = packs[p].get_max_charge_current();
        }
    }
    maxChargeCurrent = _maxChargeCurrent;
}

/*
 * Recalculate the maximum current which may be drawn from the pack.
 */
void Battery::update_max_discharge_current() {
    // FIXME
    maxDischargeCurrent = 1;
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


//// ----
//
// Charging
//
//// ----

bool Battery::too_cold_to_charge() {
    if ( get_lowest_temperature() < CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD ) {
        return true;
    }
    return false;
}

// Return true if the CHARGE_ENABLE signal from the charge controller is on.
bool Battery::charge_enable_is_on() {
    return chargeEnable;
}

bool Battery::heater_enabled() {
    return heaterEnabled;
}

// Enable battery heater(s)
void Battery::enable_heater() {
    heaterEnabled = true;
    gpio_put(HEATER_ENABLE_PIN, 1);
}

// Disable battery heater(s)
void Battery::disable_heater() {
    heaterEnabled = false;
    gpio_put(HEATER_ENABLE_PIN, 0);
}

// Prevent charging
void Battery::enable_inhibit_charge() {
    inhibitCharge = true;
    gpio_put(CHARGE_INHIBIT_PIN, 1);
}

// Allow charging
void Battery::disable_inhibit_charge() {
    inhibitCharge = false;
    gpio_put(CHARGE_INHIBIT_PIN, 0);
}

float Battery::get_max_charge_current() {
    return maxChargeCurrent;
}

float Battery::get_max_discharge_current() {
    return maxDischargeCurrent;
}

//// ----
//
// Driving
//
//// ----

// Prevent driving
void Battery::enable_inhibit_drive() {
    inhibitDrive = true;
    gpio_put(DRIVE_INHIBIT_PIN, 1);
}

// Permit driving
void Battery::disable_inhibit_drive() {
    inhibitDrive = false;
    gpio_put(DRIVE_INHIBIT_PIN, 0);
}

bool Battery::drive_is_inhibited() {
    return inhibitDrive;
}

// Allow contactors to close for the high pack and any other packs which are
// within SAFE_VOLTAGE_DELTA_BETWEEN_PACKS volts.
void Battery::disable_inhibit_for_drive() {
    int highPackId = get_index_of_high_pack();
    float highPackVoltage = packs[highPackId].get_voltage();
    float targetVoltage = highPackVoltage - SAFE_VOLTAGE_DELTA_BETWEEN_PACKS;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( p == highPackId ) {
            packs[p].disable_inhibit_contactor_close();
            continue;
        }
        if ( packs[p].get_voltage() >= targetVoltage ) {
            packs[p].disable_inhibit_contactor_close();
        }
    }
}

// Allow contactors to close for the low pack and any other packs which are
// within SAFE_VOLTAGE_DELTA_BETWEEN_PACKS volts.
void Battery::disable_inhibit_for_charge() {
    int lowPackId = get_index_of_low_pack();
    float lowPackVoltage = packs[lowPackId].get_voltage();
    float targetVoltage = lowPackVoltage + SAFE_VOLTAGE_DELTA_BETWEEN_PACKS;
    for ( int p = 0; p < numPacks; p++ ) {
        if ( p == lowPackId ) {
            packs[p].disable_inhibit_contactor_close();
            continue;
        }
        if ( packs[p].get_voltage() <= targetVoltage ) {
            packs[p].disable_inhibit_contactor_close();
        }
    }
}

bool Battery::ignition_is_on() {
    return ignitionOn;
}


//// ----
//
// Contactor control
//
//// ----

// Do not allow any contactors to close in any pack
void Battery::inhibit_contactor_close() {
    for ( int p = 0; p < numPacks; p++ ) {
        packs[p].enable_inhibit_contactor_close();
    }
}

// If any of the packs have their contactors inhibited, return true
bool Battery::one_or_more_contactors_inhibited() {
    for ( int p = 0; p < numPacks; p++ ) {
        if ( packs[p].contactors_are_inhibited() ) {
            return true;
        }
    }
    return false;
}

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



