/*
 * 7SD.h
 *
 *   
 *      Author: Ahmed Samy
 */

#ifndef sevenSD_H_
#define sevenSD_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"


// SSD Display Macros
#define DISP1 1
#define DISP2 2

#define SSD_ENABLE_PORT_DIR DDRB
#define SSD_ENABLE_PORT PORTB
#define SSD1_ENABLE_PIN 2
#define SSD2_ENABLE_PIN 1
#define SSD_DATA PORTA
#define SSD_PORT_DIR DDRA

// SSD Control Functions
void SSD_init(void);
void SSD_send(u16 N);
void SSD_enable(u8 disp);
void SSD_disable(void);
void SSD_turn_off(void);
void SSD_write(u16 N);

#endif /* 7SD_H_ */
