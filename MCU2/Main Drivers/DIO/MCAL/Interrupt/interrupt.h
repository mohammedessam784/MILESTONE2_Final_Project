/*
 * interrupt.h
 *
 * Created: 02/09/2024 04:57:44 PM
 *  Author: AbdUllah
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_types.h"
#define		EXT_INT0_ID  0
#define		EXT_INT1_ID  1
#define		EXT_INT2_ID  2

#define     LOW_LEVEL          0
#define     LOGICAL_CHANGE     1
#define     FALLING_EDGE       2
#define     RISING_EDGE        3

#define  SREG  *((volatile u8* )0x5f)
#define  SREG_I    7


#define  GICR  *((volatile u8* )0x5b)
#define  GICR_INT0 6
#define  GICR_INT1 7
#define  GICR_INT2 5

#define  GIFR  *((volatile u8* )0x5a)
#define  GIFR_INT0 6
#define  GIFR_INT1 7
#define  GIFR_INT2 5

#define  MCUCR  *((volatile u8* )0x55)
#define  MCUCR_ISC00 0
#define  MCUCR_ISC01 1
#define  MCUCR_ISC10 2
#define  MCUCR_ISC11 3


#define NULL  0
#define      ENABLED         1
#define      DISABLED        0

#define  MCUSR  *((volatile u8* )0x5f)
#define  MCUSR_ISCR2 6 


#define sei() __asm__ __volatile__ ("sei")
#define cli() __asm__ __volatile__ ("cli")


#define _VECTOR(N)		__vector_ ## N
/* VECT_NO */
#define INT0_vect					_VECTOR(1)
#define INT1_vect					_VECTOR(2)
#define INT2_vect					_VECTOR(3)
#define TIMER2_COMP_vect			_VECTOR(4)
#define TIMER2_OVF_vect				_VECTOR(5)
#define TIMER1_CAPT_vect			_VECTOR(6)
#define TIMER1_COMPA_vect			_VECTOR(7)
#define TIMER1_COMPB_vect			_VECTOR(8)
#define TIMER1_OVF_vect				_VECTOR(9)
#define TIMER0_COMP_vect			_VECTOR(10)
#define TIMER0_OVF_vect				_VECTOR(11)
#define SPI_STC_vect				_VECTOR(12)
#define USART_RXC_vect				_VECTOR(13)
#define USART_UDRE_vect				_VECTOR(14)
#define USART_TXC_vect				_VECTOR(15)
#define ADC_vect					_VECTOR(16)
#define EE_RDY_vect					_VECTOR(17)
#define ANA_COMP_vect				_VECTOR(18)
#define TWI_vect					_VECTOR(19)
#define SPM_RDY_vect				_VECTOR(20)

#define ISR(VECT_NO)    void VECT_NO(void) __attribute__((signal));\
                        void VECT_NO(void)



extern void (*EXT_CallBack[3] )();
void EXT_voidGI_Enable(); 
void EXT_voidGI_Disable(); 
void EXT_voidIntIniti(u8 Copy_u8INT_Number , u8 Copy_u8Sensor_Control );
void EXT_voidSetCallBack(void (*Copy_PvoidCallBack) (void),u8 Copy_u8INT_Number);

#endif /* INTERRUPT_H_ */