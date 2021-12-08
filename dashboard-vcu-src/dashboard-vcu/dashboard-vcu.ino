/*
 * This file is part of the electric mustang dashboard vcu
 *
 * Copyright (C) 2021 Christian Kelly <chrskly@chrskly.com>
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
 *
 */

/*
 * FUEL / BATTERY
 */

int FUEL_PWM_PIN = 2;
int FUEL_PWM_EMPTY = 5;
int FUEL_PWM_FULL = 40;
int FUEL_PWM_RANGE = FUEL_PWM_FULL - FUEL_PWM_EMPTY;

// Given a battery SOC (%) return the corresponding PWM value to display that on the gauge.
int battery_get_pwm_from_soc(int battery_soc) {
    int pwm = FUEL_PWM_EMPTY + ( FUEL_PWM_RANGE * ( battery_soc / 100.0 ) );
    return pwm;
}

/*
 * TEMPERATURE
 */


/*
 * MAIN
 */

void setup() {
    Serial.begin(9600);
    // Fuel gauges
    pinMode(FUEL_PWM_PIN, OUTPUT);
}

void loop() {
    int soc = 15;
    Serial.print("soc = ");
    Serial.println(soc);
    int p = battery_get_pwm_from_soc(soc);
    Serial.print("pwm = ");
    Serial.println(p);
    analogWrite(FUEL_PWM_PIN, p);
    delay(10000);
}
