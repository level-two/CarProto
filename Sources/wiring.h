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
#define STEER_DIR_PIN PA7
#define STEER_STEP_PIN PA6
#define STEER_SLEEP_PIN PA5
#define STEER_LEFT_PIN PINA1
#define STEER_RIGHT_PIN PINA0


#define MOTOR_PORT_REG &PORTA
#define MOTOR_DDR_REG &DDRA
#define MOTOR_TURNON_PIN PA2

#endif /* WIRING_H_ */