/*
 * interrupt.c
 *
 * Created: 02/09/2024 05:00:10 PM
 *  Author: AbdUllah
 */ 

#include "interrupt.h"
void (*EXT_CallBack[3] )()={NULL };

void EXT_voidGI_Enable() 
{
	SetBit(SREG,SREG_I);
}

void EXT_voidGI_Disable()
{
	ClrBit(SREG,SREG_I);
}


void EXT_voidIntIniti(u8 Copy_u8INT_Number , u8 Copy_u8Sensor_Control )
{
	switch(Copy_u8INT_Number)
	{
		case EXT_INT0_ID :
		SetBit(GICR,GICR_INT0);
		   switch(Copy_u8Sensor_Control)
		   {
			   case LOW_LEVEL :
			   ClrBit(MCUCR,MCUCR_ISC00);
			   ClrBit(MCUCR,MCUCR_ISC01);
			   break;
			   case LOGICAL_CHANGE :
			   SetBit(MCUCR,MCUCR_ISC00);
			   ClrBit(MCUCR,MCUCR_ISC01);
			   break;
			   case FALLING_EDGE :
			   ClrBit(MCUCR,MCUCR_ISC00);
			   SetBit(MCUCR,MCUCR_ISC01);
			   break;
			   case RISING_EDGE :
			   SetBit(MCUCR,MCUCR_ISC00);
			   SetBit(MCUCR,MCUCR_ISC01);
			   break;  
		   }
		   
		break;
		case EXT_INT1_ID :
		SetBit(GICR,GICR_INT1);
		switch(Copy_u8Sensor_Control)
		{
			case LOW_LEVEL :
			ClrBit(MCUCR,MCUCR_ISC10);
			ClrBit(MCUCR,MCUCR_ISC11);
			break;
			case LOGICAL_CHANGE:
			SetBit(MCUCR,MCUCR_ISC10);
			ClrBit(MCUCR,MCUCR_ISC11);
			break;
			case FALLING_EDGE :
			ClrBit(MCUCR,MCUCR_ISC10);
			SetBit(MCUCR,MCUCR_ISC11);
			break;
			case RISING_EDGE :
			SetBit(MCUCR,MCUCR_ISC10);
			SetBit(MCUCR,MCUCR_ISC11);
			break;
		}
		
		break;
		case EXT_INT2_ID :
		SetBit(GICR,GICR_INT2);
		switch(Copy_u8Sensor_Control)
		{
			case FALLING_EDGE :
			ClrBit(MCUSR,MCUSR_ISCR2);
			break;
			case RISING_EDGE :
			SetBit(MCUSR,MCUSR_ISCR2);
			break;
		}
		
		break;
	}
}




void EXT_voidSetCallBack(void (*Copy_PvoidCallBack) (void),u8 Copy_u8INT_Number)
{
	 switch(Copy_u8INT_Number)
	 {
		 case EXT_INT0_ID :
              EXT_CallBack[0]= Copy_PvoidCallBack;
		 break;
		 case EXT_INT1_ID :
              EXT_CallBack[1]= Copy_PvoidCallBack;
		 break;
		 case EXT_INT2_ID :
		      EXT_CallBack[2]= Copy_PvoidCallBack;
		 break;
	 }
}


/*

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (EXT_CallBack[0] != NULL)
	{
		EXT_CallBack[0]();      //  Call The Global Pointer to Function
	}
}



void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (EXT_CallBack[1] != NULL)
	{
		EXT_CallBack[1]();      //  Call The Global Pointer to Function
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (EXT_CallBack[2] != NULL)
	{
		EXT_CallBack[2]();      //  Call The Global Pointer to Function
	}
}

*/