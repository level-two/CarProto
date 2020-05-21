/*
 * step.h
 *
 * Created: 13.05.2020 12:08:22
 *  Author: Yauheni
 */

#ifndef STEPPER_STEP_STATE_H_
#define STEPPER_STEP_STATE_H_

#include "state.h"

void stepperTransitionToStep(StepperStatePtr state, bool dir);

#endif /* STEPPER_STEP_STATE_H_ */