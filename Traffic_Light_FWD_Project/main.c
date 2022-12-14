/*
 * Traffic_Light_FWD_Project
 * Main.c
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 

 #include"APPLICATION/APPLICATION.H"

//
int main(void)
{

    // Replace with your application code //
	// Driver Initialization and settings values to variables
		APP_INIT(); // comment this function whenever you want to test Driver //
		
	// Do for Ever
    while (1) 
   {
	   	// Goto Application Function flow
		APP_START(); // comment this function whenever you want to test Driver
	// Test Driver Functions
	// 1. Test Digital input/output DIO Driver
	// Test_DIO();   // completed successfully
	// 2. Test Timer0 delay Driver
	// Test_TIMER0(); // completed successfully
	// 3. Test Interrupt0 Driver
	//	INT0_Test();  // completed successfully
	// 4. Test Timer2 Overflow flag Interrupt Driver
	// TIMER2_OVF_Test();
	// 5. Test Led Driver
	// Test_Led(); // completed successfully
	// 6. Test Button Driver - completed successfully
	// Test_Button();	
	
	}
}
//
