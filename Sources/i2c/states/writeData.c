/*
 * writeData.c
 *
 * Created: 29.05.2020 7:12:56
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "writeData.h"
#include "i2c/driver/driver.h"
#include "repeatedStart.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToWriteData(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);

    state->acknowledge = acknowledge;
    state->bytesCount = 0;

    uint8_t data = state->wrData[state->bytesCount];
    // send data
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (!isSuccess) {
        i2cTransitionToCompletion(state, false);
        return;
    }

    state->bytesCount += 1;

    if (state->bytesCount < state->wrLen) {
        i2cTransitionToWriteData(state);
    } else if (state->rdLen > 0 && state->rdData != NULL) {
        i2cTransitionToRepeatedStart(state);
    } else {
        i2cTransitionToCompletion(state, true);
    }

}
