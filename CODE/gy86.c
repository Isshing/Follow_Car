#include "gy86.h"

// #define abs(a) (u32)(a>=0?a:-a)

float Yaw_IIC = 0;
float Roll_IIC = 0;
float Pitch_IIC = 0;
float accx, accy, accz;
float gyrox, gyroy, gyroz;
float anglex, angley, anglez;
float dt = 0.1;

float gyro_z_0 = -1.2; //! 值要自己确定
float gyro_y_0 = 3.86;
float g_z, last_g_z, yaw_angle = 0, last_icm_gyro_z, Kalman_pitch_angle, last_icm_gyro_y;
float g_y;
float pitch_angle = 0;
float Merge_Pitch =0;


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
    float a =0.1;

    static float last_pitch =0;
    accx = ((float)GetData(ACCEL_XOUT_H));
    accy = ((float)GetData(ACCEL_YOUT_H));
    accz = ((float)GetData(ACCEL_ZOUT_H));

    gyrox = ((float)GetData(GYRO_XOUT_H)) / 16.4;
    gyroy = ((float)GetData(GYRO_YOUT_H)) / 16.4;
    gyroz = ((float)GetData(GYRO_ZOUT_H)) / 16.4;

    Yaw_IIC = atan(accx / accz) * 57.2958;
//    Roll_IIC = atan(accy / accz) * 57.2958;
    Pitch_IIC = atan(accz / accx) * 57.2958;

    pitch_angle += (gyroy -gyro_y_0)*dt;
    yaw_angle += (accz -gyro_z_0) *dt;

    Merge_Pitch=(last_pitch+pitch_angle)*(1-a)+a*Pitch_IIC;
    last_pitch=Merge_Pitch;


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
    // OLED_ShowNum(1, 0, (uint32)Yaw_IIC, 10, 12);
    // OLED_ShowNum(1, 1, (uint32)Roll_IIC, 10, 12);
    // OLED_ShowNum(1, 2, (uint32)Pitch_IIC, 10, 12);

    // OLED_ShowNum(1, 0, (uint32)Yaw_IIC, 10, 12);
    // OLED_ShowNum(1, 1, (uint32)Roll_IIC, 10, 12);
    // OLED_ShowNum(1, 2, (uint32)Pitch_IIC, 10, 12);

    if (Yaw_IIC >= 0)
    {

        OLED_ShowString(1, 2, "+", 2);
        OLED_ShowNum(14, 2, Fabs(Yaw_IIC), 10, 12);
    }
    else
    {

        OLED_ShowString(1, 2, "-", 2);
        OLED_ShowNum(14, 2, Fabs((Yaw_IIC)), 10, 12);
    }

    if (pitch_angle >= 0)
    {

        OLED_ShowString(1, 3, "+", 2);
        OLED_ShowNum(14, 3, Fabs(pitch_angle), 10, 12);
    }
    else
    {

        OLED_ShowString(1, 3, "-", 2);
        OLED_ShowNum(14, 3, Fabs(pitch_angle), 10, 12);
    }
    //    if (Roll_IIC >= 0)
    //    {
    //
    //        OLED_ShowString(1, 4, "+", 2);
    //        OLED_ShowNum(14, 4, Fabs(Roll_IIC), 10, 12);
    //    }
    //    else
    //    {
    //
    //        OLED_ShowString(1, 4, "-", 2);
    //        OLED_ShowNum(14, 4, Fabs(Roll_IIC), 10, 12);
    //    }
}

//float gz_Kalman_Filter(float angle_m, float gyro_m)
//{
//    float P[2][2] = {{1, 0},
//                     {0, 1}};
//    static float q_bias;
//    static float K_0;
//    static float K_1;
//    static float angle_kalman;
//    static uint8 first_angle;
//    static float Q_angle = 0.000001;
//    static float Q_gyro = 0.05;
//    static float R_angle = 8.0; // 8  10
//    if (first_angle == 0)
//    {
//        angle_kalman = angle_m;
//        q_bias = 0;
//        first_angle = 1;
//    }
//    angle_kalman += (gyro_m - q_bias) * dt;
//    P[0][0] += Q_angle - (P[0][1] + P[1][0]) * dt;
//    P[0][1] -= P[1][1] * dt;
//    P[1][0] -= P[1][1] * dt;
//    P[1][1] += Q_gyro;
//    K_0 = P[0][0] / (P[0][0] + R_angle);
//    K_1 = P[1][0] / (P[1][0] + R_angle);
//    angle_kalman = angle_kalman + K_0 * (angle_m - angle_kalman);
//    q_bias = q_bias + K_1 * (angle_m - angle_kalman);
//    P[0][0] -= K_0 * P[0][0];
//    P[0][1] -= K_0 * P[0][1];
//    P[1][0] -= K_1 * P[0][0];
//    P[1][1] -= K_1 * P[0][1];
//    return angle_kalman;
//}
//
//float gy_Kalman_Filter(float angle_m, float gyro_m)
//{
//    float P[2][2] = {{1, 0},
//                     {0, 1}};
//    static float q_bias;
//    static float K_0;
//    static float K_1;
//    static float angle_kalman;
//    static uint8 first_angle = 0;
//    static float Q_angle = 0.0003;
//    static float Q_gyro = 0.001;
//    static float R_angle = 1;
//    if (first_angle == 0)
//    {
//        angle_kalman = angle_m;
//        q_bias = 0;
//        first_angle = 1;
//    }
//    angle_kalman += (gyro_m - q_bias) * dt;
//    P[0][0] += Q_angle - (P[0][1] + P[1][0]) * dt;
//    P[0][1] -= P[1][1] * dt;
//    P[1][0] -= P[1][1] * dt;
//    P[1][1] += Q_gyro;
//    K_0 = P[0][0] / (P[0][0] + R_angle);
//    K_1 = P[1][0] / (P[1][0] + R_angle);
//    angle_kalman = angle_kalman + K_0 * (angle_m - angle_kalman);
//    q_bias = q_bias + K_1 * (angle_m - angle_kalman);
//    P[0][0] -= K_0 * P[0][0];
//    P[0][1] -= K_0 * P[0][1];
//    P[1][0] -= K_1 * P[0][0];
//    P[1][1] -= K_1 * P[0][1];
//    return angle_kalman;
//}

// void gyro_calculate(void)
//{
//     static float gz;
//     gz = (float)gyroz;
//     gz = gz - gyro_z_0;
//     g_z = gz_Kalman_Filter(gz, gz - last_icm_gyro_z);
//     last_icm_gyro_z = gz;
//     yaw_angle += g_z * dt;
//     if (yaw_angle >= 360 || yaw_angle <= -360)
//         yaw_angle = 0;
// }

// void ramp_ang(void)
//{
//
//     static float gy;
//     gy = (float)gyroy;
//     gy = gy - gyro_y_0;
//     g_y = gy_Kalman_Filter(gy, gy - last_icm_gyro_y);
//     last_icm_gyro_y = gy;
//     pitch_angle += g_y * dt;
//     if (pitch_angle >= 90 || pitch_angle <= -90)
//         pitch_angle = 0;
// }
