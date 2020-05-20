/*
 * wiring.h
 *
 * Created: 09.05.2020 14:48:58
 *  Author: Yauheni
 */

#ifndef WIRING_H_
#define WIRING_H_

#include <avr/io.h>

#define DRIVER_PORT_REG &PORTA
#define DRIVER_DDR_REG &DDRA
#define DRIVER_PIN_REG &PINA

#define DRIVER_DIR_PIN 0
#define DRIVER_STEP_PIN 1
#define DRIVER_SLEEP_PIN 2

#define STOPPER_PORT_REG &PORTA
#define STOPPER_PIN_REG &PINA

#define STOPPER_LEFT_PIN 3
#define STOPPER_RIGHT_PIN 4

#endif /* WIRING_H_ */