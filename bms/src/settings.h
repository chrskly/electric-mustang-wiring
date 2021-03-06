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

#ifndef SETTINGS_H
#define SETTINGS_H

// Serial port
#define UART_ID      uart0
#define BAUD_RATE   115200
#define UART_TX_PIN      0 // pin 1
#define UART_RX_PIN      1 // pin 2


#define NUM_PACKS         2                        // The total number of paralleled packs in this battery
#define CELLS_PER_MODULE 16                        // The number of cells in each module
#define TEMPS_PER_MODULE  4                        // The number of temperature sensors in each module
#define MODULES_PER_PACK  6                        // The number of modules in each pack


#define PACK_ALIVE_TIMEOUT 5                       // If we have not seen an update from the BMS in
                                                   // PACK_ALIVE_TIMEOUT seconds, then mark the pack
                                                   // as dead.

#define SAFE_VOLTAGE_DELTA_BETWEEN_PACKS 0.01      // When closing contactors, the voltage difference between the packs shall not
                                                   // be greater than this voltage, in volts.

const int CONTACTOR_PINS[] = { 2, 3 };

//const int CS_PINS[] = { 20, 20 };
//const int CS_PINS[2] = { 20, 15 };
const int CS_PINS[2] = { 15, 15 };

#define SPI_PORT      spi0

#define SPI_MISO        16 // pin 21
#define SPI_CLK         18 // pin 24
#define SPI_MOSI        19 // pin 25

// mainNet
#define MAIN_CAN_CS     17 // pin 22

// batt1Net
//#define BATT1_CAN_CS    20 // pin 29

// batt2Net
//#define BATT2_CAN_CS    15 // pin 20

#define CAN_CLK_PIN     21 // pin 27

//const uint LED_PIN = PICO_DEFAULT_LED_PIN;

// Official min pack voltage = 269V. 269 / 6 / 16 = 2.8020833333V
#define CELL_UNDER_VOLTAGE_WARNING_THRESHOLD 2.9
#define CELL_UNDER_VOLTAGE_FAULT_THRESHOLD 2.81

// Official max pack voltage = 398V. 398 / 6 / 16 = 4.1458333333V
#define CELL_OVER_VOLTAGE_WARNING_THRESHOLD 4.1
#define CELL_OVER_VOLTAGE_FAULT_THRESHOLD 4.1458

#define CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD 0
#define CELL_OVER_TEMPERATURE_WARNING_THRESHOLD 55  // degrees
#define CELL_OVER_TEMPERATURE_FAULT_THRESHOLD 65    // degrees

#define CHARGE_THROTTLE_TEMP_LOW  45                // Start throttling charge current above this temperature
#define CHARGE_THROTTLE_TEMP_HIGH 65                // Top of the throttling scale. Limit current to CHARGE_CURRENT_MIN at and above this temperature
#define CHARGE_CURRENT_MAX 125                      // ~50kw
#define CHARGE_CURRENT_MIN 8                        // ~3.3kw

#define BALANCE_INTERVAL 1200                       // number of seconds between balancing sessions



//// ---- CAN message IDs

#define STATUS_MSG_ID 0x300                         // Status message emitted by the BMS
#define CAN_ID_ISA_SHUNT_AH 0x527                   // Message ISA shunt sends which contains Ah data.
#define CAN_ID_ISA_SHUNT_WH 0x528                   // Message ISA shunt sends which contains Wh data.

#endif