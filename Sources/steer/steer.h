/*
 * steer.h
 *
 * Created: 20.05.2020 6:27:17
 *  Author: Yauheni
 */

#ifndef STEER_H_
#define STEER_H_

#include <stdbool.h>
#include <inttypes.h>
#include "states/state.h"
#include "states/steerPosition.h"

SteerStatePtr steerSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    volatile uint8_t* pinReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin,
    uint8_t letfStopperPin,
    uint8_t rightStopperPin);

void steerRelease(SteerStatePtr);
void steerUpdate(SteerStatePtr, uint16_t);
void steerSetPosition(SteerStatePtr, SteerPosition);
SteerPosition steerCurrentPosition(SteerStatePtr);
bool steerIsBusy(SteerStatePtr);

#endif /* STEER_H_ */