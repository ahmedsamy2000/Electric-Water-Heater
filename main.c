/*
 * main.c
 *
 *   
 *      Author: Ahmed Samy
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_Interface.h"
#include"system_control_.h"
#include"GIE_Interface.h"
#include<util/delay.h>


int main()
{
	SYSTEM_VOID_Drivers_INITIALIZE();
	while(1)
	{
		if(Current_state==ON)
		{
			OnState();
		}
		else if(Current_state==OFF)
		{
			OFFstate();
		}
		else if(Current_state==SETTING)
		{
			Settingstate();
		}
		else
		{
			//nothing
		}

	}
	return 0;
}

//ON/OFF interrupt
void __vector_18(void)       __attribute__((signal));
void __vector_18(void)
{
	if(Current_state==OFF){
		Current_state = ON;
		required_temp = EEPROM_read(0x0000);
	}
	else if (Current_state==ON || Current_state==SETTING){
		Current_state = OFF;
	}
}
//temp time flag interrupt
void __vector_6(void)       __attribute__((signal));
void __vector_6(void)
{
	temp_measure_flag = 1;
}
//timer trips every 1 sec
void __vector_19(void)       __attribute__((signal));
void __vector_19(void)
{
	if ((Current_state==ON) || (Current_state==SETTING)){
		setting_counter++;
		if(setting_counter % 4 == 0){
			toggle_flag ^= 1;
		}
		if (setting_counter > 20){

			// Write the new desired temperature in EEPROM
			Current_state = ON;
		}
	}
}
