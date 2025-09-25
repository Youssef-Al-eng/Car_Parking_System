/******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name: interrupt.h
 *
 * Author: Youssef Alaa
 *
 *******************************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h> /* AVR register definitions */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define GLOBAL_INTERRUPT_BIT 7

#define Enable_Global_Interrupt()  (SREG |= (1 << GLOBAL_INTERRUPT_BIT))
#define Disable_Global_Interrupt() (SREG &= ~(1 << GLOBAL_INTERRUPT_BIT))

#endif /* INTERRUPT_H_ */
