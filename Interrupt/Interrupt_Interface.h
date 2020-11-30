/*
 * Interrupt_Interface.h
 *
 *  Created on: Nov 20, 2020
 *      Author: moame
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_
#define MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_

void GIE_VidEnable(void);
void GIE_VidDisable(void);

void VECT_INT0_VidCallBack ( void ( *Copy_INT0_PVidCallBack )( void* ) , void * Copy_INT0_PVidPointer );
void VECT_INT1_VidCallBack ( void ( *Copy_INT1_PVidCallBack )( void* ) , void * Copy_INT1_PVidPointer );
void VECT_INT2_VidCallBack ( void ( *Copy_INT2_PVidCallBack )( void* ) , void * Copy_INT2_PVidPointer );

void VECT_TIMER2_COMP_VidCallBack ( void ( *Copy_TIMER2_COMP_PVidCallBack )( void* ) , void * Copy_TIMER2_COMP_PVidPointer );
void VECT_TIMER2_OVF_VidCallBack ( void ( *Copy_TIMER2_OVF_PVidCallBack )( void* ) , void * Copy_TIMER2_OVF_PVidPointer );
void VECT_TIMER1_CAPT_VidCallBack ( void ( *Copy_TIMER1_CAPT_PVidCallBack )( void* ) , void * Copy_TIMER1_CAPT_PVidPointer );
void VECT_TIMER1_COMPA_VidCallBack ( void ( *Copy_TIMER1_COMPA_PVidCallBack )( void* ) , void * Copy_TIMER1_COMPA_PVidPointer );
void VECT_TIMER1_COMPB_VidCallBack ( void ( *Copy_TIMER1_COMPB_PVidCallBack )( void* ) , void * Copy_TIMER1_COMPB_PVidPointer );
void VECT_TIMER1_OVF_VidCallBack ( void ( *Copy_TIMER1_OVF_PVidCallBack )( void* ) , void * Copy_TIMER1_OVF_PVidPointer );
void VECT_TIMER0_COMP_VidCallBack ( void ( *Copy_TIMER0_COMP_PVidCallBack )( void* ) , void * Copy_TIMER0_COMP_PVidPointer);
void VECT_TIMER0_OVF_VidCallBack ( void ( *Copy_TIMER0_OVF_PVidCallBack )( void* ) , void * Copy_TIMER0_OVF_PVidPointer );

void VECT_SPI_STC_VidCallBack ( void ( *Copy_SPI_STC_PVidCallBack )( void* ) , void * Copy_SPI_STC_PVidPointer );
void VECT_USART_RXC_VidCallBack ( void ( *Copy_USART_RXC_PVidCallBack )( void* ) , void * Copy_USART_RXC_PVidPointer );
void VECT_USART_UDRE_VidCallBack ( void ( *Copy_USART_UDRE_PVidCallBack )( void* ) , void * Copy_USART_UDRE_PVidPointer );
void VECT_USART_TXC_VidCallBack ( void ( *Copy_USART_TXC_PVidCallBack )( void* ) , void * Copy_USART_TXC_PVidPointer );
void VECT_ADC_VidCallBack ( void ( *Copy_ADC_PVidCallBack )( void* ) , void * Copy_ADC_PVidPointer );

void VECT_EE_RDY_VidCallBack ( void ( *Copy_EE_RDY_PVidCallBack )( void* ) , void * Copy_EE_RDY_PVidPointer );
void VECT_ANA_COMP_VidCallBack ( void ( *Copy_ANA_COMP_PVidCallBack )( void* ) , void * Copy_ANA_COMP_PVidPointer );
void VECT_TWI_VidCallBack ( void ( *Copy_TWI_PVidCallBack )( void* ) , void * Copy_TWI_PVidPointer );
void VECT_SPM_RDY_VidCallBack ( void ( *Copy_SPM_RDY_PVidCallBack )( void* ) , void * Copy_SPM_RDY_PVidPointer );



#endif /* MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_ */
