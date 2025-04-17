/*
 * adc.h
 *
 * Created: 20-09-2024 3:20:13 PM
 *  Author: lapshop
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "../INT/Exit.h"
 /*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


/* ADMUX */
#define ADMUX				*((volatile u8*)0x27)		//ADC multiplexer selection register

#define ADMUX_REFS1         7							//Reference selection bit1
#define ADMUX_REFS0         6							//Reference selection bit0
#define ADMUX_ADLAR         5							//ADC left adjust result


/* ADSRA */
#define ADCSRA				*((volatile u8*)0x26)		//ADC control and status register A

#define ADCSRA_ADEN			7							//ADC enable
#define ADCSRA_ADSC			6                           //Start conversion
#define ADCSRA_ADATE	    5                           //Auto trigger enable
#define ADCSRA_ADIF			4                           //Interrupt flag
#define ADCSRA_ADIE			3                           //Interrupt enable
#define ADCSRA_ADPS2	    2							//Prescaler bit2
#define ADCSRA_ADPS1	    1							//Prescaler bit1
#define ADCSRA_ADPS0	    0							//Prescaler bit0


/* Data Reg  */
#define ADCH				*((volatile u8*)0x25)		//ADC high register
#define ADCL				*((volatile u8*)0x24)		//ADC Low register


/* SFIOR   */
#define SFIOR  *((volatile u8 *)0x50)

#define SFIOR_ADTS2			7                          //Trigger Source bit2
#define SFIOR_ADTS1	     	6                          //Trigger Source bit1
#define SFIOR_ADTS0		    5                          //Trigger Source bit0


#define ADC_CHANNEL_0                  0
#define ADC_CHANNEL_1                  1
#define ADC_CHANNEL_2                  2
#define ADC_CHANNEL_3                  3
#define ADC_CHANNEL_4                  4
#define ADC_CHANNEL_5                  5
#define ADC_CHANNEL_6                  6
#define ADC_CHANNEL_7                  7

/* Reference voltage options*/
#define AREF 0
#define AVCC 1
#define internal_2_56 3

#define ADC_ref_Type AVCC

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5


/* Pre-scaler options*/
#define ADC_Divide_by_2 0
#define ADC_Divide_by_4 2
#define ADC_Divide_by_8 3
#define ADC_Divide_by_16 4
#define ADC_Divide_by_32 5
#define ADC_Divide_by_64 6
#define ADC_Divide_by_128 7


/* Differential mode*/ 
#define ADC1_ADC0_10x 9
#define ADC1_ADC0_200x 11
#define ADC0_ADC1_1x 16

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init(u8 ADC_freq_Prescaler);

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * STEPS:
 * 1- Intially clear the registers
 * 2- set the reference type based on the connection you want to use  
 * 3- set the freq prescaler, hint : make sure ADC freq between 50KHZ - 200KHZ
 * 4- Enable the ADC
 */
u16 ADC_readChannel_single_conv(u8 channel_no);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * STEPS:
 * 1- Determine channel
 * 2- start conversion
 * 3- wait until flag is raised
 * 4- clear the flag
 * 5-Read return value
 * hint: go to the section in slides where ADLAR is explained 
 */

u16 ADC_readChannel_diff_mode(u8 option);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel and subtract it from another channel
 * and convert it to digital using the ADC driver.
 * STEPS:
 * 1- Determine differential mode  
 * 2- start conversion
 * 3- wait until flag is raised
 * 4- clear the flag
 * 5-Read return value
 * hint:compensate for any gain applied from differential mode
 *
 */



void ADC_disable(void);
/*
 * Description :
 * Function responsible for disabling ADC.
 */



void ADC_enable(void);
/*
 * Description :
 * Function responsible for enabling ADC.
 */

void ADC_enableInt(void);




#endif /* ADC_H_ */