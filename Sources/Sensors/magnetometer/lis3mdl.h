/*
 * lis3mdl.h
 *
 * Created: 14.07.2020 16:47:05
 *  Author: Yauheni
 */


#ifndef LIS3MDL_H_
#define LIS3MDL_H_

#define ADDRESS 0x1C
#define ADDRESS_V1 0x1E

#define WHOAMI_REG 0x0F
#define WHOAMI 0x3D

#define CTRL1_REG 0x20
#define TEMP_EN 7
#define OM1 6
#define OM0 5
#define OM 5
#define DO2 4
#define DO1 3
#define DO0 2
#define DO 2
#define FAST_ODR 1
#define ST 0

#define CTRL2_REG 0x21
#define FS1 6
#define FS0 5
#define FS 5
#define REBOOT 3
#define SOFT_RST 2

#define CTRL3_REG 0x22
#define LP 5
#define SIM 2
#define MD1 1
#define MD0 0
#define MD 0

#define CTRL4_REG 0x23
#define OMZ1 3
#define OMZ0 2
#define OMZ 2
#define BLE 1

#define CTRL5_REG 0x24
#define FAST_READ 7
#define BDU 6

#define STATUS_REG 0x27
#define ZYXOR 7
#define ZOR 6
#define YOR 5
#define XOR 4
#define ZYXDA 3
#define ZDA 2
#define YDA 1
#define XDA 0

#define OUT_X_L_REG 0x28
#define OUT_X_H_REG 0x29
#define OUT_Y_L_REG 0x2A
#define OUT_Y_H_REG 0x2B
#define OUT_Z_L_REG 0x2C
#define OUT_Z_H_REG 0x2D
#define TEMP_OUT_L_REG 0x2E
#define TEMP_OUT_H_REG 0x2F

#define INT_REG 0x30
#define XIEN 7
#define YIEN 6
#define ZIEN 5
#define IEA 2
#define LIR 1
#define IEN 0

#define INT_SRC_REG 0x31
#define PTH_X 7
#define PTH_Y 6
#define PTH_Z 5
#define NTH_X 4
#define NTH_Y 3
#define NTH_Z 2
#define MROI 1
#define INT 0

#define INT_THS_L_REG 0x32
#define INT_THS_H_REG 0x33

#define DATA_OUT_BASE_REG 0xA8

#endif /* LIS3MDL_H_ */