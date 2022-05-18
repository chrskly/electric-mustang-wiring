
#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"

#include "fuel.h"
#include "can.h"

int main() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;

    // flashy flashy
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Set up CANBUS
    //setup_can();
    CAN_setup();

    //pwm_set_gpio_level(FUEL_PWM_PIN, 6400);
    //initialise_fuel_gauge();

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);

        CAN_send_test_msg();
    }
}
