/*
 * state.c
 *
 * Created: 20.05.2020 12:48:34
 *  Author: Yauheni
 */

#include <inttypes.h>
#include "state.h"
#include "common/unused.h"

static void defaultUpdate(SteerStatePtr, uint16_t);
static void defaultSetPosition(SteerStatePtr, SteerPosition);

void defaultSteerStateImplementation(SteerStatePtr state) {
    state->update = defaultUpdate;
    state->setPosition = defaultSetPosition;
    state->isIdle = false;
}

static void defaultUpdate(SteerStatePtr state, uint16_t dt) {
    UNUSED(state);
    UNUSED(dt);
}

static void defaultSetPosition(SteerStatePtr state, SteerPosition position) {
    UNUSED(state);
    UNUSED(position);
}