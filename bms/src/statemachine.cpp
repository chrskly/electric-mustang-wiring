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

#include "statemachine.h"
#include "battery.h"

using namespace std;


/*
 * State          : standby
 * Ignition       : off
 * Contactors     : open
 * Charging       : no
 * heater         : off
 * drive inhibit  : off
 * charge inhibit : off
 */
void state_standby(Event event) {

    extern Battery battery;
    extern State state;

    switch (event) {

        case E_TEMPERATURE_UPDATE:
            // Battery is overheating. Stop everything.
            if ( battery.has_temperature_sensor_over_max() ) {
                battery.enable_inhibit_drive();
                battery.enable_inhibit_charge();
                state = state_fault;
                break;
            }

        case E_CELL_VOLTAGE_UPDATE:
            // Battery is empty. Disallow driving.
            if ( battery.has_empty_cell() ) {
                battery.enable_inhibit_drive();
                state = state_batteryEmpty;
                break;
            }
            /* The contactors are currently open. We don't want to allow the
             * contactors to close when the packs have different voltages. So we
             * inhibit the contactors on all packs here. When we switch into
             * another state we'll decide which contactors to allow to close
             * then. This will depend on which state we switch into.
             */
            if ( battery.packs_are_imbalanced() ) {
                battery.inhibit_contactor_close();
            }
            break;

        case E_IGNITION_ON:
            /* Packs are imbalanced. Decide which contactor(s) to allow to 
             * close. Since we're going into drive mode, we want to pick the
             * high pack(s).
             */
            if ( battery.one_or_more_contactors_inhibited() ) {
                battery.disable_inhibit_for_drive();
            }
            state = state_drive;
            break;

        case E_IGNITION_OFF:
            // Already in standby state, nothing to do.
            break;

        case E_CHARGING_INITIATED:
            /* If the batteries are not warm enough to be charged, turn on the
             * battery heater, and disallow charging until they're warm enough.
             */
            if ( battery.too_cold_to_charge() ) {
                battery.enable_heater();
                battery.enable_inhibit_charge();
            }
            state = state_charging;
            break;

        case E_EMERGENCY_SHUTDOWN:
            break;

        default:
            printf("Received unknown event");
    }

}

/*
 * State          : drive
 * Ignition       : on
 * Contactors     : closed
 * Charging       : no
 * heater         : off
 * drive inhibit  : off
 * charge inhibit : off
 */
void state_drive(Event event) {

    extern Battery battery;
    extern State state;

    switch (event) {

        case E_TEMPERATURE_UPDATE:
            // Battery is overheating. Stop everything.
            if ( battery.has_temperature_sensor_over_max() ) {
                battery.enable_inhibit_drive();
                battery.enable_inhibit_charge();
                state = state_fault;
                break;
            }

        case E_CELL_VOLTAGE_UPDATE:
            // Battery is full.
            // Can we disable regen?
            //if ( battery.has_full_cell() ) { }

            /* Battery is empty. Disallow driving (force car into neutral). We
             * cannot open the contactors as this could blow up the inverter.
             */
            if ( battery.has_empty_cell() ) {
                battery.enable_inhibit_drive();
                // wait a while, then open contactors?
                state = state_batteryEmpty;
                break;
            }

            /* If we're driving on a subset of pack(s), and we've driven down
             * the high pack(s) enough that its/their voltage matches the low
             * pack(s), allow the contactors to close on the low pack(s).
             */
            if ( battery.one_or_more_contactors_inhibited() ) {
                battery.disable_inhibit_for_drive();
            }

            break;

        case E_IGNITION_ON:
            // Already in drive mode, nothing to do.
            break;

        case E_IGNITION_OFF:
            state = state_standby;
            break;

        case E_CHARGING_INITIATED:
            /* If we're driving around with some of the packs inhibited, and we
             * want to go directly into charge mode, dealing with the contactors
             * is too awkward. While driving, the high pack(s) will be enabled
             * and the low pack(s) will be disabled. However, when charging we
             * want that to be the other way around. There's no clean way to do
             * this. So lets not try. Just go into fault mode.
             */
            if ( battery.one_or_more_contactors_inhibited() ) {
                battery.enable_inhibit_drive();
                state = state_fault;
                break;
            }

            /* Lets assume that we're not in motion (hopefully a safe 
             * assumption). All contactors are already closed so we can just 
             * switch straight into charge mode.
             */
            battery.enable_inhibit_drive();
            state = state_charging;
            break;

        case E_EMERGENCY_SHUTDOWN:
            // Tell inverter to shut down + short sleep.
            break;

        default:
            printf("Received unknown event\n");
    }

}

/*
 * State          : charging
 * Ignition       : on or off
 * Contactors     : closed
 * Charging       : yes
 * heater         : off
 * drive inhibit  : off
 * charge inhibit : off
 */
