/*
 * writeData.c
 *
 * Created: 29.05.2020 7:12:56
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "writeData.h"
#include "i2c/driver/driver.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToWriteData(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);

    state->acknowledge = acknowledge;
    state->transactionState.bytesTransferred = 0;

    uint8_t data = state->transactionParams.buffer[0];
    // send data
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (!isSuccess) {
        i2cTransitionToCompletion(state, false);
        return;
    }

    state->transactionState.bytesTransferred += 1;
    uint8_t writtenBytes = state->transactionState.bytesTransferred;
    uint8_t totalBytes = state->transactionParams.bytesCount;

    if (writtenBytes < totalBytes) {
        i2cTransitionToWriteData(state);
    } else {
        i2cTransitionToCompletion(state, true);
    }
}
