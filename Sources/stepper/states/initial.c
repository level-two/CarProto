/*
 * initialState.c
 *
 * Created: 13.05.2020 10:55:31
 *  Author: Yauheni
 */

#include "initial.h"
#include "idle.h"
#include "../driver/driver.h"

void stepperTransitionToInitial(StepperStatePtr state) {
    defaultStepperStateImplementation(state);
    stepperDriverSetup(state->config);
    stepperTransitionToIdle(state);
}
