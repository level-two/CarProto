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

typedef void (*UpdateEvent)(StepperStatePtr, uint16_t);
typedef void (*StepEvent)(StepperStatePtr, bool);
typedef void (*EnableEvent)(StepperStatePtr, bool);

struct StepperState {
    UpdateEvent update;
    StepEvent step;
    EnableEvent enable;

    bool isIdle;
    uint16_t duration;

    StepperConfigPtr config;
};

void defaultImplementation(StepperStatePtr state);

#endif /* STEPPER_STATE_H_ */