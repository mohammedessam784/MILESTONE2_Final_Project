/*
 * TIMER0_program.c
 *
 * Created: 9/2/2024 4:37:55 PM
 *  Author: Mohamed Mamdouh
 */ 


#include "TIMER0_Private.h"
#include "TIMER0_Config.h"
#include "TIMER0_interface.h"
#include "../../LIB/BitMath.h"
#include "../Interrupt/interrupt.h"
#include "../DIO/DIO.h"
#include <stdlib.h>

u32  Timer0_NumOfOV = 0;
u32  Timer0_NumOfCM = 0;

void Timer0_vInit(void)
{
	// step 1 : config Timer Mode
	
	#if (TIMER0_MODE==TIMER0_NORMAL_MODE)
	ClrBit(TCCR0 ,WGM00);
	ClrBit(TCCR0 ,WGM01);
	#elif (TIMER0_MODE==TIMER0_PHASECORRECT_MODE)
	SetBit(TCCR0 ,WGM00);
	ClrBit(TCCR0 ,WGM01);
	#elif (TIMER0_MODE==TIMER0_CTC_MODE)
	ClrBit(TCCR0 ,WGM00);
	SetBit(TCCR0 ,WGM01);
	#elif (TIMER0_MODE==TIMER0_FASTPWM_MODE)
	SetBit(TCCR0 ,WGM00);
	SetBit(TCCR0 ,WGM01);
   #endif 

}


void Timer0_vEnableInt(u8 IntId)
{
	// step 2 : Enable interrupt Mode
  
 switch (IntId)
 {
	case TIMER0_OVF_INT_ID : 
       SetBit(TIMSK,TOIE0);
       sei();
       break;
   case TIMER0_COMP_MATCH_INT_ID :
     	SetBit(TIMSK,OCIE0);
	    sei();
   	break;
	   default:break;
 }

}


void Timer0_vDisableInt(u8 IntId)
{
	// step 1 : config Timer Mode
	switch (IntId)
	{
		case TIMER0_OVF_INT_ID :
		ClrBit(TIMSK,TOIE0);
		break;
		case TIMER0_COMP_MATCH_INT_ID :
		ClrBit(TIMSK,OCIE0);
		break;
		
		default:break;
	}
}





	

void Timer0_vStart(void)
{
	//step 1 : clear TCNT0
	ClrBit(TCCR0,CS00);
	ClrBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);

	
	//step 2 : insert clock
	#if( TIMER0_PRESCALER ==  TIMER0_PRESCALER_1 )
     SetBit(TCCR0,CS00);
     ClrBit(TCCR0,CS01);
     ClrBit(TCCR0,CS02);
	
	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_8 )
     ClrBit(TCCR0,CS00);
     SetBit(TCCR0,CS01);
     ClrBit(TCCR0,CS02);

	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_64 )

    SetBit(TCCR0,CS00);
    SetBit(TCCR0,CS01);
    ClrBit(TCCR0,CS02);
     
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_256 )
      ClrBit(TCCR0,CS00);
      ClrBit(TCCR0,CS01);
      SetBit(TCCR0,CS02);
    
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_1024)
     SetBit(TCCR0,CS00);
     ClrBit(TCCR0,CS01);
     SetBit(TCCR0,CS02);
	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_EXTCLK_FALLEDGE)
     ClrBit(TCCR0,CS00);
     SetBit(TCCR0,CS01);
     SetBit(TCCR0,CS02);
	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_EXTCLK_RAISEDGE)
     SetBit(TCCR0,CS00);
     SetBit(TCCR0,CS01);
     SetBit(TCCR0,CS02);
	 
	#endif
}


void Timer0_vStop(void)
{
	// Clear all clock selection bits to stop the timer
	ClrBit(TCCR0,CS00);
	ClrBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);
}

