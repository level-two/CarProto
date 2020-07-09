/*
 * stop.c
 *
 * Created: 29.05.2020 6:54:22
 *  Author: Yauheni
 */

#include "i2c/driver/driver.h"
#include "stop.h"
#include "idle.h"

void i2cTransitionToStop(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    i2cDriverSendStop();
    i2cTransitionToIdle(state);
}
