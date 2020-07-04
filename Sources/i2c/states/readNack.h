/*
 * readNack.h
 *
 * Created: 04.07.2020 18:17:02
 *  Author: Yauheni
 */

#ifndef I2C_STATE_READ_NACK_H_
#define I2C_STATE_READ_NACK_H_

#include "state.h"

void i2cTransitionToReadNack(I2CStatePtr);

#endif /* I2C_STATE_READ_NACK_H_ */
