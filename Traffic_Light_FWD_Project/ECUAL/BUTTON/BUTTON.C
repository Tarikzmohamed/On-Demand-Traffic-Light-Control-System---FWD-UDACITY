/*
 * BUTTON.C
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#include"../BUTTON/BUTTON.H"

// Initialize Pin in Port direction to Be input by Set Direction to IN
void BUTTON_INIT(uint8_t port, uint8_t pin)
{
	// Enable Pull Down Resistor
	DIO_INIT(port, pin, IN);
}

// Read Pin in Port and save in Value for this Specific Pin number
void BUTTON_READ(uint8_t port, uint8_t pin, uint8_t* value)
{
	DIO_READ(port, pin, value);
}


