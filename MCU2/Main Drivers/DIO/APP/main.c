/*
 * main.c
 *
 * Created: 25/08/2024 06:09:11 PM
 *  Author: AbdUllah
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"
#include "../MCAL/Interrupt/interrupt.h"
#include "../MCAL/UART/UART_configuration.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/Timer2/Timer2_Config.h"
#include "../MCAL/Timer2/Timer2_interface.h"
#include "../HAL/In_Out/inputs_and_outputs.h"

#include "../HAL/MILESTONE_Motor/Motor.h"
#include "../HAL/MILESTONE_Password/Pass.h"
#include "../HAL/MILESTONE_Buzzer/Buzzer.h"
volatile u32 count=0;



int main(void)
{	
	Timer2_vInit();
	Timer2_vStart();
	Timer2_vSetTime(1000);
	Timer2_vEnableInt(TIMER2_COMP_MATCH_INT_ID);
	
	UART_init(9600);
	MILESTONE_voidBuzzerIniti();
    MILESTONE_voidMotorIniti();
	
    MILESTONE_voidPasswordSetup();

		 u8 key;
		 while (1)
         {    
			  key=UART_receiveByte();
			 switch(key)
			 {
				 {
					 case Open_Door : //'+'Open Door
					 MILESTONE_voidOpenDoor();
					 break;
					 case Password_Change://'-'Password Change
					 MILESTONE_voidChangPassword();
					 break;
					 default: break;
				 }
			 }		
         }
	
}

ISR(TIMER2_COMP_vect)
{
	
	if (count++ ==Timer2_NumOfCM)
	{
		count=0;
		count_motor++;
		count_buzzer++;
	}
}


