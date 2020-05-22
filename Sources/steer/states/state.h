/*
 * state.h
 *
 * Created: 20.05.2020 12:48:45
 *  Author: Yauheni
 */

#ifndef STEER_STATE_H_
#define STEER_STATE_H_

#include <inttypes.h>
#include <stdbool.h>
#include "button/button.h"
#include "stepper/stepper.h"
#include "steerPosition.h"

typedef struct SteerState* SteerStatePtr;

typedef void (*SteerUpdateEvent)(SteerStatePtr, uint16_t);
typedef void (*SteerSetPositionEvent)(SteerStatePtr, SteerPosition);

struct SteerState {
    SteerUpdateEvent update;
    SteerSetPositionEvent setPosition;

    bool isIdle;

    uint16_t destPosition;
    uint16_t currentPosition;
    uint16_t totalSteps;

    // configuration
    StepperStatePtr stepper;
    ButtonPtr leftStopper;
    ButtonPtr rightStopper;
};

void defaultSteerStateImplementation(SteerStatePtr state);

#endif /* STEER_STATE_H_ */