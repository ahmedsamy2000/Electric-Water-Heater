/*
 * EEPROM.h
 *
 * 
 *  Author: Ahmed Samy
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "BIT_MATH.h"

void EEPROM_write(const unsigned short address, unsigned char data);
unsigned char EEPROM_read(const unsigned short address);

#endif /* EEPROM_H_ */
