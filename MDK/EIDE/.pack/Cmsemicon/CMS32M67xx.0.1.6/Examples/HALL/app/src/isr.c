/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/****************************************************************************/
/** \file isr.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "common.h"
#include "lsitimer.h"
#include "hall.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/
extern uint8_t HALL_FILVal ; 
extern uint8_t HALL_RAWValL;
extern uint32_t HALL_Width ;  
/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/


/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/
  
/****************************************************************************
 ** \brief	SysTick_Handler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void SysTick_Handler(void)
{
		
}

/****************************************************************************
 ** \brief	ADCB_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void ADC_IRQHandler(void)
{
		
}

   
/****************************************************************************
 ** \brief	UART0_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void UART0_IRQHandler(void)
{
		
}

/****************************************************************************
 ** \brief	LSITIMER_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void LSITIMER_IRQHandler(void)
{
		NVIC_ClearPendingIRQ(LSITIMER_IRQn);			//清除中断标志
}

/****************************************************************************
 ** \brief	LSITIMER_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void HALL_IRQHandler(void)
{
	
	HALL_Width = HALL_RDWidth_DATA();		//读出间隔值
	HALL_FILVal = HALL_FIT_DATA();			//读出滤波值
	HALL_RAWValL = HALL_RAW_DATA();			//读出实时值
	
	if( HALL_GetFlagStaus(HALL_OVFLAG))
		HALL_OVIF_Clear();                //清中断
	if( HALL_GetFlagStaus(HALL_CHGFLAG))
		HALL_CHGIF_Clear();               //清中断
	
	
		NVIC_ClearPendingIRQ(HALL_IRQn);			//清除中断标志
}



