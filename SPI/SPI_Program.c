/*
 * SPI_Program.c
 *
 *  Created on: Nov 15, 2020
 *      Author: moame
 */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"

#include "../DIO/DIO_Interface.h"


void SPI_VidInitMaster(void)
{
	DIO_VidSetPinDirection(PORT_B,PIN_4,OUTPUT);
	DIO_VidSetPinDirection(PORT_B,PIN_5,OUTPUT);
	DIO_VidSetPinDirection(PORT_B,PIN_6,INPUT);
	DIO_VidSetPinDirection(PORT_B,PIN_7,OUTPUT);

	SPCR = 0b01110110;
	SPSR = 0;
}

void SPI_VidInitSlave(void)
{
	DIO_VidSetPinDirection(PORT_B,PIN_4,INPUT);
	DIO_VidSetPinDirection(PORT_B,PIN_5,INPUT);
	DIO_VidSetPinDirection(PORT_B,PIN_6,OUTPUT);
	DIO_VidSetPinDirection(PORT_B,PIN_7,INPUT);

	SPCR = 0b01100110;
	SPSR = 0;
}


void SPI_VidSendMaster(u8 Copy_U8Data, u8 * Copy_PU8Data)
{
	SPDR = Copy_U8Data;

	while(!GET_BIT(SPSR,7));

	*Copy_PU8Data = SPDR;
}


void SPI_VidSendSlave(u8 Copy_U8Data, u8 * Copy_PU8Data)
{
	SPDR = Copy_U8Data;

	while(!GET_BIT(SPSR,7));

	*Copy_PU8Data = SPDR;
}



