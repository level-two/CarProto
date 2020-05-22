/*
 * wiring.h
 *
 * Created: 09.05.2020 14:48:58
 *  Author: Yauheni
 */

#ifndef WIRING_H_
#define WIRING_H_

#include <avr/io.h>

#define STEER_PORT_REG &PORTA
#define STEER_DDR_REG &DDRA
#define STEER_PIN_REG &PINA
#define STEER_DIR_PIN 0
#define STEER_STEP_PIN 1
#define STEER_SLEEP_PIN 2
#define STEER_LEFT_PIN 3
#define STEER_RIGHT_PIN 4

#endif /* WIRING_H_ */