#include "Back_Wheel.h"

short left_dir = 1;
short right_dir = 1; // 1 + -1 -

PID_2 Motor_Left;    // 左轮电机变量
PID_2 Motor_Right;   // 右轮电机变量
Motor_Para MOTOR;    // 电机参数结构体变量
Motor_Para LORDTEST; // 检测上载是否正常

void motor_init(int pwm_in_left, int pwm_in_right)
{
    P8DIR |= BIT1 + BIT2; // P8_1和 P8_2
    P8OUT &= ~BIT1;
    P3DIR |= BIT0 + BIT1; // P7_1和 P7_2
    P3OUT &= ~BIT0;
    left_dir = -1;
    right_dir = 1;
    P8OUT |= BIT2;
    P3OUT |= BIT1;
    pwm_init(pwm_in_left, 100, 0);

    pwm_init(pwm_in_right, 100, 0);
}
void run(int left, int right)
{

    if (right >= 0) // 正传
    {
        pwm_duty(MOTOR_R_PWM, right);
        P8OUT &= ~BIT2; // 低
        P8OUT |= BIT1;  // 高
        right_dir = 1;
    }
    else
    {
        pwm_duty(MOTOR_R_PWM, -right);
        P8OUT |= BIT2;  // 低
        P8OUT &= ~BIT1; // 高

        right_dir = -1;
    }
    if (left >= 0)
    {
        pwm_duty(MOTOR_L_PWM, left);
        P3OUT &= ~BIT1; // 低
        P3OUT |= BIT0;  // 高
        left_dir = 1;
    }
    else
    {
        pwm_duty(MOTOR_L_PWM, -left);

        P3OUT |= BIT1;  // 低
        P3OUT &= ~BIT0; // 高
        left_dir = -1;
    }
}

void Motor_L_Control_Change_Integral(float setpoint, PID_2 *vPID, Motor_Para *Motor, int processValue)
{
    float thisError;
    float result;
    float increment;
    float pError = 0;
    float iError = 0;

    static float lasterror = 0; // 前一拍偏差

    thisError = setpoint - processValue; // 得到偏差值
    Motor->L_Change_P = Motor->L_Bas_KP + Motor->L_Gain_KP * (1 - 1.0 / expf(Motor->L_Cp * Fabs(thisError)));

    Motor->L_Change_I = (1.0 / expf(Motor->L_Ci * Fabs(thisError))) * Motor->L_Max_I;

    result = vPID->result;

    iError = (thisError + lasterror) / 2.0; // 如果上次输出结果处于正常范围内，正常积分

    pError = thisError - lasterror;
    vPID->P_out = Motor->L_Change_P * pError;
    vPID->I_out = Motor->L_Change_I * iError;
    increment = vPID->P_out + vPID->I_out; // 变积分不用积分分离，因为积分分离本质就是变积分的一种特殊情况
    result = result + increment;

    lasterror = thisError;
    vPID->result = MINMAX(result, -100, 100);
}

void Motor_R_Control_Change_Integral(float setpoint, PID_2 *vPID, Motor_Para *Motor, int processValue)
{
    float thisError;
    float result;
    float increment;
    float pError = 0;
    float iError = 0;
    static float lasterror = 0; // 前一拍偏差

    thisError = setpoint - processValue; // 得到偏差值
    Motor->R_Change_P = Motor->R_Bas_KP + Motor->R_Gain_KP * (1 - 1.0 / expf(Motor->R_Cp * Fabs(thisError)));
    Motor->R_Change_I = (1.0 / expf(Motor->R_Ci * Fabs(thisError))) * Motor->R_Max_I;
    result = vPID->result;

    iError = (thisError + lasterror) / 2.0; // 如果上次输出结果处于正常范围内，正常积分

    pError = thisError - lasterror;

    vPID->P_out = Motor->R_Change_P * pError;
    vPID->I_out = Motor->R_Change_I * iError;
    increment = vPID->P_out + vPID->I_out;
    result = result + increment;

    lasterror = thisError;
    vPID->result = MINMAX(result, -100, 100);
}
