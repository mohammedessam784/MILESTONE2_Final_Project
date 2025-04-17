/*
 * LCD.h
 *
 * Created: 28-08-2024 10:11:17 PM
 *  Author: lapshop
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../LIB/STD_types.h"
#include "Lcd_types.h"
#include "../../MCAL/DIO/dio.h"


//#define LCD_DATA_MODE 8

void Lcd_Init(void);
void Lcd_SendCommand(u8 command);
void Lcd_EnterData(void);
void Lcd_SendString(const u8*string);
void Lcd_ClearScreen(void);
void Lcd_SetCursor(u8 row,u8 col);
void Lcd_PrintInt(u16 num);
void Lcd_SendData(u8 data);




#endif /* LCD_H_ */