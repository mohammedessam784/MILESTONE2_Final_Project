/*
 * inputs_and_outputs.c
 *
 * Created: 04/09/2024 07:31:40 PM
 *  Author: AbdUllah
 */ 

#include "inputs_and_outputs.h"

void INPUT_Initi_Pullup(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	DIO_voidSetPinDirection( Copy_u8PORT , Copy_u8PIN , PIN_INPUT);
	DIO_voidSetPinValue( Copy_u8PORT , Copy_u8PIN ,PIN_HIGH);
}

void OUTPUT_Initi(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	DIO_voidSetPinDirection( Copy_u8PORT , Copy_u8PIN , PIN_OUTPUT);
}


void OUTPUT_Set(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	DIO_voidSetPinValue( Copy_u8PORT , Copy_u8PIN , PIN_HIGH);
}

void OUTPUT_Reset(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	DIO_voidSetPinValue( Copy_u8PORT , Copy_u8PIN , PIN_LOW);
}

void OUTPUT_Togel(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	DIO_voidTogelPinValue( Copy_u8PORT , Copy_u8PIN );
}



u8 INPUT_GET(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	return DIO_u8GetPinValue(Copy_u8PORT , Copy_u8PIN );
}

u8 OUTPUT_GET(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
	return DIO_u8GetPinValue(Copy_u8PORT , Copy_u8PIN );
}





