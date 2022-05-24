
#include "statemachine.h"

#include "battery.h"


/*
    State = standby
*/
void state_standby(Event event) {

	extern Battery battery;
	extern State state;

	if ( event == E_TEMPERATURE_UPDATE ) {
		if ( batteryHasCellOverTemp(&battery) ) {
			state = state_overTempFault;
		}
	}
	if ( event == E_CELL_VOLTAGE_UPDATE ) {
		//
	}
	if ( event == E_IGNITION_ON ) {
		// check for large voltage difference between packs
		// close contactors
	}
	if ( event == E_CHARGING_INITIATED ) {
		//
	}
	if ( event == E_OPEN_CONTACTORS ) {
		//
	}
	if ( event == E_CLOSE_CONTACTORS ) {
		//
	}

}

/*
    State = drive
*/
void state_drive(Event event) {
	//
}

/*
    State = chargeInitialise
*/
void state_chargeInitialise(Event event) {
	//
}

/*
    State = chargeInProgress
*/
void state_chargeInProgress(Event event) {
	//
}

/*
    State = overTempFault
*/
void state_overTempFault(Event event) {
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