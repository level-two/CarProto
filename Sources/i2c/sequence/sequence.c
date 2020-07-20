/*
 * i2cSequence.c
 *
 * Created: 10.07.2020 18:17:36
 *  Author: Yauheni
 */

#include <inttypes.h>
#include <stdlib.h>
#include "reference/reference.h"
#include "sequence.h"
#include "../driver/driver.h"

typedef enum {
    start,
    repeatedStart,
    addressForWrite,
    addressForRead,
    subAddress,
    writeData,
    readData,
    dataReceived,
    stop
} I2CSequenceStep;

static I2CTransactionPtr params;
static SequenceCompletion sequenceCompleted;
static I2CSequenceStep currentStep;
static uint8_t transferredBytes;
static bool inProgress = false;

static void i2cOperationCompleted(bool);
static I2CSequenceStep nextStep();
static void performStep();
static void finishTransaction(bool);


void i2cSequenceSetup() {
    i2cDriverOnOperationCompleted(i2cOperationCompleted);
}

void i2cSequenceSetCompletion(SequenceCompletion callback) {
    sequenceCompleted = callback;
}

void i2cSequenceStratTransaction(I2CTransactionPtr parameters) {
    params = parameters;
    retain(params);
    retain(params->data);

    transferredBytes = 0;
    inProgress = true;

    currentStep = start;
    performStep();
}

bool i2cSequenceInProgress() {
    return inProgress;
}

static void i2cOperationCompleted(bool isSuccess) {
    if (isSuccess) {
        currentStep = nextStep();
        performStep();
    } else {
        finishTransaction(false);
    }
}

static I2CSequenceStep nextStep() {
    switch (currentStep) {
    case start:
        return addressForWrite;
    case repeatedStart:
        return addressForRead;
    case addressForWrite:
        return subAddress;
    case addressForRead:
        return readData;
    case subAddress:
        return params->write ? writeData : repeatedStart;
    case writeData:
        return (transferredBytes < params->dataLen) ? writeData : stop;
    case readData:
        return dataReceived;
    case dataReceived:
        return (transferredBytes < params->dataLen) ? readData : stop;
    default:
        return currentStep;
    }
}

static void performStep() {
    switch (currentStep) {
    case start:
        i2cDriverSendStart();
        break;
    case repeatedStart:
        i2cDriverSendRepeatedStart();
        break;
    case addressForWrite:
        i2cDriverSendAddrForWrite(params->addr);
        break;
    case addressForRead:
        i2cDriverSendAddrForRead(params->addr);
        break;
    case subAddress:
        i2cDriverSendData(params->subaddr);
        break;
    case writeData:
        i2cDriverSendData(params->data[transferredBytes]);
        ++transferredBytes;
        break;
    case readData:
        i2cDriverReadData(transferredBytes == params->dataLen-1);
        break;
    case dataReceived:
        params->data[transferredBytes] = i2cDriverGetReceivedData();
        ++transferredBytes;
        break;
    case stop:
        i2cDriverSendStop();
        finishTransaction(true);
        break;
    }
}

static void finishTransaction(bool isSuccess) {
    release(params->data);
    release(params);
    params = NULL;

    inProgress = false;

    if (sequenceCompleted != NULL) {
        sequenceCompleted(isSuccess);
    }
}
