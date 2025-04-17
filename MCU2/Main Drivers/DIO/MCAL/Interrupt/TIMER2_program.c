/*
 * TIMER0_program.c
 *
 * Created: 9/2/2024 4:37:55 PM
 *  Author: Mohamed Mamdouh
 */ 


#include "TIMER2_Private.h"
#include "TIMER2_Config.h"
#include "TIMER2_interface.h"
#include "../../LIB/BitMath.h"
#include "../Interrupt/interrupt.h"
#include "../DIO/DIO.h"
#include <stdlib.h>

u32  Timer2_NumOfOV = 0;
u32  Timer2_NumOfCM = 0;

void Timer2_vInit(void)
{
	// step 1 : config Timer Mode
	
	#if (TIMER2_MODE==TIMER2_NORMAL_MODE)
	ClrBit(TCCR2 ,WGM00);
	ClrBit(TCCR2 ,WGM01);
	#elif (TIMER2_MODE==TIMER2_PHASECORRECT_MODE)
	SetBit(TCCR2 ,WGM00);
	ClrBit(TCCR2 ,WGM01);
	#elif (TIMER2_MODE==TIMER2_CTC_MODE)
	ClrBit(TCCR2 ,WGM00);
	SetBit(TCCR2 ,WGM01);
	#elif (TIMER2_MODE==TIMER2_FASTPWM_MODE)
	SetBit(TCCR2 ,WGM00);
	SetBit(TCCR2 ,WGM01);
   #endif 

}


void Timer2_vEnableInt(u8 IntId)
{
	// step 2 : Enable interrupt Mode
  
 switch (IntId)
 {
	case TIMER2_OVF_INT_ID : 
       SetBit(TIMSK,TOIE2);
       sei();
       break;
   case TIMER2_COMP_MATCH_INT_ID :
     	SetBit(TIMSK,OCIE2);
	    sei();
   	break;
	   default:break;
 }

}


void Timer2_vDisableInt(u8 IntId)
{
	// step 1 : config Timer Mode
	switch (IntId)
	{
		case TIMER2_OVF_INT_ID :
		ClrBit(TIMSK,TOIE2);
		break;
		case TIMER2_COMP_MATCH_INT_ID :
		ClrBit(TIMSK,OCIE2);
		break;
		
		default:break;
	}
}





	

void Timer2_vStart(void)
{
	//step 1 : clear TCNT2
	ClrBit(TCCR2,CS00);
	ClrBit(TCCR2,CS01);
	ClrBit(TCCR2,CS02);

	
	//step 2 : insert clock
	#if( TIMER2_PRESCALER ==  TIMER2_PRESCALER_1 )
     SetBit(TCCR2,CS00);
     ClrBit(TCCR2,CS01);
     ClrBit(TCCR2,CS02);
	
	
	#elif( TIMER2_PRESCALER ==  TIMER2_PRESCALER_8 )
     ClrBit(TCCR2,CS00);
     SetBit(TCCR2,CS01);
     ClrBit(TCCR2,CS02);

	#elif( TIMER2_PRESCALER ==  TIMER2_PRESCALER_32 )

    SetBit(TCCR2,CS00);
    SetBit(TCCR2,CS01);
    ClrBit(TCCR2,CS02);
     
	#elif( TIMER2_PRESCALER ==  TIMER2_PRESCALER_64 )
      ClrBit(TCCR2,CS00);
      ClrBit(TCCR2,CS01);
      SetBit(TCCR2,CS02);
    
	#elif( TIMER2_PRESCALER ==  TIMER2_PRESCALER_128)
     SetBit(TCCR2,CS00);
     ClrBit(TCCR2,CS01);
     SetBit(TCCR2,CS02);
	
	#elif( TIMER2_PRESCALER ==  TIMER2_PRESCALER_256)
     ClrBit(TCCR2,CS00);
     SetBit(TCCR2,CS01);
     SetBit(TCCR2,CS02);
	
	#elif( TIMER2_PRESCALER ==  TIMER2_PRESCALER_1024)
     SetBit(TCCR2,CS00);
     SetBit(TCCR2,CS01);
     SetBit(TCCR2,CS02);
	 
	#endif
}


