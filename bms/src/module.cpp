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

/*

    MODULE

*/

#include <stdio.h>

#include "module.h"
#include "pack.h"

using namespace std;

BatteryModule::BatteryModule(){}

BatteryModule::BatteryModule (int _id, BatteryPack* _pack, int _numCells, int _numTemperatureSensors) {

    //printf("Creating module (id:%d, pack:%d, cpm:%d, t:%d)\n", _id, _pack->id, _numCells, _numTemperatureSensors);

    id = _id;

    // Point back to parent pack
    pack = _pack;

    // Initialise all cell voltages to zero
    //numCells = _numCells;
    numCells = 16;

    for ( int c = 0; c < numCells; c++ ) {
        cellVoltage[c] = 0;
    }

    // Initialise temperature sensor readings to zero
    numTemperatureSensors = _numTemperatureSensors;

    for ( int t = 0; t < numTemperatureSensors; t++ ) {
        cellTemperature[t] = 0;
    }

    //printf("    module %d creation complete\n", id);

}

void BatteryModule::print () {
    printf("    Module id : %d (numCells : %d)\n", id, numCells);
    printf("        Cell Voltages : ");
    for ( int c = 0; c < numCells; c++ ) {
        printf("%d:%1.3fV ", c, cellVoltage[c]);
    }
    printf("\n");
    printf("        Temperatures : ");
    for ( int t = 0; t < numTemperatureSensors; t++ ) {
        printf("%d:%3.2fC ", t, cellTemperature[t]);
    }
    printf("\n");
}


//// ----
//
// Voltage
//
//// ----

// Return total module voltage by summing the cell voltages
float BatteryModule::get_voltage() {
    float voltage = 0;
    for ( int c = 0; c < numCells; c++ ) {
        voltage += cellVoltage[c];
    }
    return voltage;
}

// Return the voltage of the lowest cell voltage in the module
float BatteryModule::get_lowest_cell_voltage() {
    //printf("Inside module::get_lowest_cell_voltage\n");
    float lowestCellVoltage = 1000;
    for ( int c = 0; c < numCells; c++ ) {
        if ( cellVoltage[c] < lowestCellVoltage ) {
            lowestCellVoltage = cellVoltage[c];
        }
    }
    return lowestCellVoltage;
}

// Return true if any of the cells in the module are under min voltage
bool BatteryModule::has_empty_cell() {
    for ( int c = 0; c < numCells; c++ ) {
        if ( cellVoltage[c] < CELL_EMPTY_VOLTAGE ) {
            return true;
        }
    }
    return false;
}

// Return the voltage of the highest cell in the module
float BatteryModule::get_highest_cell_voltage() {
    float highestCellVoltage = 0;
    for ( int c = 0; c < numCells; c++ ) {
        if ( cellVoltage[c] > highestCellVoltage ) {
            highestCellVoltage = cellVoltage[c];
        }
    }
    return highestCellVoltage;
}

// Update the voltage for a single cell
void BatteryModule::update_cell_voltage(int cellIndex, float newCellVoltage) {
    cellVoltage[cellIndex] = newCellVoltage;
}

// Return true if any of the cells in the module are over max voltage
bool BatteryModule::has_full_cell() {
    for ( int c = 0; c < numCells; c++ ) {
        if ( cellVoltage[c] > CELL_FULL_VOLTAGE ) {
            return true;
        }
    }
    return false;
}


//// ----
//
// Temperature
//
//// ----

// Update the value for one of the temperature sensors
void BatteryModule::update_temperature(int tempSensorId, float newTemperature) {
    cellTemperature[tempSensorId] = newTemperature;
}

// Return the temperature of the hottest sensor in the module
float BatteryModule::get_highest_temperature() {
    float highestTemperature = -50;
    for ( int t = 0; t < numTemperatureSensors; t++ ) {
        if ( cellTemperature[t] > highestTemperature ) {
            highestTemperature = cellTemperature[t];
        }
    }
    return highestTemperature;
}

// Return true if any temperature sensor is over the max temperature
bool BatteryModule::has_temperature_sensor_over_max() {
    return ( get_highest_temperature() > CELL_OVER_TEMPERATURE_FAULT_THRESHOLD );
}

// Return the temperature of the coldest sensor in the module
float BatteryModule::get_lowest_temperature() {
    float lowestTemperature = 1000;
    for ( int t = 0; t < numTemperatureSensors; t++ ) {
        if ( cellTemperature[t] < lowestTemperature ) {
            lowestTemperature = cellTemperature[t];
        }
    }
    return lowestTemperature;
}

// returns true when any temperature sensor in this module is over the warning
// level, but below the critical level.
bool BatteryModule::temperature_at_warning_level() {
    for ( int c = 0; c < numCells; c++ ) {
        if ( cellTemperature[c] >= CELL_OVER_TEMPERATURE_WARNING_THRESHOLD and 
            cellTemperature[c] < CELL_OVER_TEMPERATURE_FAULT_THRESHOLD ) {
            return true;
        }
    }
    return false;
}


//// ----
//
// Charging
//
//// ----

// Return the maximum current the charger may push into the module
int BatteryModule::get_max_charging_current() {
    float highestTemperature = get_highest_temperature();
    if ( highestTemperature > CHARGE_THROTTLE_TEMP_LOW ) {
        float degreesOver = highestTemperature - CHARGE_THROTTLE_TEMP_LOW;
        float scaleFactor = 1 - ( degreesOver / ( CHARGE_THROTTLE_TEMP_HIGH - CHARGE_THROTTLE_TEMP_LOW ) );
        float chargeCurrent = ( scaleFactor * ( CHARGE_CURRENT_MAX - CHARGE_CURRENT_MIN ) ) + CHARGE_CURRENT_MIN;
        return (int)chargeCurrent;
    } else {
        return (int)CHARGE_CURRENT_MAX;
    }
}





