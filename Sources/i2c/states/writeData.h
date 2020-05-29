/*
 * writeData.h
 *
 * Created: 29.05.2020 6:56:48
 *  Author: Yauheni
 */


#ifndef I2C_STATE_WRITE_DATA_H_
#define I2C_STATE_WRITE_DATA_H_

#include <inttypes.h>
#include "state.h"

void i2cTransitionToWriteData(I2CStatePtr);

#endif /* I2C_STATE_WRITE_DATA_H_ */