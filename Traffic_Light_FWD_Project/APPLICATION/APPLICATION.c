/*
 * APPLICATION.c
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

#include"../APPLICATION/APPLICATION.H"
#define NUMBER_OF_LEDS 1
 uint8_t led_number = 0;  // for test External Interrupt 0


uint8_t mode=0; // 0. normal mode 1. Pedestrian mode

// 0. No state selected and no operation
// 1. Normal Mode State 1 Car Green Led on, and Pedestrian Red Led on
// 2. Normal Mode State 2 Car and Pedestrian Yellow LEDs Blink
// 3. Normal Mode State 3 Car Red Led on, and Pedestrian Green Led on
// 4. Normal Mode State 4 Car and Pedestrian Yellow LEDs Blink
uint8_t State=1; 

unsigned int no_of_overflow =20; // 2 when MCU Frequency = 1 MHZ, and clk/1024 Pre-scaler used for 5 seconds and initial value 0x0c
unsigned int overflowcounter=0;
uint8_t no_of_States=4;

void APP_INIT(void)
{
	//set mode to normal mode
	mode=Normal_Mode; // 0. normal mode 1. Pedestrian mode
	// set state to state_1
	State=State_1;
	no_of_overflow =20;
	overflowcounter=0;
	no_of_States=4;
	// Initialize and set direction of Car LEDs as Output
	LED_INIT(Cars_port, Cars_Green_Led); // Green Led for Cars in Port A Pin 0
	LED_INIT(Cars_port, Cars_Yellow_led); // Yellow Led for Cars in Port A Pin 1
	LED_INIT(Cars_port, Cars_Red_led); // Red Led for Cars in Port A Pin 2
	
	// Initialize and set direction of Car LEDs as Output //
	LED_INIT(Pedestrian_port, Pedestrian_Green_Led); // Green Led for Pedestrian in Port B Pin 0
	LED_INIT(Pedestrian_port, Pedestrian_Yellow_led); // Yellow Led for Pedestrian in Port B Pin 1
	LED_INIT(Pedestrian_port, Pedestrian_Red_led); // Red Led for Pedestrian in Port B Pin 2
	
	// Initialize and set direction for Pedestrian Push Button in Port D, Pin 2
	BUTTON_INIT(PORT_D, 2);
	
	// set Port C as Output // this is extra for turn all port C pins to be output and is not affect other requirements and can be ignored or removed
	SetPortDirection(PORT_C, 0xFF);
	
	// Initialize Timer0 //
	 TIMER0_INIT();
	 
	 // 1. Initialize Timer2 //
	 TIMER2_INIT();

	//Enable Global Interrupt //
	INT0_INIT();
}

void APP_START(void)
{

		// Choose the External Interrupt 0 sense control on rising edge & Enable External Interrupt 0 by set Bit6 in GIFR to enable INT0
		// enable External Interrupt 0 INT0
		INT0_Enable();
		
		// 2. Timer2 Overflow Enable Interrupt, no. of Overflow needed for 5 Seconds will be 20 with prescaler ckl/1024
		 TIMER2_OVI_Enable();
		 
		// 3. Set initial Value and Start Timer2 with selected Prescaler clk/1024
		 TIMER2_Start(0x0C);
		while (mode == Normal_Mode)
		{
			switch(State)
			{
				case State_1:
				{

		////////////////////////////////////////////////////////////////////////////////////////////////
		// mode =0
		// State 1 // select Normal Mode first State
		// Turn on Cars Green Led, and Pedestrian Red Led
		// Turn on Cars Green Led and Turn off other Cars LEDs
		LED_On(Cars_port, Cars_Green_Led); // Turn on Cars Green Led
		LED_Off(Cars_port, Cars_Yellow_led); // Turn off Cars Yellow Led
		LED_Off(Cars_port, Cars_Red_led); // Turn off Cars Red Led
		
		// Turn on Pedestrian Red Led, and Turn off other Pedestrian LEDs
		LED_Off(Pedestrian_port, Pedestrian_Green_Led); // turn off Pedestrian Green Led
		LED_Off(Pedestrian_port, Pedestrian_Yellow_led); // Turn off Pedestrian Yellow Led
		LED_On(Pedestrian_port,Pedestrian_Red_led); // Turn on Pedestrian Red Led
				break;	
				}
		///////////////////////////////////////////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////////////////////////////////////////
				case State_2:
				{

		// Turn on Cars Green Led, Toggle Yellow Red Led, and Turn off Cars Red Led
		LED_On(Cars_port, Cars_Green_Led); // Turn on Cars Green Led
		LED_Toggle(Cars_port, Cars_Yellow_led); // Toggle Cars Yellow Led
		LED_Off(Cars_port, Cars_Red_led); // Turn off Cars Red Led					

		// Turn on Pedestrian Red Led, Toggle Yellow Led, and Turn off Green Pedestrian Led
		LED_Off(Pedestrian_port, Pedestrian_Green_Led); // turn off Pedestrian Green Led
		LED_Toggle(Pedestrian_port, Pedestrian_Yellow_led); // Toggle Pedestrian Yellow Led
		LED_On(Pedestrian_port, Pedestrian_Red_led); // Turn on Pedestrian Red Led
		
		// Delay 50 millisecond as blinking delay
		// Delay_50_millisecond();
		// Delay_250_millisecond(); // have some problem please check and solve
		 TIMER0_delay(250);
		//  T0delay();
		 // _delay_ms(50);
		break;
				}
		///////////////////////////////////////////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////////////////////////////////////////
				case State_3:
				{
		// State 3
		// Turn on Cars Red Led, and Pedestrian Green Led
		// Turn on Cars Red Led and Turn off other Cars LEDs
		LED_Off(Cars_port, Cars_Green_Led); // Turn off Cars Green Led
		LED_Off(Cars_port, Cars_Yellow_led); // Turn off Cars Yellow Led
		LED_On(Cars_port, Cars_Red_led); // Turn on Cars Red Led
		
		// Turn on Pedestrian Green Led, and Turn off other Pedestrian LEDs
		LED_On(Pedestrian_port, Pedestrian_Green_Led); // turn off Pedestrian Green Led
		LED_Off(Pedestrian_port, Pedestrian_Yellow_led); // Turn off Pedestrian Yellow Led
		LED_Off(Pedestrian_port,Pedestrian_Red_led); // Turn on Pedestrian Red Led
		break;
				}
		///////////////////////////////////////////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////////////////////////////////////////
		// State 4
		case State_4:
				{
					// State 4
					// Turn on Cars Red Led, and Pedestrian Green Led
					// Turn on Cars Red Led, Blink car yellow led and Turn off Cars Green Led
					LED_Off(Cars_port, Cars_Green_Led); // Turn off Cars Green Led
					LED_Toggle(Cars_port, Cars_Yellow_led); // Turn off Cars Yellow Led
					LED_On(Cars_port, Cars_Red_led); // Turn on Cars Red Led
					
					// Turn on Pedestrian Green Led, Blink Pedestrian Yellow Led, and Turn off Pedestrian Red Led
					LED_On(Pedestrian_port, Pedestrian_Green_Led); // turn off Pedestrian Green Led
					LED_Toggle(Pedestrian_port, Pedestrian_Yellow_led); // Turn off Pedestrian Yellow Led
					LED_Off(Pedestrian_port,Pedestrian_Red_led); // Turn on Pedestrian Red Led
					// Delay 50 millisecond as blinking delay
					// Delay_50_millisecond();
					TIMER0_delay(250);
					// T0delay();
					// _delay_ms(50);
					break;
				}
		//////////////////////////////////////////////////////////////////////////////////////////////////
		
				default:
					{
			
			// reset state to start again from first state because App_Start will be repeated again and called from main.c in infinite while loop
					State=1;
					break;
					}				
			}

		}
}


void pedestrian_mode()
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// 1. Pedestrian mode
	// First case when button pressed and after checking that Cars Green Led is on if it is true
	////////////////////////////////////////////////////////////////////////////////////////////////////   
	if(State == State_1)
	{
		// change to the next State, reset Timer2 Counter to initial value, and rest Overflowcounter
		State++;
		TCNT2 = 0x0c;
		overflowcounter =0;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// second case when button pressed and after checking that Cars Red Led is on if it is true
	// or check if Cars Yellow Led is blinking if it is true
	// 
	else if (State == State_2) // new modification to wait 5 seconds again
	{
		// reset Timer2 Counter to initial value, and reset Overflowcounter to count 5 seconds again		
		TCNT2 = 0x0c;
		overflowcounter =0;
	}
	// second case when both yellow LEDs for Cars and Pedestrian LEDs are blinking and Cars Green LED is still on and Pedestrian LED is still off
	// I expect that Pedestrian will wait for the delay of 5 seconds to end and Pedestrian Green led will be on to cross the street
	// Third case and fourth case when button pressed it will not do anything because Pedestrian Green Led is already on
	// else if((State== State_2) || (State== State_3) || (State==4)) // old programming
	// Third case and fourth case when button pressed it will not do anything because Pedestrian Green Led is already on
	else if((State== State_3) || (State==4)) // new modifications
	{
		// no change
	}
	// to remove after test
	// State++;
	if (State>no_of_States)
	State=State_1;
	mode=Normal_Mode;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
}
//

//
// 0. normal mode 1. Pedestrian mode
// Interrupt Function Implementation
ISR (INT0_vect)
{
	mode++;
	if (mode == Pedestrian_Mode) // 0. Normal_Mode, 1. Pedestrian_Mode
	{
		pedestrian_mode();
	}
	else
	{
		// do not change mode and set it again to 1 and do nothing in multi-press mode
		mode = 1;
	}
}
//
// 
//
// TIMER2 Overflow Interrupt function Implementation
ISR(TIMER2_OVF_vect)
{
		overflowcounter++; // increment overflow counter
		if(overflowcounter==no_of_overflow)
		{
			overflowcounter =0;
			State++;
			if(State > State_4)
			{
				State=State_1;
			}	
		}
		TIMER2_Start(0x0C); // start counting again with initial value decimal 12 or hex. 0x0C
	// TCNT2 = 0x0c;   // for 250 millisecond at 1 MHz every overflow
	// your code when TIMER2 Overflow flag occurs
}
//
//

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////																										///////
/////								 Test Drivers Functions													///////
/////				Lower Layer (MCAL) Test Driver						Middle Layer(ECUAL)	Test Drivers	///////
/////	Test_DIO()	Test_TIMER0()	INT0_Test()	TIMER2_OVF_Test			Test_Button()	Test_Led(void)		///////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//
// Test DIO Driver accessed from Main instead of App_Start function
void Test_DIO()
{
	// define variable to hold button state or value
	uint8_t KEY_STATE = 0;
	// Testing DIO Driver //
	// Initialize Test_Led in port D pin 7 to be output direction
	DIO_INIT(PORT_D, 7, OUT);
	
	// Initialize Test_Button and in the same time Pedestrian Push Button in port D pin 2 to be Input direction
	DIO_INIT(PORT_D, 2, IN);

	while(1)
	{
		// While Button Pressed
		DIO_READ(PORT_D, 2, &KEY_STATE);
		if(KEY_STATE == 1)
		{
			// blink for 8 seconds
			for(uint8_t i=0; i<2; i++)
			{

		// turn on port D pin 7 to high
		DIO_Write(PORT_D, 7, HIGH);
		
		// Delay 1 second
		TIMER0_delay(1000);
		
		// Turn off Port D pin 7 to Low
		DIO_Write(PORT_D, 7, LOW);
		
		// Delay 1 second
		TIMER0_delay(1000);
		
		// Turn off Port D pin 7 to Low
		DIO_toggle(PORT_D, 7);
		
		// Delay 1 second
		TIMER0_delay(1000);
		
		// Turn off Port D pin 7 to Low
		DIO_Write(PORT_D, 7, LOW);
		
		// Delay 1 second
		TIMER0_delay(1000);
						
			}
		}
		else
		{
		// Turn off Port D pin 7 to Low
		DIO_Write(PORT_D, 7, HIGH);	
		}
	}
}
//

//
// Test TIMER 0 Driver by turning on and off TEST_LED with 4 seconds on to 2 seconds off or blinking Test_LED every 6 Second
void Test_TIMER0()
{
	// Initialize TEST_LED in PORT D Pin 7 to be Output
	DIO_INIT(PORT_D, 7, OUT);
	
	// Initialize TIMER 0 TO SET Normal Mode Operation
	// TIMER0_INIT();
	// TCCR0 = 0x00;
	
	// Do For Ever
	while(1)
	{
		// Turn on TEST_LED
		DIO_Write(PORT_D, 7, HIGH);
		
		// Delay 4 Seconds
		 TIMER0_delay(4000);
				
		// Turn off TEST_LED
		 DIO_Write(PORT_D, 7, LOW);
		
		// Delay 2 Seconds
		 TIMER0_delay(2000);
	}
}
//

// Test Interrupts of External Interrupt 0 (INT0)
void INT0_Test(void)
{
		// 1. set direction of button pin to input
		 DDRD &=(~(1<<2)); // pin 2 port D
		
		// 2. set LED in pin7 Port D to output
		 DDRD |= (1<<7); // pin 7 port D
		
		// 3. Enable global interrupt - setting bit7 or I-bit in the Status Register SREG to 1
		 sei();
		
		// 4. choose the external interrupt sense control to sense on rising edge ISC00,01 = 1,1
		 MCUCR |= (1<<0) | (1<<1);
		
		// 5. Enable external interrupt0 - INT0 bit 6 in GIFR for INT0
		 GICR |= (1<<6);
			while(1)
			{
				//
				switch(led_number)
				{
					case 0:  // Starting State and also the next state after Button Press and State is in case 1
					// turn off led in Port_D pin 7 - set the led 1 to LOW
					PORTD &=(~(1<<7)); // pin 7 Port D
					break;
					
					case 1: // Next state after Button Pressed and State is in Case 0
					// turn on led in Port_D pin 7 - set the led 1 to high
					PORTD |= (1<<7);
					break;
					
					default:
					// do nothing
					break;
				} //
			}
}
//
/*
// External Interrupt 0 function Implementation ISR Interrupt function - Remove comment hash here and add comment to application ISR(INT0_vect) above
ISR (INT0_vect)
{
	if(led_number<NUMBER_OF_LEDS)
	{
		led_number++;
	}
	else
	{
		led_number =0;
	}
}
//
*/

