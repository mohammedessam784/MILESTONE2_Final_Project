/*
 * KEYPAD.h
 *
 * Created: 03-09-2024 8:13:21 PM
 *  Author: lapshop
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

 #define F_CPU 8000000UL
#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
 #include "../LCD/Lcd_types.h"
 #include "../../MCAL/DIO/dio.h"
 #include "../LCD/LCD.h"




#define KeypadPORT_ID PORTB_ID



void Keypad_Init();
u8 Keypad_ReadButton();
//u8 IsKeyPressed();




#endif /* KEYPAD_H_ */