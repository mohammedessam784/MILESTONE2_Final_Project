/*
 * TIMER2_interface.h
 *
 * Created: 18/09/2024 02:06:47 AM
 *  Author: AbdUllah
 */ 


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

#include "../../LIB/STD_types.h"

#define TIMER2_OVF_INT_ID          0
#define TIMER2_COMP_MATCH_INT_ID   1

extern u32  Timer2_NumOfOV ;
extern u32  Timer2_NumOfCM ;
void Timer2_vInit(void);
void Timer2_vStop(void);
void Timer2_vStart(void);
void Timer2_vEnableInt(u8 IntId);
void Timer2_vDisableInt(u8 IntId);
void Timer2_vSetTime(u32 DesiredTime_ms);

void Timer2_SetPhaseCorrect(u8 DutyCycle);
void Timer2_SetFastPWM(u8 DutyCycle);

void Timer2_vCrystalOscillatorEnable();




#endif /* TIMER2_INTERFACE_H_ */