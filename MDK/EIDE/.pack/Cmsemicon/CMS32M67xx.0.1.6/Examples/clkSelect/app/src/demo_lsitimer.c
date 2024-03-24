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
/** \file demo_lsitimer.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_lsitimer.h"

/****************************************************************************/
/*	Local pre-processor symbols('#define')
****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
****************************************************************************/
	
/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
****************************************************************************/
/******************************************************************************
 ** \brief	 LSITIMER_Config
 ** \param [in] 
 **            	
 ** \return  none
 ** \note  
 ******************************************************************************/
void LSITIMER_Config(void)
{
	//����LSI timerʱ��
	CGC_PER0PeriphClockCmd(CGC_PER0Periph_LSITIMER,ENABLE);
	CGC_LSI_Enable();				    //ʹ��ϵͳ�ڲ�����ʱ��
	CGC_LSITIMERCLK_Enable();		//ʹ��LSI TIMERʱ��
	
	//�ر�LSI timer
	LSITIMER_Disable();		//�ر�LSI TIMER
	
	//����LSI timer�Ƚ�ʱ��
	LSITIMER_ConfigInput(10);		//���ñȽ�ʱ��Ϊ1.333MS 
	
	//ʹ��LSI timer�ж�
	LSITIMER_EnableInt();
	NVIC_SetPriority(LSITIMER_IRQn,3);
	NVIC_EnableIRQ(LSITIMER_IRQn);
//	
	//����LSI timer
	LSITIMER_Enable();	
}




