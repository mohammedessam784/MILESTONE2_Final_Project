/*
 * BitMath.h
 *
 * Created: 28-08-2024 11:21:25 PM
 *  Author: lapshop
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define ClrBit(reg,pin)	reg &= ~(1<<pin)
#define SetBit(reg,pin) reg |= (1<<pin)
#define GetBit(reg,pin) (reg>>pin)&1

#endif /* BITMATH_H_ */