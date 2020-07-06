/*
 * transactionParams.h
 *
 * Created: 03.07.2020 15:47:22
 *  Author: Yauheni
 */

#ifndef TRANSACTION_PARAMS_H_
#define TRANSACTION_PARAMS_H_

#include <inttypes.h>
#include <stdbool.h>

typedef struct I2CTransactionParams* I2CTransactionParamsPtr;
typedef void (*I2CTransactionCompletion)(bool);

struct I2CTransactionParams {
    uint8_t addr;
    uint8_t command;
    uint8_t bytesCount;
    uint8_t *buffer;
    bool write;
    I2CTransactionCompletion completion;
};

#endif /* TRANSACTION_PARAMS_H_ */