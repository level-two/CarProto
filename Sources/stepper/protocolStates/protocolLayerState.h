/*
 * state.h
 *
 * Created: 13.05.2020 10:53:54
 *  Author: Yauheni
 */


#ifndef PROTOCOLLAYERSTATE_H_
#define PROTOCOLLAYERSTATE_H_

#include <stdbool.h>
#include <inttypes.h>
#include "stepper/stepperConfig.h"

typedef struct ProtocolLayerState* ProtocolLayerStatePtr;

typedef enum { stepperDirLeft, stepperDirRight } StepDir;

typedef void (*UpdateEvent)(ProtocolLayerStatePtr, uint16_t);
typedef void (*StepEvent)(ProtocolLayerStatePtr, StepDir);
typedef void (*EnableEvent)(ProtocolLayerStatePtr, bool);

struct ProtocolLayerState {
    UpdateEvent update;
    StepEvent step;
    EnableEvent enable;

    bool isIdle;
    uint16_t duration;

    StepperConfigPtr config;
};

void defaultImplementation(ProtocolLayerStatePtr state);

#endif /* PROTOCOLLAYERSTATE_H_ */