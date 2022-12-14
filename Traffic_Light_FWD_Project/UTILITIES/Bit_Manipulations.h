/*
 * Bit_Manipulations.h
 *
 * Created: 12/4/2022 11:03:54 AM
 *  Author: Tarik Zaki Mohamed Mustafa Ramadan
 */ 


#ifndef BIT_MANIPULATIONS_H_
#define BIT_MANIPULATIONS_H_


// Defining functions like Macros for Bit Manipulation //
// Set bit in any register //
#define SET_BIT(REGISTER, BIT) (REGISTER |= (1<<BIT))
// Clear bit in any register //
#define CLR_BIT(REGISTER, BIT) (REGISTER &= (~(1<<BIT)))
// Toggle bit in any register //
#define TOGGLE_BIT(REGISTER, BIT) (REGISTER ^= (1<<BIT))
// Read bit in any register //
#define BIT_READ(REGISTER, BIT)  ((REGISTER & (1<<BIT))>>BIT)
// Rotate right any register with number of rotates //
#define ROTATE_RIGHT(REGISTER, NUMBER) (REGISTER=(REGISTER>>NUMBER)|(REGISTER<<(8-NUMBER)))
// Rotate left any register with number of rotates //
#define ROTATE_LEFT(REGISTER, NUMBER) (REGISTER=(REGISTER<<NUMBER)|(REGISTER>>(8-NUMBER)))


// Defining function like macros
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")


#endif /* BIT_MANIPULATIONS_H_ */