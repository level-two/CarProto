/*
 * writeData.c
 *
 * Created: 29.05.2020 7:12:56
 *  Author: Yauheni
 */

#include "writeData.h"
#include "start.h"

void i2cTransitionToWriteData(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);

    state->acknowledge = acknowledge
    state->bytesCount = 0;

    uint8_t data = state->wrData[state->bytesCount]
    // send data
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (!isSuccess) {
        i2cTransitionToError(state);
        return;
    }

    state->bytesCount += 1;

    if (state->bytesCount < state->wrLen) {
        i2cTransitionToWriteData(state);
    } else if (state->isRead) {
        i2cTransitionToRepeatedStart(state);
    } else {
        i2cTransitionToComplete(state);
    }

}
