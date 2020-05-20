/*
 * steer.c
 *
 * Created: 20.05.2020 6:27:27
 *  Author: Yauheni
 */

#include <stdlib.h>
//#include "steer.h"
//#include "stepperConfig.h"
//
//StepperHandlerPtr stepperSetup(
//volatile uint8_t* portReg,
//volatile uint8_t* ddrReg,
//volatile uint8_t* pinReg,
//uint8_t dirPin,
//uint8_t stepPin,
//uint8_t sleepPin,
//uint8_t letfStopperPin,
//uint8_t rightStopperPin) {
//
    //StepperConfigPtr config = (StepperConfigPtr) malloc(sizeof(StepperConfig));
    //if (config == NULL) {
        //return NULL;
    //}
//
    //config->portReg = portReg;
    //config->ddrReg = ddrReg;
    //config->pinReg = pinReg;
    //config->dirPin = dirPin;
    //config->stepPin = stepPin;
    //config->sleepPin = sleepPin;
    //config->letfStopperPin = letfStopperPin;
    //config->rightStopperPin = rightStopperPin;
//
    //StepperStatePtr stepperState = stepperSetup(config);
    //if (stepperState == NULL) {
        //free(config);
        //return NULL;
    //}
//
    //StepperHandlerPtr stepperHandler = (StepperHandlerPtr) malloc(sizeof(StepperHandler));
    //if (stepperHandler == NULL) {
        //free(stepperState);
        //free(config);
        //return NULL;
    //}
//
    //stepperHandler->stepperState = stepperState;
//
    //return stepperHandler;
//}
//
//void stepperEnable(StepperHandlerPtr stepperHandler, bool isEnabled) {
    //stepperEnable(stepperHandler->stepperState, isEnabled);
//}
//
//void stepperCalibrate(StepperHandlerPtr stepperHandler) {
//
//}
//
//void stepperPark(StepperHandlerPtr stepperHandler, StepperParkPosition position)
//{
    //// assert(minStep != maxStep)
//}
//
//StepperState stepperState(StepperHandlerPtr stepperHandler) {
    //return stepperStateDisabled;
//}
//
//StepperParkPosition stepperCurrentPosition(StepperHandlerPtr stepperHandler) {
    //return stepperParkedMiddle;
//}