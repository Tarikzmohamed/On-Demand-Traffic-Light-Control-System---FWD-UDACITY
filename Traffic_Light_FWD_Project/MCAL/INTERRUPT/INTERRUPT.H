/*
 * INTERRUPT.h
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
/* adding definition of Interrupt registers */
#include"../../UTILITIES/MC_REGISTERS.H"
#include"../../UTILITIES/Typedef.h"
#include"../../UTILITIES/Bit_Manipulations.h"

void INT0_INIT(void);
void INT0_Enable(void);




void INT0_Test(void);


#endif /* INTERRUPT_H_ */