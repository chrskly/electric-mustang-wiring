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

#include "battery.h"

#include "update.h"
#include "bms.h"
#include "statemachine.h"
#include "comms.h"
#include "led.h"

using namespace std;


struct can_frame rx;

// receive frame
struct can_frame frame;

State state;

Battery battery(NUM_PACKS);


int main() {
    stdio_init_all();

    set_sys_clock_khz(80000, true);

    // set up the serial port
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    printf("BMS starting up ...\n");

    battery.initialise();

    // Set up blinky LED
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    enable_led_blink();

    // 8MHz clock for CAN oscillator
    clock_gpio_init(CAN_CLK_PIN, CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_VALUE_CLK_SYS, 10);

    printf("Setting up main CAN port (BITRATE:%d:%d)\n", CAN_1000KBPS, MCP_8MHZ);
    MCP2515 mainCAN(SPI_PORT, MAIN_CAN_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
    mainCAN.reset();
    mainCAN.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    mainCAN.setNormalMode();

    printf("Sending test message on main CAN\n");
    frame.can_id = 0x001;
    frame.can_dlc = 4;
    frame.data[0] = 0xDE;
    frame.data[1] = 0xAD;
    frame.data[2] = 0xBE;
    frame.data[3] = 0xEF;
    mainCAN.sendMessage(&frame);

    battery.print();
    battery.send_test_message();

    printf("Enabling handling of inbound CAN messages from batteries\n");
    enable_handle_battery_CAN_messages();

    printf("Enabling module polling\n");
    enable_module_polling();

    while(true) { }

    return 0;
}


