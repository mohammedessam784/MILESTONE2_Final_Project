/*
 * Motor.h
 *
 * Created: 18/09/2024 05:51:43 PM
 *  Author: AbdUllah
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../MCAL/Timer0/Timer0_Config.h"
#include "../../MCAL/Timer0/Timer0_interface.h"
#include "../../LIB/STD_types.h"
#include "../In_Out/inputs_and_outputs.h"
#include "../../MCAL/DIO/DIO.h"

#include "../MILESTONE_Password/Pass.h"

#include "../../MCAL/UART/UART_configuration.h"
#include "../../MCAL/UART/UART_interface.h"


#define Open_Door '+'

extern volatile u32 count_motor;
void MILESTONE_voidMotorIniti();
void MILESTONE_voidOpenDoor();

#endif /* MOTOR_H_ */