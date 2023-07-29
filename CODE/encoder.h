
#ifndef ENCODER_H_
#define ENCODER_H_
#include "headfile.h"

#define LEFTDIRECTION BIT7
#define RIGHTDIRECTION BIT3

extern int speed_R;
extern int speed_L;
extern int encoder_R;
extern int encoder_L;
extern int encoder_RR;
extern int encoder_LL;
extern const int EncoderPerMeter;
extern int LeftMotor_TotalEncoder;
extern int RightMotor_TotalEncoder;
extern float Avg_speed;

void encoder_init(void);
void encoder_read(void);

void EncoderCount(void);
float GetEncoder(void);
void Encoder_clear(void);
void Get_Speed(void);

#endif /* ENCODER_H_ */
