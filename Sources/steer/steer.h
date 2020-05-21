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

SteerStatePtr steerSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    volatile uint8_t* pinReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin,
    uint8_t letfStopperPin,
    uint8_t rightStopperPin);



//#include "stepper.h"
//
//typedef struct {
    //StepperStatePtr stepperState;
//} StepperHandler;
//
//typedef StepperHandler* StepperHandlerPtr;
//
//typedef enum {
    //stepperParkedLeft,
    //stepperParkedRight,
    //stepperParkedMiddle
//} StepperParkPosition;
//
//typedef enum {
    //stepperStateIdle,
    //stepperStateCalibrating,
    //stepperStateParking,
    //stepperStateDisabled
//} StepperState;
//
//StepperHandlerPtr stepperSetup(
//volatile uint8_t* portReg,
//volatile uint8_t* ddrReg,
//volatile uint8_t* pinReg,
//uint8_t dirPin,
//uint8_t stepPin,
//uint8_t sleepPin,
//uint8_t letfStopperPin,
//uint8_t rightStopperPin);
//void stepperEnable(StepperHandlerPtr, bool);
//void stepperCalibrate(StepperHandlerPtr);
//void stepperPark(StepperHandlerPtr, StepperParkPosition);
//StepperState stepperState(StepperHandlerPtr);
//StepperParkPosition stepperCurrentPosition(StepperHandlerPtr);

#endif /* STEER_H_ */