/*
 * LCD.c
 *
 * Created: 28-08-2024 10:10:23 PM
 *  Author: lapshop
 */ 

#include "LCD.h"

//#if (LCD_DATA_MODE != 8)
//#error "No of Data Must be 8"
//#endif

void Lcd_Init(void){
	SetPortDirection (Lcd_data_port,PORT_OUT);
	//SetPortDirection (Lcd_control_port,PORT_OUT);
	SetPinDirection(Lcd_control_port,RS_pin,OUTPUT);
		SetPinDirection(Lcd_control_port,RW_pin,OUTPUT);
	SetPinDirection(Lcd_control_port,Enable_pin,OUTPUT);

	_delay_ms(40);
	Lcd_SendCommand(Set_Lcd_data_length);
	_delay_us(40);
	Lcd_SendCommand(Lcd_DisplayOn);
	_delay_us(40);
	Lcd_SendCommand(Lcd_clr);
	_delay_ms(2);
	Lcd_EnterData();
}	 

void Lcd_SendCommand(u8 command){
	SetPinValue(Lcd_control_port,RW_pin,Pin_LOW);
	SetPinValue(Lcd_control_port,RS_pin,Pin_LOW);
	SetPortValue(Lcd_data_port,command);
	Lcd_EnterData();
}

void Lcd_EnterData(void){
	SetPinValue(Lcd_control_port,Enable_pin,Pin_HIGH);
	_delay_ms(1);
	SetPinValue(Lcd_control_port,Enable_pin,Pin_LOW);
}

void Lcd_SendData(u8 data){
	SetPinValue(Lcd_control_port,RW_pin,Pin_LOW);
	SetPinValue(Lcd_control_port,RS_pin,Pin_HIGH);
	SetPortValue(Lcd_data_port,data);
	Lcd_EnterData();
}

void Lcd_SendString(const u8*string){
	u8 i=0;
	while(string[i]!='\0'){
		Lcd_SendData(string[i]);
		i++;
}
}

void Lcd_ClearScreen(){
	Lcd_SendCommand(Lcd_clr);
}

void Lcd_SetCursor(u8 row,u8 col){
	if (row>=0 && row<2 && col>=0 && col<16)
	{	u8 address;
		address=(row * 0x40)+col;
		SetBit(address,PIN7);
		Lcd_SendCommand(address);				
	} 
	else
	{}
}

void Lcd_PrintInt(u16 num){
	u8 lastDigit;
	u8 strInt[10];
	u16 i=0;
	if(num<10){
		Lcd_SendData(num+48);
		return;
	}
	while(num!=0){
		lastDigit=num%10;
		num/=10;
		strInt[i]=lastDigit+48;
		i++;
	}
	/*for(u32 j=i-1;j>=0;j--){
		Lcd_SendData(strInt[j]);
	}*/
	u16 j;
	for(j=0;j<(i/2);j++){
		u8 ch;
		ch=strInt[j];
		strInt[j]=strInt[i-1-j];
		strInt[i-1-j]=ch;
		
	}
	strInt[i]='\0';
	Lcd_SendString(strInt);
}	


