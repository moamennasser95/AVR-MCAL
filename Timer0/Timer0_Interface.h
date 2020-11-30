/*
 * Timer0_Interface.h
 *
 *  Created on: Nov 14, 2020
 *      Author: moame
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

void Timer0_COMP_InterruptEnable(void);
void Timer0_OVF_InterruptEnable(void);

void Timer0_VidDutyCycle(u8 Copy_U8_OCR0);
void Timer0_VidPrescaler(u16 Copy_U8Prescaler);

void Timer0_CTC_VidInit(void);
void Timer0_NonPWM_VidInit(void);
void Timer0_FastPWM_VidInit(void);
void Timer0_PhaseCorrectPWM_VidInit(void);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
