/*
 * state.c
 *
 * Created: 20.05.2020 12:48:34
 *  Author: Yauheni
 */

#include <inttypes.h>
#include "state.h"

static void defaultUpdate(SteerStatePtr state, uint16_t dt) { }
static void defaultSetPosition(SteerStatePtr state, SteerPosition position) { }

void defaultSteerStateImplementation(SteerStatePtr state) {
    state->update = defaultUpdate;
    state->setPosition = defaultSetPosition;
    state->isIdle = false;
}