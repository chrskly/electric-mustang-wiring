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

#ifndef CHADEMOSTATION_H
#define CHADEMOSTATION_H

class ChademoStation {

    private:

    public:

        // capabilites
        bool weldDetectionSupported;
        uint16_t maximumVoltageAvailable;
        uint8_t availableCurrent;
        uint16_t thresholdVoltage;

        // status
        uint8_t controlProtocolNumber;
        uint16_t outputVoltage;
        uint8_t outputCurrent;
        uint8_t timeRemainingSeconds;
        uint8_t timeRemainingMinutes;
        bool stationStatus;
        bool stationMalfunction;
        bool vehicleConnectorLock;
        bool batteryIncompatability;
        uint8_t chargingCurrentRequest;
        bool chargerStopControl;
        bool chargingSystemMalfunction;

        uint16_t lastUpdateFromEVSE;

        ChademoStation();
        void reinitialise();
        bool initial_parameter_exchange_complete();
        void process_capabilities_update();
        void process_status_update();


};

#endif