//
// Test TIMER2 Over flow Flag Interrupt (TIMER2_OVF)
void TIMER2_OVF_Test(void)
{
			// 1. set LED in pin7 Port D to output
			DDRD |= (1<<7); // pin 7 port D
			
			// 2. Enable global interrupt - setting bit7 or I-bit in the Status Register SREG to 1
			sei();
			
			// 3. Set TIMSK(Timer/Counter) interrupt Mask register bit 6 to be 1 - so it enables timer2 Overflow flag TOIE2
			TIMSK = (1<<6);
			
			// Set Timer2 initial Value
			TCNT2 = 0x0c;   // for 250 millisecond at 1 MHz
			
			// Timer0 Start counting with Selection pre-scaler clk/1024, TCCR0 Register Bit0: CS00, Bit1: CS01, Bit2: CS02 or CS00,01,02 = 1,1,1
			// SET_BIT(TCCR2, 0);
			// SET_BIT(TCCR2, 1);
			// SET_BIT(TCCR2, 2);
			TCCR2 = (1<<0) | (1<<1) | (1<<2);
			
			// other code of timer2 setup
			
			while(1)
			{
				//
				switch(led_number)
				{
					case 0:  // Starting State and also the next state after Button Press and State is in case 1
					// turn off led in Port_D pin 7 - set the led 1 to high
					PORTD &= ~(1<<7); // pin 7 Port D
					break;
					
					case 1: // Next state after Button Pressed and State is in Case 0
					// turn on led in Port_D pin 7 - set the led 1 to high
					PORTD |= (1<<7);
					break;
					
					default:
					if(led_number<NUMBER_OF_LEDS)
					{
						led_number++;
					}
					else
					{
						led_number =0;
					}
					// do nothing
					break;
				} //
			}
}
//
//

