/*
 * i2cSequence.h
 *
 * Created: 10.07.2020 19:37:05
 *  Author: Yauheni
 */


#ifndef I2C_SEQUENCE_H_
#define I2C_SEQUENCE_H_

#include <stdbool.h>
#include "transaction.h"

typedef void (*SequenceCompletion)(bool);

void i2cSequenceSetup();
void i2cSequenceSetCompletion(SequenceCompletion callback);
void i2cSequenceStratTransaction(I2CTransactionPtr parameters);
bool i2cSequenceInProgress();

#endif /* I2C_SEQUENCE_H_ */