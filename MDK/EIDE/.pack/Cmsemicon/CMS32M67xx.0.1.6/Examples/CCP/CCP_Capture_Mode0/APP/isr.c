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
#include "ccp.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/
extern volatile uint32_t  CaptureTime;

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
 ** \brief	CCP_IRQHandler
 **
 ** \param [in]  none   
 ** \return none
 ** \note
****************************************************************************/
void CCP_IRQHandler(void)
{
	if(CCP_GetOverflowIntFlag(CCP0))
	{
		CCP_ClearOverflowIntFlag(CCP0);
	}	
	if(CCP_GetCAPMode0IntFlag(CCP0))
	{																			/*�����ʱ�䣨�ߵ�ƽʱ�䣩= ��4800��������ֵ��- ����ֵ��/ CPP0��ʱ��Ƶ�� */
		CaptureTime = (4800 - CCP_GetCAPMode0Result(CCP0,CCPxA)) / 0.75 ;		/*���Եĸߵ�ƽʱ��С��CPP�������ڣ�6400us�������Բ��ü���CCPģ��������ʱ�����*/
		CCP_ClearCAPMode0IntFlag(CCP0);

		CCP_DisableRun(CCP0);		/*ʵ�����²���Ĺ��ܣ� ��Stop��Run*/
		CCP_EnableRun(CCP0);	
	}	
}




