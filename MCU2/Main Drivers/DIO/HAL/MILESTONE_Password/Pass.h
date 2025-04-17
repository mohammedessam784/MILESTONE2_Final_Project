/*
 * Pass.h
 *
 * Created: 19-09-2024 2:09:52 PM
 *  Author: lapshop
 */ 


#ifndef PASS_H_
#define PASS_H_

#include "../../LIB/STD_types.h"



#include "../../MCAL/UART/UART_configuration.h"
#include "../../MCAL/UART/UART_interface.h"

#define CorrectPass 1
#define IncorrectPass 0

#define SetUp 0
#define TakeAction 1
#define Danger_Mode 2

#define Password_Change '-'

extern u8 flag;
 extern u8 password [5];
 void MILESTONE_voidPasswordSetup();
 u8 MILESTONE_u8PasswordCheck(u8 OriginalPass[],u8 operation);  
 void MILESTONE_voidChangPassword();



#endif /* PASS_H_ */