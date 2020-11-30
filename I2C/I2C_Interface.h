/*
 * I2C_Interface.h
 *
 *  Created on: Nov 16, 2020
 *      Author: moame
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

void I2C_VidInit(void);
u8 I2C_U8Start(void);
u8 I2C_U8SendAdress(u8 COPY_U8Adress, u8 COPY_U8RW);
u8 I2C_U8SlaveCheckAdress(void);
u8 I2C_U8MasterSend(u8 COPY_U8Data);
u8 I2C_U8SlaveReceive(u8 *COPY_U8Data);
u8 I2C_U8SlaveSend(u8 COPY_U8Data);
u8 I2C_U8MasterReceive(u8 *COPY_U8Data);
void I2C_VidStop(void);


#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
