/*
 * PWM_Program.c
 *
 *  Created on: Nov 5, 2020
 *      Author: moame
 */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"
#include "../DIO/DIO_Interface.h"


/***********************************************************************/
/***************************** PWM 0 ***********************************/
/***********************************************************************/

/*
void PWM0_VidInit(void)
{
	CLR_BIT(TCCR0,0); // CS00
	CLR_BIT(TCCR0,1); // CS01
	SET_BIT(TCCR0,2); // CS02

	SET_BIT(TCCR0,3); //  WGM01
	SET_BIT(TCCR0,6); //  WGM00

	CLR_BIT(TCCR0,4); //  COM00
	SET_BIT(TCCR0,5); //  COM01

	CLR_BIT(TCCR0,7); // b Zeroooooooooooooooooo for ever


}

void PWM0_VidSetDutyCycle(u8 Copy_U8OCR)
{
	DIO_VidSetPinDirection(PORT_B,PIN_3,OUTPUT);
	OCR0 = Copy_U8OCR;
}

*/

/***********************************************************************/
/***************************** PWM 1 ***********************************/
/***********************************************************************/

void PWM1_VidInit(void)
{
	DIO_VidSetPinDirection(PORT_B,PIN_0,OUTPUT);

	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);


	CLR_BIT(TCCR1A,0); /* WGM10 & WGM11 */
	SET_BIT(TCCR1A,1);

	SET_BIT(TCCR1B,3); /* WGM12 & WGM13 */
	SET_BIT(TCCR1B,4);

	CLR_BIT(TCCR1B,0); /* Prescaler */
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);

	ICR1 = 1023;

}

void PWM1_VidSetDutyCycle(u16 Copy_U8OCR1A)
{

	OCR1A = Copy_U8OCR1A;
}



/***********************************************************************/
/***************************** PWM 2 ***********************************/
/***********************************************************************/





