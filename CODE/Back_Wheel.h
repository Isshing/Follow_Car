#ifndef _BACK_WHEEL_H_
#define _BACK_WHEEL_H_
#include "headfile.h"

#define MOTOR_L_PWM 13 // DIR 8-1
#define MOTOR_R_PWM 14 // DIR 8-2

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MINMAX(input, low, upper) MIN(MAX(input, low), upper)

extern short right_dir;
extern short left_dir;

/*����PID��������*/
typedef struct // λ������ͨPID
{
    float maximum;  /*���ֵ����*/
    float minimum;  /*���ֵ����*/
    float setpoint; // �趨ֵ
    float result;   // ���ֵ
    float integral; // ����ֵ

} PID_1;

typedef struct // ��������ͨPID
{
    float maximum;  /*���ֵ����*/
    float minimum;  /*���ֵ����*/
    float setpoint; // �趨ֵ

    float result;     // ���ֵ
    float integral;   // ����ֵ
    float derivative; // ΢��ֵ

    float P_out;
    float I_out;

} PID_2;

typedef struct // ���ֽṹ�����
{
    // ����ֲ���
    float L_Max_I;
    float L_Ci;

    float R_Max_I;
    float R_Ci;

    // ���������
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

extern PID_2 Motor_Left;    // ���ֱ���
extern PID_2 Motor_Right;   // ���ֱ���
extern Motor_Para MOTOR;    // PID�����ṹ��
extern Motor_Para LORDTEST; // PID�����ṹ��

void motor_init(int pwm_in_left, int pwm_in_right);
void run(int left, int right);
void Motor_L_Control_Change_Integral(float setpoint, PID_2 *vPID, Motor_Para *Motor, int processValue);
void Motor_R_Control_Change_Integral(float setpoint, PID_2 *vPID, Motor_Para *Motor, int processValue);

#endif /* HARDWARE_MOTOR_CTRL_H_ */
