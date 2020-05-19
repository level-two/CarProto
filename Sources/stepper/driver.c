/*
 * driver.c
 *
 * Created: 09.05.2020 14:43:45
 *  Author: Yauheni
 */

#include "driver.h"
#include "common/bitManipulations.h"

void driverLayerSetup(StepperConfigPtr config) {
    // inputs with pullups
    setBits(config->portReg, bitVector2(config->letfStopperPin, config->rightStopperPin));

    // optputs
    setBits(config->ddrReg, bitVector3(config->dirPin, config->stepPin, config->sleepPin));
}

void driverLayerSetDir(StepperConfigPtr config, bool val) {
    writeBit(config->portReg, config->dirPin, val);
}

void driverLayerSetStep(StepperConfigPtr config, bool val) {
    writeBit(config->portReg, config->stepPin, val);
}

void driverLayerSetSleep(StepperConfigPtr config, bool val) {
    writeBit(config->portReg, config->sleepPin, val);
}

bool driverLayerLeftStopperStatus(StepperConfigPtr config) {
    return readBit(config->pinReg, config->letfStopperPin);
}

bool driverLayerRightStopperStatus(StepperConfigPtr config) {
    return readBit(config->pinReg, config->rightStopperPin);
}
