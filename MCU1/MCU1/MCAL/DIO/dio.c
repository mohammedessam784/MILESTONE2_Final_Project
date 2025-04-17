/*
 * dio.c
 *
 * Created: 28-08-2024 11:27:25 PM
 *  Author: lapshop
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "dio.h"
#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"


void SetPortDirection(u8 PORT,u8 Direction ){
		switch(PORT){
			case PORTA_ID:
				DDRA=Direction;
				break;
			case PORTB_ID:
				DDRB=Direction;
				break;
			case PORTC_ID:
				DDRC=Direction;
				break;
			case PORTD_ID:
				DDRD=Direction;
				break;
		}
}

void SetPinValue(u8 PORT , u8 PIN , u8 VALUE){
	if(VALUE==Pin_LOW){
		switch(PORT){
			case PORTA_ID :
				ClrBit(PORTA,PIN);
				break;	
			case PORTB_ID :
				ClrBit(PORTB,PIN);
				break;
			case PORTC_ID :
				ClrBit(PORTC,PIN);
				break;
			case PORTD_ID :
				ClrBit(PORTD,PIN);
				break;
	}
	}
	else if(VALUE==Pin_HIGH){
		switch(PORT){
			case PORTA_ID:
			SetBit(PORTA,PIN);
			break;
			case PORTB_ID:
			SetBit(PORTB,PIN);
			break;
			case PORTC_ID:
			SetBit(PORTC,PIN);
			break;
			case PORTD_ID:
			SetBit(PORTD,PIN);
			break;
		}
	}	
}

void SetPortValue(u8 PORT , u8 VALUE){
			switch(PORT){
				case PORTA_ID:
					PORTA=VALUE;
					break;
				case PORTB_ID:
					PORTB=VALUE;
					break;
				case PORTC_ID:
					PORTC=VALUE;
					break;
				case PORTD_ID:
					PORTD=VALUE;
					break;
			}
}

void SetPinDirection(u8 PORT , u8 PIN , u8 DIRECTION){
	 	if(DIRECTION==INPUT){
		 	switch(PORT){
			 	case PORTA_ID :
			 	ClrBit(DDRA,PIN);
			 	break;
			 	case PORTB_ID :
			 	ClrBit(DDRB,PIN);
			 	break;
			 	case PORTC_ID :
			 	ClrBit(DDRC,PIN);
			 	break;
			 	case PORTD_ID :
			 	ClrBit(DDRD,PIN);
			 	break;
				default: break;
		 	}
	 	}
	 	else if(DIRECTION==OUTPUT){
		 	switch(PORT){
			 	case PORTA_ID:
			 	SetBit(DDRA,PIN);
			 	break;
			 	case PORTB_ID:
			 	SetBit(DDRB,PIN);
			 	break;
			 	case PORTC_ID:
			 	SetBit(DDRC,PIN);
			 	break;
			 	case PORTD_ID:
			 	SetBit(DDRD,PIN);
			 	break;
				default: break;
		 	}
	 	}
 	}

u8 GetPinValue(u8 PORT , u8 PIN ){
	switch(PORT){
			case PORTA_ID :
			return GetBit(PINA,PIN);
			
			case PORTB_ID :
			return GetBit(PINB,PIN);
			
			case PORTC_ID :
			return GetBit(PINC,PIN);
			
			case PORTD_ID :
			return GetBit(PIND,PIN);
			
			default: return;
	}
	
	}

u8 GetPortValue(u8 PORT){
		switch(PORT){
			case PORTA_ID :
			return PINA;
			
			case PORTB_ID :
			return PINB;
			
			case PORTC_ID :
			return PINC;
			
			case PORTD_ID :
			return PIND;
			
			default: return;
		}
		

}

					  