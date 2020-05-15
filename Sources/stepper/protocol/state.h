/*
 * state.h
 *
 * Created: 13.05.2020 10:53:54
 *  Author: Yauheni
 */


#ifndef STATE_H_
#define STATE_H_

#include <stdbool.h>
#include <avr/common.h>

typedef struct State *StatePtr;
typedef enum { left, right } StepDir;

typedef void (*UpdateEvent)(StatePtr, uint16_t);
typedef void (*StepEvent)(StatePtr, StepDir);
typedef void (*EnableEvent)(StatePtr, bool);

struct State {
    UpdateEvent update;
    StepEvent step;
    EnableEvent enable;

    bool isIdle;
    uint16_t duration;
};

void defaultImplementation(StatePtr state);

#endif /* STATE_H_ */