/*
 * CarProto.c
 *
 * Created: 22.04.2020 18:13:29
 * Author : Yauheni
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avr-uart/uart.h"
//#include "steer/steer.h"
//#include "timer/timer0.h"
//#include "motor/motor.h"
//#include "wiring.h"
#include "i2c/i2c.h"

static uint8_t* buffer;
static uint8_t count = 1;
static void readCompleted(bool);

int main(void)
{
    i2cConfigure(i2cNormalMode);
    uart0_init(UART_BAUD_SELECT_DOUBLE_SPEED(115200, F_CPU));

    uart0_puts("Hi Jack!");

    buffer = (uint8_t*) calloc(count, sizeof(uint8_t));

    while(1) {
        uint8_t command = uart0_available() ? (uint8_t) uart0_getc() : 0;

        switch (command) {
        case 'r':
            uart0_puts("Read\n");
            i2cTransaction(0x68, 0x0F, count, buffer, false, readCompleted);
            break;
        default:
            break;
        }

        _delay_us(100);
    }

    return EXIT_SUCCESS;
}

static void readCompleted(bool isSuccess) {
    if (isSuccess) {
        uart0_puts("Data read successfully: ");
        uart0_putc(buffer[0]);
        uart0_putc('\n');
    } else {
        uart0_puts("Failed to read data\n");
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