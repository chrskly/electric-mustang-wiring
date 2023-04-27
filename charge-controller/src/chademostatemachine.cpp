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
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
 *
 * Transitions:
 *  => plug_in
 *     - plug must be inserted (CS)
 */
void chademo_state_idle(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_PLUG_INSERTED:
            charger.chademo.state = chademo_state_handshaking;
            break;

        case E_CHARGE_INHIBIT_ENABLED:
            charger.chademo.state = chademo_state_charge_inhibited;
            break;

        default:
            printf("WARNING : received invalid event\n");

    }

}

/*
 * State : plug_in
 *
 * Plug has been inserted. Waiting on station pull IN1/CP high to indicate
 * station is ready to start.
 *
 * Note: possible issue here if IN1/CP and CS activate simultaneously or in the
 *       wrong order. Can this happen?
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
 *
 * Transitions:
 *  => handshaking
 *     - IN1 goes high
 *  => idle
 *     - plug removed
 */
void chademo_state_plug_in(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_IN1_ACTIVATED:
            charger.chademo.station.reinitialise();
            // begin sending messages needed for handshaking
            enable_send_outbound_CAN_messages();            
            charger.chademo.state = chademo_state_handshaking;
            break;

        case E_PLUG_REMOVED:
            charger.chademo.reinitialise();
            charger.chademo.state = chademo_state_idle;
            break;

        case E_CHARGE_INHIBIT_ENABLED:
            charger.chademo.state = chademo_state_charge_inhibited;
            break;

        default:
            printf("WARNING : received invalid event\n");

    }

}

/*
 * State : handshaking
 *  - exchanging params with evse
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
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
 *  => error
 *     - 
 */
