/*
 * start.c
 *
 * Created: 29.05.2020 6:54:15
 *  Author: Yauheni
 */

#include "start.h"
#include "addressForWrite.h"
#include "error.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToStart(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;

}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToAddress(state);
    } else {
        i2cTransitionToError(state);
    }
}


