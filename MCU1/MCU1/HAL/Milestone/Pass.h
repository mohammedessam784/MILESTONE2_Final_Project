/*
 * Pass.h
 *
 * Created: 19-09-2024 2:09:52 PM
 *  Author: lapshop
 */ 


#ifndef PASS_H_
#define PASS_H_

#include "../../LIB/STD_types.h"
#include "../KEYPAD/keypad.h"



#define CorrectPass 'A'
#define IncorrectPass 'B'

#define SetUp 0
#define TakeAction 1
#define Danger_Mode 2

#define Password_Change '-'

#define Open_Door '+'



 void MILESTONE_voidPasswordSetup();
 u8 MILESTONE_u8PasswordCheck(u8 operation);  
 void MILESTONE_voidChangPassword();
  void MILESTONE_voidBuzzer();
  void MILESTONE_voidOpenDoor();


#endif /* PASS_H_ */