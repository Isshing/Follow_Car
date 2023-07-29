#include "gy86.h"

// #define abs(a) (u32)(a>=0?a:-a)

float Yaw_IIC, Roll_IIC, Pitch_IIC;
float accx, accy, accz;
float gyrox, gyroy, gyroz;
float anglex, angley, anglez;

void InitMPU6050()
{
    Single_WriteI2C(PWR_MGMT_1, 0x00);
    Single_WriteI2C(SMPLRT_DIV, 0x07);
    Single_WriteI2C(CONFIG, 0x06);
    Single_WriteI2C(GYRO_CONFIG, 0x18);
    Single_WriteI2C(ACCEL_CONFIG, 0x01);
}

void I2C_SendACK(unsigned char ack)
{
    SDAOUT;
    SCLOUT;
    if (ack)
        SDA1;
    else
        SDA0;
    SCL1;
    delayus(2);
    SCL0;
    delayus(2);
}

unsigned char I2C_RecvACK()
{
    unsigned char cy;
    SCLOUT;
    SCL1;

    SDAIN;
    delayus(2);
    if (SDADATA)
    {
        cy = 1;
    }
    else
    {
        cy = 0;
    }
    SCL0;
    delayus(5);
    SDAOUT;
    return cy;
}

void Single_WriteI2C(unsigned char REG_Address, unsigned char REG_data)
{
    I2C_Start();
    I2C_SendByte(SlaveAddress);
    I2C_SendByte(REG_Address);
    I2C_SendByte(REG_data);
    I2C_Stop();
}
void I2C_Start(void)
{
    SDAOUT;
    SDA1;
    SCLOUT;
    SCL1;
    delayus(2);
    SDA0;
    delayus(2);
    SCL0;
}
void I2C_Stop(void)
{

    SDAOUT;
    SDA0;
    SCL0;
    SCLOUT;
    delayus(1);
    SCL1;
    SDA1;
    delayus(1);
}

void I2C_SendByte(unsigned char dat)
{
    unsigned char i;
    SDAOUT;
    for (i = 0; i < 8; i++)
    {
        if ((dat << i) & 0x80)
        {
            SDA1;
        }
        else
        {
            SDA0;
        }
        SCLOUT;
        SCL1;
        delayus(5);
        SCL0;
        delayus(5);
    }
    I2C_RecvACK();
}

unsigned char I2C_RecvByte()
{
    unsigned char i;
    unsigned char dat = 0, cy;

    SDAOUT;
    SCLOUT;
    SDA1;
    SDAIN;
    for (i = 0; i < 8; i++)
    {
        dat <<= 1;
        SCL1;
        delayus(5);
        if (SDADATA)
        {
            cy = 1;
        }
        else
        {
            cy = 0;
        }
        dat |= cy;
        delayus(2);
    }
    SDAOUT;
    return dat;
}

void mpupose(void)
{
    accx = ((float)GetData(ACCEL_XOUT_H));
    accy = ((float)GetData(ACCEL_YOUT_H));
    accz = ((float)GetData(ACCEL_ZOUT_H));

    //    gyrox=((float)GetData(GYRO_XOUT_H))/16.4;
    //    gyroy=((float)GetData(GYRO_YOUT_H))/16.4;
    //    gyroz=((float)GetData(GYRO_ZOUT_H))/16.4;

    Yaw_IIC = atan(accx / accz) * 57.2958;
    Roll_IIC = atan(accy / accz) * 57.2958;
    Pitch_IIC = atan(accz / accx) * 57.2958;
}

int GetData(unsigned char REG_Address)
{
    char H, L;
    H = MPU_Read_Byte(REG_Address);
    L = MPU_Read_Byte(REG_Address + 1);
    return (H << 8) + L;
}

unsigned char MPU_Read_Byte(unsigned char reg)
{
    unsigned char res;
    MPU_IIC_Start();
    MPU_IIC_Send_Byte((0X68 << 1) | 0);
    MPU_IIC_Wait_Ack();
    MPU_IIC_Send_Byte(reg);
    MPU_IIC_Wait_Ack();
    MPU_IIC_Start();
    MPU_IIC_Send_Byte((0X68 << 1) | 1);
    MPU_IIC_Wait_Ack();
    res = MPU_IIC_Read_Byte(0);
    MPU_IIC_Stop();
    return res;
}
void MPU_IIC_Start(void)
{
    SDAOUT;
    SDA1;
    SCL1;
    MPU_IIC_Delay();
    SDA0;
    MPU_IIC_Delay();
    SCL0;
}
void MPU_IIC_Delay(void)
{
    delayus(5);
}
void MPU_IIC_Send_Byte(unsigned char txd)
{
    unsigned char t;
    SDAOUT;
    SCL0;
    for (t = 0; t < 8; t++)
    {
        if (((txd & 0x80) >> 7) == 1)
            SDA1;
        else
            SDA0;
        txd <<= 1;
        SCL1;
        MPU_IIC_Delay();
        SCL0;
        MPU_IIC_Delay();
    }
}
unsigned char MPU_IIC_Wait_Ack(void)
{
    unsigned char ucErrTime = 0;
    SDAIN;
    SDA1;
    MPU_IIC_Delay();
    SCL1;
    MPU_IIC_Delay();
    while (SDADATA)
    {
        ucErrTime++;
        if (ucErrTime > 250)
        {
            MPU_IIC_Stop();
            return 1;
        }
    }
    SCL0;
    return 0;
}
unsigned char MPU_IIC_Read_Byte(unsigned char ack)
{
    unsigned char i, receive = 0;
    SDAIN;
    for (i = 0; i < 8; i++)
    {
        SCL0;
        MPU_IIC_Delay();
        SCL1;
        receive <<= 1;
        if (SDADATA)
            receive++;
        MPU_IIC_Delay();
    }
    if (!ack)
        MPU_IIC_NAck();
    else
        MPU_IIC_Ack();
    return receive;
}
void MPU_IIC_Stop(void)
{
    SDAOUT;
    SCL0;
    SDA0;
    MPU_IIC_Delay();
    SCL1;
    SDA1;
    MPU_IIC_Delay();
}
void MPU_IIC_NAck(void)
{
    SCL0;
    SDAOUT;
    SDA1;
    MPU_IIC_Delay();
    SCL1;
    MPU_IIC_Delay();
    SCL0;
}
void MPU_IIC_Ack(void)
{
    SCL0;
    SDAOUT;
    SDA0;
    MPU_IIC_Delay();
    SCL1;
    MPU_IIC_Delay();
    SCL0;
}

void Data_show()
{
    OLED_ShowNum(0, 0, Yaw_IIC, 4, 12);
    OLED_ShowNum(0, 10, Roll_IIC, 4, 12);
    OLED_ShowNum(0, 20, Pitch_IIC, 4, 12);
}
