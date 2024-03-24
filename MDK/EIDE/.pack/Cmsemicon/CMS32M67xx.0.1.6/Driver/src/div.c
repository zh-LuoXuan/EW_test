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
/** \file div.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "div.h"
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
 ** \brief	DIV_Cal
 **			ʵ�� "/" (ȡ��) 
 ** \param [in] x:������
 **				y:����
 ** \return  ��
 ** \note	 
*****************************************************************************/
int32_t DIV_Cal(int32_t x, int32_t y)
{
	DIV->ALUA = x;
	DIV->ALUB = y;
	while(!DIV_IS_IDLE())
	{
		;
	}	
    return (DIV->RES0);   	
}
	  
/*****************************************************************************
 ** \brief	DIV_Mod
 **			ʵ�� "%" (ȡ��)
 ** \param [in] x:������
 **				y:����
 ** \return  ����
 ** \note	 
*****************************************************************************/
int32_t DIV_Mod(int32_t x, int32_t y)
{
	DIV->ALUA = x;
	DIV->ALUB = y;
	while(!DIV_IS_IDLE())
	{
		;
	}	
    return (DIV->RES1);   	  
}

/*****************************************************************************
 ** \brief	DIV_GetDiv
 **			ֱ�Ӷ����������е���
 ** \param   none
 ** \return  ��
 ** \note	 
*****************************************************************************/
int32_t DIV_GetDiv(void)
{
	 return (DIV->RES0); 
}

/*****************************************************************************
 ** \brief	DIV_GetMod
 **			ֱ�Ӷ����������е���
 ** \param   none
 ** \return  ����
 ** \note	 
*****************************************************************************/
int32_t DIV_GetMod(void)
{
	 return (DIV->RES1); 
}

/*****************************************************************************
 ** \brief	DIV_EnableSingedMode
 **			ʹ���з��ų���������
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void DIV_EnableSingedMode(void)
{
	DIV->CON |= DIV_CON_SIGN_Msk;
}
/*****************************************************************************
 ** \brief	DIV_EnableUnsingedMode
 **			ʹ���޷��ų���������
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void DIV_EnableUnsingedMode(void)
{
	DIV->CON &= ~(DIV_CON_SIGN_Msk);
}



