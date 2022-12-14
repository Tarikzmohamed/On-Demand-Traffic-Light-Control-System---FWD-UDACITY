/*
 * LED.h
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 


#ifndef LED_H_
#define LED_H_

#include"../../UTILITIES/Typedef.h"
#include"../../UTILITIES/Bit_Manipulations.h"
#include"../../UTILITIES/MC_REGISTERS.H"
#include"../../MCAL/DIO/DIO.H"
#include"../MCAL/TIMER/TIMER.H"

void LED_INIT(uint8_t port, uint8_t pin);
void LED_On(uint8_t port, uint8_t pin);
void LED_Off(uint8_t port, uint8_t pin);
void LED_Toggle(uint8_t port, uint8_t pin);

void Test_Led(void);

#endif /* LED_H_ */