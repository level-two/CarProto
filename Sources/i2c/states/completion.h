/*
 * completion.h
 *
 * Created: 31.05.2020 17:08:32
 *  Author: Yauheni
 */


#ifndef COMPLETION_H_
#define COMPLETION_H_

#include <inttypes.h>
#include "state.h"

void i2cTransitionToCompletion(I2CStatePtr state, bool isSuccess);

#endif /* COMPLETION_H_ */