#include "Back_Wheel.h"


short left_dir = 1;
short right_dir = 1; //1 + -1 -


PID_2 Motor_Left;    // ���ֵ������
PID_2 Motor_Right;   // ���ֵ������
Motor_Para MOTOR;    // ��������ṹ�����
Motor_Para LORDTEST; // ��������Ƿ�����

void motor_init(int pwm_in_left, int pwm_in_right)
{
    P8DIR |= BIT1 + BIT2; //P8_1�� P8_2
    P8OUT &= ~BIT1;
    P3DIR |= BIT0 + BIT1; //P7_1�� P7_2
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

    if (right >= 0)  //����
    {
        pwm_duty(MOTOR_R_PWM, right);
        P8OUT &= ~BIT2; //��
        P8OUT |= BIT1; //��
        right_dir = 1;

    }
    else
    {
        pwm_duty(MOTOR_R_PWM, -right);
        P8OUT |=BIT2; //��
        P8OUT &= ~BIT1; //��

        right_dir = -1;

    }
    if (left >= 0)
    {
        pwm_duty(MOTOR_L_PWM, left);
        P3OUT &= ~BIT1; //��
        P3OUT |= BIT0; //��
        left_dir = 1;
    }
    else
    {
        pwm_duty(MOTOR_L_PWM, -left);

        P3OUT |=BIT1; //��
        P3OUT &= ~BIT0; //��
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

    static float lasterror = 0; // ǰһ��ƫ��

    thisError         = setpoint - processValue; // �õ�ƫ��ֵ
//    Motor->L_Change_P = Motor->L_Bas_KP + Motor->L_Gain_KP * (1 - 1.0 / FExp(Motor->L_Cp * Fabs(thisError)));

//    Motor->L_Change_I = (1.0 / FExp(Motor->L_Ci * Fabs(thisError))) * Motor->L_Max_I;

    result = vPID->result;

    iError = (thisError + lasterror) / 2.0; // ����ϴ�����������������Χ�ڣ���������

    pError      = thisError - lasterror;
    vPID->P_out = Motor->L_Bas_KP * pError;
    vPID->I_out = Motor->L_Max_I * iError;
    increment = vPID->P_out + vPID->I_out; // ����ֲ��û��ַ��룬��Ϊ���ַ��뱾�ʾ��Ǳ���ֵ�һ���������
    result    = result + increment;

    lasterror    = thisError;
    vPID->result = MINMAX(result, -100, 100);
}

void Motor_R_Control_Change_Integral(float setpoint, PID_2 *vPID, Motor_Para *Motor, int processValue)
{
    float thisError;
    float result;
    float increment;
    float pError           = 0;
    float iError           = 0;
    static float lasterror = 0; // ǰһ��ƫ��

    thisError         = setpoint - processValue; // �õ�ƫ��ֵ
//    Motor->R_Change_P = Motor->R_Bas_KP + Motor->R_Gain_KP * (1 - 1.0 / FExp(Motor->R_Cp * Fabs(thisError)));
//    Motor->R_Change_I = (1.0 / FExp(Motor->R_Ci * Fabs(thisError))) * Motor->R_Max_I;
    result            = vPID->result;

    iError = (thisError + lasterror) / 2.0; // ����ϴ�����������������Χ�ڣ���������

    pError = thisError - lasterror;

    vPID->P_out = Motor->L_Bas_KP * pError;
    vPID->I_out = Motor->L_Max_I * iError;
    increment = vPID->P_out + vPID->I_out;
    result    = result + increment;

    lasterror    = thisError;
    vPID->result = MINMAX(result, -100, 100);
}
