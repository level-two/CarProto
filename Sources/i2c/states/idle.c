/*
 * idle.c
 *
 * Created: 29.05.2020 6:52:52
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "idle.h"
#include "start.h"
#include "transactionParams.h"

static void newTransaction(I2CStatePtr, I2CTransactionParams);

void i2cTransitionToIdle(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->newTransaction = newTransaction;
    state->transactionState.bytesTransferred = 0;
}

static void newTransaction(I2CStatePtr state, I2CTransactionParams params) {
    state->transactionParams = params;
    i2cTransitionToStart(state);
}
