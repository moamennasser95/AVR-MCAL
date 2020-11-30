/*
 * Interrupt_Program.c
 *
 *  Created on: Nov 20, 2020
 *      Author: moame
 */


#include "../../LIBERARY/STD_Types.h"
#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"

#include "Interrupt_Private.h"



void GIE_VidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_VidDisable(void)
{
	CLR_BIT(SREG,7);
}

/***********************************************/
/****************** VECT_INT0 ******************/
/***********************************************/
static void(*INT0_PVidCallBack)(void*) = NULL ;
static void * INT0_PVidPointer = NULL ;

void VECT_INT0_VidCallBack ( void ( *Copy_INT0_PVidCallBack )( void* ) , void * Copy_INT0_PVidPointer )
{
	INT0_PVidCallBack = Copy_INT0_PVidCallBack ;
	INT0_PVidPointer = Copy_INT0_PVidPointer ;
}

ISR(VECT_INT0)
{
	if(INT0_PVidCallBack != NULL)
	{
		INT0_PVidCallBack(INT0_PVidPointer) ;
	}
}


/***********************************************/
/****************** VECT_INT1 ******************/
/***********************************************/
static void(*INT1_PVidCallBack)(void*) = NULL ;
static void * INT1_PVidPointer = NULL ;

void VECT_INT1_VidCallBack ( void ( *Copy_INT1_PVidCallBack )( void* ) , void * Copy_INT1_PVidPointer )
{
	INT1_PVidCallBack = Copy_INT1_PVidCallBack ;
	INT1_PVidPointer = Copy_INT1_PVidPointer ;
}

ISR(VECT_INT1)
{
	if(INT1_PVidCallBack != NULL)
	{
		INT1_PVidCallBack(INT1_PVidPointer) ;
	}
}


/***********************************************/
/****************** VECT_INT2 ******************/
/***********************************************/
static void(*INT2_PVidCallBack)(void*) = NULL ;
static void * INT2_PVidPointer = NULL ;

void VECT_INT2_VidCallBack ( void ( *Copy_INT2_PVidCallBack )( void* ) , void * Copy_INT2_PVidPointer )
{
	INT2_PVidCallBack = Copy_INT2_PVidCallBack ;
	INT2_PVidPointer = Copy_INT2_PVidPointer ;
}

ISR(VECT_INT2)
{
	if(INT2_PVidCallBack != NULL)
	{
		INT2_PVidCallBack(INT2_PVidPointer) ;
	}
}


/************************************************/
/*************** VECT_TIMER2_COMP ***************/
/************************************************/
static void(*TIMER2_COMP_PVidCallBack)(void*) = NULL ;
static void * TIMER2_COMP_PVidPointer = NULL ;

void VECT_TIMER2_COMP_VidCallBack ( void ( *Copy_TIMER2_COMP_PVidCallBack )( void* ) , void * Copy_TIMER2_COMP_PVidPointer )
{
	TIMER2_COMP_PVidCallBack = Copy_TIMER2_COMP_PVidCallBack ;
	TIMER2_COMP_PVidPointer = Copy_TIMER2_COMP_PVidPointer ;
}

ISR(VECT_TIMER2_COMP)
{
	if(TIMER2_COMP_PVidCallBack != NULL)
	{
		TIMER2_COMP_PVidCallBack(TIMER2_COMP_PVidPointer) ;
	}
}


/***********************************************/
/*************** VECT_TIMER2_OVF ***************/
/***********************************************/
static void(*TIMER2_OVF_PVidCallBack)(void*) = NULL ;
static void * TIMER2_OVF_PVidPointer = NULL ;

void VECT_TIMER2_OVF_VidCallBack ( void ( *Copy_TIMER2_OVF_PVidCallBack )( void* ) , void * Copy_TIMER2_OVF_PVidPointer )
{
	TIMER2_OVF_PVidCallBack = Copy_TIMER2_OVF_PVidCallBack ;
	TIMER2_OVF_PVidPointer = Copy_TIMER2_OVF_PVidPointer ;
}

ISR(VECT_TIMER2_OVF)
{
	if(TIMER2_OVF_PVidCallBack != NULL)
	{
		TIMER2_OVF_PVidCallBack(TIMER2_OVF_PVidPointer) ;
	}
}


