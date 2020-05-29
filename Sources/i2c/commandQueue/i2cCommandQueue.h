/*
 * i2cCommandQueue.h
 *
 * Created: 29.05.2020 14:04:53
 *  Author: Yauheni
 */


#ifndef I2CCOMMANDQUEUE_H_
#define I2CCOMMANDQUEUE_H_


I2CCommandPtr i2cCommandMake();
void i2cCommandRelease(I2CCommandPtr);



#endif /* I2CCOMMANDQUEUE_H_ */