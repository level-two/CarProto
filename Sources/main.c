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
//#include "steer/steer.h"
//#include "timer/timer0.h"
//#include "motor/motor.h"
//#include "wiring.h"
#include "i2c/i2c.h"

static void readCompleted(bool, uint8_t*, uint8_t);

int main(void)
{
    sei();
    uart0_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));
    uart0_puts("Hi Jack!\n");

    i2cConfigure(i2cNormalMode);

    while(1) {
        uint8_t command = uart0_available() ? (uint8_t) uart0_getc() : 0;

        switch (command) {
        case 's':
            i2cRead(0x68, 0x0F, 1, readCompleted);
            i2cWriteByte(0x68, 0x22, 0xEB, NULL);
            i2cRead(0x68, 0x22, 10, readCompleted);
            i2cRead(0x18, 0x8f, 6, readCompleted);
            i2cRead(0x18, 0x0f, 6, readCompleted);
            i2cRead(0x18, 0x8f, 1, readCompleted);
            i2cRead(0x18, 0x0f, 1, readCompleted);
            break;
        default:
            break;
        }

        _delay_us(100);
    }

    return EXIT_SUCCESS;
}

static void readCompleted(bool isSuccess, uint8_t* data, uint8_t len) {
    if (isSuccess) {
        uart0_puts("Data: ");

        for (uint8_t i = 0; i < len; i++) {
            uint8_t byte = (data[i] >> 4) & 0x0F;
            char ch = (byte < 0x0A ? 0x30 : 0x37) + byte;
            uart0_putc(ch);

            byte = data[i] & 0x0F;
            ch = (byte < 0x0A ? 0x30 : 0x37) + byte;
            uart0_putc(ch);

            uart0_putc(i < len-1 ? ' ' : '\n');
        }

        free(data);
    } else {
        uart0_puts("=[\n");
    }
}

/*
static SteerStatePtr steerInit();
static MotorPtr motorInit();
static void logMessage(const char*);

int main(void)
{
    uart0_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));
    uart1_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));

    SteerStatePtr steer = steerInit();
    if (steer == NULL) return EXIT_FAILURE;

    MotorPtr motor = motorInit();
    if (motor == NULL) {
        steerRelease(steer);
        return EXIT_FAILURE;
    }

    timer0Start();

    uart0_puts("Hi Jack!");
    uart1_puts("Hi Jack!");

	while(1) {
        uint16_t dt = timer0Microseconds();
        timer0Reset();

        steerUpdate(steer, dt);

        uint8_t command =
            uart0_available() ? (uint8_t)uart0_getc() :
            uart1_available() ? (uint8_t)uart1_getc() : 0;

        switch (command) {
        case 'L':
            if (steerIsBusy(steer)) {
                logMessage("Busy");
                break;
            }
            steerSetPosition(steer, steerPositionLeft);
            logMessage("Turning left");
            break;

        case 'R':
            if (steerIsBusy(steer)) {
                logMessage("Busy");
                break;
            }
            steerSetPosition(steer, steerPositionRight);
            logMessage("Turning right");
            break;

        case 'M':
            if (steerIsBusy(steer)) {
                logMessage("Busy");
                break;
            }
            steerSetPosition(steer, steerPositionMiddle);
            logMessage("Turning middle");
            break;

        case 'F':
            motorTurnOn(motor, true);
            logMessage("Go!");
            break;

        case 'S':
            motorTurnOn(motor, false);
            logMessage("Stopped");
            break;

        default:
            break;
        }

		_delay_us(100);
	}

    return EXIT_SUCCESS;
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

static MotorPtr motorInit() {
    return motorSetup(
        MOTOR_PORT_REG,
        MOTOR_DDR_REG,
        MOTOR_TURNON_PIN);
}

static void logMessage(const char* message) {
    uart0_puts(message);
    uart0_putc('\n');
    uart1_puts(message);
    uart1_putc('\n');
}
*/