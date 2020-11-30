/*
 * SPI_Interface.h
 *
 *  Created on: Nov 15, 2020
 *      Author: moame
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void SPI_VidInitMaster(void);

void SPI_VidInitSlave(void);

void SPI_VidSendMaster(u8 Copy_U8Data, u8 * Copy_PU8Data);

void SPI_VidSendSlave(u8 Copy_U8Data, u8 * Copy_PU8Data);


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
