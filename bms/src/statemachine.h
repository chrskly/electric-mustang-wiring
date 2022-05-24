
enum Event {
	E_TEMPERATURE_UPDATE,  // a battery temperature update has been received
	E_CELL_VOLTAGE_UPDATE, // a cell voltage update has been received
	E_IGNITION_ON,         // the ignition was turned on
	E_CHARGING_INITIATED,  // charging has been initiated
	E_OPEN_CONTACTORS,     //
	E_CLOSE_CONTACTORS,    //
};

typedef void (*State)(Event);

void state_standby(Event event);
void state_drive(Event event);
void state_chargeInitialise(Event event);
void state_chargeInProgress(Event event);
void state_overTempFault(Event event);
void state_underVoltageFault(Event event);
void state_unknownFault(Event event);


