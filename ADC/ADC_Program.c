/*
 * ADC_Program.c
 *
 *  Created on: Nov 3, 2020
 *      Author: moame
 */

#include "../../LIBERARY/AVR32_REG.h"
#include "../../LIBERARY/BIT_MATH.h"
#include "../../LIBERARY/ERROR_STATE.h"
#include "../../LIBERARY/STD_Types.h"

#include "../Interrupt/Interrupt_Private.h"
#include "ADC_Interface.h"


void ADC_VidInit(void)
{

	SET_BIT( ADCSRA , 7 ) ; // Enable ADC


#if ADC_VREF == INTERNAL_OFF
	CLR_BIT( ADMUX , 6 ) ; // REFS0
	CLR_BIT( ADMUX , 7 ) ; // REFS1

#elif ADC_VREF == EXTERNAL_AVCC
	SET_BIT( ADMUX , 6 ) ; // REFS0
	CLR_BIT( ADMUX , 7 ) ; // REFS1

#elif ADC_VREF == RESERVED
	CLR_BIT( ADMUX , 6 ) ; // REFS0
	SET_BIT( ADMUX , 7 ) ; // REFS1

#elif ADC_VREF == INTERNAL_VOLTAGE
	SET_BIT( ADMUX , 6 ) ; // REFS0
	SET_BIT( ADMUX , 7 ) ; // REFS1

#endif


#if ADC_ADJ	== RIGHT_ADJ
	CLR_BIT( ADMUX , 5 ) ; // ADLAR

#elif ADC_ADJ == LEFT_ADJ
	SET_BIT( ADMUX , 5 ) ;

#endif


#if ADC_PRESCALER == PRESCALER_2
	SET_BIT( ADCSRA , 0 ) ;
	CLR_BIT( ADCSRA , 1 ) ;
	CLR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_4
	CLR_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	CLR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_8
	SET_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	CLR_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_16
	CLR_BIT( ADCSRA , 0 ) ;
	CLR_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_32
	SET_BIT( ADCSRA , 0 ) ;
	CLR_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_64
	CLR_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_128
	SET_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#endif




}

/**********************************************************************/
void ADC_VidSelectChannel(u8 Copy_U8Channel)
{

	ADMUX&= 0XE0;

	if ( Copy_U8Channel >= 0    &&    Copy_U8Channel <= 31 )
	{
		ADMUX|= Copy_U8Channel ;
	}
	else
	{
	}
}



/**********************************************************************/
void ADC_VidRead(u16 * Copy_ReadValue)
{

	SET_BIT( ADCSRA , 6 ) ; // ( ADSC ) Start Converting

	while(GET_BIT(ADCSRA,6) == 1); // because this bit become equal zero after finishing converting

	*Copy_ReadValue = ADC ; // read value ( We Are Reading The Low First Then The High

}

/**********************************************************************/
void ADC_VidAutoTriggerEnable(void)
{

	SET_BIT( ADCSRA , 5 ) ; // Auto Trigger Enable

#if ADC_TRIGGER_SOURCE == FREE_RUNNING_MODE
	CLR_BIT( SFIOR , 5 ) ;
	CLR_BIT( SFIOR , 6 ) ;
	CLR_BIT( SFIOR , 7 ) ;

#elif ADC_TRIGGER_SOURCE == ANALOG_COMPARATOR_MODE
	SET_BIT( SFIOR , 5 ) ;
	CLR_BIT( SFIOR , 6 ) ;
	CLR_BIT( SFIOR , 7 ) ;

#elif ADC_TRIGGER_SOURCE == EXTERNAL_INTERRUPT_MODE
	CLR_BIT( SFIOR , 5 ) ;
	SET_BIT( SFIOR , 6 ) ;
	CLR_BIT( SFIOR , 7 ) ;

#elif ADC_TRIGGER_SOURCE == TIMER0_COMP_MODE
	SET_BIT( SFIOR , 5 ) ;
	SET_BIT( SFIOR , 6 ) ;
	CLR_BIT( SFIOR , 7 ) ;

#elif ADC_TRIGGER_SOURCE == TIMER0_OVF_MODE
	CLR_BIT( SFIOR , 5 ) ;
	CLR_BIT( SFIOR , 6 ) ;
	SET_BIT( SFIOR , 7 ) ;

#elif ADC_TRIGGER_SOURCE == TIMER1_COMP_B_MODE
	SET_BIT( SFIOR , 5 ) ;
	CLR_BIT( SFIOR , 6 ) ;
	SET_BIT( SFIOR , 7 ) ;

#elif ADC_TRIGGER_SOURCE == TIMER1_OVF_MODE
	CLR_BIT( SFIOR , 5 ) ;
	SET_BIT( SFIOR , 6 ) ;
	SET_BIT( SFIOR , 7 ) ;

#elif ADC_TRIGGER_SOURCE == TIMER1_CAPTURE_EVENT_MODE
	SET_BIT( SFIOR , 5 ) ;
	SET_BIT( SFIOR , 6 ) ;
	SET_BIT( SFIOR , 7 ) ;

#endif

}

/**********************************************************************/



extern void ADC_VidCallBack(void(*Copy_PU8CallBack))
{

}

ISR(ISR_ADC)
{

}





/*

void ADC_VidTriggingMode(u8 Copy_U8Mode)   // msh fahmha
{
	switch (Copy_U8Mode)
	{
		case 0 :
			CLR_BIT( ADCSRA , 5 ) ;
			break ;
		case 1 :
			SET_BIT( ADCSRA , 5 ) ;
			break ;
	}
}



void ADC_VidInterruptEnable(void)
{
	SET_BIT( ADCSRA , 3 ) ;
}



void ADC_VidInterruptDisable(void)
{
	CLR_BIT( ADCSRA , 3 ) ;
}

void ADC_VidInterruptFlagPolling(void)
{
	ADCH = 0 ;
	ADCL = 0 ;

	while(!GET_BIT(ADCSRA,4)); // anther way to know that conversion has been ended
	SET_BIT(ADCSRA,4); // 3shan n5leha b zero ,, hnkteb 3leha 1

}

*/
