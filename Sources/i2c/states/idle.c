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

static void addTransaction(I2CStatePtr, uint8_t, uint8_t, uint8_t, uint8_t*, bool, I2CTransactionCompletion);

void i2cTransitionToIdle(I2CStatePtr state) {
    i2cDefaultStateImplementation(state);
    state->addTransaction = addTransaction;
    state->transactionState.bytesTransferred = 0;

    if (state->transactionParams != NULL) {
        free(state->transactionParams);
        state->transactionParams = NULL;
    }

    if (!queueIsEmpty(state->transactionQueue)) {
        state->transactionParams = (I2CTransactionParamsPtr) queuePopFront(state->transactionQueue);
        i2cTransitionToStart(state);
    }
}

static void addTransaction(
    I2CStatePtr state,
    uint8_t addr,
    uint8_t command,
    uint8_t bytesCount,
    uint8_t *buffer,
    bool write,
    I2CTransactionCompletion completion)
{
    I2CTransactionParamsPtr params = (I2CTransactionParamsPtr) malloc(sizeof(struct I2CTransactionParams));
    params->addr = addr;
    params->command = command;
    params->bytesCount = bytesCount;
    params->buffer = buffer;
    params->write = write;
    params->completion = completion;

    state->transactionParams = params;

    i2cTransitionToStart(state);
}
