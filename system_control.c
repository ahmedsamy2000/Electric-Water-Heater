/*
 * system_control.c
 *
 *   
 *      Author: Ahmed Samy
 */
#include"system_control_.h"
void SYSTEM_VOID_Drivers_INITIALIZE(void)
{
	void GIE_voidEnable(void);
	void TIMER0_voidInit(void);
	void TIMER1_voidInit(void);
	void ADC_voidInit(void);
	void ADC_voidInit_Interrupt(void);
	void SSD_init(void);
	void heat_init(void);
	void cool_init(void);
    temp_measure_counter=0;
    sum=0;
    //setting intiall required temp =40

    required_temp=40;
    Current_state=OFF;
	if(EEPROM_read(0x0000) != 0xFF)
	{
		required_temp = EEPROM_read(0x0000);
	}
	else
	{
		required_temp = INIT_DESIRED_TEMP;
	}
}

void OnState(void)
{
	if(temp_measure_flag==1)
	{
		ADC_voidStartConversion(1);
		actual_temp= ADC_u16Read_DigitalValue();
		//add by function
		addTempRead(temp_array, actual_temp);
		SSD_write(actual_temp);
		temp_measure_flag=0;
	}
	SSD_write(actual_temp);
	//check on temp.
	temp_check();
	if(UP_pressed()==PRESSED || DOWN_pressed()==PRESSED)
	{
		SSD_disable();
		setting_counter = 0;
		Current_state = SETTING;
	}

}
//setting state
void Settingstate(void){
	heat_stop();
	led_off();
	cool_stop();

	if(toggle_flag == 1){
		SSD_write(required_temp);
	}
	else{
		SSD_turn_off();
	}

	// if UP or DOWN pressed, change the required temp

	if((UP_pressed() == PRESSED) && (required_temp < MAX_TEMP)){
		required_temp = required_temp + 5;
		setting_counter = 0;
		SSD_write(required_temp);
	}
	else if ((DOWN_pressed() == PRESSED) && (required_temp > MIN_TEMP)){
		required_temp = required_temp - 5;
		setting_counter = 0;
		SSD_write(required_temp);
	}

	EEPROM_write(0x0000,required_temp);

}


void addTempRead(u16* array, u16 value)
	{
		array[temp_measure_counter]=value;
		sum=sum+array[temp_measure_counter];
		temp_measure_counter++;
		avg=sum/temp_measure_counter;
		if (temp_measure_counter=10)
		{
			temp_measure_counter=0;
			sum=0;

	}


void temp_check(void)
	{
		if( (required_temp < avg_temp + ERROR_TEMP) && (required_temp > avg_temp -ERROR_TEMP ) )
			{
				// Actual Temperature equals required Temperature
				// No need for Heating or Cooling
				heat_stop();
				cool_stop();
				led_off();
	}
	else if(required_temp < avg_temp + ERROR_TEMP)
			{
				// Actual Temperature is Larger
				// we need the Cooling element

				heat_stop();
				cool_start();
				led_on();
			}
	else if (required_temp > avg_temp - ERROR_TEMP)
			{
				// Actual Temperature is Smaller
				// we need the Heating element

				heat_start();
				cool_stop();
		if (toggle_flag == 1)
				{
					led_on();
				}
		else {
					led_off();
				}
			}
		}


void OFFstate(void)
{
		SSD_turn_off();
		led_off();
		heat_stop();
		cool_stop();
		go_to_sleep();
}
void go_to_sleep(void)
{

	MCUCR&=~(1<<SM0);
	MCUCR&=~(1<<SM1);
	MCUCR&=~(1<<SM2);

	MCUCR|=(1<<SE);

}
