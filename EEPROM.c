/*
 * EEPROM.c
 *
 * 
 *  Author: Ahmed Samy
 */ 

#include "EEPROM.h"

/*----------------------------------------------------------------------------*-
EEPROM_read() : To read the data from the EEPROM given the addressess.
-*----------------------------------------------------------------------------*/

unsigned char EEPROM_read(const unsigned short address){
	// Setup addressess Register
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	// Start Reading
	SET_BIT(EECR,EERE);
	
	// Return Data
	return EEDR;
}

/*----------------------------------------------------------------------------*-
EEPROM_write() : to write data in the EEPROM given the addressess and the data.
-*----------------------------------------------------------------------------*/

void EEPROM_write(const unsigned short address, unsigned char data){
	unsigned char INT_EN=0;
		
	// Setup addressess Register
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	// Put Data in Data Register
	EEDR = data;
	
	// Disable Interrupts to work fine
	if(((SREG&(1<<7))>>7)==1){
		INT_EN = 1;
		CLR_BIT(SREG,7);
	}
	
	// Start Writing
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	// Back
	if (INT_EN==1)
	{
		SET_BIT(SREG,7);
	}
	
}
