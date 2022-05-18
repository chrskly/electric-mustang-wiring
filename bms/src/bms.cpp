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
#include "pack.h"

#define SPI_PORT      spi0

#define SPI_MISO        16 // pin 21
#define SPI_CLK         18 // pin 24
#define SPI_MOSI        19 // pin 25

// mainNet
#define MAIN_NET_CS     17
#define MAIN_NET_INT     9

// batt1Net
#define BATT1_CS        15
#define BATT1_INT       14

// batt2Net
#define BATT2_CS        15
#define BATT2_INT       14

// Serial port
#define UART_ID      uart0
#define BAUD_RATE   115200
#define UART_TX_PIN      0 // pin 1
#define UART_RX_PIN      1 // pin 2

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

MCP2515 mainCAN(spi0, MAIN_NET_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
MCP2515 batt1CAN(spi0, BATT1_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);
MCP2515 batt2CAN(spi0, BATT2_CS, SPI_MISO, SPI_MOSI, SPI_CLK, 10000000);

struct BatteryPack batt1;
struct BatteryPack batt2;

struct can_frame rx;


void setupCAN() {
    // set up CAN ports

    batt1.CAN = batt1CAN;
    batt2.CAN = batt2CAN;

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


int main() {
    stdio_init_all();

    // set up the serial port
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    uart_puts(UART_ID, "BMS starting up...\n");

    setupCAN();

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

    return 0;
}


