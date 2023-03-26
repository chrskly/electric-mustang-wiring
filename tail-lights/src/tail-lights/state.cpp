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

#include <Arduino.h>
#include <Time.h>

#include "settings.h"
#include "state.h"

extern unsigned long flashPoint;
extern unsigned long previousFlashPoint;

void do_flash() {

    flashPoint = millis() - previousFlashPoint;

    if ( flashPoint > 0 && flashPoint < FLASH_SINGLE_DURATION ) {
        analogWrite(BLOCK_1_PIN, HIGH_LIGHT_LEVEL);
        analogWrite(BLOCK_2_PIN, 0);
        analogWrite(BLOCK_3_PIN, 0);
    }
    else if ( flashPoint > FLASH_SINGLE_DURATION && flashPoint < ( 2 * FLASH_SINGLE_DURATION ) ) {
        analogWrite(BLOCK_1_PIN, 0);
        analogWrite(BLOCK_2_PIN, HIGH_LIGHT_LEVEL);
        analogWrite(BLOCK_3_PIN, 0);
    }
    else if ( flashPoint > ( 2 * FLASH_SINGLE_DURATION ) && flashPoint < ( 3 * FLASH_SINGLE_DURATION ) ) {
        analogWrite(BLOCK_1_PIN, 0);
        analogWrite(BLOCK_2_PIN, 0);
        analogWrite(BLOCK_3_PIN, HIGH_LIGHT_LEVEL);
    }
    else if ( flashPoint > (3*FLASH_SINGLE_DURATION) ) {
        previousFlashPoint = flashPoint;
    }

}

void do_brake() {
    analogWrite(BLOCK_1_PIN, HIGH_LIGHT_LEVEL);
    analogWrite(BLOCK_2_PIN, HIGH_LIGHT_LEVEL);
    analogWrite(BLOCK_3_PIN, HIGH_LIGHT_LEVEL);
}

void do_lights() {
    analogWrite(BLOCK_1_PIN, LOW_LIGHT_LEVEL);
    analogWrite(BLOCK_2_PIN, LOW_LIGHT_LEVEL);
    analogWrite(BLOCK_3_PIN, LOW_LIGHT_LEVEL);
}

void do_off() {
    analogWrite(BLOCK_1_PIN, 0);
    analogWrite(BLOCK_2_PIN, 0);
    analogWrite(BLOCK_3_PIN, 0);
}


