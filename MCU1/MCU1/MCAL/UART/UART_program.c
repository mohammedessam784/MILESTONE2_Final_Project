/*
 * UART_program.c
 *
 * Created: 25-09-2024 8:14:12 PM
 *  Author: lapshop
 */ 
#include "UART_configuration.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "util/delay.h"


void UART_init(u32 baud_rate){
	SetBit(UCSRA_REG ,U2X_BIT);	//double the transmisson speed
	
	SetBit(UCSRB_REG,RXEN_BIT);	//enable receiver and transmitter
	SetBit(UCSRB_REG,TXEN_BIT);
		 
	SetBit(UCSRC_REG,URSEL_BIT);//access UCSRC
	
	SetBit(UCSRC_REG,UCSZ0_BIT);//8-bit mode
	SetBit(UCSRC_REG,UCSZ1_BIT);
	
	u16 UBRR_Val = (u16)(((F_CPU / (baud_rate * 8UL))) - 1); //decide baud rate
															  //ubrr: 0->4095	
	UBRRH_REG = UBRR_Val>>8;
	UBRRL_REG = UBRR_Val;
}

void UART_sendByte(const u8 data){
	while(!GetBit(UCSRA_REG,UDRE_BIT)); //UDRE Flag=1 means that the TX buffer is empty and ready to transmit data
	UDR_REG = data;
}

u8 UART_recieveByte(void){
	while(!GetBit(UCSRA_REG,RXC_BIT));
	//UART_sendByte(UDR_REG);
	return UDR_REG;
}

void UART_sendString(const u8 *str){
	while (*str != '\0')
	{
		UART_sendByte(*str);
		str++;
		_delay_us(1);
	}
}

void UART_receiveString(u8 *Str){
	u8 i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '\0')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

}