void chademo_state_handshaking(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_EVSE_CAPABILITIES_UPDATED:

            charger.chademo.station.process_capabilities_update();

            // Can the charger provide us with enough voltage?
            if ( ! charger.chademo.car_and_station_voltage_compatible() ) {
                printf("ERROR : Insufficient voltage available at station. Stopping\n");
                charger.chademo.state = chademo_state_error;
                break;
            }

            // update time estimates
            // update current request

            // If we have received all of the params we need from the station, move to the next step
            if ( charger.chademo.station.initial_parameter_exchange_complete() ) {
                // Activate OUT1/CP3 to indicate to station that we can proceed
                charger.chademo.activate_out1();
                charger.chademo.state = chademo_state_await_connector_lock;
                break;
            }

            break;

        case E_EVSE_STATUS_UPDATED:
            // Check for control protocol compatibility (controlProtocolNumber)
            if ( ! charger.chademo.car_and_station_protocol_compatible() ) {
                printf("ERROR : chademo protocol version mismatch. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a malfunction (stationMalfunction)
            if ( charger.chademo.station.is_reporting_station_malfunction() ) {
                printf("ERROR : station is reporting a malfunction. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a battery incompatability (batteryIncompatability)
            if ( charger.chademo.station.is_reporting_battery_incompatibility() ) {
                printf("ERROR : station is reporting a battery incompatiblity. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a malfunction with the car (chargingSystemMalfunction)
            if ( charger.chademo.station.is_reporting_charging_system_malfunction() ) {
                printf("ERROR : station is reporting a charging system malfunction. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Check if charger is shutting down (chargerStopControl)
            if ( charger.chademo.station.station_is_shutting_down() ) {
                printf("ERROR : station is shutting down. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_plug_in;
            }

            if ( charger.chademo.station.initial_parameter_exchange_complete() ) {
                // Activate OUT1/CP3 to indicate to station that we can proceed
                charger.chademo.activate_out1();
                charger.chademo.state = chademo_state_await_connector_lock;
            }
            break;

        case E_EVSE_INCOMPATIBLE:
            charger.chademo.state = chademo_state_error;

        case E_PLUG_REMOVED:
            charger.chademo.reinitialise();
            charger.chademo.state = chademo_state_idle;
            break;

        case E_CHARGE_INHIBIT_ENABLED:
            // FIXME disable CAN msgs
            // disable_send_outbound_CAN_messages();
            charger.chademo.state = chademo_state_charge_inhibited;

        default:
            printf("WARNING : received invalid event\n");
    }
}

/*
 * State : await_connector_lock
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
 * 
 */
void chademo_state_await_connector_lock(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_EVSE_CAPABILITIES_UPDATED:
            break;

        case E_EVSE_STATUS_UPDATED:
            // Check for control protocol compatibility (controlProtocolNumber)
            if ( ! charger.chademo.car_and_station_protocol_compatible() ) {
                printf("ERROR : chademo protocol version mismatch. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a malfunction (stationMalfunction)
            if ( charger.chademo.station.is_reporting_station_malfunction() ) {
                printf("ERROR : station is reporting a malfunction. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a battery incompatability (batteryIncompatability)
            if ( charger.chademo.station.is_reporting_battery_incompatibility() ) {
                printf("ERROR : station is reporting a battery incompatiblity. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a malfunction with the car (chargingSystemMalfunction)
            if ( charger.chademo.station.is_reporting_charging_system_malfunction() ) {
                printf("ERROR : station is reporting a charging system malfunction. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Check if charger is shutting down (chargerStopControl)
            if ( charger.chademo.station.station_is_shutting_down() ) {
                printf("ERROR : station is shutting down. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_plug_in;
            }

            // check if lock is complete
            if ( charger.chademo.station.connector_is_locked() ) {
                charger.chademo.state = chademo_state_await_insulation_test;
                break;
            }
            break;

        case E_PLUG_REMOVED:
            charger.chademo.reinitialise();
            charger.chademo.deactivate_out1();
            charger.chademo.state = chademo_state_idle;
            break;

        case E_CHARGE_INHIBIT_ENABLED:
            charger.chademo.deactivate_out1();
            charger.chademo.state = chademo_state_charge_inhibited;

        default:
            printf("WARNING : received invalid event\n");

    }
}



/*
 * State : chademo_await_insulation_test
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
 *
 * Connector locked : yes
 *
 */
void chademo_state_await_insulation_test(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_PLUG_REMOVED:
            charger.chademo.reinitialise();
            charger.chademo.state = chademo_state_idle;
            break;

        case E_CHARGE_INHIBIT_ENABLED:
            // FIXME how do we exit safely from here? send error msg?
            charger.chademo.state = chademo_state_charge_inhibited;

        default:
            printf("WARNING : received invalid event\n");

    }
}

/*
 * State : energy_transfer
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
 *
 */
void chademo_state_energy_transfer(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_PLUG_REMOVED:
            break;

        case E_EVSE_CAPABILITIES_UPDATED:

            // Current available at station may have changed
            charger.chademo.recalculate_charging_current_request();

            // If current available has changed then the charging time may need update
            charger.chademo.recalculate_charging_time();

            break;

        case E_EVSE_STATUS_UPDATED:
            // Check for control protocol compatibility (controlProtocolNumber)
            if ( ! charger.chademo.car_and_station_protocol_compatible() ) {
                printf("ERROR : chademo protocol version mismatch. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a malfunction (stationMalfunction)
            if ( charger.chademo.station.is_reporting_station_malfunction() ) {
                printf("ERROR : station is reporting a malfunction. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a battery incompatability (batteryIncompatability)
            if ( charger.chademo.station.is_reporting_battery_incompatibility() ) {
                printf("ERROR : station is reporting a battery incompatiblity. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Fail out if the charging station has reported a malfunction with the car (chargingSystemMalfunction)
            if ( charger.chademo.station.is_reporting_charging_system_malfunction() ) {
                printf("ERROR : station is reporting a charging system malfunction. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_error;
            }

            // Check if charger is shutting down (chargerStopControl)
            if ( charger.chademo.station.station_is_shutting_down() ) {
                printf("ERROR : station is shutting down. Stopping\n");
                disable_send_outbound_CAN_messages();
                charger.chademo.state = chademo_state_plug_in;
            }

        case E_CHARGE_INHIBIT_ENABLED:

            // FIXME how do we exit safely from here? send error msg?
            charger.chademo.state = chademo_state_charge_inhibited;

        default:
            printf("WARNING : received invalid event\n");

    }

}

/*
 * State : winding_down
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no 
 *
 */
void chademo_state_winding_down(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_PLUG_REMOVED:
            break;

        case E_CHARGE_INHIBIT_ENABLED:
            break;

        break;

    }

}

/*
 * State : charge_inhibited
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
 *
 */
void chademo_state_charge_inhibited(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        case E_CHARGE_INHIBIT_DISABLED:
            break;

        default:
            printf("WARNING : received invalid event\n");

    }
}

/*
 * State : error
 *
 * IN1         : deactivated
 * IN2         : deactivated
 * OUT1        : 
 * OUT2        : 
 * CS          : deactivated
 * Plug locked : no
 *
 */
void chademo_state_error(ChademoEvent event) {

    switch (event) {

        case E_BMS_UPDATE_RECEIVED:
            charger.chademo.recalculate_charging_current_request();
            break;

        // Only way out of error is to remove the plug and start over
        case E_PLUG_REMOVED:
            charger.chademo.reinitialise();
            charger.chademo.state = chademo_state_idle;
            break;

    }
}





