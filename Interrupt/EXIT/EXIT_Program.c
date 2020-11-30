#include "../../../LIBERARY/AVR32_REG.h"
#include "../../../LIBERARY/BIT_MATH.h"
#include "../../../LIBERARY/ERROR_STATE.h"
#include "../../../LIBERARY/STD_Types.h"

#include "../../DIO/DIO_Interface.h"
#include "EXIT_Private.h"


#define FALLING	  0
#define RISING    1
#define OCH       2
#define LOW_LEVEL 3

#define ISC FALING


void EXIT_VidInit()
{
	#if ISC== FALLING
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);
	
	#elif ISC== RISING
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);
	
	#elif ISC== OCH
	/* SET_BIT(MCUCR,1); */
	/* SET_BIT(MCUCR,0); */

	#elif ISC== LOW_LEVEL
	/* SET_BIT(MCUCR,1); */
	/* SET_BIT(MCUCR,0); */

	#endif
}


void EXIT_Enable(void)
{
	SET_BIT(GICR, 6);
}

void EXIT_Disable(void)
{
	CLR_BIT(GICR, 6);
}

/********************************************************************************/

/*
static void (*PVidCallBack)(void)= NULL;

void EXIT0_VidSetCallback(void(*Copy_PVidCallBack)(void))
{
	PVidCallBack= Copy_PVidCallBack;
}


void __vector_1(void)    // ISR(INT0_vect)
{
	if(PVidCallBack!= NULL)
	{
		PVidCallBack();
	}
}

*/
/********************************************************************************/
/*
static void (*PVidCallBack)(void)= NULL;

void Timer1_OVF_VidSetCallback(void(*Copy_PVidCallBack)(void))
{
	PVidCallBack= Copy_PVidCallBack;
}


void __vector_10(void)    // ISR(Timer1_Overflow_vect)
{
	if(PVidCallBack!= NULL)
	{
		PVidCallBack();
	}
}
*/
