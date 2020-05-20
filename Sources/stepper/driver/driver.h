/*
 * driver.h
 *
 * Created: 08.05.2020 0:09:30
 *  Author: Yauheni
 */

#ifndef STEPPER_DRIVER_H_
#define STEPPER_DRIVER_H_

#include <stdbool.h>
#include <inttypes.h>

typedef struct {
    volatile uint8_t* portReg;
    volatile uint8_t* ddrReg;
    uint8_t dirPin;
    uint8_t stepPin;
    uint8_t sleepPin;
} StepperConfig;

typedef StepperConfig *StepperConfigPtr;

void stepperDriverSetup(StepperConfigPtr);
void stepperDriverSetStep(StepperConfigPtr, bool);
void stepperDriverSetDir(StepperConfigPtr, bool);
void stepperDriverSetSleep(StepperConfigPtr, bool);

#endif /* STEPPER_DRIVER_H_ */