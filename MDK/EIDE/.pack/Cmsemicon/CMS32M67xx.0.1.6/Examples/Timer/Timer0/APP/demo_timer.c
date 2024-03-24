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
/** \file demo_timer.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_timer.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

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
/*****************************************************************************
 ** \brief	TMR0_Period_Count_Config
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void TMR0_Period_Count_Config(void)
{
	/*
	(1)����Timer0 ��ʱ��
	*/
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_TIMER01,ENABLE);/*��Timer0��ʱ��*/
	TMR_ConfigClk(TMR0,TMR_CLK_DIV_1);		/*Timer0����ʱ�ӷ�ƵΪ 1��Ƶ*/
	/*
	(2)����Timer0 ����ģʽ
	*/	
	TMR_ConfigRunMode(TMR0,TMR_COUNT_PERIOD_MODE, TMR_BIT_16_MODE);		/*����Timer0Ϊ16λ���ڼ���ģʽ*/
	TMR_DisableOneShotMode(TMR0);										/*�رյ���ģʽ*/
	/*
	(3)����Timer0 ��������
	*/		
	TMR_SetPeriod(TMR0,4800);				/* 4800*Fclk*/				
	/*
	(4)����Timer0 �ж�
	*/	
	TMR_EnableOverflowInt(TMR0);
	NVIC_EnableIRQ(TIMER0_IRQn);	
	/*
	(5)����Timer0 �ж����ȼ�
	*/	
	NVIC_SetPriority(TIMER0_IRQn,3);	
	/*
	(5)����Timer0
	*/	
	TMR_Start(TMR0);			
}





























