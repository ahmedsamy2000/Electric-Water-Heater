/*
 * ADC_Program.c
 *
 * 
 *      Author: Ahmed Samy
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_Private.h"
#include"ADC_Config.h"

void ADC_voidInit(void)
{
	/*Select  Reference Volt*/
#if ADC_Reference_Volt == ADC_AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif ADC_Reference_Volt == ADC_INTERNAL_2.56V
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
#error"Invalid ADC Reference Volt Options....."
#endif
/*Select Right or Left Adj*/
#if ADC_LEFT_RIGHT_ADJUST == ADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#elif ADC_LEFT_RIGHT_ADJUST == ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#else
#error"Invalid ADC_LEFT_RIGHT_ADJUST Options....."
#endif
/*Select 128 Prescaler*/
	ADCSRA&=0xF8;
	ADCSRA|=0x07;
/*Enable ADC*/
SET_BIT(ADCSRA,7);
}
void ADC_voidInit_Interrupt(void)
{
	/*Select  Reference Volt*/
#if ADC_Reference_Volt == ADC_AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif ADC_Reference_Volt == ADC_INTERNAL_2.56V
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
#error"Invalid ADC Reference Volt Options....."
#endif
/*Select Right or Left Adj*/
#if ADC_LEFT_RIGHT_ADJUST == ADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#elif ADC_LEFT_RIGHT_ADJUST == ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#else
#error"Invalid ADC_LEFT_RIGHT_ADJUST Options....."
#endif
/*Select 128 Prescaler*/
	ADCSRA&=0xF8;
	ADCSRA|=0x07;
/*Enable ADC*/
SET_BIT(ADCSRA,7);
/*ADC Interrupt Enable*/
SET_BIT(ADCSRA,3);
}
void ADC_voidStartConversion_interrupt(u8 Copy_u8Channel)
{
	ADMUX&=0xE0;
	ADMUX|=Copy_u8Channel;
	/*Start conversion*/
	SET_BIT(ADCSRA,6);
}
void ADC_voidStartConversion(u8 Copy_u8Channel)
{
	ADMUX&=0xE0;
	ADMUX|=Copy_u8Channel;
	/*Start conversion*/
	SET_BIT(ADCSRA,6);
	/*Wait on Flag until to be HIGH*/
	while(GET_BIT(ADCSRA,4)==0);
}
u16 ADC_u16Read_DigitalValue(void)
{
	return ADC;
}
