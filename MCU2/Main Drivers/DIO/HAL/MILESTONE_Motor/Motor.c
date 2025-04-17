/*
 * Motor.c
 *
 * Created: 18/09/2024 05:51:26 PM
 *  Author: AbdUllah
 */ 
#include "Motor.h"
volatile u32 count_motor=0;
void MILESTONE_voidMotorIniti()
{
	OUTPUT_Initi(PORTB_ID,PIN0_ID);
	OUTPUT_Initi(PORTB_ID,PIN1_ID);
	OUTPUT_Initi(PORTB_ID,PIN2_ID);
	Timer0_vInit();
	Timer0_vStart();
	Timer0_SetFastPWM(0);
	OUTPUT_Initi(PORTB_ID,PIN4_ID);
}


void MILESTONE_voidOpenDoor()
{
	MILESTONE_u8PasswordCheck(password , TakeAction);
	count_motor=0;
	 while(1)
	 {
		 UART_sendByte(count_motor);
		 
		if (count_motor<=15)
		{
			OUTPUT_Set(PORTB_ID,PIN0_ID);
			OUTPUT_Reset(PORTB_ID,PIN1_ID);
			OUTPUT_Reset(PORTB_ID,PIN2_ID);
			
			Timer0_SetFastPWM(100);
			OUTPUT_Reset(PORTB_ID,PIN4_ID);
			
		}
		else if(count_motor>15 && count_motor<=18)
		{
            OUTPUT_Reset(PORTB_ID,PIN0_ID);
            OUTPUT_Set(PORTB_ID,PIN1_ID);
            OUTPUT_Reset(PORTB_ID,PIN2_ID);
			
			Timer0_SetFastPWM(0);
			OUTPUT_Reset(PORTB_ID,PIN4_ID);
		}
		else if(count_motor>18 && count_motor<=33)
		{
			OUTPUT_Reset(PORTB_ID,PIN0_ID);
			OUTPUT_Reset(PORTB_ID,PIN1_ID);
			OUTPUT_Set(PORTB_ID,PIN2_ID);
			
			Timer0_SetFastPWM(75);
			OUTPUT_Set(PORTB_ID,PIN4_ID);
		}
		else
		{
			OUTPUT_Reset(PORTB_ID,PIN0_ID);
			OUTPUT_Reset(PORTB_ID,PIN1_ID);
			OUTPUT_Reset(PORTB_ID,PIN2_ID);
			Timer0_SetFastPWM(0);
			OUTPUT_Reset(PORTB_ID,PIN4_ID);
			UART_sendByte('D');
			break;
		}
		 
	 }
	 
}

