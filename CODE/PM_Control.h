#ifndef __PM_CONTROL_H__
#define __PM_CONTROL_H__
#include "headfile.h"

extern int SetLeft;
extern int SetRight;
extern char start_flag;

void Speed_Control(void);
void Control_Init(void);
void Turn_Right(void);
void Turn_Left(void);
void Reback(void);

#endif /* HARDWARE_PID_H_ */
