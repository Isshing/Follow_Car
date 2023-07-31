
#ifndef _GY86_H_
#define _GY86_H_
#include "headfile.h"

#define SCL1 P4OUT |= BIT1
#define SCL0 P4OUT &= ~BIT1
#define SCLOUT P4DIR |= BIT1
#define SDA1 P4OUT |= BIT2
#define SDA0 P4OUT &= ~BIT2
#define SDAIN P4DIR &= ~BIT2
#define SDAOUT P4DIR |= BIT2
#define SDADATA (P4IN & BIT2)
#define SlaveAddress 0xD0

#define PWR_MGMT_1 0x6B
#define SMPLRT_DIV 0x19
#define CONFIG 0x1A
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C

#define ACCEL_XOUT_H 0x3B
#define ACCEL_YOUT_H 0x3D
#define ACCEL_ZOUT_H 0x3F
#define GYRO_XOUT_H 0x43
#define GYRO_YOUT_H 0x45
#define GYRO_ZOUT_H 0x47

#define CPU_F ((double)15990784)
#define delayus(x) __delay_cycles((long)(CPU_F * (double)x / 1000000.0))

/***************��������*****************/

extern float Yaw_IIC, Roll_IIC, Pitch_IIC;
extern float accx, accy, accz;
extern float gyrox, gyroy, gyroz;
extern float anglex, angley, anglez;

extern float gyro_z_0, gyro_y_0;
extern float g_z, yaw_angle, pitch_angle, last_icm_gyro_z, Kalman_pitch_angle, last_icm_gyro_y;

extern float Merge_Pitch;

/*************************************/

extern void I2C_SendByte(unsigned char dat);
extern void I2C_Stop(void);
extern void I2C_Start(void);
extern void Single_WriteI2C(unsigned char REG_Address, unsigned char REG_data);
extern unsigned char I2C_RecvACK();
extern void InitMPU6050();
extern void mpupose(void);
extern int GetData(unsigned char REG_Address);
extern unsigned char MPU_Read_Byte(unsigned char reg);
extern void MPU_IIC_Start(void);
extern void MPU_IIC_Delay(void);
extern void MPU_IIC_Send_Byte(unsigned char txd);
extern unsigned char MPU_IIC_Wait_Ack(void);
extern unsigned char MPU_IIC_Read_Byte(unsigned char ack);
extern void MPU_IIC_Stop(void);
extern void MPU_IIC_NAck(void);
extern void MPU_IIC_Ack(void);
extern void Data_show(void);
void gyro_calculate(void);
void ramp_ang(void);
#endif /* HARDWARE_GY86_H_ */
