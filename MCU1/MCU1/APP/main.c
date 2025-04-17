/*
 * main.c
 *
 * Created: 28-09-2024 10:08:32 PM
 *  Author: lapshop
 */ 
  #include "../MCAL/ADC/adc.h"
  #include "../MCAL/ADC/lm35.h"
  #include "../MCAL/INT/Exit.h"
  #include "../MCAL/TIMER2/TIMER2_Private.h"
  #include "../MCAL/TIMER2/TIMER2_Config.h"
  #include "../MCAL/TIMER2/TIMER2_interface.h" 
  #include "../MCAL/UART/UART_configuration.h"
  #include "../MCAL/UART/UART_interface.h"
  #include "../MCAL/UART/UART_private.h"
  
   #include "../HAL/Milestone/Pass.h"
  volatile u16 temp;
  
  int main(){
	  UART_init(9600);
	  Lcd_Init();
	  Keypad_Init();
	  ADC_init(ADC_Divide_by_64);
	  ADC_enableInt();
	  Timer2_vInit();
	  Timer2_vStart();
	  
	  temp=LM35_getTemperature();
	
	  MILESTONE_voidPasswordSetup();
	  u8 key;
	  
	  while (1)
	  {
		  Lcd_SetCursor(0, 0);
		  Lcd_SendString(" '+' Open Door  ");
		  Lcd_SetCursor(1, 0);
		  Lcd_SendString(" '-' Pass Change");
		  
		  key=Keypad_ReadButton();
		  if(key=='+' || key=='-')
		  {
			UART_sendByte(key);
			switch(key){
				case Open_Door : //'+'
				MILESTONE_voidOpenDoor();
				break;
				case Password_Change://'-'
				MILESTONE_voidChangPassword();
				break;
				default: break;
			}
	    }
  }
}
  ISR(ADC_vect){
	 temp=LM35_getTemperature();
	 	  if (temp<20)
	 	  {
		 	  Timer2_SetFastPWM(0);
	 	  }
	 	  else if(temp>=20 && temp<25){
		 	  Timer2_SetFastPWM(10);
	 	  }
	 	  else if(temp>=25 && temp<35){
		 	  Timer2_SetFastPWM(50);
	 	  }
	 	  else if(temp>=35){
		 	  Timer2_SetFastPWM(100);
	 	  }

	 SetBit(ADCSRA,ADCSRA_ADSC);
  	  
  }	 

