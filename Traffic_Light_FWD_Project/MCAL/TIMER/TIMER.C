/*
 * TIMER.C
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#include<math.h>
#include"../TIMER/TIMER.H"
#include"../../UTILITIES/MC_REGISTERS.H"
// #include"../DIO/DIO.H"

// global variables definition and initialization

void TIMER0_INIT()
{
	// Select normal mode Bit3: WGM01, and Bit6: WGM00 to be 0 and 0 or TCCR0 = 0x00;
	// CLR_BIT(TCCR0, 3);
	// CLR_BIT(TCCR0, 6);
	 TCCR0 = 0x00;
}

void TIMER0_Start(uint8_t count_start)
{
		// Set Timer0 initial Value
		TCNT0 =count_start;
		// Timer0 Start counting with Selection pre-scaler clk/1024, TCCR0 Register Bit0: CS00, Bit1: CS01, Bit2: CS02 or CS00,01,02 = 1,0,1
		// SET_BIT(TCCR0, 0);
		// CLR_BIT(TCCR0, 1);
		// SET_BIT(TCCR0, 2);
		TCCR0 = (1<<0) | (1<<2);
		// TCCR0 = 0x05;
}

void TIMER0_clear_overflow()
{
	// Check if Timer0 Overflow True or False
	// if it is false wait and do nothing until TIFR register overflow bit0: TOV0 = 1
	 TIFR &= (1<<0);
	// SET_BIT(TIFR, 0);
}


void TIMER0_Stop()
{

	// set TCCR0 register to 0x00 - so it will clear prescaler and so it will stop
	TCCR0 = 0x00;
}

void TIMER2_INIT()
{
	// Select normal mode Bit3: WGM01, and Bit6: WGM00 to be 0 and 0 or TCCR2 = 0x00;
	// CLR_BIT(TCCR2, 3);
	// CLR_BIT(TCCR2, 6);
	 TCCR2 = 0x00;
}

void TIMER2_OVI_Enable()
{
	// 1. Enable global Interrupt
	 sei();
	// SET_BIT(SREG, 7);

	// 2. Set TIMSK(Timer/Counter) interrupt Mask register bit 6 to be 1 - so it enable timer2 Overflow flag TOIE2
	TIMSK = (1<<6);
	// SET_BIT(TIMSK, 6);
	
}

void TIMER2_Start(uint8_t count_start)
{
	// Set Timer2 initial Value
	TCNT2 =count_start;
	// Timer0 Start counting with Selection pre-scaler clk/1024, TCCR0 Register Bit0: CS00, Bit1: CS01, Bit2: CS02 or CS00,01,02 = 1,1,1
	// SET_BIT(TCCR2, 0);
	// SET_BIT(TCCR2, 1);
	// SET_BIT(TCCR2, 2);
	TCCR2 = (1<<0) | (1<<1) | (1<<2);
	// TCCR2 = 0x02;
}

void TIMER2_clear_overflow()
{
	// Check if Timer2 Overflow True or False
	// if it is false wait and do nothing until TIFR register overflow bit6: TOV2 = 1
	 TIFR &=(1<<6);
	// SET_BIT(TIFR, 6);
}


void TIMER2_Stop()
{

	// Set TCCR2 register to 0x00 - so it will clear prescaler and so it will stop
	TCCR2 = 0x00;
}

void Delay_250_millisecond()
{
	int count_start = 0x0C;  // start counting from (Dec. 207 or Hex 0xCF) for each overflow occur to accumulate finally 244 x 1024 x 2 = 499,712 us
	// = 499.712 ms to for functions delay
	int no_of_overflow =1; // 1 when MCU Frequency = 1 MHZ, and clk/1024 prescaler used
	int overflowcounter=0;
	// TCCR0 = 0x00;
	 TIMER0_INIT(); // select and initiate timer0 mode to be normal mode
	while(overflowcounter<no_of_overflow)
	{
	 TCNT0 = count_start;  		// Load TCNT0 //
	 TCCR0 = 0x05;  		// Timer0, normal mode, clk/1024 pre-scalar //
	// TIMER0_Start(count_start);  // start timer0 with clk/1024 Pre-scaler	
	// while(TIMER0_check_overflow() == 1); // wait loop and do nothing until timer0 overflow is true
	// while((TIFR &(1<<0)) ==0);

	// TIFR = 0x1; 
	 TIMER0_clear_overflow(); // clear timer0 overflow flag
	overflowcounter++; // increment overflow counter
	}
	overflowcounter=0;
	TCCR0 = 0;
	TIFR = 0x1;  		// Clear TOV0 flag //
	
	// TIFR = 0x1;  		// Clear TOV0 flag //
	// TIMER0_clear_overflow(); // clear timer0 overflow flag
	// TCCR0 = 0;
	// TIMER0_Stop(); // stop timer 0 Set Timer0 initial Value TCCR0 = 0x00;
}

void Delay_Five_seconds()
{

	int count_start = 0x0C;  // start counting from (Dec. 12 or Hex 0x0C) for each overflow occur to accumulate finally 244 x 1024 x 20 = 4,997,120 us
	// = 4,997.12 ms  = 4.99712 Seconds to for functions delay
	unsigned int no_of_overflow =20; // 2 when MCU Frequency = 1 MHZ, and clk/1024 Pre-scaler used
	unsigned int overflowcounter=0;
	TIMER0_INIT(); // select and initiate timer0 mode to be normal mode
	while(overflowcounter<no_of_overflow)
	{
		// Set Timer0 initial Value
		TCNT0 =count_start;
		// Timer0 Start counting with Selection pre-scaler clk/1024, TCCR0 Register Bit0: CS00, Bit1: CS01, Bit2: CS02 or CS00,01,02 = 1,0,1
		// SET_BIT(TCCR0, 0);
		// CLR_BIT(TCCR0, 1);
		// SET_BIT(TCCR0, 2);
		TCCR0 = (1<<0) | (1<<2);
		// TCCR0 = 0x05;
		// TIMER0_Start(count_start);  // start timer0 with clk/1024 Pre-scaler
		
		// while(TIMER0_check_overflow() == 1); // wait loop and do nothing until timer0 overflow is true
		while((TIFR &(1<<0)) ==0);

		TIMER0_clear_overflow(); // clear timer0 overflow flag
		overflowcounter++; // increment overflow counter
	}
		TCCR0 = 0;
		TIFR = 0x1;  		// Clear TOV0 flag //
		// TIMER0_Stop(); // stop timer 0 Set Timer0 initial Value TCCR0 = 0x00;

}

// TIMER0 Delay with milli_second input
void TIMER0_delay(uint16_t ms_time_delay)
{
	unsigned int no_of_overflows =0; // 2 when MCU Frequency = 1 MHZ, and clk/1024 Pre-scaler used
	// unsigned int no_of_overflows =20; // 2 when MCU Frequency = 1 MHZ, and clk/1024 Pre-scaler used
	unsigned int overflowcounter=0;
	double T_maxdelay, T_tick;
	uint8_t Timer0_initial_value =0;
	// Prescaler 1024, and F_CPU frequency = 1 Mhz
	T_tick = 1024.0/1000.0 ; // milli_second
	
	// Tmaxdelay = T_tick * 2^8 for 8-bit Timer 0
	T_maxdelay = T_tick * 256; // mill_second
	
	// first case //
	if(ms_time_delay<(uint16_t) T_maxdelay)
	{
		Timer0_initial_value = (T_maxdelay - ms_time_delay)/ T_tick; 
		no_of_overflows = 1;
	}
	
	// Second case //
	if(ms_time_delay == (uint16_t) T_maxdelay)
	{
		Timer0_initial_value = 0;
		no_of_overflows = 1;
	}
	
	// Third case //
	if(ms_time_delay > (uint16_t) T_maxdelay)
	{
		no_of_overflows = ceil((double) ms_time_delay/T_maxdelay);
		Timer0_initial_value = 256 - ((double) ms_time_delay/T_tick)/no_of_overflows;
	}
	
	// initialize Timer 0 Mode to be Normal mode
	// Select normal mode Bit3: WGM01, and Bit6: WGM00 to be 0 and 0 or TCCR0 = 0x00;
	// CLR_BIT(TCCR0, 3);
	// CLR_BIT(TCCR0, 6);
	TCCR0 = 0x00;
	// TIMER0_INIT();
	while(overflowcounter<no_of_overflows)
	{
		// Set Timer0 initial Value
		TCNT0 =Timer0_initial_value;
		// Timer0 Start counting with Selection pre-scaler clk/1024, TCCR0 Register Bit0: CS00, Bit1: CS01, Bit2: CS02 or CS00,01,02 = 1,0,1
		// SET_BIT(TCCR0, 0);
		// CLR_BIT(TCCR0, 1);
		// SET_BIT(TCCR0, 2);
		TCCR0 = (1<<0) | (1<<2);
		// TCCR0 = 0x05;
		
		// while(TIMER0_check_overflow() == 1); // wait loop and do nothing until timer0 overflow is true
		//while((TIFR &(1<<0)) ==0);
		while((TIFR&0x01)==0);  // Wait for TOV0 to roll over //

		// TIMER0_clear_overflow(); // clear timer0 overflow flag
		TIFR = 0x1;  		// Clear TOV0 flag //
		overflowcounter++; // increment overflow counter
	}
	TCCR0 = 0;
	TIFR = 0x1;  		// Clear TOV0 flag //
	// TIMER0_Stop(); // stop timer 0 Set Timer0 initial Value TCCR0 = 0x00;
}

// 250 ms delay function by Timer 0. Prescaler=0x05 clk/1024 and timer intial value or value to be loaded in Timer counter TCNT0 = 12 or 0x0c
void T0delay()
{
	TCNT0 = 0x0C;  		// Load TCNT0  with decimal 12 or 0x0c hexadecimal, total delay will be = (256-12)*1024*1 = 249,856 microsecond = 249.86 millisecond//
	TCCR0 = 0x05;  		// Timer0, normal mode, clk/1024 pre-scalar //
	
	while((TIFR&0x01)==0);  // Wait for TOV0 to roll over //
	TCCR0 = 0;
	TIFR = 0x1;  		// Clear TOV0 flag //
}
