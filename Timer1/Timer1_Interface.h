/*
 * Timer1_Interface.h
 *
 *  Created on: Nov 14, 2020
 *      Author: moame
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

void Timer1_CAPT_InterruptEnable(void);
void Timer1_CAPT_SetFlag(void);
void Timer1_COMPA_InterruptEnable(void);
void Timer1_COMPA_SetFlag(void);
void Timer1_COMPB_InterruptEnable(void);
void Timer1_COMPB_SetFlag(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_SetFlag(void);


void Timer1_VidWaveGenerationMode(u8 Copy_U8ModeNumber);
void Timer1_VidCompareOutputMode(u8 Copy_U8ModeNumber);
void Timer1_VidPrescaler(u16 Copy_U8Prescaler);

void Timer1_VidLoad_OCR1A(u8 Copy_U8_OCR1A);
void Timer1_VidLoad_OCR1B(u8 Copy_U8_OCR1B);
void Timer1_VidLoad_ICR(u8 Copy_U8_ICR);

void Timer1_VidStopTimer(void);


#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
