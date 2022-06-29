
#include <stdio.h>

#include "../../structs.h"
#include "../../module.h"


int main() {
	BatteryModule module;
	BatteryPack pack;

	initialise_module(&module, &pack);

	// Set and test temperatures
	update_temperature(&module, 0, 20.0f);
	update_temperature(&module, 1, 21.0f);
	update_temperature(&module, 2, 66.0f);
	update_temperature(&module, 3, 56.0f);

	float highest_temperature = get_highest_temperature(&module);
	if ( highest_temperature == 66.0f ) {
		printf("get_highest_temperature OK");
	} else {
		printf("get_highest_temperature NOT OK");
	}

	float lowest_temperature = get_lowest_temperature(&module);
	if ( lowest_temperature == 20.0f ) {
		printf("get_lowest_temperature OK");
	} else {
		printf("get_lowest_temperature NOT OK");
	}

	if ( has_temperature_sensor_over_max(&module) ) {
		printf("has_temperature_sensor_over_max OK");
	} else {
		printf("has_temperature_sensor_over_max NOT OK");
	}

    if ( temperature_at_warning_level(&module) ) {
    	printf("temperature_at_warning_level OK");
    } else {
    	printf("temperature_at_warning_level NOT OK");
    }


	// Set and test voltages
}