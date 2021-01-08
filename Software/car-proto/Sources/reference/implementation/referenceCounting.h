/*
 * referenceCounting.h
 *
 * Created: 20.07.2020 12:38:21
 *  Author: Yauheni
 */

#ifndef REFERENCE_COUNTING_H_
#define REFERENCE_COUNTING_H_

#include <stdint.h>

void* alloc(size_t size);
void retain(void* pointer);
void release(void* pointer);
uint8_t referenceCount(void* pointer);

#endif /* REFERENCE_COUNTING_H_ */