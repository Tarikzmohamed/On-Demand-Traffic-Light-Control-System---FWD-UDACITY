/*
 * INTERRUPT.C
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#include"../INTERRUPT/INTERRUPT.H"

// 1. Initialize Interrupt 0 by Enabling Global Interrupt 0
void INT0_INIT()
{
	// Disable Global Interrupt - Clr I_bit 7 in SREG register to 0
	// cli();
	// __asm__ __volatile__ ("cli" ::: "memory");
	CLR_BIT(SREG, 7);
	
	// ENABLE GLOBAL Interrupt - Set I_Bit or bit 7 in SREG register to 1
	// __asm__ __volatile__ ("sei" ::: "memory");
	// sei();
	SET_BIT(SREG, 7);
}

// 2. Choose the External Interrupt 0 sense control on rising edge & Enable External Interrupt 0 by set Bit6 in GIFR to enable INT0
void INT0_Enable()
{
		// set INT0_RISING_EDGE: ISC00=1, ISC01=1 
		// MCUCR |=(1<<ISC00) | (1<<ISC01);
		// MCUCR |=(1<<0) | (1<<1);
		SET_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
		
		// Enable External Interrupt 0 INT0 by set bit 6 in GIFR register
		// GICR |= (1<<INT0);
		// GICR |=(1<<6);
		SET_BIT(GICR, 6);
}

