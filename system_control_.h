/*
 * system_control_.h
 *
 *   
 *      Author: Ahmed Samy
 */

#ifndef SYSTEM_CONTROL__H_
#define SYSTEM_CONTROL__H_

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_Interface.h"
#include"TIMER_Interface.h"
#include"GIE_Interface.h"
#include"Cool_Heat_Elements.h"
#include "Buttons.h"
#include"EEPROM.h"
#include"LED.h"
#include<util/delay.h>
//PARAMETERS
#define ERROR_TEMP 5
#define MAX_TEMP 75
#define MIN_TEMP 35
#define INIT_TEMP 50
//SYSTEM STATES
#define OFF 0
#define ON 1
#define SETTING 2

void SYSTEM_VOID_Drivers_INITIALIZE(void);
void OnState(void);
void Settingstate(void);
void OFFstate(void);
void go_to_sleep(void);	


//functions
void addTempRead(u16* array, u16 value);
void temp_check(void);



u8 Current_state;
u16 required_temp;
u16 actual_temp;
u16 avg_temp;
u8 temp_measure_flag;
u8 temp_measure_counter;
u8 setting_counter;
u8 array_counter;
u16 toggle_flag;
u16 temp_array[10];
u16 sum;
u16 avg ;


#endif /* SYSTEM_CONTROL__H_ */
