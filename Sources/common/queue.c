/*
 * queue.c
 *
 * Created: 06.07.2020 17:36:26
 *  Author: Yauheni
 */

#include <stdlib.h>
#include <util/atomic.h>
#include "queue.h"

typedef struct Node* NodePtr;

struct Node {
    void *data;
    NodePtr next;
};

struct Queue {
    NodePtr head;
};

QueuePtr queueMake() {
    QueuePtr queue = (QueuePtr) malloc(sizeof(struct Queue));
    queue->head = NULL;
    return queue;
}

void queueRelease(QueuePtr queue, bool freeDataMemory) {
    while (queueHead(queue) != NULL) {
        void *data = queuePopFront(queue);
        if (freeDataMemory) {
            free(data);
        }
    }
    free(queue);
}

bool queueIsEmpty(QueuePtr queue) {
    bool isEmpty = true;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        isEmpty = (queue->head == NULL);
    }

    return isEmpty;
}

void* queueHead(QueuePtr queue) {
    void *headData = NULL;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if (queue->head != NULL) {
            headData = queue->head->data;
        }
    }

    return headData;
}

void queuePushBack(QueuePtr queue, void *data) {
    NodePtr node = (NodePtr) malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if (queue->head == NULL) {
            queue->head = node;
        } else {
            NodePtr last = queue->head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = node;
        }
    }
}

void* queuePopFront(QueuePtr queue) {
    NodePtr node = NULL;
    void *data = NULL;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if (queue->head != NULL) {
            node = queue->head;
            data = node->data;
            queue->head = node->next;
        }
    }

    if (node != NULL) {
        free(node);
    }

    return data;
}