/************************************************/
/*************** VECT_TIMER1_CAPT ***************/
/************************************************/
static void(*TIMER1_CAPT_PVidCallBack)(void*) = NULL ;
static void * TIMER1_CAPT_PVidPointer = NULL ;

void VECT_TIMER1_CAPT_VidCallBack ( void ( *Copy_TIMER1_CAPT_PVidCallBack )( void* ) , void * Copy_TIMER1_CAPT_PVidPointer )
{
	TIMER1_CAPT_PVidCallBack = Copy_TIMER1_CAPT_PVidCallBack ;
	TIMER1_CAPT_PVidPointer = Copy_TIMER1_CAPT_PVidPointer ;
}

ISR(VECT_TIMER1_CAPT)
{
	if(TIMER1_CAPT_PVidCallBack != NULL)
	{
		TIMER1_CAPT_PVidCallBack(TIMER1_CAPT_PVidPointer) ;
	}
}


/*************************************************/
/*************** VECT_TIMER1_COMPA ***************/
/*************************************************/
static void(*TIMER1_COMPA_PVidCallBack)(void*) = NULL ;
static void * TIMER1_COMPA_PVidPointer = NULL ;

void VECT_TIMER1_COMPA_VidCallBack ( void ( *Copy_TIMER1_COMPA_PVidCallBack )( void* ) , void * Copy_TIMER1_COMPA_PVidPointer )
{
	TIMER1_COMPA_PVidCallBack = Copy_TIMER1_COMPA_PVidCallBack ;
	TIMER1_COMPA_PVidPointer = Copy_TIMER1_COMPA_PVidPointer ;
}

ISR(VECT_TIMER1_COMPA)
{
	if(TIMER1_COMPA_PVidCallBack != NULL)
	{
		TIMER1_COMPA_PVidCallBack(TIMER1_COMPA_PVidPointer) ;
	}
}


/*************************************************/
/*************** VECT_TIMER1_COMPB ***************/
/*************************************************/
static void(*TIMER1_COMPB_PVidCallBack)(void*) = NULL ;
static void * TIMER1_COMPB_PVidPointer = NULL ;

void VECT_TIMER1_COMPB_VidCallBack ( void ( *Copy_TIMER1_COMPB_PVidCallBack )( void* ) , void * Copy_TIMER1_COMPB_PVidPointer )
{
	TIMER1_COMPB_PVidCallBack = Copy_TIMER1_COMPB_PVidCallBack ;
	TIMER1_COMPB_PVidPointer = Copy_TIMER1_COMPB_PVidPointer ;
}

ISR(VECT_TIMER1_COMPB)
{
	if(TIMER1_COMPB_PVidCallBack != NULL)
	{
		TIMER1_COMPB_PVidCallBack(TIMER1_COMPB_PVidPointer) ;
	}
}


/***********************************************/
/*************** VECT_TIMER1_OVF ***************/
/***********************************************/
static void(*TIMER1_OVF_PVidCallBack)(void*) = NULL ;
static void * TIMER1_OVF_PVidPointer = NULL ;

void VECT_TIMER1_OVF_VidCallBack ( void ( *Copy_TIMER1_OVF_PVidCallBack )( void* ) , void * Copy_TIMER1_OVF_PVidPointer )
{
	TIMER1_OVF_PVidCallBack = Copy_TIMER1_OVF_PVidCallBack ;
	TIMER1_OVF_PVidPointer = Copy_TIMER1_OVF_PVidPointer ;
}

ISR(VECT_TIMER1_OVF)
{
	if(TIMER1_OVF_PVidCallBack != NULL)
	{
		TIMER1_OVF_PVidCallBack(TIMER1_OVF_PVidPointer) ;
	}
}


/************************************************/
/*************** VECT_TIMER0_COMP ***************/
/************************************************/
static void(*TIMER0_COMP_PVidCallBack)(void*) = NULL ;
static void * TIMER0_COMP_PVidPointer = NULL ;

