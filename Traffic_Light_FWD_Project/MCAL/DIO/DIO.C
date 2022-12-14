/*
 * DIO.C
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#include"../DIO/DIO.H"

// for DIO Initialization //
void DIO_INIT(volatile uint8_t portnumber, uint8_t pinnumber, uint8_t direction) 
{
	switch(portnumber)
	{
		case PORT_A:
		if(direction==IN)
		{
			// DDRA &=(~(1<<pinnumber)); // Clear bit related to pin number in Port A to Make it Input
			CLR_BIT(DDRA, pinnumber);
		}
		else if(direction==OUT)
		{
			// DDRA |=(1<<pinnumber); // Set bit related to pin number in Port A to Make Output
			SET_BIT(DDRA, pinnumber); 
		}
		break;
		case PORT_B:
		if(direction==IN)
		{
			// DDRB &=(~(1<<pinnumber)); // Clear bit related to pin number in Port B to Make it Input
			CLR_BIT(DDRB, pinnumber);
		}
		else if (direction==OUT)
		{
			// DDRB |=(1<<pinnumber); // Set bit related to pin number in Port B to Make Output
			SET_BIT(DDRB, pinnumber); 
		}
		break;
		case PORT_C:
		if(direction==IN)
		{
			// DDRC &=(~(1<<pinnumber)); // Clear bit related to pin number in Port C to Make it Input
			CLR_BIT(DDRC, pinnumber);
		}
		else if (direction==OUT)
		{
			// DDRC |=(1<<pinnumber); // Set bit related to pin number in Port C to Make Output
			SET_BIT(DDRC, pinnumber); 
		}
		break;
		case PORT_D:
		if(direction==IN)
		{
			// DDRD &=(~(1<<pinnumber)); // Clear bit related to pin number in Port D  to Make it Input
			CLR_BIT(DDRD, pinnumber);
		}
		else if (direction==OUT)
		{
			// DDRD |=(1<<pinnumber); // Set bit related to pin number in Port D to Make Output
			SET_BIT(DDRD, pinnumber); 
		}
		break;
	}
}
// for Write data to DIO //
void DIO_Write(volatile uint8_t portnumber, uint8_t pinnumber, uint8_t value)
{
	switch(portnumber)
	{
	case PORT_A:
	if(value==LOW)
	{
		// PORTA &=(~(1<<pinnumber)); // Clear bit related to pin number in Port A  to Make it off or GND
		CLR_BIT(PORTA, pinnumber);
	}	
	else if (value==HIGH)
	{
		// PORTA |=(1<<pinnumber); // Set bit related to pin number in Port A to Make it On or VCC
		SET_BIT(PORTA, pinnumber);
	}
	break;
	case PORT_B:
	if(value==LOW)
	{
		// PORTB &=(~(1<<pinnumber)); // Clear bit related to pin number in Port B  to Make it off or GND
		CLR_BIT(PORTB, pinnumber);
	}
	else if (value==HIGH)
	{
		// PORTB |=(1<<pinnumber); // Set bit related to pin number in Port B to Make it On or VCC
		SET_BIT(PORTB, pinnumber);
	}
	break;
	case PORT_C:
	if(value==LOW)
	{
		// PORTC &=(~(1<<pinnumber)); // Clear bit related to pin number in Port C to Make it off or GND
		CLR_BIT(PORTC, pinnumber);
	}
	else if(value==HIGH)
	{
		// PORTC |=(1<<pinnumber); // Set bit related to pin number in Port C to Make it On or VCC
		SET_BIT(PORTC, pinnumber);
	}
	break;
	case PORT_D:
	if(value==LOW)
	{
		// PORTD &=(~(1<<pinnumber)); // Clear bit related to pin number in Port D to Make it off or GND
		CLR_BIT(PORTD, pinnumber);
	}
	else if(value==HIGH)
	{
		// PORTD |=(1<<pinnumber); // Set bit related to pin number in Port D to Make it On or VCC
		SET_BIT(PORTD, pinnumber);
	}
	break;
	}
}
//  for toggle DIO pin //
void DIO_toggle(uint8_t portnumber, uint8_t pinnumber)
{
	switch(portnumber)
	{
		case PORT_A:
		// PORTA ^=(1<<pinnumber); // Toggle bit or change pin value from off to on or on to off in specific pin in Port A
		TOGGLE_BIT(PORTA, pinnumber);
		break;
		case PORT_B:
		// PORTB ^=(1<<pinnumber); // Toggle bit or change pin value from off to on or on to off in specific pin in Port A
		TOGGLE_BIT(PORTB, pinnumber);
		break;
		case PORT_C:
		// PORTC ^=(1<<pinnumber); // Toggle bit or change pin value from off to on or on to off in specific pin in Port A
		TOGGLE_BIT(PORTC, pinnumber);
		break;
		case PORT_D:
		// PORTD ^=(1<<pinnumber); // Toggle bit or change pin value from off to on or on to off in specific pin in Port A
		TOGGLE_BIT(PORTD, pinnumber);
		break;
	}
}
// for READ data from DIO //
void DIO_READ(uint8_t portnumber, uint8_t pinnumber, uint8_t* value)
{
	switch(portnumber)
	{
		case PORT_A:
		// Read pinnumber value of port A as one or zero instead as value related to port A
		// *value=(PINA&(1<<pinnumber))>>pinnumber;
		*value = BIT_READ(PINA, pinnumber);
		break;
		case PORT_B:
		// Read pinnumber value of port B as one or zero instead as value related to port B
		// *value=(PINB&(1<<pinnumber))>>pinnumber;
		*value = BIT_READ(PINB, pinnumber);
		break;
		case PORT_C:
		// Read pinnumber value of port C as one or zero instead as value related to port C
		// *value=(PINC&(1<<pinnumber))>>pinnumber;
		*value = BIT_READ(PINC, pinnumber);
		break;
		case PORT_D:
		// Read pinnumber value of port D as one or zero instead as value related to port D
		// *value=(PIND&(1<<pinnumber))>>pinnumber;
		*value = BIT_READ(PIND, pinnumber);
		break;
	}
}
// Set Port pins Direction Directly from 0x00 to be complete Input to 0xff to be complete Output, and you can write any value between these values
// to set input and output pins in Port directly
void SetPortDirection(uint8_t portnumber, uint8_t direction)
{
	switch (portnumber)
	{
		case PORT_A:
		DDRA = direction;
		break;
		case PORT_B:
		DDRB = direction;
		break;
		case PORT_C:
		DDRC = direction;
		break;
		case PORT_D:
		DDRD = direction;
		break;
	}
}
