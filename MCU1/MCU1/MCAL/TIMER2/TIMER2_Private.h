/*
 * TIMER2_Private.h
 *
 * Created: 18/09/2024 02:07:13 AM
 *  Author: AbdUllah
 */ 


#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define TCCR2     (*((volatile u8*)0x45))
#define TIMSK     (*((volatile u8*)0x59))
#define TCNT0     (*((volatile u8*)0x44))
#define OCR2      (*((volatile u8*)0x43))
#define ASSR      (*((volatile u8*)0x42))


// TCCR0 BITS
#define WGM20          6
#define COM21          5
#define COM20          4
#define WGM21          3
#define CS22           2
#define CS21           1
#define CS20           0

// TIMSK BITS
#define TOIE2          6
#define OCIE2          7

// ASSR BITS
#define AS2       4

/*Timer Mode*/
#define   TIMER2_NORMAL_MODE        0
#define   TIMER2_CTC_MODE           1
#define   TIMER2_PHASECORRECT_MODE  2
#define   TIMER2_FASTPWM_MODE       3

/*Timer prescaler*/
#define    TIMER2_PRESCALER_1                   0
#define    TIMER2_PRESCALER_8                   1
#define    TIMER2_PRESCALER_32                  2
#define    TIMER2_PRESCALER_64                  3
#define    TIMER2_PRESCALER_128                 4
#define    TIMER2_PRESCALER_256                 5
#define    TIMER2_PRESCALER_1024                6

/*Timer OC0 Mode */
#define   TIMER2_OC2_DISCONNECTED        0
#define   TIMER2_OC2_TOG                 1
#define   TIMER2_OC2_CLEAR               2
#define   TIMER2_OC2_SET                 3
#define	  TIMER_OC2_PWM_NON_INVERTING    4
#define	  TIMER_OC2_PWM_INVERTING	 	 5





#endif /* TIMER2_PRIVATE_H_ */