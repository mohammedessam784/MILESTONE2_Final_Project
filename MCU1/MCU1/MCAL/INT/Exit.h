/*
 * Exit.h
 *
 * Created: 11-09-2024 9:26:46 PM
 *  Author: lapshop
 */ 


#ifndef EXIT_H_
#define EXIT_H_
  #include "../../LIB/STD_types.h"
  #include "../../LIB/BitMath.h"


  #define SREG *((volatile u8*)0x5F)	//Status register-GIE
  #define SREG_I 7
  
  #define GICR *((volatile u8*)0x5B)	 //General Interrupt Control Register-PIE
  #define GICR_INT0 6
  #define GICR_INT1 7
  #define GICR_INT2 5
  
  #define GIFR *((volatile u8*)0x5A)	   //PIF
  #define GIFR_INT0 6
  #define GIFR_INT1 7
  #define GIFR_INT2 5

  #define MCUCR *((volatile u8*)0x55) /* rising/falling edge */	 //control register for int 0/1
  #define MCUCR_ISC00 0
  #define MCUCR_ISC01 1
  #define MCUCR_ISC10 2
  #define MCUCR_ISC11 3

  #define MCUCSR *((volatile u8*)0x54)		//control and status register for int 2
  #define MCUCSR_ISC2 6

  #define Low_Level 0
  #define Logical_Change 1
  #define RisingEdge 2
  #define  FallingEdge 3
  
  #define EXT_INT1     7
  #define EXT_INT0     6
  #define EXT_INT2     5


  #define NULL 0

#define sei() __asm__ __volatile__ ("sei") //enable global interrupt-Set enable interrupt

#define ISR(VECT_NO)  void VECT_NO(void) __attribute__((signal));\
                      void VECT_NO(void)


#define _VECTOR(N)		__vector_ ## N        

#define INT0_vect		_VECTOR(1)
#define INT1_vect		_VECTOR(2)
#define INT2_vect		_VECTOR(3)
#define TIMER0_COMP_vect _VECTOR(10)
#define TIMER0_OVF_vect _VECTOR(11)
#define ADC_vect       _VECTOR(16)

  void GlobalInt_Enable();
  void GlobalInt_Disable();
  void EXTI_Init(u8 Int_no,u8 SenseControl);
  void SetCallBack(void(*ptrCallBack)(),u8 Int_no);






#endif /* EXIT_H_ */