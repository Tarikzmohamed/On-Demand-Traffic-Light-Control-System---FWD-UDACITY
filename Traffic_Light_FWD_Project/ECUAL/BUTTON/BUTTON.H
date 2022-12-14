/*
 * BUTTON.h
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include"../../UTILITIES/Typedef.h"
#include"../../UTILITIES/Bit_Manipulations.h"
#include"../../UTILITIES/MC_REGISTERS.H"
#include"../../MCAL/DIO/DIO.H"
// New modifications 11-Dec-2022
#include"../MCAL/INTERRUPT/INTERRUPT.H"
#include"../MCAL/TIMER/TIMER.H"


void BUTTON_INIT(uint8_t port, uint8_t pin);
void BUTTON_READ(uint8_t port, uint8_t pin, uint8_t* value);

void Test_Button(void);


#endif /* BUTTON_H_ */