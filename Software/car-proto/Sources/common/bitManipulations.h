/*
 * bitManipulations.h
 *
 * Created: 08.05.2020 1:32:25
 *  Author: Yauheni
 */


#ifndef BITMANIPULATIONS_H_
#define BITMANIPULATIONS_H_

#include <stdbool.h>
#include <inttypes.h>

inline uint8_t bitVector(uint8_t bit0) {
    return (1 << bit0);
}

inline uint8_t bitVector2(uint8_t bit0, uint8_t bit1) {
    return (1 << bit0) | (1 << bit1);
}

inline uint8_t bitVector3(uint8_t bit0, uint8_t bit1, uint8_t bit2) {
    return (1 << bit0) | (1 << bit1) | (1 << bit2);
}

inline uint8_t bitVector4(uint8_t bit0, uint8_t bit1, uint8_t bit2, uint8_t bit3) {
    return (1 << bit0) | (1 << bit1) | (1 << bit2) | (1 << bit3);
}


inline void setBit(volatile uint8_t* ptr, uint8_t bit) {
    *ptr |= bitVector(bit);
}

inline void clearBit(volatile uint8_t* ptr, uint8_t bit) {
    *ptr &= ~bitVector(bit);
}

inline void toggleBit(volatile uint8_t* ptr, uint8_t bit) {
    *ptr ^= bitVector(bit);
}

inline void writeBit(volatile uint8_t* ptr, uint8_t bit, bool val) {
    if (val) {
        setBit(ptr, bit);
    } else {
        clearBit(ptr, bit);
    }
}

inline bool readBit(volatile uint8_t* ptr, uint8_t bit) {
    return *ptr & bitVector(bit);
}


inline void setBits(volatile uint8_t* ptr, uint8_t mask) {
    *ptr |= mask;
}

inline void clearBits(volatile uint8_t* ptr, uint8_t mask) {
    *ptr &= ~mask;
}

inline void writeBits(volatile uint8_t* ptr, uint8_t mask, uint8_t val) {
    *ptr = (*ptr & ~mask) | (val & mask);
}

inline uint8_t readBits(volatile uint8_t* ptr, uint8_t mask) {
    return *ptr & mask;
}

#endif /* BITMANIPULATIONS_H_ */