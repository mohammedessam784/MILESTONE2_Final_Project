/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_interface.h
 *
 * Description: Interface Header file for the UART AVR driver
 *
 * Author: Jana Wael
 *
 *******************************************************************************/

#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_TYPES.h"
#include "UART_configuration.h"

extern void (*UART_CallBack)();
void UART_init(u32 baud_rate);
void UART_sendByte(const u8 data);
u8 UART_receiveByte(void);
void UART_sendString(const u8 *str);
void UART_receiveString(u8 *Str);



#endif /* UART_UART_INTERFACE_H_ */