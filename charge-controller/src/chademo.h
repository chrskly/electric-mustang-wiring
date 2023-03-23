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


#ifndef CHADEMO_H
#define CHADEMO_H

#include "chademostatemachine.h"

class Chademo {

    private:
        ChademoState* state;

        uint8_t controlProtocolNumber;          // Chademo protocol version

        // control signals
        bool chargingEnabled;                   //
        bool chargingStopRequest;               //
        bool chargingSystemFault;               //

        // error conditions
        bool highBatteryTemperature;            //

        // charging params
        uint8_t chargingCurrentRequest;         //
        uint8_t chargingRateIndication;         //
        uint8_t maximumChargingTimeSeconds;     //
        uint8_t maximumChargingTimeMinutes;     //
        uint8_t estimatedChargingTimeRemaining; //
        uint8_t chargingRate;                   //

    public:
        Chademo();

        // evse capabilities
        bool evseWeldDetectionSupported;        //
        uint16_t evseMaximumVoltageAvailable;   //
        uint8_t evseAvailableCurrent;           //
        uint16_t evseThresholdVoltage;          //

        // evse status
        uint8_t evseControlProtocolNumber;      //
        uint16_t evseOutputVoltage;             //
        uint8_t evseOutputCurrent;              //
        uint8_t evseTimeRemainingSeconds;       //
        uint8_t evseTimeRemainingMinutes;       //
        bool stationStatus;                     //
        bool stationMalfunction;                //
        bool vehicleConnectorLock;              //
        bool batteryIncompatability;            //
        bool chargingSystemMalfunction;         //
        bool chargerStopControl;                //

        bool battery_over_voltage();
        bool battery_under_voltage();
        bool battery_voltage_deviation_error();
        bool battery_current_deviation_error();
};

#endif