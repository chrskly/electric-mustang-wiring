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

#ifndef SETTINGS_H
#define SETTINGS_H

#define VERSION 1.0

// Serial port
#define UART_ID      uart0
#define BAUD_RATE   115200
#define UART_TX_PIN      0 // pin 1
#define UART_RX_PIN      1 // pin 2

#define CHARGE_INHIBIT_PIN 99

// Chademo pins
#define CHADEMO_IN1_PIN 99
#define CHADEMO_IN2_PIN 99
#define CHADEMO_OUT1_PIN 99
#define CHADEMO_OUT2_PIN 99

// Messages from EVSE
#define EVSE_CAPABILITIES_MESSAGE_ID 0x108
#define EVSE_STATUS_MESSAGE_ID 0x109

#endif