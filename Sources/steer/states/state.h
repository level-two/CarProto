/*
 * state.h
 *
 * Created: 20.05.2020 12:48:45
 *  Author: Yauheni
 */

#ifndef STEER_STATE_H_
#define STEER_STATE_H_

#include <inttypes.h>
#include "button/button.h"
#include "stepper/stepper.h"

typedef struct SteerState* SteerStatePtr;

typedef void (*UpdateEvent)(SteerStatePtr, uint16_t);

struct SteerState {
    UpdateEvent update;

    StepperStatePtr stepper;
    ButtonPtr leftStopper;
    ButtonPtr rightStopper;
};

void defaultImplementation(SteerStatePtr state);

#endif /* STEER_STATE_H_ */