/*
 * transaction.h
 *
 * Created: 03.07.2020 15:47:22
 *  Author: Yauheni
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <inttypes.h>
#include <stdbool.h>

typedef struct I2CTransaction* I2CTransactionPtr;
typedef void (*I2CTransactionCompletion)(bool, uint8_t*, uint8_t);

struct I2CTransaction {
    bool write;
    uint8_t addr;
    uint8_t subaddr;
    uint8_t dataLen;
    uint8_t *data;
    I2CTransactionCompletion completion;
};

#endif /* TRANSACTION_H_ */