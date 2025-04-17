/*
 * Exit.c
 *
 * Created: 11-09-2024 9:27:05 PM
 *  Author: lapshop
 */ 
   #include "Exit.h"
   void GlobalInt_Enable(){
	   SetBit(SREG,SREG_I);
   }

   void GlobalInt_Disable(){
	   ClrBit(SREG,SREG_I);
   }

void EXTI_Init(u8 Int_no,u8 SenseControl ){
	   switch(Int_no){
		   case EXT_INT0:
		   SetBit(GICR,GICR_INT0);
		   switch(SenseControl){
			   case Low_Level:
			   ClrBit(MCUCR,MCUCR_ISC00);
			   ClrBit(MCUCR,MCUCR_ISC01);
			   break;
			   case Logical_Change:
			   SetBit(MCUCR,MCUCR_ISC00);
			   ClrBit(MCUCR,MCUCR_ISC01);
			   break;
			   case RisingEdge:
			   SetBit(MCUCR,MCUCR_ISC00);
			   SetBit(MCUCR,MCUCR_ISC01);
			   return;
			   case FallingEdge:
			   ClrBit(MCUCR,MCUCR_ISC00);
			   SetBit(MCUCR,MCUCR_ISC01);
			   break;
		   }
		   break;
		   case EXT_INT1:
		   SetBit(GICR,GICR_INT1);
		   switch(SenseControl){
			   case Low_Level:
			   ClrBit(MCUCR,MCUCR_ISC10);
			   ClrBit(MCUCR,MCUCR_ISC11);
			   break;
			   case Logical_Change:
			   SetBit(MCUCR,MCUCR_ISC10);
			   ClrBit(MCUCR,MCUCR_ISC11);
			   break;
			   case RisingEdge:
			   SetBit(MCUCR,MCUCR_ISC10);
			   SetBit(MCUCR,MCUCR_ISC11);
			   break;
			   case FallingEdge:
			   ClrBit(MCUCR,MCUCR_ISC10);
			   SetBit(MCUCR,MCUCR_ISC11);
			   break;
		   }

		   break;
		   case EXT_INT2:
		   SetBit(GICR,GICR_INT2);
		   switch(SenseControl){
			   case FallingEdge:
			   ClrBit(MCUCSR,MCUCSR_ISC2);
			   break;
			   case RisingEdge:
			   SetBit(MCUCSR,MCUCSR_ISC2);
			   break;
		   }
		   break;

	   }
   }

void (*CallBack[3])() = {NULL};  // array of 3 pointers (3 interrupts) to a function (same function passed to the callBack fn )

void SetCallBack(void(*ptrCallBack)(),u8 Int_no){
	if (ptrCallBack != NULL)
	{
		switch (Int_no)
		{
		case EXT_INT0:
			CallBack[0]=ptrCallBack;
			break;
		case EXT_INT1:
			CallBack[1]=ptrCallBack;
			break;
		case EXT_INT2:
			CallBack[2]=ptrCallBack;
			break;			
		}
	} 
	else
	{
	}
}

/*

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( CallBack[0] != NULL )
	{	
		CallBack[0]();         
	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (CallBack[1] != NULL)
	{
		CallBack[1]();       
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (CallBack[2] != NULL)
	{
		CallBack[2]();       
	}
}

*/




