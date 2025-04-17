/*
 * UART_interface.h
 *
 * Created: 25-09-2024 7:53:16 PM
 *  Author: lapshop
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_types.h"
#include "UART_configuration.h"

void UART_init(u32 baud_rate);
void UART_sendByte(const u8 data);
u8 UART_recieveByte(void);
void UART_sendString(const u8 *str);
void UART_receiveString(u8 *Str);




#endif /* UART_INTERFACE_H_ */