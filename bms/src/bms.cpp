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

#include "mcp2515/mcp2515.h"

#include "structs.h"

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
//#define MAIN_CAN_INT     9

// batt1Net
#define BATT1_CAN_CS    22 // pin 29
//#define BATT1_CAN_INT   14

// batt2Net
#define BATT2_CAN_CS    15 // pin 20
//#define BATT2_CAN_INT   14

// Serial port
#define UART_ID      uart0
#define BAUD_RATE   115200
#define UART_TX_PIN      0 // pin 1
#define UART_RX_PIN      1 // pin 2

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

// CAN interfaces
MCP2515 mainCAN(spi0, MAIN_CAN_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
MCP2515 batt1CAN(spi0, BATT1_CAN_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
MCP2515 batt2CAN(spi0, BATT2_CAN_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);

// Interrupt flag for each CAN interface
bool mainCANInterrupt = false;
bool batt1CANInterrupt = false;
bool batt2CANInterrupt = false;

// Set up battery

struct Battery battery;

//struct BatteryPack batt1;
//struct BatteryPack batt2;
//battery.pack[0] = batt1;
//battery.pack[1] = batt2;

struct can_frame rx;

// receive frame
struct can_frame frame;

// Store the statemachine state
State state;


void setupCAN() {
    // set up CAN ports

    battery.packs[0]->CAN = batt1CAN;
    battery.packs[2]->CAN = batt2CAN;

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

void handleMainCANInterrupt(uint gpio, uint32_t events) {
    mainCANInterrupt = true;
}

void handleBatt1CANInterrupt(uint gpio, uint32_t events) {
    batt1CANInterrupt = true;
}

void handleBatt2CANInterrupt(uint gpio, uint32_t events) {
    batt2CANInterrupt = true;
}

void processCANReads() {

    // Read message from mainCAN interface if one is ready
    if ( mainCANInterrupt ) {
        mainCANInterrupt = false;
        uint8_t irq = mainCAN.getInterrupts();
        if (irq & MCP2515::CANINTF_RX0IF) {
            if (mainCAN.readMessage(MCP2515::RXB0, &frame) == MCP2515::ERROR_OK) {
                // frame contains received from RXB0 message
            }
        }
        if (irq & MCP2515::CANINTF_RX1IF) {
            if (mainCAN.readMessage(MCP2515::RXB1, &frame) == MCP2515::ERROR_OK) {
                // frame contains received from RXB1 message
            }
        }
    }

    // Read message from batt1CAN
    if ( batt1CANInterrupt ) {
        batt1CANInterrupt = false;
        uint8_t irq = batt1CAN.getInterrupts();
        if (irq & MCP2515::CANINTF_RX0IF) {
            if (batt1CAN.readMessage(MCP2515::RXB0, &frame) == MCP2515::ERROR_OK) {
                // frame contains received from RXB0 message
            }
        }
        if (irq & MCP2515::CANINTF_RX1IF) {
            if (batt1CAN.readMessage(MCP2515::RXB1, &frame) == MCP2515::ERROR_OK) {
                // frame contains received from RXB1 message
            }
        }
    }

    // Read message from batt2CAN
    if ( batt2CANInterrupt ) {
        batt2CANInterrupt = false;
        uint8_t irq = batt2CAN.getInterrupts();
        if (irq & MCP2515::CANINTF_RX0IF) {
            if (batt2CAN.readMessage(MCP2515::RXB0, &frame) == MCP2515::ERROR_OK) {
                // frame contains received from RXB0 message
            }
        }
        if (irq & MCP2515::CANINTF_RX1IF) {
            if (batt2CAN.readMessage(MCP2515::RXB1, &frame) == MCP2515::ERROR_OK) {
                // frame contains received from RXB1 message
            }
        }
    }

}


int main() {
    stdio_init_all();

    // set up the serial port
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    uart_puts(UART_ID, "BMS starting up...\n");

    // 8MHz clock for CAN
    clock_gpio_init(CAN_CLK_PIN, CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 10);

    setupCAN();

    // interrupt for mainCAN, batt1CAN, and batt2CAN
    gpio_set_irq_enabled_with_callback(MAIN_CAN_INT, GPIO_IRQ_LEVEL_LOW, true, &handleMainCANInterrupt);
    gpio_set_irq_enabled_with_callback(BATT1_CAN_INT, GPIO_IRQ_LEVEL_LOW, true, &handleBatt1CANInterrupt);
    gpio_set_irq_enabled_with_callback(BATT2_CAN_INT, GPIO_IRQ_LEVEL_LOW, true, &handleBatt2CANInterrupt);

    for ( int p = 0; p < NUM_PACKS; p++ ) {
        struct BatteryPack pack;
        battery.packs[p] = &pack;
        for ( int m = 0; m < MODULES_PER_PACK; m++ ) {
            BatteryModule module;
                pack.modules[m] = &module;
        }
    }

    
    while(true) {
        if(mainCAN.readMessage(&rx) == MCP2515::ERROR_OK) {
            char str[200];
            sprintf(str, "CAN1 New frame from ID: %10x\n", rx.can_id);
            uart_puts(UART_ID, str);
            // sleep for a second, then retransmit
            sleep_ms(1000);
            mainCAN.sendMessage(&rx);
        }
        if(batt1CAN.readMessage(&rx) == MCP2515::ERROR_OK) {
            char str[200];
            sprintf(str, "CAN0 New frame from ID: %10x\n", rx.can_id);
            uart_puts(UART_ID, str);
            // sleep for a second, then retransmit
            sleep_ms(1000);
            batt1CAN.sendMessage(&rx);
        }
    }
    

    // 
    enableModulePolling();

    while(true) {
        // process inbound messages
        // send outbound messages
        // send status message out on main CAN port
    }

    return 0;
}


