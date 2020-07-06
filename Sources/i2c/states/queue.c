/*
 * queue.c
 *
 * Created: 06.07.2020 17:36:26
 *  Author: Yauheni
 */

#include <stdlib.h>
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
    return (queue->head == NULL);
}

void* queueHead(QueuePtr queue) {
    return queue->head;
}

void queuePushBack(QueuePtr queue, void *data) {
    NodePtr node = (NodePtr) malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;

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

void* queuePopFront(QueuePtr queue) {
    if (queue->head == NULL) { return NULL; }

    NodePtr node = queue->head;
    void *data = node->data;
    queue->head = node->next;
    free(node);
    return data;
}
