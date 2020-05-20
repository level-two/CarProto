/*
 * initialState.h
 *
 * Created: 13.05.2020 10:55:15
 *  Author: Yauheni
 */

#ifndef STEPPER_INITIAL_STATE_H_
#define STEPPER_INITIAL_STATE_H_

#include "state.h"
#include "../driver/driver.h"

void transitionToInitial(StepperStatePtr, StepperConfigPtr);

#endif /* STEPPER_INITIAL_STATE_H_ */