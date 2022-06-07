
enum Event {
	E_TEMPERATURE_UPDATE,  // a battery temperature update has been received
	E_CELL_VOLTAGE_UPDATE, // a cell voltage update has been received
	E_IGNITION_ON,         // Ignition was turned on
	E_IGNITION_OFF,        // Ignition was turned off
	E_CHARGING_INITIATED,  // charging has been initiated
	E_EMERGENCY_SHUTDOWN,  //
};

typedef void (*State)(Event);

void state_standby(Event event);
void state_drive(Event event);
void state_charging(Event event);
void state_overTempFault(Event event);
void state_underVoltageFault(Event event);
void state_overVoltageFault(Event event);
void state_unknownFault(Event event);