void Timer2_vStop(void)
{
	// Clear all clock selection bits to stop the timer
	ClrBit(TCCR2,CS00);
	ClrBit(TCCR2,CS01);
	ClrBit(TCCR2,CS02);
}

void Timer2_vSetTime(u32 DesiredTime_ms)
{
	// Array of prescaler values --> u32    
	
	u32 prescaler[]={1,8,32,64,128,256,1024};

	// Calculate the tick time in microseconds u32---> // result will be in micro 
	
	//u32 tick_time=prescaler[TIMER2_PRESCALER]/F_OSC;

	// Calculate the total number of ticks required u32
   u32 total_number_of_ticks=(DesiredTime_ms*1000)*F_OSC/prescaler[TIMER2_PRESCALER];
	
	// If the timer is in Normal mode
	#if( TIMER2_MODE ==  TIMER2_NORMAL_MODE )

	// Calculate the number of overflows required (How many times does it go to the ISR)
	Timer2_NumOfOV=total_number_of_ticks/256;

	// If the timer is in CTC mode
	#elif( TIMER2_MODE ==  TIMER2_CTC_MODE )
	

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
         OCR2 = compare_register;
		 
	// Calculate the number of compare matches required
     Timer2_NumOfCM=total_number_of_ticks/compare_register;

	#endif
	
}


// Function to set the duty cycle for Fast PWM mode
void Timer2_SetFastPWM(u8 DutyCycle)
{
	// Set pin PB3 (OC2) as output
	
	DIO_voidSetPinDirection(PORTD_ID, PIN7_ID,PIN_OUTPUT);

	//check the TIMER0 mode
    #if (TIMER2_MODE==TIMER2_FASTPWM_MODE)
     
 	//check the output signal mode (NON_INVERTING)
	 
	 #if TIMER2_OC2_MODE==TIMER_OC2_PWM_NON_INVERTING  
	 //for NON_INVERTING  select non-inverting mode
	 ClrBit(TCCR2 ,COM00);
	 SetBit(TCCR2 ,COM01);
	 // Set the duty cycle for non-inverting mode --> value should be set on OCR0
	 OCR2 = abs((DutyCycle*256/100)-1);
	 
	//-----------------------------------------------------------// 
	 
	 #elif TIMER2_OC2_MODE==TIMER_OC2_PWM_INVERTING
	 //check the output signal mode (INVERTING)
	 SetBit(TCCR2 ,COM00);
	 SetBit(TCCR2 ,COM01);
	 // Set the duty cycle for non-inverting mode --> value should be set on OCR0
	 OCR2 = abs(256-(DutyCycle*256/100));
	 
	 
	 #endif
	 #endif

	//-----------------------------------------------------------//

}



// Function to set the duty cycle for Phase Correct PWM mode
void Timer2_SetPhaseCorrect(u8 DutyCycle)
{
	
	// Set pin PB3 (OC2) as output
	
	DIO_voidSetPinDirection(PORTD_ID, PIN7_ID,PIN_OUTPUT);

	//check the TIMER2 mode
	#if (TIMER2_MODE==TIMER2_PHASECORRECT_MODE)
	
	//check the output signal mode (NON_INVERTING)
	
	#if TIMER2_OC2_MODE==TIMER_OC2_PWM_NON_INVERTING
	//for NON_INVERTING  select non-inverting mode
	ClrBit(TCCR2 ,COM00);
	SetBit(TCCR2 ,COM01);
	// Set the duty cycle for non-inverting mode --> value should be set on OCR0
	OCR2 = abs((DutyCycle*256/100)-1);
	
	//-----------------------------------------------------------//
	
	#elif TIMER2_OC2_MODE==TIMER_OC2_PWM_INVERTING
	//check the output signal mode (INVERTING)
	SetBit(TCCR2 ,COM00);
	SetBit(TCCR2 ,COM01);
	// Set the duty cycle for non-inverting mode --> value should be set on OCR2
	OCR2 = abs(255-(DutyCycle*256/100));
	
	
	#endif
	#endif

	//-----------------------------------------------------------//

}

void Timer2_vCrystalOscillatorEnable()
{
	SetBit(ASSR,AS2);
}