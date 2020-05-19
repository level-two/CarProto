/*
 * stepper.c
 *
 * Created: 08.05.2020 0:58:50
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "stepper.h"
#include "stepperConfig.h"

StepperHandlerPtr stepperSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    volatile uint8_t* pinReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin,
    uint8_t letfStopperPin,
    uint8_t rightStopperPin) {

    StepperConfigPtr config = (StepperConfigPtr) malloc(sizeof(StepperConfig));
    if (config == NULL) {
        return NULL;
    }

    config->portReg = portReg;
    config->ddrReg = ddrReg;
    config->pinReg = pinReg;
    config->dirPin = dirPin;
    config->stepPin = stepPin;
    config->sleepPin = sleepPin;
    config->letfStopperPin = letfStopperPin;
    config->rightStopperPin = rightStopperPin;

    ProtocolLayerStatePtr protocolState = protocolLayerSetup(config);
    if (protocolState == NULL) {
        free(config);
        return NULL;
    }

    StepperHandlerPtr stepperHandler = (StepperHandlerPtr) malloc(sizeof(StepperHandler));
    if (stepperHandler == NULL) {
        free(protocolState);
        free(config);
        return NULL;
    }

    stepperHandler->protocolState = protocolState;

    return stepperHandler;
}

void stepperEnable(StepperHandlerPtr stepperHandler, bool isEnabled) {
    protocolLayerEnable(stepperHandler->protocolState, isEnabled);
}

void stepperCalibrate(StepperHandlerPtr stepperHandler) {

}

void stepperPark(StepperHandlerPtr stepperHandler, StepperParkPosition position)
{
    // assert(minStep != maxStep)
}

StepperState stepperState(StepperHandlerPtr stepperHandler) {
    return stepperStateDisabled;
}

StepperParkPosition stepperCurrentPosition(StepperHandlerPtr stepperHandler) {
    return stepperParkedMiddle;
}