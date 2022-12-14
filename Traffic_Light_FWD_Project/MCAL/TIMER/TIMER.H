/*
 * TIMER.h
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/* adding definition of Timer registers */

#include"../../UTILITIES/Typedef.h"
#include"../../UTILITIES/Bit_Manipulations.h"
#include"../../UTILITIES/MC_REGISTERS.H"

void TIMER0_INIT(void);
void TIMER0_Start(uint8_t count_start);
void TIMER0_clear_overflow(void);
void TIMER0_Stop(void);
void TIMER0_delay(uint16_t ms_time_delay);

void TIMER2_INIT(void);
void TIMER2_OVI_Enable(void);
void TIMER2_Start(uint8_t count_start);
void TIMER2_clear_overflow(void);
void TIMER2_Stop(void);

void T0delay(void);
void Delay_250_millisecond(void);
void Delay_Five_seconds(void);

void Test_TIMER0(void);
void TIMER2_OVF_Test(void);

#endif /* TIMER_H_ */