/*
 * idle.c
 *
 * Created: 29.05.2020 6:52:52
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "idle.h"
#include "start.h"

static void write(I2CStatePtr, uint8_t, uint8_t*, uint8_t, I2CCompletionCallback);
static void writeRead(I2CStatePtr, uint8_t, uint8_t*, uint8_t, uint8_t*, uint8_t, I2CCompletionCallback);

void i2cTransitionToIdle(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);

    state->write = write;
    state->writeRead = writeRead;

    state->addr = 0;
    state->wrData = NULL;
    state->wrLen = 0;
    state->wrData = NULL;
    state->wrLen = 0;
    state->completion = NULL;
}

static void write(
    I2CStatePtr state,
    uint8_t addr,
    uint8_t *data,
    uint8_t len,
    I2CCompletionCallback completion)
{
    state->addr = addr;
    state->wrData = data;
    state->wrLen = len;
    state->completion = completion;
    i2cTransitionToStart(state);
}

static void writeRead(
    I2CStatePtr state,
    uint8_t addr,
    uint8_t *wrData,
    uint8_t wrLen,
    uint8_t *rdData,
    uint8_t rdLen,
    I2CCompletionCallback completion)
{
    state->addr = addr;
    state->wrData = wrData;
    state->wrLen = wrLen;
    state->wrData = rdData;
    state->wrLen = rdLen;
    state->completion =completion;
    i2cTransitionToStart(state);
}
