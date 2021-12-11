/*
 * EXTI_Interface.h
 *
 *  
 *      Author: Ahmed Samy
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI0_voidInit(void);
void EXTI1_voidInit(void);
void EXTI2_voidInit(void);

void EXTI_voidSenseControl(u8 Copy_u8EXTI,u8 Copy_u8SenseControl);

#endif /* EXTI_INTERFACE_H_ */
