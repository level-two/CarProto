/*
 * idle.c
 *
 * Created: 29.05.2020 6:52:52
 *  Author: Yauheni
 */

#include "idle.h"

void i2cTransitionToIdle(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
}
