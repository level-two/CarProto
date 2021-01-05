/*
 * l3g4200d.h
 *
 * Created: 13.07.2020 15:56:45
 *  Author: Yauheni
 */


#ifndef L3G4200D_H_
#define L3G4200D_H_

#define ADDRESS 0x68
#define ADDRESS_V1 0x69

#define WHOAMI_REG 0x0F
#define WHOAMI 0xD3

#define CTRL1_REG 0x20
#define DR1 7
#define DR0 6
#define DR 6
#define BW1 5
#define BW0 4
#define BW 4
#define PD 3
#define ZEN 2
#define YEN 1
#define XEN 0
#define ZYXEN 0

#define CTRL2_REG 0x21
#define HPM1 5
#define HPM0 4
#define HPM 4
#define HPCF3 3
#define HPCF2 2
#define HPCF1 1
#define HPCF0 0
#define HPCF 0

#define CTRL3_REG 0x22
#define I1_INT1 7
#define I1_BOOT 6
#define H_LACTIVE 5
#define PP_OD 4
#define I2_DRDY 3
#define I2_WTM 2
#define I2_ORUN 1
#define I2_EMPTY 0

#define CTRL4_REG 0x23
#define BDU 7
#define BLE 6
#define FS1 5
#define FS0 4
#define FS 4
#define ST1 2
#define ST0 1
#define ST 1
#define SIM 0

#define CTRL5_REG 0x24
#define BOOT 7
#define FIFO_EN 6
#define HPEN 4
#define INT1_SEL1 3
#define INT1_SEL0 2
#define INT1_SEL 2
#define OUT_SEL1 1
#define OUT_SEL0 0
#define OUT_SEL 0

#define REFERENCE_REG 0x25
#define OUT_TEMP_REG 0x26

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

#define FIFO_CTRL_REG 0x2E
#define FM2 7
#define FM1 6
#define FM0 5
#define FM 5
#define WTM4 4
#define WTM3 3
#define WTM2 2
#define WTM1 1
#define WTM0 0
#define WTM 0

#define FIFO_SRC_REG 0x2F
#define WTM_STA 7
#define OVRN 6
#define EMPTY 5
#define FSS4 4
#define FSS3 3
#define FSS2 2
#define FSS1 1
#define FSS0 0
#define FSS 0

#define INT1_CFG_REG 0x30
#define AND_OR 7
#define LIR 6
#define ZHIE 5
#define ZLIE 4
#define YHIE 3
#define YLIE 2
#define XHIE 1
#define XLIE 0

#define INT1_SRC_REG 0x31
#define IA 6
#define ZH 5
#define ZL 4
#define YH 3
#define YL 2
#define XH 1
#define XL 0

#define INT1_THS_XH_REG 0x32
#define INT1_THS_XL_REG 0x33
#define INT1_THS_YH_REG 0x34
#define INT1_THS_YL_REG 0x35
#define INT1_THS_ZH_REG 0x36
#define INT1_THS_ZL_REG 0x37

#define INT1_DURATION_REG 0x38
#define WAIT 7
#define DURATION6 6
#define DURATION5 5
#define DURATION4 4
#define DURATION3 3
#define DURATION2 2
#define DURATION1 1
#define DURATION0 0
#define DURATION 0

#define DATA_OUT_BASE_REG 0xA8

#endif /* L3G4200D_H_ */