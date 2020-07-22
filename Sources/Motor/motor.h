/*
 * motor.h
 *
 * Created: 28.05.2020 10:50:13
 *  Author: Yauheni
 */


#ifndef MOTOR_H_
#define MOTOR_H_

#include <inttypes.h>
#include <stdbool.h>

typedef struct {
    volatile uint8_t* portReg;
    volatile uint8_t* ddrReg;
    uint8_t motorPin;
    bool isMotorOn;
} Motor;

typedef Motor* MotorPtr;

MotorPtr motorSetup(volatile uint8_t* portReg, volatile uint8_t* ddrReg, uint8_t motorPin);
void motorTurnOn(MotorPtr, bool);
bool isMotorOn(MotorPtr);
void motorReleaseResources(MotorPtr);

#endif /* MOTOR_H_ */