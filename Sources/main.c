/*
 * CarProto.c
 *
 * Created: 22.04.2020 18:13:29
 * Author : Yauheni
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "avr-uart/uart.h"
#include "steer/steer.h"
#include "wiring.h"

static SteerStatePtr steerInit();

int main(void)
{
	uart0_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));
	uart1_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));

    SteerStatePtr steer = steerInit();

    // TODO: Handle error - disable hardware and notify about error
    if (steer == NULL) return -1;

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

static SteerStatePtr steerInit() {
    return steerSetup(
        STEER_PORT_REG,
        STEER_DDR_REG,
        STEER_PIN_REG,
        STEER_DIR_PIN,
        STEER_STEP_PIN,
        STEER_SLEEP_PIN,
        STEER_LEFT_PIN,
        STEER_RIGHT_PIN);
}
