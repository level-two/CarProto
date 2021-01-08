/*
 * queue.c
 *
 * Created: 06.07.2020 17:36:26
 *  Author: Yauheni
 */

#include <stdlib.h>
#include <util/atomic.h>
#include "reference/reference.h"
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
    QueuePtr queue = (QueuePtr) alloc(sizeof(struct Queue));
    autorelease(queue);
    queue->head = NULL;
    return queue;
}

void queueFlush(QueuePtr queue) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        NodePtr node = queue->head;
        while (node != NULL) {
            NodePtr next = node->next;
            release(node->data);
            release(node);
            node = next;
        }
        queue->head = NULL;
    }
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
    NodePtr node = (NodePtr) alloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;
    retain(data);

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

    release(node);
    autorelease(data);

    return data;
}
