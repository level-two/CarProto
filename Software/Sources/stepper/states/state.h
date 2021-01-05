/*
 * state.h
 *
 * Created: 13.05.2020 10:53:54
 *  Author: Yauheni
 */

#ifndef STEPPER_STATE_H_
#define STEPPER_STATE_H_

#include <stdbool.h>
#include <inttypes.h>
#include "../driver/driver.h"

typedef struct StepperState* StepperStatePtr;

typedef void (*StepperUpdateEvent)(StepperStatePtr, uint16_t);
typedef void (*StepperStepEvent)(StepperStatePtr, bool);
typedef void (*StepperEnableEvent)(StepperStatePtr, bool);
typedef void (*StepperReleaseEvent)(StepperStatePtr);

struct StepperState {
    StepperUpdateEvent update;
    StepperStepEvent step;
    StepperEnableEvent enable;
    StepperReleaseEvent release;

    bool isIdle;
    uint16_t duration;

    StepperConfigPtr config;
};

void defaultStepperStateImplementation(StepperStatePtr state);

#endif /* STEPPER_STATE_H_ */