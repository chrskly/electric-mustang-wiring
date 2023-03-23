/*
 * This file is part of the ev mustang charge controller project.
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

#include "hardware/gpio.h"

#include "chademostatemachine.h"
#include "settings.h"

void gpio_callback(uint gpio, uint32_t events) {
    extern ChademoState chademoState;

    if ( gpio == CHADEMO_IN1_PIN ) {
        if ( gpio_get(CHADEMO_IN1_PIN) == 1 ) {
            chademoState(E_IN1_WENT_HIGH);
        } else {
            chademoState(E_IN1_WENT_LOW);
        }
    }

    if ( gpio == CHADEMO_IN2_PIN ) {
        if ( gpio_get(CHADEMO_IN2_PIN) == 1 ) {
            chademoState(E_IN2_WENT_HIGH);
        } else {
            chademoState(E_IN2_WENT_LOW);
        }
    }

}

void enable_listen_for_IN1_signal() {
    gpio_set_irq_enabled_with_callback(CHADEMO_IN1_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
}

void enable_listen_for_IN2_signal() {
    gpio_set_irq_enabled(CHADEMO_IN2_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
}
