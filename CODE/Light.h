#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "headfile.h"

#define GET_VAL 0

#define C_0_VAL (P6IN&BIT6)
#define C_1_VAL (P6IN&BIT1)
#define C_2_VAL (P6IN&BIT2)
#define C_3_VAL (P6IN&BIT0)
#define C_4_VAL (P1IN&BIT6)
typedef struct
{
    short c_0;
    short c_1;
    short c_2;
    short c_3;
    short c_4;

} LIGHT;


typedef struct
{
    float Kp;
    float Ki;
    float kd;
    float line_err;
    float line_err_last;
    float target;
    float intergral;
    float out_val;

} LineErrPID;

extern LIGHT LINELIGHT;

extern LineErrPID LINECTL;
extern int corner_flag;
extern int beeb_flag;
extern int check_corner;
extern int corner_enter;
extern int circle_time;
extern int force_out;
extern int corner_find;
extern int problem;
extern int apoint_time;

void light_init(void);
void light_clear(void);
void light_get(void);
void Light_Error(LIGHT *light, LineErrPID *pid);
void PID_LINE_SET(LineErrPID *pid);

#endif
