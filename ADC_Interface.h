/*
 * ADC_Interface.h
 *
 *  
 *      Author: Ahmed Samy
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
void ADC_voidStartConversion(u8 Copy_u8Channel);
u16 ADC_u16Read_DigitalValue(void);
void ADC_voidStartConversion_interrupt(u8 Copy_u8Channel);
void ADC_voidInit_Interrupt(void);



#endif /* ADC_INTERFACE_H_ */
