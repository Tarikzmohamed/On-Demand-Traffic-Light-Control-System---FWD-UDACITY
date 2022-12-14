/*
 * APPLICATION.h
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_

#define F_CPU 1000000UL

// Including Micro controller main Registers and Helpers header files
#include"../UTILITIES/Typedef.h"
#include"../../UTILITIES/Bit_Manipulations.h"
#include"../../UTILITIES/MC_REGISTERS.H"

// Including Lower and Middle Layers Drivers 
// New modifications removed lower driver - 11-Dec-2022
//#include"../MCAL/DIO/DIO.H"
//#include"../MCAL/TIMER/TIMER.H"
//#include"../MCAL/INTERRUPT/INTERRUPT.H"

// new modification with middle layers drivers only - no change 11-Dec-2022
#include"../ECUAL/LED/LED.H"
#include"../ECUAL/BUTTON/BUTTON.H"

// defining Port, and Pin for cars LEDs
#define Cars_port			PORT_A
#define Cars_Green_Led			0
#define Cars_Yellow_led			1
#define Cars_Red_led			2

// defining Port, and Pin for Pedestrian LEDs
#define Pedestrian_port		PORT_B
#define Pedestrian_Green_Led	0
#define Pedestrian_Yellow_led	1
#define Pedestrian_Red_led		2

// states in normal mode
#define State_1		1
#define State_2		2
#define State_3 	3
#define State_4		4

//Modes 0 Normal Mode, 1 Pedestrian Mode
#define Normal_Mode			0
#define Pedestrian_Mode		1

// Defining Basic Function where called from main.c
void APP_INIT(void);
void APP_START(void);

// simplify Process on Application to write clear statements
void pedestrian_mode(void);

//
#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,used)) __VA_ARGS__; \
void vector (void)
//
// Interrupt vectors //
// Vector 0 is the reset vector //
// External Interrupt Request 0 //
#define INT0_vect            _VECTOR1
#define INT0_vect_num                 1
#define _VECTOR1           __vector_1
//
/*
// TIMER0_OVF Interrupt Request 11 //
#define TIMER0_OVF_vect	      _VECTOR11
#define TIMER0_OVF_vect_num		       11
#define _VECTOR11          __vector_11
*/
//
// TIMER/COUNTER2_OVF overflow Interrupt Request 5 //
#define TIMER2_OVF_vect            _VECTOR5
#define TIMER2_OVF_vect_num                 5
#define _VECTOR5                 __vector_5
//


#endif /* APPLICATION_H_ */