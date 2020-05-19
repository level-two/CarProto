/*
 * portManipulations.h
 *
 * Created: 18.05.2020 12:14:43
 *  Author: Yauheni
 */ 


#ifndef PORTMANIPULATIONS_H_
#define PORTMANIPULATIONS_H_


inline void setPort(volatile uint8_t* ptr, uint8_t bit) {
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



#endif /* PORTMANIPULATIONS_H_ */