/*
 * lis331dlh.h
 *
 * Created: 14.07.2020 16:19:07
 *  Author: Yauheni
 */


#ifndef LIS331DLH_H_
#define LIS331DLH_H_

#define ADDRESS 0x18
#define ADDRESS_V1 0x19

#define WHOAMI_REG 0x0F
#define WHOAMI 0x32

#define CTRL1_REG 0x20
#define PM2 7
#define PM1 6
#define PM0 5
#define PM 5
#define DR1 4
#define DR0 3
#define DR 3
#define ZEN 2
#define YEN 1
#define XEN 0
#define ZYXEN 0

#define CTRL2_REG 0x21
#define BOOT 7
#define HPM1 6
#define HPM0 5
#define HPM 5
#define FDS 4
#define HPEN2 3
#define HPEN1 2
#define HPCF1 1
#define HPCF0 0
#define HPCF 0

#define CTRL3_REG 0x22
#define IHL 7
#define PP_OD 6
#define LIR2 5
#define I2_CFG1 4
#define I2_CFG0 3
#define I2_CFG 3
#define LIR1 2
#define I1_CFG1 1
#define I1_CFG0 0
#define I1_CFG 0

#define CTRL4_REG 0x23
#define BDU 7
#define BLE 6
#define FS1 5
#define FS0 4
#define FS 4
#define STSIGN 3
#define ST 1
#define SIM 0

#define CTRL5_REG 0x24
#define TURN_ON1 1
#define TURN_ON0 0
#define TURN_ON 0

#define HP_FILTER_RESET_REG 0x25
#define REFERENCE_REG 0x26

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

#define INT1_CFG_REG 0x30
#define I1_AOI 7
#define I1_SIXD 6
#define I1_ZHIE 5
#define I1_ZLIE 4
#define I1_YHIE 3
#define I1_YLIE 2
#define I1_XHIE 1
#define I1_XLIE 0

#define INT1_SRC_REG 0x31
#define I1_IA 6
#define I1_ZH 5
#define I1_ZL 4
#define I1_YH 3
#define I1_YL 2
#define I1_XH 1
#define I1_XL 0

#define INT1_THS_REG 0x32
#define I1_THS6 6
#define I1_THS5 5
#define I1_THS4 4
#define I1_THS3 3
#define I1_THS2 2
#define I1_THS1 1
#define I1_THS0 0
#define I1_THS 0

#define INT1_DURATION_REG 0x33
#define I1_DURATION6 6
#define I1_DURATION5 5
#define I1_DURATION4 4
#define I1_DURATION3 3
#define I1_DURATION2 2
#define I1_DURATION1 1
#define I1_DURATION0 0
#define I1_DURATION 0

#define INT2_CFG_REG 0x34
#define I2_AOI 7
#define I2_SIXD 6
#define I2_ZHIE 5
#define I2_ZLIE 4
#define I2_YHIE 3
#define I2_YLIE 2
#define I2_XHIE 1
#define I2_XLIE 0

#define INT2_SRC_REG 0x35
#define I2_IA 6
#define I2_ZH 5
#define I2_ZL 4
#define I2_YH 3
#define I2_YL 2
#define I2_XH 1
#define I2_XL 0

#define INT2_THS_REG 0x36
#define I2_THS6 6
#define I2_THS5 5
#define I2_THS4 4
#define I2_THS3 3
#define I2_THS2 2
#define I2_THS1 1
#define I2_THS0 0
#define I2_THS 0

#define INT2_DURATION_REG 0x37
#define I2_DURATION6 6
#define I2_DURATION5 5
#define I2_DURATION4 4
#define I2_DURATION3 3
#define I2_DURATION2 2
#define I2_DURATION1 1
#define I2_DURATION0 0
#define I2_DURATION 0

#define DATA_OUT_BASE_REG 0xA8


#endif /* LIS331DLH_H_ */