/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_configuration.h
 *
 * Description: Configuration Header File for UART AVR Driver
 *
 * Author: Jana Wael
 *
 *******************************************************************************/
 
#ifndef UART_UART_CONFIGURATION_H_
#define UART_UART_CONFIGURATION_H_

#define F_CPU				8000000UL
/*
 * Choose data size:
 * UART_DATA_SIZE_5_BITS
 * UART_DATA_SIZE_6_BITS
 * UART_DATA_SIZE_7_BITS
 * UART_DATA_SIZE_8_BITS
 */
#define UART_DATA_SIZE		UART_DATA_SIZE_8_BITS

/*
 * Choose parity:
 * UART_PARITY_ODD
 * UART_PARITY_EVEN
 * UART_PARITY_NO_PARITY
 */
#define UART_PARITY			UART_PARITY_NO_PARITY

/*
 * Choose stop bits:
 * UART_STOP_BITS_1
 * UART_STOP_BITS_2
 */
#define UART_STOP_BITS		UART_STOP_BITS_1

/*
 * Choose Baude Rate:
 * UART_BR_16MHZ_2400
   UART_BR_16MHZ_9600
   UART_BR_16MHZ_115200

   UART_BR_8MHZ_2400
   UART_BR_8MHZ_9600
   UART_BR_8MHZ_115200
 */
#define UART_BAUD_RATE	UART_BR_8MHZ_9600

#endif /* UART_UART_CONFIGURATION_H_ */