
#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

// PWM pin which drives fuel gauge
const uint FUEL_PWM_PIN = 15;


/*
  Set up the fuel gauge
  */
void initialise_fuel_gauge() {
    gpio_set_function(FUEL_PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(FUEL_PWM_PIN);
    uint chan = pwm_gpio_to_channel(FUEL_PWM_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(slice_num, &config, true);
}


/* 
  Returns the PWM duty cycle needed to display the given soc
  */
uint fuel_get_pwm_for_soc(uint soc) {
	/*
	 These are the PWM values arrived at by trial and error.
	 soc  pwm  diff
	 100% 9400 3000
      75% 6400 1600
      50% 4800 1300
      25% 3500 1500
       0% 2000
     */

    // 76% -> 100%
    // 120 per 1%
    if ( soc > 75 ) {
    	return 6400 + (( soc - 75 ) * 120 );
    }
    else if ( soc == 75 ) {
    	return 6400;
    }
    // 51% -> 74%
    // 64 per 1%
    else if ( soc > 50 ) {
    	return 4800 + (( soc - 50 ) * 64 );
    }
    else if ( soc == 50 ) {
    	return 4800;
    }
    // 25% -> 49%
    // 52 per 1%
    else if ( soc > 25 ) {
    	return 3500 + (( soc - 25 ) * 52 );
    }
    else if ( soc == 25 ) {
    	return 3500;
    }
    // 0% -> 24%
    // 60 per 1%
    else if ( soc > 0 ) {
    	return 2000 + ( soc * 60 );
    }
    else if ( soc == 0 ) {
        return 2000;
    }
    else {
    	// FIXME do error here
    	return 2000;
    }
}

/*
  Set the value to display on the fuel gauge
  */
	void set_soc(uint soc) {
	uint pwm = fuel_get_pwm_for_soc(soc);
	pwm_set_gpio_level(FUEL_PWM_PIN, pwm);
}