void VECT_TIMER0_COMP_VidCallBack ( void ( *Copy_TIMER0_COMP_PVidCallBack )( void* ) , void * Copy_TIMER0_COMP_PVidPointer)
{
	TIMER0_COMP_PVidCallBack = Copy_TIMER0_COMP_PVidCallBack ;
	TIMER0_COMP_PVidPointer = Copy_TIMER0_COMP_PVidPointer ;
}

ISR(VECT_TIMER0_COMP)
{
	if(TIMER0_COMP_PVidCallBack != NULL)
	{
		TIMER0_COMP_PVidCallBack( TIMER0_COMP_PVidPointer ) ;
	}
}


/***********************************************/
/*************** VECT_TIMER0_OVF ***************/
/***********************************************/
static void(*TIMER0_OVF_PVidCallBack)(void*) = NULL ;
static void * TIMER0_OVF_PVidPointer = NULL ;

void VECT_TIMER0_OVF_VidCallBack ( void ( *Copy_TIMER0_OVF_PVidCallBack )( void* ) , void * Copy_TIMER0_OVF_PVidPointer )
{
	TIMER0_OVF_PVidCallBack = Copy_TIMER0_OVF_PVidCallBack ;
	TIMER0_OVF_PVidPointer = Copy_TIMER0_OVF_PVidPointer ;
}

ISR(VECT_TIMER0_OVF)
{
	if(TIMER0_OVF_PVidCallBack != NULL)
	{
		TIMER0_OVF_PVidCallBack(TIMER0_OVF_PVidPointer) ;
	}
}


/**********************************************/
/**************** VECT_SPI_STC ****************/
/**********************************************/
static void(*SPI_STC_PVidCallBack)(void*) = NULL ;
static void * SPI_STC_PVidPointer = NULL ;

void VECT_SPI_STC_VidCallBack ( void ( *Copy_SPI_STC_PVidCallBack )( void* ) , void * Copy_SPI_STC_PVidPointer )
{
	SPI_STC_PVidCallBack = Copy_SPI_STC_PVidCallBack ;
	SPI_STC_PVidPointer = Copy_SPI_STC_PVidPointer ;
}

ISR(VECT_SPI_STC)
{
	if(SPI_STC_PVidCallBack != NULL)
	{
		SPI_STC_PVidCallBack(SPI_STC_PVidPointer) ;
	}
}


/**********************************************/
/*************** VECT_USART_RXC ***************/
/**********************************************/
static void(*USART_RXC_PVidCallBack)(void*) = NULL ;
static void * USART_RXC_PVidPointer = NULL ;

void VECT_USART_RXC_VidCallBack ( void ( *Copy_USART_RXC_PVidCallBack )( void* ) , void * Copy_USART_RXC_PVidPointer )
{
	USART_RXC_PVidCallBack = Copy_USART_RXC_PVidCallBack ;
	USART_RXC_PVidPointer = Copy_USART_RXC_PVidPointer ;
}

ISR(VECT_USART_RXC)
{
	if(USART_RXC_PVidCallBack != NULL)
	{
		USART_RXC_PVidCallBack(USART_RXC_PVidPointer) ;
	}
}


/***********************************************/
/*************** VECT_USART_UDRE ***************/
/***********************************************/
static void(*USART_UDRE_PVidCallBack)(void*) = NULL ;
static void * USART_UDRE_PVidPointer = NULL ;

void VECT_USART_UDRE_VidCallBack ( void ( *Copy_USART_UDRE_PVidCallBack )( void* ) , void * Copy_USART_UDRE_PVidPointer )
{
	USART_UDRE_PVidCallBack = Copy_USART_UDRE_PVidCallBack ;
	USART_UDRE_PVidPointer = Copy_USART_UDRE_PVidPointer ;
}

ISR(VECT_USART_UDRE)
{
	if(USART_UDRE_PVidCallBack != NULL)
	{
		USART_UDRE_PVidCallBack(USART_UDRE_PVidPointer) ;
	}
}


/**********************************************/
/*************** VECT_USART_TXC ***************/
/**********************************************/
static void(*USART_TXC_PVidCallBack)(void*) = NULL ;
static void * USART_TXC_PVidPointer = NULL ;

void VECT_USART_TXC_VidCallBack ( void ( *Copy_USART_TXC_PVidCallBack )( void* ) , void * Copy_USART_TXC_PVidPointer )
{
	USART_TXC_PVidCallBack = Copy_USART_TXC_PVidCallBack ;
	USART_TXC_PVidPointer = Copy_USART_TXC_PVidPointer ;
}

