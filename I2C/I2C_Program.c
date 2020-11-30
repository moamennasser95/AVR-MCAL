/*
 * I2C_Program.c
 *
 *  Created on: Nov 16, 2020
 *      Author: moame
 */



#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"

#include "../DIO/DIO_Interface.h"

/*

void I2C_VidInit(void)
{
	CLEAR_BIT(TWSR,0);
	CLEAR_BIT(TWSR,1);
	TWBR=2;
	SET_BIT(TWCR,6);
	TWAR=0x05;  //adress =0x04
	SET_BIT(TWCR,2);
}


u8 I2C_U8Start(void)
{
	TWCR|=(1<<7)|(1<<5);
	while (!(TWCR & (1<<7)));
	if ((TWSR & 0xF8) == 0x08)
		return 1;
	return 0;
}


u8 I2C_U8SendAdress(u8 COPY_U8Adress, u8 COPY_U8RW)
{
	TWDR = (COPY_U8Adress<<1)|COPY_U8RW;
	CLEAR_BIT(TWCR,5);
	TWCR |= (1<<7);
	while (!(TWCR & (1<<7)));
	if ( ((TWSR & 0xF8) == 0x18) || ((TWSR & 0xF8) == 0x40))
	{
		return 1;
	}

	return 0;
}


u8 I2C_U8SlaveCheckAdress(void)
{
	SET_BIT(TWCR,6);
	TWCR |= (1<<7);
	while (!(TWCR & (1<<7)));
	if ( ((TWSR & 0xF8) == 0x60) || ((TWSR & 0xF8) == 0xA8))
		{
			return 1;
		}
	return 0;
}

u8 I2C_U8MasterSend(u8 COPY_U8Data)
{
	TWDR=COPY_U8Data;
	TWCR |= (1<<7);
	while (!(TWCR & (1<<7)));

	if ((TWSR & 0xF8) == 0x28)
			{
				return 1;
			}
		return 0;
}

u8 I2C_U8SlaveReceive(u8 *COPY_U8Data)
{

	TWCR |= (1<<7);
	while (!(TWCR & (1<<7)));
	if ((TWSR & 0xF8) == 0x80)
			{
			*COPY_U8Data=TWDR;
				return 1;
			}
		return 0;
}




u8 I2C_U8SlaveSend(u8 COPY_U8Data)
{

	TWDR=COPY_U8Data;
	TWCR |= (1<<7);
	while (!(TWCR & (1<<7)));

	if ((TWSR & 0xF8) == 0xC8)
			{
				return 1;
			}
		return 0;
}


u8 I2C_U8MasterReceive(u8 *COPY_U8Data)
{

	TWCR |= (1<<7);
	while (!(TWCR & (1<<7)));
	if ((TWSR & 0xF8) == 0x80)
			{
			*COPY_U8Data=TWDR;
				return 1;
			}
		return 0;
}


void I2C_VidStop(void)
{
	TWCR |= (1<<7)|(1<<5)|(1<<4);
}



u8 I2C_U8Start(void)
{
	TWCR|=(1<<7)|(1<<5);
	while (!(TWCR & (1<<7)));
	if ((TWSR & 0xF8) == 0x08)
		return 1;
	return 0;
}





/*
void I2C_VidInit(void)
{
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	TWBR=2;
	SET_BIT(TWCR,6);
	TWAR=0x05; // address = 0x04
	SET_BIT(TWCR,2);

}

u8 I2C_U8Start(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(GET_BIT(TWCR,TWINT)==0);
	if()
}
*/












