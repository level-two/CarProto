/*
 * queue.h
 *
 * Created: 06.07.2020 17:35:56
 *  Author: Yauheni
 */


#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

typedef struct Queue* QueuePtr;

QueuePtr queueMake();
void queueRelease(QueuePtr, bool freeDataMemory);
bool queueIsEmpty(QueuePtr);
void* queueHead(QueuePtr);
void queuePushBack(QueuePtr, void *item);
void* queuePopFront(QueuePtr);

#endif /* QUEUE_H_ */