/*
 * inputs_and_outputs.h
 *
 * Created: 04/09/2024 07:32:07 PM
 *  Author: AbdUllah
 */ 


#ifndef INPUTS_AND_OUTPUTS_H_
#define INPUTS_AND_OUTPUTS_H_

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO.h"

void INPUT_Initi_Pullup(u8 Copy_u8PORT , u8 Copy_u8PIN);
void OUTPUT_Initi(u8 Copy_u8PORT , u8 Copy_u8PIN);

void OUTPUT_Set(u8 Copy_u8PORT , u8 Copy_u8PIN);
void OUTPUT_Reset(u8 Copy_u8PORT , u8 Copy_u8PIN);
void OUTPUT_Togel(u8 Copy_u8PORT , u8 Copy_u8PIN);

u8 INPUT_GET(u8 Copy_u8PORT , u8 Copy_u8PIN);
u8 OUTPUT_GET(u8 Copy_u8PORT , u8 Copy_u8PIN);

#endif /* INPUTS_AND_OUTPUTS_H_ */