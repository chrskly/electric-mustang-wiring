/*
 * This file is part of the ev mustang project.
 *
 * Copyright (C) 2023 Christian Kelly <chrskly@chrskly.com>
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

#include "state.h"
#include "settings.h"

State state = OFF;

unsigned long flashPoint;
unsigned long previousFlashPoint;

void setup() {

}



void loop() {

/*
    // FLASH overrides everything else
    if ( digitalRead(FLASH_IN_PIN) == 1 ) {
        if ( state != FLASH ) {
            flashPoint = 0;
        }
        do_flash();
    }

    // 
    else if ( digitalRead(BRAKE_IN_PIN) == 1 ) {
        do_brake();
    }

    // Car lights are on, do running lights
    else if ( digitalRead(LIGHTS_ON_IN_PIN) == 1 ) {
        do_lights();
    }

    // Off
    else {
        do_off();
    }
*/

    do_flash();

}


