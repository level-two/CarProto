/*
 * state.c
 *
 * Created: 29.05.2020 7:14:25
 *  Author: Yauheni
 */

#include "state.h"
#include "common/unused.h"

static void defaultAcknowledge(I2CStatePtr, bool);
static void defaultWrite(I2CStatePtr, uint8_t, uint8_t*, uint8_t, I2CCompletionCallback);
static void defaultWriteRead(I2CStatePtr, uint8_t, uint8_t*, uint8_t, uint8_t*, uint8_t, I2CCompletionCallback);

void defaultI2CStateImplementation(I2CStatePtr state) {
    state->acknowledge = defaultAcknowledge;
    state->write = defaultWrite;
    state->writeRead = defaultWriteRead;

}

static void defaultAcknowledge(I2CStatePtr state, bool isSuccess) {
    UNUSED(state);
    UNUSED(isSuccess);
}

static void defaultWrite(I2CStatePtr state, uint8_t addr, uint8_t *data, uint8_t len, I2CCompletionCallback completion) {
    UNUSED(state);
    UNUSED(addr);
    UNUSED(data);
    UNUSED(len);
    UNUSED(completion);
}

static void defaultWriteRead(I2CStatePtr state, uint8_t addr, uint8_t *wrData, uint8_t wrLen, uint8_t *rdData, uint8_t rdLen, I2CCompletionCallback completion) {
    UNUSED(state);
    UNUSED(addr);
    UNUSED(wrData);
    UNUSED(wrLen);
    UNUSED(rdData);
    UNUSED(rdLen);
    UNUSED(completion);
}