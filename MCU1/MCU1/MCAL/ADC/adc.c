/*
 * adc.c
 *
 * Created: 20-09-2024 3:19:47 PM
 *  Author: lapshop
 */ 
  #include "adc.h"

void ADC_init(u8 ADC_freq_Prescaler){
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * STEPS:
 * 1- Intially clear the registers
 * 2- set the reference type based on the connection you want to use  
 * 3- set the freq prescaler, hint : make sure ADC freq between 50KHZ - 200KHZ
 * 4- Enable the ADC
 */
ADMUX=0x0;
ADMUX |= ADC_ref_Type<<6;
ADCSRA=0x0;
ADCSRA |= ADC_freq_Prescaler;
SetBit(ADCSRA,ADCSRA_ADEN);
}

u16 ADC_readChannel_diff_mode(u8 option){

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
  ADMUX &=0xE0;//clear previous channel setting
  ADMUX |=option;
  SetBit(ADCSRA,ADCSRA_ADSC);
  while(!GetBit(ADCSRA,ADCSRA_ADIF));
  SetBit(ADCSRA,ADCSRA_ADIF);
  u16 ADC=ADCL|(ADCH<<8);
  return ADC;

}

u16 ADC_readChannel_single_conv(u8 channel_no){
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
 ADMUX &=0xE0;//1100 0000
 ADMUX |=channel_no;
 SetBit(ADCSRA,ADCSRA_ADSC);
 while(!GetBit(ADCSRA,ADCSRA_ADIF));
 SetBit(ADCSRA,ADCSRA_ADIF);
 u16 ADC=ADCL|(ADCH<<8);
 return ADC;
}

void ADC_enableInt(void){
	SetBit(ADCSRA,ADCSRA_ADIE);
	sei();
}