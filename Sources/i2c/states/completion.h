/*
 * completion.h
 *
 * Created: 31.05.2020 17:08:32
 *  Author: Yauheni
 */


#ifndef I2C_STATE_COMPLETION_H_
#define I2C_STATE_COMPLETION_H_

#include <stdbool.h>
#include "state.h"

void i2cTransitionToCompletion(I2CStatePtr state, bool isSuccess);

#endif /* I2C_STATE_COMPLETION_H_s */