/*
 * lm35.c
 *
 * Created: 20-09-2024 5:07:46 PM
 *  Author: lapshop
 */ 
 #include "adc.h"
 #include "lm35.h"

u16 LM35_getTemperature(void){
	u16 DigitalVal=0;
	f32 AnalogVal=0;
	DigitalVal=ADC_readChannel_single_conv(SENSOR_CHANNEL_ID);

	AnalogVal = (DigitalVal * ADC_REF_VOLT_VALUE*100.0) / (1024.0);

	//AnalogVal = (AnalogVal * 100);  

	return (u16)AnalogVal;

}
