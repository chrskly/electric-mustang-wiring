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
#include "pico/stdlib.h"

#include "led.h"

bool LEDon = false;
int LEDcounter = 0;
int LEDonDuration = 2;
int LEDoffDuration = 10;
struct repeating_timer ledBlinkTimer;   


// Switch status light to a different mode
void led_set_mode(LED_MODE newMode) {
    printf("Setting LED mode %d\n", newMode);
    switch( newMode ) {
        case STANDBY:
            LEDonDuration = 1;
            LEDoffDuration = 9;
        case DRIVE:
            LEDonDuration = 10;
            LEDoffDuration = 0;
        case CHARGING:
            LEDonDuration = 5;
            LEDoffDuration = 5;
        case FAULT:
            LEDonDuration = 1;
            LEDoffDuration = 1;
    }

}


bool led_blink(struct repeating_timer *t) {
    ++LEDcounter;
    printf("counter %d (%d/%d)\n", LEDcounter, LEDonDuration, LEDoffDuration);

    if ( LEDon ) {
        if ( LEDcounter > LEDonDuration ) {
            gpio_put(PICO_DEFAULT_LED_PIN, 0);
            LEDcounter = 0;
            LEDon = false;
        }
    } else {
        if ( LEDcounter > LEDoffDuration ) {
            gpio_put(PICO_DEFAULT_LED_PIN, 1);
            LEDcounter = 0;
            LEDon = true;
        }
    }

    return true;
}

void enable_led_blink() {
    add_repeating_timer_ms(100, led_blink, NULL, &ledBlinkTimer);
}

