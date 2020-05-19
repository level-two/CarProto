/*
 * stepperConfig.h
 *
 * Created: 19.05.2020 6:36:57
 *  Author: Yauheni
 */


#ifndef STEPPERCONFIG_H_
#define STEPPERCONFIG_H_

#include <inttypes.h>

typedef struct {
    volatile uint8_t* portReg;
    volatile uint8_t* ddrReg;
    volatile uint8_t* pinReg;
    uint8_t dirPin;
    uint8_t stepPin;
    uint8_t sleepPin;
    uint8_t letfStopperPin;
    uint8_t rightStopperPin;
} StepperConfig;

typedef StepperConfig *StepperConfigPtr;

#endif /* STEPPERCONFIG_H_ */