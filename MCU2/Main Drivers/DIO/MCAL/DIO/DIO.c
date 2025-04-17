/*
 * DIO.c
 *
 * Created: 22/08/2024 06:44:17 PM
 *  Author: AbdUllah
 */ 
#include "DIO.h"

void DIO_voidSetPinDirection (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8DIRECTION)
{
if(Copy_u8DIRECTION==PIN_INPUT)
{
    switch(Copy_u8PORT)
	{
	 case PORTA_ID : ClrBit( DDRA,Copy_u8PIN ); break;	   
	 case PORTB_ID : ClrBit( DDRB,Copy_u8PIN ); break;
	 case PORTC_ID : ClrBit( DDRC,Copy_u8PIN ); break;
	 case PORTD_ID : ClrBit( DDRD,Copy_u8PIN ); break;
	 default:                                   break;
	}
}
else/*PIN_OUTPUT*/
{
	switch(Copy_u8PORT)
	{
	 case PORTA_ID : SetBit( DDRA,Copy_u8PIN ); break;
	 case PORTB_ID : SetBit( DDRB,Copy_u8PIN ); break;
	 case PORTC_ID : SetBit( DDRC,Copy_u8PIN ); break;
	 case PORTD_ID : SetBit( DDRD,Copy_u8PIN ); break;
	 default:                                   break;
	}

}

}


void DIO_voidSetPortDirection (u8 Copy_u8PORT , u8 Copy_u8Direction )
{
	
	switch(Copy_u8PORT)
	{
		case PORTA_ID :  DDRA=Copy_u8Direction ; break;
		case PORTB_ID :  DDRB=Copy_u8Direction ; break;
		case PORTC_ID :  DDRC=Copy_u8Direction ; break;
		case PORTD_ID :  DDRD=Copy_u8Direction ; break;
		default:                                 break;
	}
	
}

void DIO_voidSetPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE)
{
	if(Copy_u8VALUE==PIN_HIGH)
	{
	   switch(Copy_u8PORT)
	   {
		   case PORTA_ID : SetBit( PORTA,Copy_u8PIN ); break;
		   case PORTB_ID : SetBit( PORTB,Copy_u8PIN ); break;
		   case PORTC_ID : SetBit( PORTC,Copy_u8PIN ); break;
		   case PORTD_ID : SetBit( PORTD,Copy_u8PIN ); break;
		   default:                                    break;
	   }
	}
	else/*PIN_low*/
	{
		switch(Copy_u8PORT)
		{
			case PORTA_ID : ClrBit( PORTA,Copy_u8PIN ); break;
			case PORTB_ID : ClrBit( PORTB,Copy_u8PIN ); break;
			case PORTC_ID : ClrBit( PORTC,Copy_u8PIN ); break;
			case PORTD_ID : ClrBit( PORTD,Copy_u8PIN ); break;
			default:                                    break;
		}
	}	
}


void DIO_voidSetPortValue (u8 Copy_u8PORT , u8 Copy_u8VALUE)
{
 
    switch(Copy_u8PORT)
    {
	    case PORTA_ID :  PORTA=Copy_u8VALUE ; break;
	    case PORTB_ID :  PORTB=Copy_u8VALUE ; break;
	    case PORTC_ID :  PORTC=Copy_u8VALUE ; break;
	    case PORTD_ID :  PORTD=Copy_u8VALUE ; break;
	    default:                              break;
    }	
	 
}


u8 DIO_u8GetPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	   switch(Copy_u8PORT)
	   {
		   case PORTA_ID :  return GetBit(PINA,Copy_u8PIN) ; break;
		   case PORTB_ID :  return GetBit(PINB,Copy_u8PIN) ; break;
		   case PORTC_ID :  return GetBit(PINC,Copy_u8PIN) ; break;
		   case PORTD_ID :  return GetBit(PIND,Copy_u8PIN) ; break;
		   default:                                          break;
	   }
}

u8 DIO_u8GetPortValue(u8 Copy_u8PORT)
{
	switch(Copy_u8PORT)
	{
		case PORTA_ID :  return PINA; break;
		case PORTB_ID :  return PINB; break;
		case PORTC_ID :  return PINC; break;
		case PORTD_ID :  return PIND; break;
		default:                      break;
	}
}


void DIO_voidTogelPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	switch(Copy_u8PORT)
	{
		case PORTA_ID : TogelBit( PORTA,Copy_u8PIN ); break;
		case PORTB_ID : TogelBit( PORTB,Copy_u8PIN ); break;
		case PORTC_ID : TogelBit( PORTC,Copy_u8PIN ); break;
		case PORTD_ID : TogelBit( PORTD,Copy_u8PIN ); break;
		default:                                      break;
	}
}
