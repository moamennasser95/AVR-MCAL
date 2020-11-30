/*
 * Timer0_Program.c
 *
 *  Created on: Nov 14, 2020
 *      Author: moame
 */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"

#include "../DIO/DIO_Interface.h"

void Timer0_COMP_InterruptEnable(void)
{
	/* Interrupt On Compare Match Enable ( last operation ) */
		SET_BIT(TIMSK,1); // TOIE0
}

void Timer0_OVF_InterruptEnable(void)
{
	/* Interrupt On Over flow  Enable ( last operation ) */
		SET_BIT(TIMSK,0); // TOIE0
}


void Timer0_CTC_VidInit(void)
{
	/* Waveform Generation Mode ( CTC Mode ) */
	CLR_BIT(TCCR0,6); // WGM00
	SET_BIT(TCCR0,3); // WGM01
}


void Timer0_NonPWM_VidInit(void)
{
	/* Waveform Generation Mode ( CTC Mode ) */
	CLR_BIT(TCCR0,6); // WGM00
	SET_BIT(TCCR0,3); // WGM01

	/* Compare Output Mode ( Toggle )*/
	SET_BIT(TCCR0,4); // COM00
	CLR_BIT(TCCR0,5); // COM01
}


void Timer0_FastPWM_VidInit(void)
{
	/* Waveform Generation Mode ( Fast PWM Mode ) */
	SET_BIT(TCCR0,6); // WGM00
	SET_BIT(TCCR0,3); // WGM01

	/* Compare Output Mode ( Set )*/
	SET_BIT(TCCR0,4); // COM00
	SET_BIT(TCCR0,5); // COM01
}


void Timer0_PhaseCorrectPWM_VidInit(void)
{
	/* Waveform Generation Mode ( Phase Correct Mode ) */
	SET_BIT(TCCR0,6); // WGM00
	CLR_BIT(TCCR0,3); // WGM01

	/* Compare Output Mode ( Set )*/
	SET_BIT(TCCR0,4); // COM00
	SET_BIT(TCCR0,5); // COM01
}


void Timer0_VidDutyCycle(u8 Copy_U8_OCR0)
{
	/* Set OC0 Direction As OUTPUT */
	DIO_VidSetPinDirection(PORT_B , PIN_3 , OUTPUT);

	/* Load OCR0 Value ( From 0 to 255 ) */
	OCR0 = Copy_U8_OCR0;
}

void Timer0_VidPrescaler(u16 Copy_U8Prescaler)
{
	switch(Copy_U8Prescaler)
	{

	case 1 :
		SET_BIT(TCCR0,0); // CS00
		CLR_BIT(TCCR0,1); // CS01
		CLR_BIT(TCCR0,2); // CS02
		break;

	case 8 :
		CLR_BIT(TCCR0,0); // CS00
		SET_BIT(TCCR0,1); // CS01
		CLR_BIT(TCCR0,2); // CS02
		break;

	case 64 :
		SET_BIT(TCCR0,0); // CS00
		SET_BIT(TCCR0,1); // CS01
		CLR_BIT(TCCR0,2); // CS02
		break;

	case 256 :
		CLR_BIT(TCCR0,0); // CS00
		CLR_BIT(TCCR0,1); // CS01
		SET_BIT(TCCR0,2); // CS02
		break;

	case 1024 :
		SET_BIT(TCCR0,0); // CS00
		CLR_BIT(TCCR0,1); // CS01
		SET_BIT(TCCR0,2); // CS02
		break;

	default :
		break;

	}

}

