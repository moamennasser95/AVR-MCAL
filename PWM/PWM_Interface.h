/*
 * PWM_Interface.h
 *
 *  Created on: Nov 5, 2020
 *      Author: moame
 */

#ifndef MCAL_PWM_PWM_INTERFACE_H_
#define MCAL_PWM_PWM_INTERFACE_H_

void PWM_VidInit(void);

void PWM_VidSetDutyCycle(u8 Copy_U8OCR);

void PWM1_VidInit(void);

void PWM1_VidSetDutyCycle(u8 Copy_U8OCR1A);





#endif /* MCAL_PWM_PWM_INTERFACE_H_ */
