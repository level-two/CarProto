/*
 * readData.c
 *
 * Created: 29.05.2020 6:57:11
 *  Author: Yauheni
 */

#include "readData.h"
#include "i2c/driver/driver.h"
#include "completion.h"
#include "readAck.h"
#include "readNack.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToReadData(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->acknowledge = acknowledge;
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (!isSuccess) {
        i2cTransitionToCompletion(state, false);
        return;
    }

    state->transactionState.bytesTransferred += 1;
    uint8_t readBytes = state->transactionState.bytesTransferred;
    uint8_t totalBytes = state->transactionParams->bytesCount;

    uint8_t data = i2cDriverGetReceivedData();
    state->transactionParams->buffer[readBytes-1] = data;

    if (readBytes < totalBytes) {
        i2cTransitionToReadAck(state);
    } else {
        i2cTransitionToReadNack(state);
    }
}
