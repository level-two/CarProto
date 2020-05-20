/*
 * stepper.c
 *
 * Created: 08.05.2020 0:58:50
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "stepper.h"
#include "states/state.h"
#include "states/initialState.h"
#include "driver/driver.h"

StepperStatePtr stepperSetup(
    volatile uint8_t* portReg,
    volatile uint8_t* ddrReg,
    uint8_t dirPin,
    uint8_t stepPin,
    uint8_t sleepPin) {

    StepperConfigPtr config = (StepperConfigPtr) malloc(sizeof(StepperConfig));
    if (config == NULL) { return NULL; }

    config->portReg = portReg;
    config->ddrReg = ddrReg;
    config->dirPin = dirPin;
    config->stepPin = stepPin;
    config->sleepPin = sleepPin;

    StepperStatePtr state = (StepperStatePtr) malloc(sizeof(struct StepperState));
    if (state == NULL) {
        free(config);
        return NULL;
    }

    state->config = config;
    transitionToInitial(state);

    return state;
}

void stepperRelease(StepperStatePtr state) {
    state->release(state);
    free(state);
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
