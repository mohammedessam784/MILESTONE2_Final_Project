/*
 * Pass.c
 *
 * Created: 19-09-2024 2:25:37 AM
 *  Author: lapshop
 */

#include "Pass.h"
#include "../../LIB/STD_types.h"

void MILESTONE_voidPasswordSetup()
{
	Lcd_ClearScreen();
    Lcd_SendString("Plz enter pass:");
    Lcd_SetCursor(1,0);
    u8 key;
    u8 passLength=0;
    while(1)
    {
        key=Keypad_ReadButton();
        if (key)
        {
            if (key != 'C' && passLength<5)
            {
                Lcd_SendData('*');
				UART_sendByte(key);
                passLength++;
            }
            if(key=='C' && passLength==5)
            {
				UART_sendByte('\r');
                if(MILESTONE_u8PasswordCheck(SetUp))
                {
                    Lcd_ClearScreen();
                    //Lcd_SendString("Pass saved");
                    return;
                }

                else
                {
                    //Lcd_SendString("Pass missmatch");
                    return;
                }
            }
        }
    }
}

u8 Messages[2][16]= {"Re-enter ur pass","Enter ur pass"};

u8 MILESTONE_u8PasswordCheck(u8 operation)
{
	while(1){
    for (u8 trial = 3; trial > 0; trial--)
    {
        Lcd_ClearScreen();
        Lcd_SendString(Messages[operation]);  
        Lcd_SetCursor(1, 0);
        u8 passLength = 0;
        u8 key;
      
        while (1)
        {
			Lcd_SetCursor(1,8);
			Lcd_SendString("Trials=");
			Lcd_SendData(trial+48);
			
            key = Keypad_ReadButton();  

            if (key)
            {
                if (key != 'C' && passLength<5)    
                {
					Lcd_SetCursor(1, passLength);
                    Lcd_SendData('*');  
				    UART_sendByte(key); 
                    passLength++;
                }
                
                if (key =='C' && passLength == 5)
                {
						UART_sendByte('\r');
						u8 ch=UART_recieveByte();
                        if (ch==IncorrectPass)
                        {                           
                            Lcd_ClearScreen();
                            Lcd_SendString("Wrong Password");
                           break;  
                        }
					   else if(ch==CorrectPass)
					   {
						   Lcd_ClearScreen();
						   //Lcd_SendString("Correct Pass");
						   return CorrectPass;
					   }
                }
            }
        }
    }
    
    Lcd_ClearScreen();
	MILESTONE_voidBuzzer();
	}
    return IncorrectPass;  
}

void MILESTONE_voidChangPassword()
{
	 MILESTONE_u8PasswordCheck(TakeAction);
	 MILESTONE_voidPasswordSetup();
}


