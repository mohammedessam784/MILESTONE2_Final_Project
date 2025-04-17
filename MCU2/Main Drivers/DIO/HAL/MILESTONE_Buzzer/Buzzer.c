/*
 * Buzzer.c
 *
 * Created: 20/09/2024 04:41:44 PM
 *  Author: AbdUllah
 */ 

#include "buzzer.h"
volatile u8 count_buzzer=0;
void MILESTONE_voidBuzzerIniti()
{
	OUTPUT_Initi(PORTB_ID,PIN5_ID);
}

void MILESTONE_voidBuzzer()
{
	count_buzzer=0;
	OUTPUT_Set(PORTB_ID,PIN5_ID);
	while(1)
	{ 
		   if (count_buzzer<9)
		   {
			   UART_sendByte(57-count_buzzer);
		   }
		   else
		   {
			   UART_sendByte('C');
			   OUTPUT_Reset(PORTB_ID,PIN5_ID);
			   break;
		   }
    }
}
