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
#include "chademostation.h"
#include "car.h"

class Chademo {

    private:
        
        // control signals
        bool chargingEnabled;                   //
        bool chargingStopRequest;               //
        bool chargingSystemFault;               //

        // charging params
        uint8_t chargingRateIndication;         //
        uint8_t estimatedChargingTimeRemaining; //
        uint8_t chargingRate;                   //

    public:

        ChademoState state;
        ChademoStation station;

        Chademo();

        bool plug_is_in();
        bool in1_is_active();
        bool in2_is_active();

        void activate_out1();
        void deactivate_out1();
        void activate_out2();
        void deactivate_out2();

        void initialise_state();
        bool battery_over_voltage();
        bool battery_under_voltage();
        bool battery_voltage_deviation_error();
        bool battery_current_deviation_error();

        bool car_and_station_protocol_compatible();
        bool car_and_station_voltage_compatible();
        bool car_and_station_capabilities_match();

        bool station_malfunction();
        bool battery_incompatible();

};

#endif