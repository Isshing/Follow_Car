#ifndef __PM_CONTROL_H__
#define __PM_CONTROL_H__
#include "headfile.h"

extern int SetLeft;
extern int SetRight;
extern char start_flag;

extern float fuzzy_kp_bas;
extern float fuzzy_P_out;
extern float fuzzy_D_out;
extern float fuzzy_I_out;
extern float fuzzy_kp;
extern float fuzzy_kd;
extern float kp_m;
extern float kd_m;
extern float DFF[7];
extern float EFF[7];
extern float fuzzy_ki;

extern float Vd;

void Speed_Control(void);
void Control_Init(void);
void Turn_Right(void);
void Turn_Left(void);
void Reback(void);
void pid_diff(void);

#endif /* HARDWARE_PID_H_ */
