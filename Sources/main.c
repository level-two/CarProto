/*
 * CarProto.c
 *
 * Created: 22.04.2020 18:13:29
 * Author : Yauheni
 */

#include <avr/io.h>
#include <util/delay.h>
#include "avr-uart/uart.h"
#include "stepper/stepper.h"

int main(void)
{
	uart0_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));
	uart1_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));

    stepperSetup();

	while(1) {
		_delay_ms(10);
		uint16_t c0 = uart0_getc();

		if (c0 != UART_NO_DATA) {
    		uart0_putc(c0 & 0xff);
    		uart1_putc(c0 & 0xff);
		}

        uint16_t c1 = uart1_getc();
        if (c1 != UART_NO_DATA) {
            uart0_putc(c1 & 0xff);
            uart1_putc(c1 & 0xff);
        }
	}
}
