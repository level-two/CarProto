/*
 * completion.c
 *
 * Created: 31.05.2020 17:08:47
 *  Author: Yauheni
 */

#include "completion.h"
#include "idle.h"
#include "stop.h"

void i2cTransitionToCompletion(I2CStatePtr state, bool isSuccess) {
    i2cDefaultStateImplementation(state);
    state->completion(isSuccess);
    i2cTransitionToStop(state);
}