/*
// TIMER2 Overflow Interrupt function Implementation ISR Interrupt Function
ISR(TIMER2_OVF_vect)
{
	overflowcounter++; // increment overflow counter
	if(overflowcounter==no_of_overflow)
	{
		overflowcounter =0;
		led_number++;
		if(led_number > NUMBER_OF_LEDS)
		{
			led_number=0;
		}
	}
	// TIMER2_Start(0x0C); // start counting again with initial value decimal 12 or hex. 0x0C
	 TCNT2 = 0x0c;   // for 250 millisecond at 1 MHz
	// your code when TIMER2 Overflow flag occurs
}
*/

// Test Button Driver accessed from Main instead of App_Start function
void Test_Button()
{
	// define variable to hold button state or value
	uint8_t* BUTTON_STATE;
	uint8_t Key;
	BUTTON_STATE = &Key;
	// Testing Button driver and when button pressed led on port D pin7 will turn on high
	// initialize Led connected on port D pin 7 & button connected on port D pin 2
	DIO_INIT(PORT_D,7,OUT);
	 BUTTON_INIT(PORT_D, 2);
	while(1)
	{
		// read state of button and save value in BUTTON_STATE
		BUTTON_READ(PORT_D, 2, BUTTON_STATE);
		Key = *BUTTON_STATE;
		// BUTTON_READ(PORT_D, 2, &BUTTON_STATE);
		// While Button Pressed
		// DIO_READ(PORT_D, 2, &BUTTON_STATE);
		// Check for BUTTON_STATE if Button pressed//
		if(Key == 1)
		{
			// blink 5 times whenever button pressed
			for(uint8_t i=0; i<20; i++)
				{
				// turn on port D pin 7 to high
				DIO_toggle(PORT_D, 7);
				// Delay 250 millisecond
				TIMER0_delay(250);
				// turn on port D pin 7 to high
				DIO_toggle(PORT_D, 7);
				// Delay 250 millisecond
				TIMER0_delay(250);
				}
		}
		// if Button not pressed
		else if (Key == 0)
		{
			// turn on test led when no button pressed
			 DIO_Write(PORT_D,7, HIGH);
			// DIO_Write(PORTD, 7, HIGH);
		}
	}
}

//

// Test Led Driver accessed from Main instead of App_Start function
void Test_Led()
{
	// Testing LED Driver //
	// Initialize Test_Led in port D pin 7 to be output direction
	LED_INIT(PORT_D, 7);
	// do for Ever
	while(1)
	{
		// turn on port D pin 7 to high
		LED_On(PORT_D, 7);
		
		// Delay 4 Seconds
		TIMER0_delay(4000);
		
		// Turn off Port D pin 7 to Low
		LED_Off(PORT_D, 7);
		
		// Delay 1 Seconds
		TIMER0_delay(1000);
		
		// Turn off Port D pin 7 to Low
		LED_Toggle(PORT_D, 7);
		
		// Delay 4 Seconds
		TIMER0_delay(4000);
		
		// Turn off Port D pin 7 to Low
		LED_Off(PORT_D, 7);
		
		// Delay 1 Seconds
		TIMER0_delay(1000);
	}
}

//