void Timer0_vSetTime(u32 DesiredTime_ms)
{
	// Array of prescaler values --> u32    
	
	u32 prescaler[]={1,8,64,256,1024};

	// Calculate the tick time in microseconds u32---> // result will be in micro 
	
	//u32 tick_time=prescaler[TIMER0_PRESCALER]/F_OSC;

	// Calculate the total number of ticks required u32
   u32 total_number_of_ticks=(DesiredTime_ms*1000)*F_OSC/prescaler[TIMER0_PRESCALER];
	
	// If the timer is in Normal mode
	#if( TIMER0_MODE ==  TIMER0_NORMAL_MODE )

	// Calculate the number of overflows required (How many times does it go to the ISR)
	Timer0_NumOfOV=total_number_of_ticks/256;

	// If the timer is in CTC mode
	#elif( TIMER0_MODE ==  TIMER0_CTC_MODE )
	

	// Find the appropriate compare match value (HINT : % )
	u32 compare_register;
	for(compare_register= 255;compare_register>1;--compare_register)
	{    
		if (total_number_of_ticks%compare_register==0)
		{
			break;
		}
	}


	// Set the output compare register
         OCR0 = compare_register;
		 
	// Calculate the number of compare matches required
     Timer0_NumOfCM=total_number_of_ticks/compare_register;

	#endif
	
}


// Function to set the duty cycle for Fast PWM mode
void Timer0_SetFastPWM(u8 DutyCycle)
{
	// Set pin PB3 (OC0) as output
	
	DIO_voidSetPinDirection(PORTB_ID, PIN3_ID,PIN_OUTPUT);

	//check the TIMER0 mode
    #if (TIMER0_MODE==TIMER0_FASTPWM_MODE)
     
 	//check the output signal mode (NON_INVERTING)
	 
	 #if TIMER0_OC0_MODE==TIMER_OC0_PWM_NON_INVERTING  
	 //for NON_INVERTING  select non-inverting mode
	 ClrBit(TCCR0 ,COM00);
	 SetBit(TCCR0 ,COM01);
	 // Set the duty cycle for non-inverting mode --> value should be set on OCR0
	 OCR0 = abs((DutyCycle*256/100)-1);
	 
	//-----------------------------------------------------------// 
	 
	 #elif TIMER0_OC0_MODE==TIMER_OC0_PWM_INVERTING
	 //check the output signal mode (INVERTING)
	 SetBit(TCCR0 ,COM00);
	 SetBit(TCCR0 ,COM01);
	 // Set the duty cycle for non-inverting mode --> value should be set on OCR0
	 OCR0 = abs(256-(DutyCycle*256/100));
	 
	 
	 #endif
	 #endif

	//-----------------------------------------------------------//

}



// Function to set the duty cycle for Phase Correct PWM mode
void Timer0_SetPhaseCorrect(u8 DutyCycle)
{
	
	// Set pin PB3 (OC0) as output
	
	DIO_voidSetPinDirection(PORTB_ID, PIN3_ID,PIN_OUTPUT);
	if (DutyCycle==0)
	{
		DIO_voidSetPinValue(PORTB_ID, PIN3_ID,PIN_LOW);
		return;
	}
	else if(DutyCycle==100)
	{
		DIO_voidSetPinValue(PORTB_ID, PIN3_ID,PIN_HIGH);
		return;
	}

	//check the TIMER0 mode
	#if (TIMER0_MODE==TIMER0_PHASECORRECT_MODE)
	
	//check the output signal mode (NON_INVERTING)
	
	#if TIMER0_OC0_MODE==TIMER_OC0_PWM_NON_INVERTING
	//for NON_INVERTING  select non-inverting mode
	ClrBit(TCCR0 ,COM00);
	SetBit(TCCR0 ,COM01);
	// Set the duty cycle for non-inverting mode --> value should be set on OCR0
	OCR0 = abs((DutyCycle*256/100)-1);
	
	//-----------------------------------------------------------//
	
	#elif TIMER0_OC0_MODE==TIMER_OC0_PWM_INVERTING
	//check the output signal mode (INVERTING)
	SetBit(TCCR0 ,COM00);
	SetBit(TCCR0 ,COM01);
	// Set the duty cycle for non-inverting mode --> value should be set on OCR0
	OCR0 = abs(255-(DutyCycle*256/100));
	
	
	#endif
	#endif

	//-----------------------------------------------------------//

}