#ifndef _BACK_WHEEL_H_
#define _BACK_WHEEL_H_
#include "headfile.h"


#define MOTOR_L_PWM 13//DIR 8-1
#define MOTOR_R_PWM 14//DIR 8-2

#define MIN(a, b)                 (((a) < (b)) ? (a) : (b))
#define MAX(a, b)                 (((a) > (b)) ? (a) : (b))
#define MINMAX(input, low, upper) MIN(MAX(input, low), upper)

extern short right_dir;
extern short left_dir;

/*定义PID对象类型*/
typedef struct // 位置型普通PID
{
    float maximum;  /*输出值上限*/
    float minimum;  /*输出值下限*/
    float setpoint; // 设定值
    float result;   // 输出值
    float integral; // 积分值

} PID_1;

typedef struct // 增量型普通PID
{
    float maximum;  /*输出值上限*/
    float minimum;  /*输出值下限*/
    float setpoint; // 设定值

    float result;     // 输出值
    float integral;   // 积分值
    float derivative; // 微分值

    float P_out;
    float I_out;

} PID_2;

typedef struct // 后轮结构体参数
{
    // 变积分参数
    float L_Max_I;
    float L_Ci;

    float R_Max_I;
    float R_Ci;

    // 变比例参数
    float L_Bas_KP;
    float L_Gain_KP;
    float L_Cp;

    float R_Bas_KP;
    float R_Gain_KP;
    float R_Cp;

    float L_Change_P;
    float L_Change_I;

    float R_Change_P;
    float R_Change_I;

} Motor_Para;

extern PID_2 Motor_Left;    // 左轮变量
extern PID_2 Motor_Right;   // 右轮变量
extern Motor_Para MOTOR;    // PID参数结构体
extern Motor_Para LORDTEST; // PID参数结构体

void motor_init(int pwm_in_left, int pwm_in_right);
void run(int left, int right);
void Motor_L_Control_Change_Integral(float setpoint, PID_2 *vPID, Motor_Para *Motor, int processValue);
void Motor_R_Control_Change_Integral(float setpoint, PID_2 *vPID, Motor_Para *Motor, int processValue);


#endif /* HARDWARE_MOTOR_CTRL_H_ */
