/*
 * EXTI_Program.c
 *
 *  
 *      Author: Ahmed Samy
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_Private.h"


void EXTI0_voidInit(void)
{
	/*Select Sense Control*/
#if EXTI_SENSE_CONTROL==EXTI_RISING_EDGE
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);
#elif EXTI_SENSE_CONTROL==EXTI_FALLING_EDGE
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);

#elif EXTI_SENSE_CONTROL==EXTI_ANY_LOGICAL_CHANGE
	CLR_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

#elif EXTI_SENSE_CONTROL==EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
#else
	#error"Invalid Sense Control Options FOR EXTI0 AND EXTI1"
#endif
	/*external interrupt 0 enable*/
	SET_BIT(GICR,6);
}

void EXTI1_voidInit(void)
{
	/*Select Sense Control*/
#if EXTI_SENSE_CONTROL==EXTI_RISING_EDGE
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#elif EXTI_SENSE_CONTROL==EXTI_FALLING_EDGE
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);

#elif EXTI_SENSE_CONTROL==EXTI_ANY_LOGICAL_CHANGE
	CLR_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);

#elif EXTI_SENSE_CONTROL==EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#else
	#error"Invalid Sense Control Options FOR EXTI0 AND EXTI1"
#endif
	/*external interrupt 0 enable*/
	SET_BIT(GICR,7);
}

void EXTI2_voidInit(void)
{
	/*Select Sense Control*/
#if EXTI_SENSE_CONTROL==EXTI_RISING_EDGE
	SET_BIT(MCUCSR,6);

#elif EXTI_SENSE_CONTROL==EXTI_FALLING_EDGE
	CLR_BIT(MCUCSR,6);
#else
	#error"Invalid Sense Control Options FOR EXTI0 AND EXTI1"
#endif
	/*external interrupt 0 enable*/
	SET_BIT(GICR,5);
}

