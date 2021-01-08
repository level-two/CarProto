/*
 * initial.c
 *
 * Created: 21.05.2020 11:57:36
 *  Author: Yauheni
 */

#include "initial.h"
#include "calibration.h"

void steerTransitionToInitial(SteerStatePtr state) {
    defaultSteerStateImplementation(state);

    state->currentPosition = 0;
    state->totalSteps = 0;

    steerTransitionToCalibration(state);
}