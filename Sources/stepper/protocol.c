/*
 * protocol.c
 *
 * Created: 09.05.2020 15:15:27
 *  Author: Yauheni
 */

#include "protocol.h"
#include "driver.h"

ProtocolLayerState state;

// current operation/phase
// time
//

void protocolLayerSetup() {
    driverLayerSetup();
    state = idle;
}

void protocolLayerUpdate() {
    // get ticks
}

void protocolLayerStep(ProtocolLayerDir dir) {

}

void protocolLayerTerminateOperation() {

}

void protocolLayerEnable(bool isEnabled) {

}

ProtocolLayerState protocolLayerState() {
    return state;
}

