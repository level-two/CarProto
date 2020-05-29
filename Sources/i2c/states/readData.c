/*
 * readData.c
 *
 * Created: 29.05.2020 6:57:11
 *  Author: Yauheni
 */

#include "readData.h"
#include "repeatedStart.h"

static void acknowledge(I2CStatePtr, bool);

void i2cTransitionToReadData(I2CStatePtr state, ) {
    i2cDefaultStateImplementation(state);

    state->acknowledge = acknowledge
    state->bytesCount = 0;


    // TODO: Put MACK on successful data reception
    // TODO: Is ACK polling acceptable here? How errors should be handled?
}

static void acknowledge(I2CStatePtr state, bool isSuccess) {
    if (!isSuccess) {
        i2cTransitionToError(state);
        return;
    }

    // get data
    uint8_t data = 0;
    uint8_t readBytes = state->bytesCount;
    state->rdData[readBytes] = data;

    state->bytesCount += 1;

    if (state->bytesCount < state->rdLen) {
        i2cTransitionToReadData(state);
    } else {
        i2cTransitionToComplete(state);
    }

}
