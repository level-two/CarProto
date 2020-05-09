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
void setup()
void state() // idle, in progress and so on

// operations should be atomic - i.e one operation per time. Status should reflect if there is operation in progress
void step(left/right) // error on operation requests collision
void isReached(left/right)
void terminateOperation()




#endif /* PROTOCOL_H_ */