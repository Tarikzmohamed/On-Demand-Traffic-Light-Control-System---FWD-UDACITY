/*
 * DIO.h
 *
 * Created: 12/2/2022 4:38:43 AM
 * Author : Tarik Zaki Mohamed Mustafa Ramadan
 */ 


#ifndef DIO_H_
#define DIO_H_
// adding definition of Ports registers //
#include"../../UTILITIES/MC_REGISTERS.H"
#include"../../UTILITIES/Typedef.h"
#include"../../UTILITIES/Bit_Manipulations.h"

// Simplify writing ports //
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

// Defining Direction Values for Pins only //
#define IN 0
#define OUT 1

// Defining for Values for Pin Output only //
#define LOW 0
#define HIGH 1

// Functions Prototypes Definitions //
void DIO_INIT(uint8_t portnumber, uint8_t pinnumber, uint8_t direction);  // for DIO Initialization //
void DIO_Write(uint8_t portnumber, uint8_t pinnumber, uint8_t value); // for Write data to DIO //
void DIO_toggle(uint8_t portnumber, uint8_t pinnumber); //  for toggle DIO pin //
void DIO_READ(uint8_t portnumber, uint8_t pinnumber, uint8_t* value); // for READ data from DIO //
void SetPortDirection(uint8_t portnumber, uint8_t direction); 
void Test_DIO(void);

#endif // DIO_H_ //