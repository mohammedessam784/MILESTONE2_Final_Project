/*
 * KEYPAD.c
 *
 * Created: 03-09-2024 8:13:07 PM
 *  Author: lapshop
 */ 
  #include "KEYPAD.h"
  #include <util/delay.h>

  
  void Keypad_Init(){
	  SetPortDirection(KeypadPORT_ID,0xF0); //cols-> 7-4 ->output , rows-> 3-0 ->input 			
	  SetPortValue(KeypadPORT_ID,0xFF);  // high output / pull-up input
  }
  
 
 u8 Keypad_ReadButton(){
	   for(u8 col=4;col<8;col++){
		   	SetPinValue(KeypadPORT_ID,col,Pin_LOW);
			for(u8 row=0;row<4;row++){
				if(! GetPinValue(KeypadPORT_ID,row)){
						//_delay_ms(30);
						if(! GetPinValue(KeypadPORT_ID,row)){
							while(! GetPinValue(KeypadPORT_ID,row));
							u8 keyMap[4][4]={ {'7','8','9','/'},
											{'4','5','6','x'},
											{'1','2','3','-'},
											{'C','0','=','+'} };
							u8 ch=keyMap[row][col-4];
							return ch;
						}						
			  }
			 }
			SetPinValue(KeypadPORT_ID,col,Pin_HIGH);
	   }
	   return 0;
}

  
  
  
					  
