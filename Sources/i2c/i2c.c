/*
 * i2c.c
 *
 * Created: 29.05.2020 6:52:12
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "i2c.h"
#include "states/state.h"
#include "states/idle.h"
#include "states/transactionParams.h"

typedef struct Transaction* TransactionPtr;

struct Transaction {
    I2CTransactionParams params;
    I2COperationCompletion completion;
    TransactionPtr next;
};

static I2CStatePtr i2cState;
static TransactionPtr currentTransaction;

static void transactionCompleted(bool isSuccess);

void i2cConfigure() {
    i2cState = (I2CStatePtr) malloc(sizeof(struct I2CState));
    i2cTransitionToIdle(i2cState);
    currentTransaction = NULL;
}

void i2cTransaction(
    uint8_t addr,
    uint8_t command,
    uint8_t bytesCount,
    uint8_t *buffer,
    bool write,
    I2COperationCompletion completion)
{
    I2CTransactionParams params = {
        .addr = addr,
        .command = command,
        .bytesCount = bytesCount,
        .buffer = buffer,
        .write = write,
        .completion= transactionCompleted
    };

    TransactionPtr newTransaction = (TransactionPtr) malloc(sizeof(struct Transaction));
    newTransaction->params = params;
    newTransaction->completion = completion;
    newTransaction->next = NULL;

    if (currentTransaction == NULL) {
        currentTransaction = newTransaction;
        i2cState->newTransaction(i2cState, currentTransaction->params);
    } else {
        TransactionPtr last = currentTransaction;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newTransaction;
    }
}

static void transactionCompleted(bool isSuccess) {
    currentTransaction->completion(isSuccess);

    TransactionPtr next = currentTransaction->next;
    free(currentTransaction);
    currentTransaction = next;

    if (currentTransaction != NULL) {
        i2cState->newTransaction(i2cState, currentTransaction->params);
    }
}