/*
 * repeatedStart.c
 *
 * Created: 29.05.2020 6:54:07
 *  Author: Yauheni
 */

#include "repeatedStart.h"
#include "addressForRead.h"
#include "error.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToRepeatedStart(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;

}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (isSuccess) {
        i2cTransitionToAddressForRead(state);
    } else {
        i2cTransitionToError(state);
    }
}


