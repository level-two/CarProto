/*
 * readData.h
 *
 * Created: 29.05.2020 6:57:04
 *  Author: Yauheni
 */


#ifndef I2C_STATE_READ_DATA_H_
#define I2C_STATE_READ_DATA_H_

#include <inttypes.h>
#include "state.h"

void i2cTransitionToReadData(I2CStatePtr);

#endif /* I2C_STATE_READ_DATA_H_ */