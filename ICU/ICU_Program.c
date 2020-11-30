/*
 * ICU_Program.c
 *
 *  Created on: Nov 28, 2020
 *      Author: moame
 */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"

#include "../Timer1/Timer1_Interface.h"

#include "../DIO/DIO_Interface.h"

void ICU_VidInit(void)
{
	Timer1_VidPrescaler(1);

	SET_BIT(TCCR1B,7); // Noice Canceler
}


void ICU_VidEdgeSelectRising(void)
{
	SET_BIT(TCCR1B,6);
}

void ICU_VidEdgeSelectFalling(void)
{
	CLR_BIT(TCCR1B,6);
}

