/*
 * EXIT_Program.c
 *
 *  Created on: Nov 27, 2020
 *      Author: moame
 */


#include "../../LIBERARY/STD_Types.h"
#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"


#define FALLING	  0
#define RISING    1
#define OCH       2
#define LOW_LEVEL 3

#define ISC FALING

/***********************************************/
/******************** EXIT0 ********************/
/***********************************************/
void EXIT0_VidInit()
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


void EXIT0_Enable(void)
{
	SET_BIT(GICR, 6);
}

void EXIT0_Disable(void)
{
	CLR_BIT(GICR, 6);
}



/***********************************************/
/******************** EXIT1 ********************/
/***********************************************/
/*
void EXIT1_VidInit()
{
	#if ISC== FALLING
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);

	#elif ISC== RISING
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC== OCH
	//SET_BIT(MCUCR,1);
	//SET_BIT(MCUCR,0);

	#elif ISC== LOW_LEVEL
	//SET_BIT(MCUCR,1);
	//SET_BIT(MCUCR,0);

	#endif
}


void EXIT1_Enable(void)
{
	SET_BIT(GICR, 6);
}

void EXIT1_Disable(void)
{
	CLR_BIT(GICR, 6);
}
*/


/***********************************************/
/******************** EXIT2 ********************/
/***********************************************/
/*
void EXIT2_VidInit()
{
	#if ISC== FALLING
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);

	#elif ISC== RISING
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

	#elif ISC== OCH
	//SET_BIT(MCUCR,1);
	//SET_BIT(MCUCR,0);

	#elif ISC== LOW_LEVEL
	//SET_BIT(MCUCR,1);
	//SET_BIT(MCUCR,0);

	#endif
}


void EXIT2_Enable(void)
{
	SET_BIT(GICR, 6);
}

void EXIT2_Disable(void)
{
	CLR_BIT(GICR, 6);
}

*/
