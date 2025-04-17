/*
 * dio.h
 *
 * Created: 28-08-2024 11:16:54 PM
 *  Author: lapshop
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../LIB/BitMath.h"
#include "../../LIB/STD_types.h"

#define PORTA *((volatile u8 *)0x3B)
#define DDRA *((volatile u8 *)0x3A)
#define PINA *((volatile u8 *)0x39)

#define PORTB  *((volatile u8*)0x38)
#define DDRB *((volatile u8*)0x37)
#define PINB *((volatile u8*)0x36)

#define PORTC *((volatile u8 *)0x35)
#define DDRC *( (volatile u8 *)0x34)
#define PINC *((volatile u8 *)0x33)

#define PORTD *((volatile u8*)0x32)
#define DDRD *((volatile u8*)0x31)
#define PIND *((volatile u8*)0x30)

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


#define Pin_LOW 0
#define Pin_HIGH 1

#define INPUT 0
#define OUTPUT 1

#define PORT_IN 0x0
#define PORT_OUT 0xFF
				  
#define PORT_LOW 0x0
#define PORT_HIGH 0xFF

//functions 
void SetPinDirection(u8 PORT , u8 PIN , u8 DIRECTION);	  

void SetPinValue(u8 PORT , u8 PIN , u8 VALUE);	

void SetPortValue(u8 PORT , u8 VALUE);	

u8 GetPinValue(u8 PORT , u8 PIN );

void SetPortDirection(u8 PORT , u8 Direction );	

u8 GetPortValue(u8 PORT);

#endif /* DIO_H_ */