/*
 * UART_Program.c
 *
 *  Created on: Nov 12, 2020
 *      Author: moame
 */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"

#include "../DIO/DIO_Interface.h"


void UART_VidInit( u32 Copy_U8BoudRate )
{

	DIO_VidSetPinDirection( PORT_D , PIN_1 , OUTPUT ) ;

	u16 UBRR ;

	UBRR = ( F_CPU / ( 16 * Copy_U8BoudRate ) ) -1 ;

	UBRRH = (u8)( UBRR >> 8 ) ;
	UBRRL = (u8)( UBRR ) ;

	SET_BIT( UCSRB , 3 );
	SET_BIT( UCSRB , 4 );

	UCSRC = (1<<7) | (1<<2) | (1<<1) ;

}


void UART_VidTransmit( u8 Copy_U8Data )
{
	while(!GET_BIT(UCSRA,5)); // flags of intruupt

	UDR = Copy_U8Data ;
}

void UART_VidTransmitString(u8 * Copy_PU8String)
{
	for ( u8 Counter=0  ;  Copy_PU8String[Counter]!='\0'  ;  Counter++ )
	{
		UART_VidTransmit( Copy_PU8String[Counter] );
	}

}
void UART_VidReceive(u8 * Copy_U8Data)
{
	while(!GET_BIT(UCSRA,7)); // flags of intruupt

	*Copy_U8Data = UDR ;

}


