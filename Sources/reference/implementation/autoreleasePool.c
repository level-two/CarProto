/*
 * autoreleasePool.c
 *
 * Created: 21.07.2020 11:25:24
 *  Author: Yauheni
 */

#include <stdlib.h>
#include "referenceCounting.h"
#include "autoreleasePool.h"

#define POOL_SIZE_STEP 16

struct AutoreleasePool {
    void** pointers;
    uint8_t count;
    uint8_t capacity;
};

static struct AutoreleasePool autoreleasePool = { NULL, 0, 0 };
static void adjustAutoreleasePoolSize();

void autorelease(void* pointer) {
    adjustAutoreleasePoolSize();
    autoreleasePool.pointers[autoreleasePool.count] = pointer;
    autoreleasePool.count++;
}

void flushAutoreleasePool() {
    for (uint8_t i = 0; i < autoreleasePool.count; i++) {
        release(autoreleasePool.pointers[i]);
    }
    autoreleasePool.count = 0;
    adjustAutoreleasePoolSize();
}

static void adjustAutoreleasePoolSize() {
    if (autoreleasePool.count == 0) {
        autoreleasePool.capacity = POOL_SIZE_STEP;
        autoreleasePool.pointers = realloc(autoreleasePool.pointers, POOL_SIZE_STEP * sizeof(void*));
    }
    else if (autoreleasePool.count == autoreleasePool.capacity) {
        autoreleasePool.capacity += POOL_SIZE_STEP;
        autoreleasePool.pointers = realloc(autoreleasePool.pointers, autoreleasePool.capacity * sizeof(void*));
    }
}