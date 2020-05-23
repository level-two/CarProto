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
#include "timer/timer0.h"
#include "wiring.h"

static SteerStatePtr steerInit();

int main(void)
{
	uart1_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));

    SteerStatePtr steer = steerInit();
    if (steer == NULL) return -1;

    timer0Start();

	while(1) {
        uint16_t dt = timer0Microseconds();
        timer0Reset();

        steerUpdate(steer, dt);

        if (uart1_available()) {
            uint8_t command = (uint8_t)uart1_getc();

            switch (command) {
            case 'L':
                steerSetPosition(steer, steerPositionLeft);
                uart1_puts("Turning left");
                break;
            case 'R':
                steerSetPosition(steer, steerPositionLeft);
                uart1_puts("Turning right");
                break;
            case 'M':
                steerSetPosition(steer, steerPositionLeft);
                uart1_puts("Turning middle");
                break;
            }
        }

		_delay_us(100);
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
