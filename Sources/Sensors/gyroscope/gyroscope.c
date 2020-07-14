/*
 * gyroscope.c
 *
 * Created: 10.07.2020 15:05:24
 *  Author: Yauheni
 */

#include <stdlib.h>
#include <stdbool.h>
#include "gyroscope.h"
#include "i2c/i2c.h"
#include "common/unused.h"
#include "l3g4200d.h"

static void onFifoSrcReg(bool, uint8_t*, uint8_t);
static void onData(bool, uint8_t*, uint8_t);

static GyroscopeDataCallback onDataReceived;

void gyroConfigure() {
    i2cWriteByte(ADDRESS, CTRL5_REG, (1 << FIFO_EN) | (0x3 << OUT_SEL), NULL);
    i2cWriteByte(ADDRESS, FIFO_CTRL_REG, (0x2 << FM), NULL);
    i2cWriteByte(ADDRESS, CTRL1_REG, (0x0 << DR) | (0x0 << BW) | (1 << PD) | (0x7 << ZYXEN), NULL);
}

void gyroOnDataReceived(GyroscopeDataCallback callback) {
    onDataReceived = callback;
}

void gyroRequestData() {
    i2cReadByte(ADDRESS, FIFO_SRC_REG, onFifoSrcReg);
}

static void onFifoSrcReg(bool isSuccess, uint8_t* data, uint8_t len) {
    UNUSED(len);
    if (!isSuccess) { return; }

    uint8_t fifoSrcReg = data[0];
    free(data);

    uint8_t availableDataLen = (fifoSrcReg & (0x1F << FSS)) >> FSS;

    if (availableDataLen == 0) {
        onDataReceived(NULL, 0);
        return;
    }

    i2cRead(ADDRESS, DATA_OUT_BASE_REG, 6 * availableDataLen, onData);
}

static void onData(bool isSuccess, uint8_t* data, uint8_t len) {
    if (!isSuccess) { return; }
    onDataReceived(data, len);
}
