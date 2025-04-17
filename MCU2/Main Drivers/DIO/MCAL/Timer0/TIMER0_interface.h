/*
 * TIMER0_interface.h
 *
 * Created: 9/2/2024 4:37:10 PM
 *  Author: Mohamed Mamdouh
 */
 
#include "../../LIB/STD_TYPES.h"

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TIMER0_OVF_INT_ID          0
#define TIMER0_COMP_MATCH_INT_ID   1

extern u32  Timer0_NumOfOV ;
extern u32  Timer0_NumOfCM ;
void Timer0_vInit(void);
void Timer0_vStop(void);
void Timer0_vStart(void);
void Timer0_vEnableInt(u8 IntId);
void Timer0_vDisableInt(u8 IntId);
void Timer0_vSetTime(u32 DesiredTime_ms);

void Timer0_SetPhaseCorrect(u8 DutyCycle);
void Timer0_SetFastPWM(u8 DutyCycle);

#endif /* TIMER0_INTERFACE_H_ */