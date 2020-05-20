/*
 * state.c
 *
 * Created: 20.05.2020 12:48:34
 *  Author: Yauheni
 */

#include <inttypes.h>
#include "state.h"

static void defaultUpdate(SteerStatePtr state, uint16_t dt) { }

void defaultImplementation(SteerStatePtr state) {
    state->update = defaultUpdate;
}