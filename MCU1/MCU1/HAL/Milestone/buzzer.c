/*
 * buzzer.c
 *
 * Created: 30-09-2024 5:51:23 PM
 *  Author: lapshop
 */ 
#include "../LCD/LCD.h"
#include "../LCD/Lcd_types.h"
#include "../../LIB/STD_types.h"
#include "Pass.h"

 void MILESTONE_voidBuzzer(){
	 u8 counter_buzzer;
	Lcd_ClearScreen();
	Lcd_SetCursor(0,2);
	Lcd_SendString("  \"WARNING\"  ");
	Lcd_SetCursor(1,0);
	Lcd_SendString("Wait for ");
	 while(1)
	 {
		counter_buzzer=UART_recieveByte();
		if (counter_buzzer=='C')
		{
			Lcd_ClearScreen();
			return;
		}
	     else if(counter_buzzer>'0')
	     {
		     Lcd_SetCursor(1,9);
		     Lcd_SendData(counter_buzzer);

	     }
	    Lcd_SetCursor(1,11); 
	    Lcd_SendString(" sec");
	 }
 }
 
void MILESTONE_voidOpenDoor()
{
	MILESTONE_u8PasswordCheck(TakeAction);
	u8 count_motor=0;
	while(1)
	{
		count_motor=UART_recieveByte();
		if (count_motor<=15)
		{
			Lcd_SendCommand( FRIST_LINE_INDEX_0 );
			Lcd_SendString("\"Door Unlocking\" ");
		}
		else if(count_motor>15 && count_motor<=18){
			Lcd_SendCommand( FRIST_LINE_INDEX_0 );
			Lcd_SendString("     \"Hold\"     ");
		}
		else if(count_motor>18 && count_motor<=33){
			Lcd_SendCommand(FRIST_LINE_INDEX_0 );
			Lcd_SendString(" \"Door Locking\" ");
		}
		else
		{
			Lcd_ClearScreen();
			return;
		}
		
	}
	
}
 
