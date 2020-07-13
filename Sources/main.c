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
#include "common/unused.h"
#include "avr-uart/uart.h"
#include "i2c/i2c.h"
#include "sensors/gyroscope/gyroscope.h"

static void onGyroData(uint8_t*, uint8_t);

int main(void)
{
    sei();
    uart0_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));
    uart0_puts("Hi Jack!\n");

    i2cConfigure(i2cNormalMode);
    gyroConfigure();
    gyroOnDataReceived(onGyroData);

    while(1) {
        gyroRequestData();
        _delay_ms(100);
    }

    return EXIT_SUCCESS;
}

static void onGyroData(uint8_t* data, uint8_t len) {
    UNUSED(len);

    for (uint8_t i = 0; i < 6; i++) {
        uint8_t byte = (data[i] >> 4) & 0x0F;
        char ch = (byte < 0x0A ? 0x30 : 0x37) + byte;
        uart0_putc(ch);

        byte = data[i] & 0x0F;
        ch = (byte < 0x0A ? 0x30 : 0x37) + byte;
        uart0_putc(ch);

        uart0_putc(((i % 6) == 5) ? '\n' : ' ');
    }

    free(data);
}
