/*
 * Buzzer.h
 *
 * Created: 20/09/2024 04:41:19 PM
 *  Author: AbdUllah
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "../../LIB/STD_types.h"
#include "../In_Out/inputs_and_outputs.h"
#include "../../MCAL/DIO/DIO.h"

extern volatile u8 count_buzzer;
void MILESTONE_voidBuzzerIniti();
void MILESTONE_voidBuzzer();




#endif /* BUZZER_H_ */