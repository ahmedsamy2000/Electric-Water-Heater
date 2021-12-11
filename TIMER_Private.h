/*
 * TIMER_Private.h
 *
 *   
 *      Author: Ahmed Samy
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TIMER0_OVERFLOW_MODE      1
#define TIMER0_CTC_MODE           2
#define TIMER0_FAST_PWM           3
#define TIMER0_PHASE_CORRECT_PWM  4

#define TIMER0_CTC_MODE_OC0_OFF      1
#define TIMER0_CTC_MODE_OC0_TOGGLE   2
#define TIMER0_CTC_MODE_OC0_SET      3
#define TIMER0_CTC_MODE_OC0_CLR      4

#define TIMER0_OFF                0
#define TIMER0_NO_PRESCALER       1
#define TIMER0_8_PRESCALER        2
#define TIMER0_64_PRESCALER       3
#define TIMER0_256_PRESCALER      4
#define TIMER0_1024_PRESCALER     5

#define TIMER0_EXTERNAL_SOURCE_WITH_FALLING_EDGE    6
#define TIMER0_EXTERNAL_SOURCE_WITH_RISING_EDGE     7

#define TIMER0_PWM_NON_INVERTING   1
#define TIMER0_PWM_INVERTING       2

#define TCCR0     *((volatile u8*)0x53)
#define TIMSK     *((volatile u8*)0x59)
#define TCNT0     *((volatile u8*)0x52)
#define OCR0      *((volatile u8*)0x5C)

//TIMER 1
#define TCCR1B      *((volatile u8*)0x4E)
#define OCR1AH      *((volatile u8*)0x4B)
#define OCR1AL      *((volatile u8*)0x4A)


#endif /* TIMER_PRIVATE_H_ */