ISR(VECT_USART_TXC)
{
	if(USART_TXC_PVidCallBack != NULL)
	{
		USART_TXC_PVidCallBack(USART_TXC_PVidPointer) ;
	}
}


/**********************************************/
/****************** VECT_ADC ******************/
/**********************************************/
static void(*ADC_PVidCallBack)(void*) = NULL ;
static void * ADC_PVidPointer = NULL ;

void VECT_ADC_VidCallBack ( void ( *Copy_ADC_PVidCallBack )( void* ) , void * Copy_ADC_PVidPointer )
{
	ADC_PVidCallBack = Copy_ADC_PVidCallBack ;
	ADC_PVidPointer = Copy_ADC_PVidPointer ;
}

ISR(VECT_ADC)
{
	if(ADC_PVidCallBack != NULL)
	{
		ADC_PVidCallBack(ADC_PVidPointer) ;
	}
}


/***********************************************/
/***************** VECT_EE_RDY *****************/
/***********************************************/
static void(*EE_RDY_PVidCallBack)(void*) = NULL ;
static void * EE_RDY_PVidPointer = NULL ;

void VECT_EE_RDY_VidCallBack ( void ( *Copy_EE_RDY_PVidCallBack )( void* ) , void * Copy_EE_RDY_PVidPointer )
{
	EE_RDY_PVidCallBack = Copy_EE_RDY_PVidCallBack ;
	EE_RDY_PVidPointer = Copy_EE_RDY_PVidPointer ;
}

ISR(VECT_EE_RDY)
{
	if(EE_RDY_PVidCallBack != NULL)
	{
		EE_RDY_PVidCallBack(EE_RDY_PVidPointer) ;
	}
}


/***********************************************/
/**************** VECT_ANA_COMP ****************/
/***********************************************/
static void(*ANA_COMP_PVidCallBack)(void*) = NULL ;
static void * ANA_COMP_PVidPointer = NULL ;

void VECT_ANA_COMP_VidCallBack ( void ( *Copy_ANA_COMP_PVidCallBack )( void* ) , void * Copy_ANA_COMP_PVidPointer )
{
	ANA_COMP_PVidCallBack = Copy_ANA_COMP_PVidCallBack ;
	ANA_COMP_PVidPointer = Copy_ANA_COMP_PVidPointer ;
}

ISR(VECT_ANA_COMP)
{
	if(ANA_COMP_PVidCallBack != NULL)
	{
		ANA_COMP_PVidCallBack(ANA_COMP_PVidPointer) ;
	}
}


/**********************************************/
/****************** VECT_TWI ******************/
/**********************************************/
static void(*TWI_PVidCallBack)(void*) = NULL ;
static void * TWI_PVidPointer = NULL ;

void VECT_TWI_VidCallBack ( void ( *Copy_TWI_PVidCallBack )( void* ) , void * Copy_TWI_PVidPointer )
{
	TWI_PVidCallBack = Copy_TWI_PVidCallBack ;
	TWI_PVidPointer = Copy_TWI_PVidPointer ;
}

ISR(VECT_TWI)
{
	if(TWI_PVidCallBack != NULL)
	{
		TWI_PVidCallBack(TWI_PVidPointer) ;
	}
}


/**********************************************/
/**************** VECT_SPM_RDY ****************/
/**********************************************/
static void(*SPM_RDY_PVidCallBack)(void*) = NULL ;
static void * SPM_RDY_PVidPointer = NULL ;

void VECT_SPM_RDY_VidCallBack ( void ( *Copy_SPM_RDY_PVidCallBack )( void* ) , void * Copy_SPM_RDY_PVidPointer )
{
	SPM_RDY_PVidCallBack = Copy_SPM_RDY_PVidCallBack ;
	SPM_RDY_PVidPointer = Copy_SPM_RDY_PVidPointer ;
}

ISR(VECT_SPM_RDY)
{
	if(SPM_RDY_PVidCallBack != NULL)
	{
		SPM_RDY_PVidCallBack(SPM_RDY_PVidPointer) ;
	}
}

