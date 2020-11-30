/*
 * Timer1_Program.c
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


void Timer1_VidLoad_OCR1A(u8 Copy_U8_OCR1A)
{
	DIO_VidSetPinDirection(PORT_D , PIN_5 , OUTPUT);

	OCR1A = Copy_U8_OCR1A ;
}

void Timer1_VidLoad_OCR1B(u8 Copy_U8_OCR1B)
{
	DIO_VidSetPinDirection(PORT_D , PIN_4 , OUTPUT);

	OCR1B = Copy_U8_OCR1B ;
}

void Timer1_VidLoad_ICR(u8 Copy_U8_ICR)
{
	DIO_VidSetPinDirection(PORT_D , PIN_6 , INPUT);

	ICR1 = Copy_U8_ICR ;
}

/*****************************************************/


void Timer1_CAPT_InterruptEnable(void)
{
	/* Interrupt On Input Capture Enable ( last operation ) */
		SET_BIT(TIMSK,5); // TICIE1
}

void Timer1_COMPA_InterruptEnable(void)
{
	/* Interrupt On Compare Match A Enable ( last operation ) */
		SET_BIT(TIMSK,4); // OCIEIA
}

void Timer1_COMPB_InterruptEnable(void)
{
	/* Interrupt On Compare Match B Enable ( last operation ) */
		SET_BIT(TIMSK,3); // OCIEIB
}

void Timer1_OVF_InterruptEnable(void)
{
	/* Interrupt On Over Flow  Enable ( last operation ) */
		SET_BIT(TIMSK,2); // TOIE1
}

/*****************************************************/


void Timer1_CAPT_SetFlag(void)
{
	/* Interrupt On Input Capture Enable ( last operation ) */
		SET_BIT(TIFR,5); // ICF1
}

void Timer1_COMPA_SetFlag(void)
{
	/* Interrupt On Compare Match A Enable ( last operation ) */
		SET_BIT(TIFR,4); // OCIE1A
}

void Timer1_COMPB_SetFlag(void)
{
	/* Interrupt On Compare Match B Enable ( last operation ) */
		SET_BIT(TIFR,3); // OCIE1B
}

void Timer1_OVF_SetFlag(void)
{
	/* Interrupt On Over Flow  Enable ( last operation ) */
		SET_BIT(TIFR,2); // TOV1
}

/*****************************************************/

void Timer1_VidWaveGenerationMode(u8 Copy_U8ModeNumber)
{
	switch(Copy_U8ModeNumber)
	{
	case 0:
		CLR_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 1:
		SET_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 2:
		CLR_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 3:
		SET_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 4:
		CLR_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 5:
		SET_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 6:
		CLR_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 7:
		SET_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		CLR_BIT(TCCR1B,4); // WGM13
		break ;

	case 8:
		CLR_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	case 9:
		SET_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	case 10:
		CLR_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	case 11:
		SET_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		CLR_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	case 12:
		CLR_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	case 13:
		SET_BIT(TCCR1A,0); // WGM10
		CLR_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	case 14:
		CLR_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	case 15:
		SET_BIT(TCCR1A,0); // WGM10
		SET_BIT(TCCR1A,1); // WGM11
		SET_BIT(TCCR1B,3); // WGM12
		SET_BIT(TCCR1B,4); // WGM13
		break ;

	default :
		break;

	}
}



void Timer1_VidCompareOutputMode(u8 Copy_U8ModeNumber)
{
	switch(Copy_U8ModeNumber)
	{
	case 0:	// Normal
		CLR_BIT(TCCR1A,4); // COM1B0
		CLR_BIT(TCCR1A,5); // COM1B1
		CLR_BIT(TCCR1A,6); // COM1A0
		CLR_BIT(TCCR1A,7); // COM1A1
		break ;

	case 1:	// Toggle
		SET_BIT(TCCR1A,4); // COM1B0
		CLR_BIT(TCCR1A,5); // COM1B1
		SET_BIT(TCCR1A,6); // COM1A0
		CLR_BIT(TCCR1A,7); // COM1A1
		break ;

	case 2:	// Clear Then Set
		CLR_BIT(TCCR1A,4); // COM1B0
		SET_BIT(TCCR1A,5); // COM1B1
		CLR_BIT(TCCR1A,6); // COM1A0
		SET_BIT(TCCR1A,7); // COM1A1
		break ;

	case 3:	// Set Then Clear
		SET_BIT(TCCR1A,4); // COM1B0
		SET_BIT(TCCR1A,5); // COM1B1
		SET_BIT(TCCR1A,6); // COM1A0
		SET_BIT(TCCR1A,7); // COM1A1
		break ;

	}
}



void Timer1_VidPrescaler(u16 Copy_U8Prescaler)
{
	switch(Copy_U8Prescaler)
	{

	case 1 :
		SET_BIT(TCCR1B,0); // CS00
		CLR_BIT(TCCR1B,1); // CS01
		CLR_BIT(TCCR1B,2); // CS02
		break;

	case 8 :
		CLR_BIT(TCCR1B,0); // CS00
		SET_BIT(TCCR1B,1); // CS01
		CLR_BIT(TCCR1B,2); // CS02
		break;

	case 64 :
		SET_BIT(TCCR1B,0); // CS00
		SET_BIT(TCCR1B,1); // CS01
		CLR_BIT(TCCR1B,2); // CS02
		break;

	case 256 :
		CLR_BIT(TCCR1B,0); // CS00
		CLR_BIT(TCCR1B,1); // CS01
		SET_BIT(TCCR1B,2); // CS02
		break;

	case 1024 :
		SET_BIT(TCCR1B,0); // CS00
		CLR_BIT(TCCR1B,1); // CS01
		SET_BIT(TCCR1B,2); // CS02
		break;

	default :
		break;

	}
}


void Timer1_VidStopTimer(void)
{
	TCNT1 = 0 ;
	TCCR1B = 0 ;
}

