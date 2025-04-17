/*
 * Lcd_types.h
 *
 * Created: 28-08-2024 10:34:55 PM
 *  Author: lapshop
 */ 


#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_

//Ports
#define Lcd_data_port PORTC_ID
#define Lcd_control_port PORTD_ID

//Control pins
#define RS_pin PIN2
#define RW_pin PIN3
#define	Enable_pin PIN4

//Data pins
#define D0 PIN0
#define D1 PIN1
#define D2 PIN2
#define D3 PIN3
#define D4 PIN4
#define D5 PIN5
#define D6 PIN6
#define D7 PIN7

//Commands (data pins)
#define Lcd_clr 0x01
#define Lcd_return_home 0x03
#define Lcd_shift_R 0x1F
#define Lcd_shift_L 0x1B
#define Set_Lcd_data_length 0x38
#define Lcd_DisplayOn 0x0C
#define FRIST_LINE_INDEX_0 0x80


#endif /* LCD_TYPES_H_ */