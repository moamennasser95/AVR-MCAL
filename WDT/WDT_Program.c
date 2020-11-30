/*
 * WDT_Program.c
 *
 *  Created on: Nov 23, 2020
 *      Author: moame
 */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"

#include "../DIO/DIO_Interface.h"



void WDT_VidOn(u16 Copy_U16Time)
{
	switch(Copy_U16Time)
	{
	case 16 :
		CLR_BIT(WDTCR,0);
		CLR_BIT(WDTCR,1);
		CLR_BIT(WDTCR,2);
		break;

	case 32 :
		SET_BIT(WDTCR,0);
		CLR_BIT(WDTCR,1);
		CLR_BIT(WDTCR,2);
		break;

	case 64 :
		CLR_BIT(WDTCR,0);
		SET_BIT(WDTCR,1);
		CLR_BIT(WDTCR,2);
		break;

	case 128 :
		SET_BIT(WDTCR,0);
		SET_BIT(WDTCR,1);
		CLR_BIT(WDTCR,2);
		break;

	case 256 :
		CLR_BIT(WDTCR,0);
		CLR_BIT(WDTCR,1);
		SET_BIT(WDTCR,2);
		break;

	case 512 :
		SET_BIT(WDTCR,0);
		CLR_BIT(WDTCR,1);
		SET_BIT(WDTCR,2);
		break;

	case 1024 :
		CLR_BIT(WDTCR,0);
		SET_BIT(WDTCR,1);
		SET_BIT(WDTCR,2);
		break;

	case 2048 :
		SET_BIT(WDTCR,0);
		SET_BIT(WDTCR,1);
		SET_BIT(WDTCR,2);
		break;
	}

	SET_BIT(WDTCR,3);
	//SET_BIT(WDTCR,4);

}


void WDT_VidOff(void)
{

	WDTCR|=0b00011000;
	WDTCR=0x00;


}
