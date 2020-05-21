/*
 * releaseState.c
 *
 * Created: 20.05.2020 13:30:10
 *  Author: Yauheni
 */

#include <stdbool.h>
#include <util/delay.h>
#include "release.h"
#include "../driver/driver.h"

void stepperTransitionToRelease(StepperStatePtr state) {
    defaultStepperStateImplementation(state);
    stepperDriverSetSleep(state->config, true);
    _delay_us(1);
    stepperDriverRelease(state->config);
}
