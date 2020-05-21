/*
 * initial.c
 *
 * Created: 21.05.2020 11:57:36
 *  Author: Yauheni
 */

#include "initial.h"
#include "idle.h"

void steerTransitionToInitial(SteerStatePtr state) {
    defaultSteerStateImplementation(state);

    steerTransitionToIdle(state);
}