void state_charging(Event event) {

    extern Battery battery;
    extern State state;

    switch (event) {

        case E_TEMPERATURE_UPDATE:
            // Battery is overheating. Stop everything.
            if ( battery.has_temperature_sensor_over_max() ) {
                battery.enable_inhibit_drive();
                battery.enable_inhibit_charge();
                state = state_fault;
                break;
            }

            // If we're waiting on the battery to warm, and it has, allow charging
            if ( battery.heater_enabled() && ! battery.too_cold_to_charge() ) {
                battery.disable_heater();
                battery.disable_inhibit_charge();
            }

            /* Deal with the unlikely scenario where the battery gets too cold
             * mid-charge. Enable heater, block charging.
             */
            if ( ! battery.heater_enabled() && battery.too_cold_to_charge() ) {
                battery.enable_inhibit_charge();
                battery.enable_heater();
            }

            // Recalculate max charging current
            battery.update_max_charging_current();
            break;

        case E_CELL_VOLTAGE_UPDATE:
            /* Prevent cells from getting over-charged */
            if ( battery.has_full_cell() ) {
                battery.enable_inhibit_charge();
            }
            break;

        case E_IGNITION_ON:
            /* We're going to continue to charge so we should prevent the car
             * from driving away.
             */
            battery.enable_inhibit_drive();
            break;

        case E_IGNITION_OFF:
            battery.disable_inhibit_drive();
            break;

        case E_CHARGING_INITIATED:
            // We're already charging. Nothing to do.
            break;

        case E_EMERGENCY_SHUTDOWN:
            break;

        default:
            printf("Received unknown event\n");
    }
}


/*
 * State          : batteryEmpty
 * Ignition       : on or off
 * Contactors     : open or closed
 * Charging       : no
 * heater         : off
 * drive inhibit  : off
 * charge inhibit : off
 */
void state_batteryEmpty(Event event) {

    extern Battery battery;
    extern State state;

    switch (event) {

        case E_TEMPERATURE_UPDATE:
            // Battery is overheating. Stop everything.
            if ( battery.has_temperature_sensor_over_max() ) {
                battery.enable_inhibit_drive();
                battery.enable_inhibit_charge();
                state = state_fault;
                break;
            }

        case E_CELL_VOLTAGE_UPDATE:
            // After resting for a while, the voltage may rise again slightly.
            if ( ! battery.has_empty_cell() ) {
                // allow driving again
                battery.disable_inhibit_drive();

                //
                if ( battery.ignition_is_on() ) {
                    //
                    if ( battery.one_or_more_contactors_inhibited() ) {
                        battery.disable_inhibit_for_drive();
                    }
                    state = state_drive;


                } else if ( battery.charge_enable_is_on() ) {
                    //
                }
                state = state_standby;
            }
            break;

        case E_IGNITION_ON:
            // Disallow driving.
            battery.enable_inhibit_drive();
            break;

        case E_CHARGING_INITIATED:
            // Is it too cold to charge?
            if ( battery.too_cold_to_charge() ) {
                battery.enable_inhibit_charge();
                if ( ! battery.heater_enabled() ) {
                    battery.enable_heater();
                }
            }
            state = state_charging;
            break;

        case E_EMERGENCY_SHUTDOWN:
            break;

        default:
            printf("Received unknown event");
    }
}

/*
 * State          : fault
 * Ignition       : --
 * Contactors     : open / closed
 * Charging       : no
 * heater         : off
 * drive inhibit  : on
 * charge inhibit : on
 *
 * Reasons we can be in this state:
 *   - We tried to go from drive to charge with imbalanced packs
 *   - Batteries are too hot
 */
void state_fault(Event event) {

    extern Battery battery;
    extern State state;

    switch (event) {

        case E_TEMPERATURE_UPDATE:
            /* Temperature has dropped below max limit. We need to figure out
             * which state to switch to based on the input signals
             */
            if ( ! battery.has_temperature_sensor_over_max() && ! battery.packs_are_imbalanced() ) {
                // Charge mode overrides drive mode
                if ( battery.charge_enable_is_on() ) {
                    battery.disable_inhibit_charge();
                    state = state_charging;
                    break;
                }
                // Drive mode
                if ( battery.ignition_is_on() ) {
                    battery.disable_inhibit_charge();
                    battery.disable_inhibit_drive();
                    state = state_drive;
                    break;
                }
                // Standby mode
                battery.disable_inhibit_drive();
                battery.disable_inhibit_charge();
                state = state_standby;
                break;
            }
            break;

        case E_CELL_VOLTAGE_UPDATE:
            break;

        case E_IGNITION_ON:
            break;

        case E_IGNITION_OFF:
            break;

        case E_CHARGING_INITIATED:
            break;

        case E_EMERGENCY_SHUTDOWN:
            break;

        default:
            printf("Received unknown event\n");
    }
}