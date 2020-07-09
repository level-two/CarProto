/*
 * initial.c
 *
 * Created: 07.07.2020 16:53:14
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "initial.h"
#include "idle.h"
#include "transactionParams.h"

void i2cTransitionToInitial(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->transactionQueue = queueMake();
    state->transactionParams = NULL;
    state->transactionState.bytesTransferred = 0;
    i2cTransitionToIdle(state);
}