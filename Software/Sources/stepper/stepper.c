/*
 * stepper.c
 *
 * Created: 08.05.2020 0:58:50
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "reference/reference.h"
#include "stepper.h"
#include "states/state.h"
#include "states/initial.h"
#include "driver/driver.h"

StepperStatePtr stepperSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin) {

    StepperConfigPtr config = (StepperConfigPtr) alloc(sizeof(StepperConfig));
    if (config == NULL) { return NULL; }
    autorelease(config);

    config->portReg = portReg;
    config->ddrReg = ddrReg;
    config->dirPin = dirPin;
    config->stepPin = stepPin;
    config->sleepPin = sleepPin;

    StepperStatePtr state = (StepperStatePtr) alloc(sizeof(struct StepperState));
    if (state == NULL) { return NULL; }
    autorelease(state);

    state->config = config;
    retain(config);

    stepperTransitionToInitial(state);

    return state;
}

void stepperReleaseResources(StepperStatePtr state) {
    if (state == NULL) { return; }
    state->release(state);

    release(state->config);
    state->config = NULL;
}

void stepperUpdate(StepperStatePtr state, uint16_t dt) {
    state->update(state, dt);
}

void stepperStep(StepperStatePtr state, StepperRotationDir dir) {
    state->step(state, (dir == stepCW) ? true : false);
}

void stepperEnable(StepperStatePtr state, bool isEnabled) {
    state->enable(state, isEnabled);
}

bool stepperIsBusy(StepperStatePtr state) {
    return !state->isIdle;
}
