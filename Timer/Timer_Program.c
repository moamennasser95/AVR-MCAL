/*
 * Timer_Program.c
 *
 *  Created on: Nov 4, 2020
 *      Author: moame
 */

#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"
#include "../DIO/DIO_Interface.h"
#include "../Interrupt/EXIT/EXIT_Interface.h"
#include "../Interrupt/GIE/GIE_Interface.h"

/***********************************************************************/
/***************************** TIMER 0 *********************************/
/***********************************************************************/
/*
static void(*Timer0_PVidCallBack)(void)= '\0';

void Timer0_VidInit(void)
{
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);

	CLR_BIT(TCCR0,3); // Normal
	CLR_BIT(TCCR0,6);

	CLR_BIT(TCCR0,4); // by default
	CLR_BIT(TCCR0,5);
	CLR_BIT(TCCR0,7);



	SET_BIT(TIMSK,0); // last operation
}

void Timer0_VidVallBack(void (* Copy_PVidCallBack)(void))
{
	Timer0_PVidCallBack=Copy_PVidCallBack;
}


void __vector_id_1(void)
{
	if(Timer0_VidFunction!=NULL)
		{
		Timer0_VidFunction();
		}

}
*/

/***********************************************************************/
/***************************** TIMER 1 *********************************/
/***********************************************************************/

static void(*Timer1_PVidCallBack)(void)= '\0';


void Timer1_VidInit(void)
{



	SET_BIT(TIMSK,0); // last operation
}



void Timer1_VidCallBack(void (* Copy_PVidCallBack)(void))
{
	Timer1_PVidCallBack=Copy_PVidCallBack;
}

/*

void __vector_id_1(void)
{
	if(Timer1_VidFunction!=NULL)
		{
		Timer1_VidFunction();
		}

}
*/


/***********************************************************************/
/***************************** TIMER 2 *********************************/
/***********************************************************************/

/*
static void(*Timer2_PVidCallBack)(void)= '\0';


void Timer2_VidInit(void)
{
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);

	CLR_BIT(TCCR0,3); // Normal
	CLR_BIT(TCCR0,6);

	CLR_BIT(TCCR0,4); // by default
	CLR_BIT(TCCR0,5);
	CLR_BIT(TCCR0,7);



	SET_BIT(TIMSK,0); // last operation
}

void Timer2_VidVallBack(void (* Copy_PVidCallBack)(void))
{
	Timer2_PVidCallBack=Copy_PVidCallBack;
}


void __vector_id_1(void)
{
	if(Timer2_VidFunction!=NULL)
		{
		Timer2_VidFunction();
		}

}
*/

