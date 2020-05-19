/*
 * protocol.h
 *
 * Created: 08.05.2020 0:11:01
 *  Author: Yauheni
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <stdbool.h>
#include "stepperConfig.h"
#include "protocolStates/protocolLayerState.h"

typedef enum {
    protocolStatusBusy,
    protocolStatusIdle,
    protocolStatusIdleLeft,
    protocolStatusIdleRight
} ProtocolLayerStatus;

ProtocolLayerStatePtr protocolLayerSetup(StepperConfigPtr);
void protocolLayerUpdate(ProtocolLayerStatePtr, uint16_t);
void protocolLayerStep(ProtocolLayerStatePtr, StepDir);
void protocolLayerEnable(ProtocolLayerStatePtr, bool);
ProtocolLayerStatus protocolLayerStatus(ProtocolLayerStatePtr);

#endif /* PROTOCOL_H_ */