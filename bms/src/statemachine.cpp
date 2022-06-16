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


/*
 * State      : standby
 * Ignition   : off
 * Contactors : open
 * Charging   : no
 */
void state_standby(Event event) {

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
			if ( has_temperature_sensor_over_max(&battery) ) {
			    state = state_overTempFault;
		    }
		    break;
		case E_CELL_VOLTAGE_UPDATE:
			if ( has_cell_over_voltage(&battery) ) {
				state = state_overVoltageFault;
				break;
			}
			if ( has_cell_under_voltage(&battery) ) {
				state = state_underVoltageFault;
				break;
			}
			break;
		case E_IGNITION_ON:
		    close_contactors(&battery);
		    state = state_drive;
		    break;
		case E_CHARGING_INITIATED:
		    // Is it warm enough to charge?
		    if ( too_cold_to_charge(&battery) ) {
		    	break;
		    }
			close_contactors(&battery);
			state = state_charging;
			break;
		case E_EMERGENCY_SHUTDOWN:
		    open_contactors(&battery);
		    break;
		default:
		    printf("Received unknown event");
	}

}

/*
 * State      : drive
 * Ignition   : on
 * Contactors : closed
 * Charging   : no
 */
void state_drive(Event event) {

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
			if ( has_temperature_sensor_over_max(&battery) ) {
				// Tell inverter to shut down + short sleep
				open_contactors(&battery);
				state = state_overTempFault;
			}
			break;
		case E_CELL_VOLTAGE_UPDATE:
			if ( has_cell_over_voltage(&battery) ) {
				// Can we tell the inverter to turn off regen?
				//state = state_overVoltageFault;
			}
			if ( has_cell_under_voltage(&battery) ) {
				// Battery is empty. Disallow driving.
				// Tell inverter to shut down + short sleep.
				open_contactors(&battery);
				state = state_underVoltageFault;
				break;
			}
			break;
		case E_IGNITION_OFF:
			// Tell inverter to shut down + short sleep
			open_contactors(&battery);
			break;
		case E_CHARGING_INITIATED:
		    // FIXME - what do we do here.
		    // Can we check if the car is in motion?
		    break;
		case E_EMERGENCY_SHUTDOWN:
		    // Tell inverter to shut down + short sleep.
		    open_contactors(&battery);
		    break;
	}

}

/*
 * State      : charging
 * Ignition   : on or off
 * Contactors : closed
 * Charging   : yes
 */
void state_charging(Event event) {

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
		    // Switch to error state if any cell is too hot
			if ( has_temperature_sensor_over_max(&battery) ) {
				// Tell charger to shut down
				// open contactors
			    state = state_overTempFault;
		    }
		    // Is it too cold to continue charging?
		    if ( too_cold_to_charge(&battery) ) {
		    	// Tell charger to shut down
		    	// open contactors
		    	state = state_standby;
		    }
		    break;
		case E_CELL_VOLTAGE_UPDATE:
			if ( has_cell_over_voltage(&battery) ) {
				// Tell charger to shut down
				// open contactors
				state = state_overVoltageFault;
			}
			break;
		case E_IGNITION_ON:
		    // Since we're already charging, then contactors are already closed.
		    // Nothing to do.
		    break;
		case E_CHARGING_INITIATED:
			// We're already charging. Nothing to do.
			break;
		case E_EMERGENCY_SHUTDOWN:
		    open_contactors(&battery);
		    break;
		default:
		    printf("Received unknown event");
	}
}

/*
 * State      : overTempFault
 * Ignition   : off
 * Contactors : open
 * Charging   : no
 */
void state_overTempFault(Event event) {

	extern Battery battery;
	extern State state;

	// Only allow escape from overTempFault when the temperature has fallen to
	// an acceptable level. All other events will be ignored.

	switch (event) {
		case E_TEMPERATURE_UPDATE:
			if ( ! has_temperature_sensor_over_max(&battery) ) {
			    state = state_standby;
		    }
		    break;
		case E_CELL_VOLTAGE_UPDATE:
			break;
		case E_IGNITION_ON:
		    break;
		case E_CHARGING_INITIATED:
			break;
		case E_EMERGENCY_SHUTDOWN:
		    break;
		default:
		    printf("Received unknown event");
	}
}

/*
 * State      : overVoltageFault
 * Ignition   : off
 * Contactors : open
 * Charging   : no
 */
void state_overVoltageFault(Event event) {

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
		    // overTempFault beats overVoltageFault, so if a cell is too hot
		    // then switch to overTempFault state.
			if ( has_temperature_sensor_over_max(&battery) ) {
			    state = state_overTempFault;
		    }
		    break;
		case E_CELL_VOLTAGE_UPDATE:
			if ( ! has_cell_over_voltage(&battery) ) {
				state = state_standby;
			}
			break;
		case E_IGNITION_ON:
		    // Allow the car to drive off the excess charge which triggered an
		    // overVoltageFault.
		    // FIXME - can we tell the inverter to disable regen?
		    close_contactors(&battery);
		    state = state_drive;
		    break;
		case E_CHARGING_INITIATED:
			// Disallow charging when in overVoltageFault state.
		    // FIXME signal to charger over CAN that charging is disallowed
			break;
		case E_EMERGENCY_SHUTDOWN:
		    break;
		default:
		    printf("Received unknown event");
	}
}

/*
 * State      : underVoltageFault
 * Ignition   : off
 * Contactors : open
 * Charging   : no
 */
void state_underVoltageFault(Event event) {

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
			if ( has_temperature_sensor_over_max(&battery) ) {
			    state = state_overTempFault;
		    }
		    break;
		case E_CELL_VOLTAGE_UPDATE:
		    // cell voltage might rise slightly on its own over time when at rest
		    if ( ! has_cell_under_voltage(&battery) ) {
		    	state = state_standby;
		    }
			break;
		case E_IGNITION_ON:
		    // Battery is empty. Disallow driving.
		    break;
		case E_CHARGING_INITIATED:
		    // Is it warm enough to charge?
		    if ( too_cold_to_charge(&battery) ) {
		    	break;
		    }
			close_contactors(&battery);
			state = state_charging;
			break;
		case E_EMERGENCY_SHUTDOWN:
		    break;
		default:
		    printf("Received unknown event");
	}
}

/*
 * State      : unknownFault
 * Ignition   : --
 * Contactors : --
 * Charging   : --
 */
void state_unknownFault(Event event) {
	//
}