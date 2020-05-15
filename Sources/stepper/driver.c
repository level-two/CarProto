/*
 * driver.c
 *
 * Created: 09.05.2020 14:43:45
 *  Author: Yauheni
 */

#include <avr/io.h>
#include "driver.h"
#include "common/bitManipulations.h"
#include "wiring.h"

void driverLayerSetup() {
    setBits(&DRIVER_DDR_REG, bitVector3(DRIVER_DIR_PIN, DRIVER_STEP_PIN, DRIVER_SLEEP_PIN));

    // inputs with pull ups
    clearBits(&DRIVER_DDR_REG, bitVector2(DRIVER_LEFT_STOPPER_PIN, DRIVER_RIGHT_STOPPER_PIN));
    setBits(&DRIVER_PORT_REG, bitVector2(DRIVER_LEFT_STOPPER_PIN, DRIVER_RIGHT_STOPPER_PIN));
}

void driverLayerSetDir(bool val) {
    writeBit(&DRIVER_PORT_REG, DRIVER_DIR_PIN, val);
}

void driverLayerSetStep(bool val) {
    writeBit(&DRIVER_PORT_REG, DRIVER_STEP_PIN, val);
}

void driverLayerSetSleep(bool val) {
    writeBit(&DRIVER_PORT_REG, DRIVER_SLEEP_PIN, val);
}

bool driverLayerLeftStopperStatus() {
    return readBit(&DRIVER_PIN_REG, DRIVER_LEFT_STOPPER_PIN);
}

bool driverLayerRightStopperStatus() {
    return readBit(&DRIVER_PIN_REG, DRIVER_RIGHT_STOPPER_PIN);
}
