/*
 * releaseState.c
 *
 * Created: 20.05.2020 13:30:10
 *  Author: Yauheni
 */

#include <stdbool.h>
#include <util/delay.h>
#include "releaseState.h"
#include "../driver/driver.h"

void transitionToRelease(StepperStatePtr state) {
    defaultImplementation(state);
    stepperDriverSetSleep(state->config, true);
    _delay_us(1);
    stepperDriverRelease(state->config);
}
