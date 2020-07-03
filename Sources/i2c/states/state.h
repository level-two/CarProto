/*
 * state.h
 *
 * Created: 29.05.2020 7:14:33
 *  Author: Yauheni
 */

#ifndef I2C_STATE_H_
#define I2C_STATE_H_

#include <inttypes.h>
#include <stdbool.h>

typedef struct I2CState* I2CStatePtr;
typedef struct TransactionParams TransactionParams;

typedef void (*I2CCompletionCallback)(bool);
typedef void (*I2CAcknowledgeEvent)(I2CStatePtr, bool);
typedef void (*I2CTransactionEvent)(I2CStatePtr, TransactionParams);

struct TransactionParams {
    uint8_t addr;
    uint8_t command;
    uint8_t bytesCount;
    uint8_t *buffer;
    bool write;
    I2COperationCompletion completion;
};

struct TransactionState {
    uint8_t bytesTransferred;
};

struct I2CState {
    I2CAcknowledgeEvent acknowledge;
    I2CTransactionEvent newTransaction;

    struct TransactionParams transactionParams;
    struct TransactionState transactionState;
};

void i2cDefaultStateImplementation(I2CStatePtr state);

#endif /* I2C_STATE_H_ */