/*
 * LED.C
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#include"../LED/LED.H"

// Initialize Pin in Port direction to Be output by Set Direction to OUT
void LED_INIT(uint8_t port, uint8_t pin)
{
	DIO_INIT(port,pin,OUT);		
}
	// Turn on Pin in Port to be High or VCC by Writing 1 to this Specific Pin number
void LED_On(uint8_t port, uint8_t pin)
{
	DIO_Write(port,pin, HIGH);
}

// Turn on Pin in Port to be LOW or GND by Writing 0 to this Specific Pin number
void LED_Off(uint8_t port, uint8_t pin)
{
	DIO_Write(port, pin, LOW);	
}

// change Pin in Port to be (LOW or GND) or (HIGH or VCC) by Writing toggling or xor with 1 to this Specific Pin number
void LED_Toggle(uint8_t port, uint8_t pin)
{
	DIO_toggle(port, pin);
}
