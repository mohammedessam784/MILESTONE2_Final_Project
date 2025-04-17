/*
 * Pass.c
 *
 * Created: 19-09-2024 2:25:37 AM
 *  Author: lapshop
 */

#include "Pass.h"



u8 flag=0;
u8 password [5];
void MILESTONE_voidPasswordSetup()
{
	u8 key;
    u8 passLength=0;
    u8 _1stPass[5];
    while(1)
    {
        key=UART_receiveByte();
        if (key)
        {
            if (key != '\r' && passLength<5)
            {
                _1stPass[passLength]=key;
                passLength++;
            }
            if(key=='\r' && passLength==5)
            {
                if(MILESTONE_u8PasswordCheck(_1stPass,SetUp))
                {
                    for(u8 i=0; i<passLength; i++)
					{
                        password[i]=_1stPass[i];
					}
                    return;
                }
            }
        }
    }
}

u8 Messages[2][16]= {"Re-enter ur pass","Enter ur pass"};

u8 MILESTONE_u8PasswordCheck(u8 OriginalPass[], u8 operation)
{
	 while (1)// buzzer_return:
	 {
    for (u8 trial = 3; trial > 0; trial--)
    {
        u8 passLength = 0;
        u8 _2ndPass[5];  
        u8 key;

        
        while (1)
        {
            key=UART_receiveByte();
            if (key)
            {
                if (key != '\r' && passLength<5)    
                {
                    _2ndPass[passLength] = key;  
                    passLength++;
                }
                
                if (key =='\r'&& passLength == 5)
                {
                    u8 i;
                    for (i = 0; i < passLength; i++)
                    {
                        if (OriginalPass[i] != _2ndPass[i])
                        {
                            break;  // Exit the for(passlength loop)
                        }
						
                    }


                    if (i == passLength)
                    {
						UART_sendByte('A');
                        return CorrectPass;  
                    }
					else
					{
						UART_sendByte('B');
						break;
					}
					
                }
            }
        }
    }
	
	 MILESTONE_voidBuzzer();
	 }
    return IncorrectPass;  
}

void MILESTONE_voidChangPassword()
{
	 MILESTONE_u8PasswordCheck(password , TakeAction);
	 MILESTONE_voidPasswordSetup();
}


