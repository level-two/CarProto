/*
 * protocol.h
 *
 * Created: 08.05.2020 0:11:01
 *  Author: Yauheni
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <stdbool.h>

// layer 2 (protocol impl) - signal timings etc

typedef enum {
    idle,
    inProgress,
    reachedLeft,
    reachedRight,
    disabled
} ProtocolLayerState;

typedef enum {
    left,
    right
} ProtocolLayerDir;

void protocolLayerSetup();
void protocolLayerUpdate();
void protocolLayerStep(ProtocolLayerDir dir);
void protocolLayerTerminateOperation();
void protocolLayerEnable(bool isEnabled);
ProtocolLayerState protocolLayerState();

#endif /* PROTOCOL_H_ */