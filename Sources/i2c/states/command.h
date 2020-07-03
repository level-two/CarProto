/*
 * command.h
 *
 * Created: 29.05.2020 6:56:48
 *  Author: Yauheni
 */


#ifndef I2C_STATE_COMMAND_H_
#define I2C_STATE_COMMAND_H_

#include <inttypes.h>
#include "state.h"

void i2cTransitionToCommand(I2CStatePtr);

#endif /* I2C_STATE_COMMAND_H_ */