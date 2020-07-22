/*
 * motor.cbutton
 *
 * Created: 28.05.2020 10:50:24
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "motor.h"
#include "reference/reference.h"
#include "common/bitManipulations.h"

MotorPtr motorSetup(volatile uint8_t* portReg, volatile uint8_t* ddrReg, uint8_t motorPin) {
    MotorPtr motor = (MotorPtr) alloc(sizeof(Motor));
    if (motor == NULL) return NULL;

    autorelease(motor);

    motor->portReg = portReg;
    motor->ddrReg = ddrReg;
    motor->motorPin = motorPin;
    motor->isMotorOn = false;

    clearBit(motor->portReg, motor->motorPin);
    setBit(motor->ddrReg, motor->motorPin);
    return motor;
}

void motorTurnOn(MotorPtr motor, bool isOn) {
    motor->isMotorOn = isOn;
    writeBit(motor->ddrReg, motor->motorPin, isOn);
}

bool isMotorOn(MotorPtr motor) {
    return motor->isMotorOn;
}

void motorReleaseResources(MotorPtr motor) {
    if (motor == NULL) return;
    clearBit(motor->portReg, motor->motorPin);
    clearBit(motor->ddrReg, motor->motorPin);
}