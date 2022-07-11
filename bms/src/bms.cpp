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

/*------------------------------------------------------------------------------

EV Mustang BMS

Pins
GPIO0  (1)  uart rx  - to ftdi tx
GPIO1  (2)  uart tx  - to ftdi rx
GPIO16 (21) SPI0 RX  - to MISO on both mcp2515 boards (via level converter)
GPIO18 (24) SPI0 SCK - to SCK on both mcp2515 boards (via level converter)
GPIO19 (25) SPI0 TX  - to MOSI on both mcp2515 boards (via level converter)
GPIO17 (22) SPI0 CS0 - to CS on mcp2515 board 0 (via level converter)
SPIO15 (20) SPI0 CS1 - to CS on mcp2515 board 1 (vai level converter)

------------------------------------------------------------------------------*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "hardware/pll.h"


#include "mcp2515/mcp2515.h"

#include "structs.h"

#include "battery.h"
#include "pack.h"
#include "update.h"
#include "bms.h"
#include "statemachine.h"
#include "comms.h"


#define SPI_PORT      spi0

#define SPI_MISO        16 // pin 21
#define SPI_CLK         18 // pin 24
#define SPI_MOSI        19 // pin 25

// mainNet
#define MAIN_CAN_CS     17 // pin 22

// batt1Net
#define BATT1_CAN_CS    20 // pin 29

// batt2Net
//#define BATT2_CAN_CS    15 // pin 20
#define BATT2_CAN_CS    20 // pin 29

#define CAN_CLK_PIN     21 // pin 27

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

// CAN interfaces
MCP2515 mainCAN(spi0, MAIN_CAN_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
MCP2515 batt1CAN(spi0, BATT1_CAN_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
MCP2515 batt2CAN(spi0, BATT2_CAN_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);

// Set up battery

struct Battery battery;

struct can_frame rx;

// receive frame
struct can_frame frame;

// Store the statemachine state
State state;


void setupCAN() {
    // set up CAN ports

    clock_gpio_init(CAN_CLK_PIN, CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_VALUE_CLK_SYS, 10);

    //battery.packs[0]->CAN = &batt1CAN;
    battery.packs[0]->CAN = &batt2CAN;
    battery.packs[1]->CAN = &batt2CAN;

    mainCAN.reset();
    mainCAN.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    mainCAN.setNormalMode();

    batt1CAN.reset();
    batt1CAN.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    batt1CAN.setNormalMode();

    batt2CAN.reset();
    batt2CAN.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    batt2CAN.setNormalMode();

}

void send_startup_test_messages() {
    frame.can_dlc = 1;
    frame.data[0] = 0x01;
    printf("Sending test message on mainCAN\n");
    mainCAN.sendMessage(&frame);
    mainCAN.sendMessage(&frame);
    mainCAN.sendMessage(&frame);
    printf("Sending test message on batt2CAN\n");
    batt2CAN.sendMessage(&frame);
    batt2CAN.sendMessage(&frame);
    batt2CAN.sendMessage(&frame);

}


int main() {
    stdio_init_all();

    set_sys_clock_khz(80000, true);

    // set up the serial port
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    //uart_puts(UART_ID, "BMS starting up...\n");
    printf("BMS starting up ...\n");

    // sleep for a bit to allow serial port to start up on PC
    sleep_ms(5000);

    // 8MHz clock for CAN oscillator
    printf("Turning on CAN clock\n");
    sleep_ms(1000);
    //clock_gpio_init(CAN_CLK_PIN, CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_VALUE_CLK_SYS, 10);

    // Initialise the battery state
    printf("Initialising battery state\n");
    initialise_battery(&battery);

    printf("Setting up CAN ports...\n");
    setupCAN();

    send_startup_test_messages();

    // print initial status
    print_pack_status(battery.packs[0], 0);
    print_pack_status(battery.packs[1], 1);

    // 
    printf("Enabling module polling\n");
    enable_module_polling();

    while(true) {
        // process inbound messages
        // send outbound messages
        // send status message out on main CAN port
    }

    return 0;
}


