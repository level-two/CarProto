/*
 * readData.c
 *
 * Created: 29.05.2020 6:57:11
 *  Author: Yauheni
 */

#include "readData.h"
#include "i2c/driver/driver.h"
#include "completion.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToReadData(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);

    state->acknowledge = acknowledge;
    state->transactionState.bytesTransferred = 0;

    // TODO: Put MACK on successful data reception
    // TODO: Is ACK polling acceptable here? How errors should be handled?
    // TODO: NMACK when data read is done
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (!isSuccess) {
        i2cTransitionToCompletion(state, false);
        return;
    }

    state->transactionState.bytesTransferred += 1;
    uint8_t readBytes = state->transactionState.bytesTransferred;
    uint8_t totalBytes = state->transactionParams.bytesCount;

    // get data
    uint8_t data = 0;
    state->transactionParams.buffer[readBytes-1] = data;

    if (readBytes < totalBytes) {
        i2cTransitionToReadData(state);
    } else {
        i2cTransitionToCompletion(state, true);
    }
}
