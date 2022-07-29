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

    // sleep for a bit to allow serial port to start up on PC
    sleep_ms(5000);

    //uart_puts(UART_ID, "BMS starting up...\n");
    printf("BMS starting up ...\n");

    // 8MHz clock for CAN oscillator
    clock_gpio_init(CAN_CLK_PIN, CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_VALUE_CLK_SYS, 10);

    printf("Setting up main CAN port\n");
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

    //--  BATT 0

    printf("Setting up battery 0 CAN port\n");
    MCP2515 b0_CAN(SPI_PORT, 15, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
    b0_CAN.reset();
    b0_CAN.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    b0_CAN.setNormalMode();

    printf("Sending test message on battery 0 CAN port\n");
    frame.can_id = 0x001;
    frame.can_dlc = 3;
    frame.data[0] = 0xBA;
    frame.data[1] = 0x77;
    frame.data[2] = 0x00;
    b0_CAN.sendMessage(&frame);

    //--  BATT 1

    printf("Setting up battery 1 CAN port\n");
    MCP2515 b1_CAN(SPI_PORT, 20, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
    b1_CAN.reset();
    b1_CAN.setBitrate(CAN_1000KBPS, MCP_8MHZ);
    b1_CAN.setNormalMode();

    printf("Sending test message on battery 1 CAN port\n");
    frame.can_id = 0x001;
    frame.can_dlc = 3;
    frame.data[0] = 0xBA;
    frame.data[1] = 0x77;
    frame.data[2] = 0x01;
    b1_CAN.sendMessage(&frame);    

    // The CAN library seems to only work if I define the instances at this scope ¯\_(ツ)_/¯
    /*
    printf("Creating CANports ...\n");
    for ( int p = 0; p < NUM_PACKS; p++ ) {
        printf("Creating CAN port : CS %d, CONT %d, MOD %d, CELL %d, TEMP %d\n", CS_PINS[p], CONTACTOR_PINS[p], MODULES_PER_PACK, CELLS_PER_MODULE, TEMPS_PER_MODULE);
        // this is static, so not getting recreated
        static MCP2515 port(SPI_PORT, CS_PINS[p], CONTACTOR_PINS[p], MODULES_PER_PACK, CELLS_PER_MODULE, TEMPS_PER_MODULE);
        static MCP2515* port_ptr = &port;
        printf(">> PORT %d : %p\n", p, port_ptr);
        battery.set_CAN_port(p, port_ptr);
        printf(">> sending test message\n");
        port.sendMessage(&frame);
        port.sendMessage(&frame);
        port.sendMessage(&frame);
    }
    */
    /*
    printf(">>>> Printing CANports ...\n");
    for ( int p = 0; p < NUM_PACKS; p++ ) {
        printf(">> PORT %d : %p\n", p, battery.packs[p]->CAN);
    }
    */    

    battery.print();
    battery.send_test_message();

    printf("Enabling module polling\n");
    enable_module_polling();

    while(true) {
        // process inbound messages
        // send outbound messages
        // send status message out on main CAN port
    }

    return 0;
}


