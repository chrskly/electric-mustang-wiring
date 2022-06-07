
#include <stdio.h>

#include "statemachine.h"
#include "battery.h"


/*
    State = standby
*/
void state_standby(Event event) {

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
			if ( batteryHasCellOverTemp(&battery) ) {
			    state = state_overTempFault;
		    }
		    break;
		case E_CELL_VOLTAGE_UPDATE:
			if ( batteryHasCellOverVoltage(&battery) ) {
				state = state_overVoltageFault;
			}
			break;
		case E_IGNITION_ON:
		    // check for large voltage difference between packs
		    // close contactors
		    break;
		case E_CHARGING_INITIATED:
			// check for large voltage difference between packs
			// close contactors
			state = state_charging;
			break;
		case E_EMERGENCY_SHUTDOWN:
		    break;
		default:
		    printf("Received unknown event");
	}

}

/*
    State = drive
*/
void state_drive(Event event) {

	// contactors closed

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
			if ( batteryHasCellOverTemp(&battery) ) {
				// Tell inverter to shut down + short sleep
				batteryOpenContactors(&battery);
				state = state_overTempFault;
			}
			break;
		case E_CELL_VOLTAGE_UPDATE:
			if ( batteryHasCellOverVoltage(&battery) ) {
				// Tell inverter to shut down + short sleep
				state = state_overVoltageFault;
			}
			break;
		case E_IGNITION_OFF:
			// Tell inverter to shut down + short sleep
			batteryOpenContactors(&battery);
			break;
	}

}

/*
    State = charging
*/
void state_charging(Event event) {

	extern Battery battery;
	extern State state;

	switch (event) {
		case E_TEMPERATURE_UPDATE:
		    // Switch to error state if any cell is too hot
			if ( batteryHasCellOverTemp(&battery) ) {
			    state = state_overTempFault;
		    }
		    // open contactors?
		    break;
		case E_CELL_VOLTAGE_UPDATE:
			if ( batteryHasCellOverVoltage(&battery) ) {
				state = state_overVoltageFault;
			}
			// open contactors
			break;
		case E_IGNITION_ON:
		    // check for large voltage difference between packs
		    // close contactors
		    break;
		case E_CHARGING_INITIATED:
			// check for large voltage difference between packs
			// close contactors
			state = state_charging;
			break;
		case E_EMERGENCY_SHUTDOWN:
		    break;
		default:
		    printf("Received unknown event");
	}
}

/*
    State = overTempFault
*/
void state_overTempFault(Event event) {
	//
}

/*
    State = overVoltageFault
*/
void state_overVoltageFault(Event event) {
	//
}

/*
    State = underVoltageFault
*/
void state_underVoltageFault(Event event) {
	//
}

/*
    State = unknownFault
*/
void state_unknownFault(Event event) {
	//
}