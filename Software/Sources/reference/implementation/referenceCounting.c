/*
 * referenceCounting.c
 *
 * Created: 20.07.2020 12:38:40
 *  Author: Yauheni
 */

#include <stdlib.h>
#include <assert.h>
#include "referenceCounting.h"

#define TABLE_SIZE_STEP 16

typedef struct {
    void* pointer;
    uint8_t refCount;
} Reference;

typedef struct {
    Reference** refs;
    uint8_t count;
    uint8_t capacity;
} ReferenceTable;

static ReferenceTable refsTable = { NULL, 0, 0 };

static void insert(Reference *ref);
static void remove(uint8_t idx);
static uint8_t indexOf(void* pointer);
static void adjustTableCapacity();

void* alloc(size_t size) {
    Reference *ref = (Reference*) malloc(sizeof(Reference));
    if (ref == NULL) { return NULL; }

    ref->refCount = 1;
    ref->pointer = malloc(size);

    if (ref->pointer == NULL) {
        free(ref);
        return NULL;
    }

    insert(ref);
    return ref->pointer;
}

void retain(void* pointer) {
    uint8_t idx = indexOf(pointer);
    if (idx == refsTable.count) { return; }
    refsTable.refs[idx]->refCount++;
}

void release(void* pointer) {
    uint8_t idx = indexOf(pointer);
    if (idx == refsTable.count) { return; }

    refsTable.refs[idx]->refCount--;

    if (refsTable.refs[idx]->refCount == 0) {
        Reference *ref = refsTable.refs[idx];
        free(ref->pointer);
        free(ref);
        remove(idx);
    }
}

uint8_t referenceCount(void* pointer) {
    uint8_t idx = indexOf(pointer);
    return (idx == refsTable.count) ? 0 : refsTable.refs[idx]->refCount;
}


static void insert(Reference *ref) {
    adjustTableCapacity();
    refsTable.refs[refsTable.count] = ref;
    refsTable.count++;
}

static void remove(uint8_t idx) {
    for (uint8_t i = idx; i < refsTable.count-1; i++) {
        refsTable.refs[i] = refsTable.refs[i+1];
    }
    refsTable.count--;
    adjustTableCapacity();
}

static uint8_t indexOf(void* pointer) {
    uint8_t idx = 0;
    for (; idx < refsTable.count && refsTable.refs[idx]->pointer != pointer; idx++);
    return idx;
}

static void adjustTableCapacity() {
    if (refsTable.count == 0) {
        refsTable.capacity = TABLE_SIZE_STEP;
        refsTable.refs = (Reference**) realloc(refsTable.refs, TABLE_SIZE_STEP * sizeof(Reference*));
    }
    else if (refsTable.count == refsTable.capacity) {
        refsTable.capacity += TABLE_SIZE_STEP;
        refsTable.refs = (Reference**) realloc(refsTable.refs, refsTable.capacity * sizeof(Reference*));
    }
    else if (refsTable.count == refsTable.capacity - TABLE_SIZE_STEP - (TABLE_SIZE_STEP >> 1)) {
        refsTable.capacity -= TABLE_SIZE_STEP;
        refsTable.refs = (Reference**) realloc(refsTable.refs, refsTable.capacity * sizeof(Reference*));
    }

    assert(refsTable.refs != NULL);
}
