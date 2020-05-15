/*
 * protocol.h
 *
 * Created: 08.05.2020 0:11:01
 *  Author: Yauheni
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <stdbool.h>
#include "state.h"

typedef enum {
    busy,
    idle,
    idleLeft,
    idleRight
} ProtocolLayerStatus;

void protocolLayerUpdate(StatePtr state, uint16_t dt);
void protocolLayerStep(StatePtr state, StepDir dir);
void protocolLayerEnable(StatePtr state, bool isEnabled);
ProtocolLayerStatus protocolLayerStatus(StatePtr state);

#endif /* PROTOCOL_H_ */