/*
 * MC_REGISTERS.h
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */


#ifndef MC_REGISTERS_H_
#define MC_REGISTERS_H_

#include"Typedef.h"
#include"Bit_Manipulations.h"

/* Defining registers for Port A */
#define PINA *((volatile uint8_t*)0X39)
#define DDRA *((volatile uint8_t*)0X3A)
#define PORTA *((volatile uint8_t*)0X3B)

/* Defining registers for Port B */
#define PINB *((volatile uint8_t*)0X36)
#define DDRB *((volatile uint8_t*)0X37)
#define PORTB *((volatile uint8_t*)0X38)

/* Defining registers for Port C */
#define PINC *((volatile uint8_t*)0X33)
#define DDRC *((volatile uint8_t*)0X34)
#define PORTC *((volatile uint8_t*)0X35)

/* Defining registers for Port D */
#define PIND *((volatile uint8_t*)0X30)
#define DDRD *((volatile uint8_t*)0X31)
#define PORTD *((volatile uint8_t*)0X32)

/* Defining registers for Timer0 */
#define TCNT0 *((volatile uint8_t*)0X52)
#define TCCR0 *((volatile uint8_t*)0X53)
#define OCR0 *((volatile uint8_t*)0X5C)

/* Defining registers for Timer2 */
#define TCNT2 *((volatile uint8_t*)0X44)
#define TCCR2 *((volatile uint8_t*)0X45)
#define OCR2 *((volatile uint8_t*)0X43)

// common for Registers for Timer Interrupt //
#define TIFR *((volatile uint8_t*)0X58)
#define TIMSK *((volatile uint8_t*)0X59)

/* Defining registers for External Interrupt */
#define MCUCR *((volatile uint8_t*)0X55)
#define MCUCSR *((volatile uint8_t*)0X54)

/* Defining registers for Global Interrupt */
#define GICR *((volatile uint8_t*)0X5B)
#define GIFR *((volatile uint8_t*)0X5A)
#define SREG *((volatile uint8_t*)0x5F)

#endif /* MC_REGISTERS_H_ */