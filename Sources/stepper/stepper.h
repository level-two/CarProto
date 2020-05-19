/*
 * stepper.h
 *
 * Created: 05.05.2020 17:40:07
 *  Author: Yauheni
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#include <stdbool.h>
#include "protocol.h"

typedef struct {
    ProtocolLayerStatePtr protocolState;
} StepperHandler;

typedef StepperHandler* StepperHandlerPtr;

typedef enum {
    stepperParkedLeft,
    stepperParkedRight,
    stepperParkedMiddle
} StepperParkPosition;

typedef enum {
    stepperStateIdle,
    stepperStateCalibrating,
    stepperStateParking,
    stepperStateDisabled
} StepperState;

StepperHandlerPtr stepperSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    volatile uint8_t* pinReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin,
    uint8_t letfStopperPin,
    uint8_t rightStopperPin);
void stepperEnable(StepperHandlerPtr, bool);
void stepperCalibrate(StepperHandlerPtr);
void stepperPark(StepperHandlerPtr, StepperParkPosition);
StepperState stepperState(StepperHandlerPtr);
StepperParkPosition stepperCurrentPosition(StepperHandlerPtr);

#endif /* STEPPER_H_ */