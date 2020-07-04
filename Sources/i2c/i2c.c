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
static TransactionPtr transactionQueueHead;

static TransactionPtr currentTransaction();
static void pushBack(TransactionPtr);
static TransactionPtr popFront();

static TransactionPtr makeTransaction(uint8_t, uint8_t, uint8_t, uint8_t*, bool, I2COperationCompletion);
static void release(TransactionPtr);
static void execute(TransactionPtr);
static void transactionCompleted(bool);


void i2cConfigure() {
    i2cState = (I2CStatePtr) malloc(sizeof(struct I2CState));
    i2cTransitionToIdle(i2cState);
    transactionQueueHead = NULL;
}

void i2cTransaction(
    uint8_t addr,
    uint8_t command,
    uint8_t bytesCount,
    uint8_t *buffer,
    bool write,
    I2COperationCompletion completion)
{
    TransactionPtr transaction = makeTransaction(addr, command, bytesCount, buffer, write, completion);
    pushBack(transaction);
    execute(currentTransaction());
}


static TransactionPtr makeTransaction(
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
        .completion = transactionCompleted
    };

    TransactionPtr transaction = (TransactionPtr) malloc(sizeof(struct Transaction));
    transaction->params = params;
    transaction->completion = completion;
    transaction->next = NULL;

    return transaction;
}

static void transactionCompleted(bool isSuccess) {
    TransactionPtr transaction = popFront();
    transaction->completion(isSuccess);
    release(transaction);
    execute(currentTransaction());
}

static void pushBack(TransactionPtr transaction) {
    if (transactionQueueHead == NULL) {
        transactionQueueHead = transaction;
    } else {
        TransactionPtr last = transactionQueueHead;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = transaction;
    }
}

static TransactionPtr popFront() {
    TransactionPtr transaction = transactionQueueHead;
    transactionQueueHead = transactionQueueHead->next;
    return transaction;
}

static void release(TransactionPtr transaction) {
    free(transaction);
}

static TransactionPtr currentTransaction() {
    return transactionQueueHead;
}

static void execute(TransactionPtr transaction) {
    if (transaction != NULL) {
        i2cState->newTransaction(i2cState, transaction->params);
    }
}
