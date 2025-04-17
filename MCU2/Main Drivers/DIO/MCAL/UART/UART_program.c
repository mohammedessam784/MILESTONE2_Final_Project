/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_program.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: Jana Wael
 *
 *******************************************************************************/

#include "UART_interface.h"
#include "UART_configuration.h"
#include "UART_private.h"
#include "../../LIB/BitMath.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void (*UART_CallBack)()=0;
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(u32 baud_rate)
{
	u16 ubrr_value = 0;

	/* U2X = 1 for double transmission speed */
	SetBit(UCSRA_REG ,U2X_BIT);
	
	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * TXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	SetBit(UCSRB_REG,RXEN_BIT);
	SetBit(UCSRB_REG,TXEN_BIT);
	
	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/ 	
	SetBit(UCSRC_REG,URSEL_BIT);
	SetBit(UCSRC_REG,UCSZ0_BIT);
	SetBit(UCSRC_REG,UCSZ1_BIT);
// 	ClrBit(UCSRC_REG,UPM0_BIT);
// 	ClrBit(UCSRC_REG,UPM1_BIT);
	
	/* Calculate the UBRR register value */
	ubrr_value = UART_BR_8MHZ_9600*2; //use 16UL if you're not using double speed mode

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH_REG = ubrr_value>>8;
	UBRRL_REG = ubrr_value;
}




/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const u8 data)
{
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while(!GetBit(UCSRA_REG,UDRE_BIT)){}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	_delay_us(100);
	UDR_REG = data;

	/************************* Another Method *************************
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transmission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	*******************************************************************/
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
u8 UART_receiveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(!GetBit(UCSRA_REG,RXC_BIT))
	{
	 // UART_CallBack();	
	}

	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
	
    return UDR_REG;		
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const u8 *str)
{
	while (*str != '\0')
	{
		UART_sendByte(*str);
		str++;
		_delay_us(1);
	}
	UART_sendByte('\r'); //to indicate that this is the end of the string
}



/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(u8 *Str)
{
	u8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_receiveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '\r')
	{
		i++;
		Str[i] = UART_receiveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}

