/*
 * idle.c
 *
 * Created: 29.05.2020 6:52:52
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "idle.h"
#include "start.h"

static void newTransaction(I2CStatePtr, TransactionParams);

void i2cTransitionToIdle(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->newTransaction = newTransaction;
}

static void newTransaction(I2CStatePtr state, TransactionParams params) {
    state->transactionParams = params;
    i2cTransitionToStart(state);
}
