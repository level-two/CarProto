/*
 * state.c
 *
 * Created: 29.05.2020 7:14:25
 *  Author: Yauheni
 */

#include "state.h"
#include "common/unused.h"

static void defaultAcknowledge(I2CStatePtr);
static void defaultWrite(I2CStatePtr, uint8_t, uint8_t*, uint8_t)
static void defaultRead(I2CStatePtr, uint8_t, uint8_t*, uint8_t, uint8_t*, uint8_t);

void defaultI2CStateImplementation(I2CStatePtr state) {
    state->acknowledge = defaultAcknowledge;
    state->write = defaultWrite;
    state->read = defaultRead;

}

static void defaultAcknowledge(I2CStatePtr state) {
    UNUSED(state);
}

static void defaultWrite(I2CStatePtr state, uint8_t addr, uint8_t *data, uint8_t len) {
    UNUSED(state);
    UNUSED(addr);
    UNUSED(data);
    UNUSED(len);
}

static void defaultRead(I2CStatePtr state,
    uint8_t addr, uint8_t *wrData, uint8_t wrLen,
    uint8_t *rdData, uint8_t rdLen) {
    UNUSED(state);
    UNUSED(addr);
    UNUSED(wrData);
    UNUSED(wrLen);
    UNUSED(rdData);
    UNUSED(rdLen);
}