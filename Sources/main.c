/*
 * CarProto.c
 *
 * Created: 22.04.2020 18:13:29
 * Author : Yauheni
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avr-uart/uart.h"
#include "i2c/i2c.h"
#include "sensors/accelerometer/accelerometer.h"

static void onData(AccelerometerData);
static void printHex(uint8_t byte);

int main(void)
{
    sei();
    uart0_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));
    uart0_puts("Hi Jack!\n");

    i2cConfigure(i2cFastMode);

    accelerometerConfigure();
    accelerometerOnDataReceived(onData);

    while(1) {
        accelerometerRequestData();
        _delay_ms(100);
    }

    return EXIT_SUCCESS;
}

static void onData(AccelerometerData data) {
    printHex(data.x >> 8);
    printHex(data.x & 0xFF);
    uart0_putc(' ');
    printHex(data.y >> 8);
    printHex(data.y & 0xFF);
    uart0_putc(' ');
    printHex(data.z >> 8);
    printHex(data.z & 0xFF);
    uart0_putc('\n');
}

static void printHex(uint8_t byte) {
    uint8_t half = (byte >> 4) & 0x0F;
    char ch = (half < 0x0A ? 0x30 : 0x37) + half;
    uart0_putc(ch);

    half = byte & 0x0F;
    ch = (half < 0x0A ? 0x30 : 0x37) + half;
    uart0_putc(ch);
}