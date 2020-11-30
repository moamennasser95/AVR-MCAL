/*
 * UART_Interface.h
 *
 *  Created on: Nov 12, 2020
 *      Author: moame
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_VidInit( u32 Copy_U8BoudRate );

void UART_VidTransmit( u8 Copy_U8Data );

void UART_VidReceive(u8 * Copy_PU8Data);

void UART_VidTransmitString(u8 * Copy_PU8String);



#endif /* MCAL_UART_UART_INTERFACE_H_ */
