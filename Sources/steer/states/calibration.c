/*
 * calibration.c
 *
 * Created: 22.05.2020 7:10:00
 *  Author: Yauheni
 */

#include "calibration.h"
#include "setPosition.h"
#include "steerPosition.h"
#include "stepper/stepper.h"
#include "button/button.h"

#define MOVE_LEFT_STEP_DIR stepCW
#define MOVE_RIGHT_STEP_DIR stepCCW

static void update(SteerStatePtr, uint16_t);

void steerTransitionToCalibration(SteerStatePtr state) {
    defaultSteerStateImplementation(state);
    state->update = update;
    state->destPosition = 0;
    state->totalSteps = 0;
}

static void update(SteerStatePtr state, uint16_t dt) {
    stepperUpdate(state->stepper, dt);

    if (stepperIsBusy(state->stepper)) { return; }

    if (state->destPosition == 0) {
        if (!buttonIsPressed(state->leftStopper)) {
            stepperStep(state->stepper, MOVE_LEFT_STEP_DIR);
        } else {
            state->destPosition = 1;
        }
    } else {
        if (!buttonIsPressed(state->rightStopper)) {
            stepperStep(state->stepper, MOVE_RIGHT_STEP_DIR);
            state->totalSteps++;
        } else {
            state->currentPosition = state->totalSteps;
            steerTransitionToSetPosition(state, steerPositionMiddle);
        }
    }
}