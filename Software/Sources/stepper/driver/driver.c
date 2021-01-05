/*
 * driver.c
 *
 * Created: 09.05.2020 14:43:45
 *  Author: Yauheni
 */

#include "driver.h"
#include "common/bitManipulations.h"

void stepperDriverSetup(StepperConfigPtr config) {
    // to avoid glitch on sleep signal during port configuration
    // prepare it to be high when switched to output mode
    writeBit(config->portReg, config->sleepPin, true);
    setBits(config->ddrReg, bitVector3(config->dirPin, config->stepPin, config->sleepPin));
}

void stepperDriverRelease(StepperConfigPtr config) {
    clearBits(config->ddrReg, bitVector3(config->dirPin, config->stepPin, config->sleepPin));
    // make sure all pins are in HiZ-state
    clearBits(config->portReg, bitVector3(config->dirPin, config->stepPin, config->sleepPin));
}

void stepperDriverSetDir(StepperConfigPtr config, bool val) {
    writeBit(config->portReg, config->dirPin, val);
}

void stepperDriverSetStep(StepperConfigPtr config, bool val) {
    writeBit(config->portReg, config->stepPin, val);
}

void stepperDriverSetSleep(StepperConfigPtr config, bool val) {
    writeBit(config->portReg, config->sleepPin, !val);
}