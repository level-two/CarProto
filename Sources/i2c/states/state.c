/*
 * state.c
 *
 * Created: 29.05.2020 7:14:25
 *  Author: Yauheni
 */

#include "state.h"
#include "common/unused.h"

static void defaultAcknowledge(I2CStatePtr, bool);
static void defaultNewTransaction(I2CStatePtr, I2CTransactionParams);

void defaultI2CStateImplementation(I2CStatePtr state) {
    state->acknowledge = defaultAcknowledge;
    state->newTransaction = defaultNewTransaction;
}

static void defaultAcknowledge(I2CStatePtr state, bool isSuccess) {
    UNUSED(state);
    UNUSED(isSuccess);
}

static void defaultNewTransaction(I2CStatePtr state, I2CTransactionParams transactionParams) {
    UNUSED(state);
    UNUSED(transactionParams);
}
