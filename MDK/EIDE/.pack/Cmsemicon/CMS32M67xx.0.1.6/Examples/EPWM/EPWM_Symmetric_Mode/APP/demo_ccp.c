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
/** \file demo_ccp.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_ccp.h"

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
 ** \brief	CCP_Capture_Mode0_Config
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void CCP_Capture_Mode0_Config(void)
{
	/*
	(1)����CCP��ʱ��
	*/
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);				/*����CCPģ��ʱ��*/
	CCP_ConfigCLK(CCP0,CCP_CLK_DIV_64,CCP_RELOAD_CCPLOAD,4800);			/*Fccp = 48Mhz /64 = 0.75Mh ->����������� = 4800/0.75Mhz = 6400us*/
																		/*CCP0ģ�����������ֵΪ4800*/
	/*
	(2)����CCP����ģʽ
	*/
	CCP_EnableCAPMode0(CCP0);											/*����CCP0�Ĺ���ģʽΪ����ģʽ0*/
	CCP_ConfigCAPMode0(CCP0,CCP_CAP_MODE0_RISING_TO_FALLING);			/*����CCP0�Ĳ���ģʽ0 �Ĳ���ʽΪ�����ص��½���(�ߵ�ƽʱ��)*/
																		/*����/�½��ز���CCPģ��ʹ��(CCPRUN =1)�󣬼���ֵ��4800(����ֵ)���¼�������������������ֹͣ�����������浱ǰ�ļ���ֵ*/
													/*�������½��ز���CCPģ��ʹ��(CCPRUN =1)�󣬵���������ʱ����ֵ��4800(����ֵ)���¼�������������(�½���)������ֹͣ�����������浱ǰ�ļ���ֵ*/
													/*�½��������ز���CCPģ��ʹ��(CCPRUN =1)�󣬵������½���ʱ����ֵ��4800(����ֵ)���¼�������������(������)������ֹͣ�����������浱ǰ�ļ���ֵ*/
	/*
	(3)����CCP����ͨ��
	*/
	CCP_SelCAPMode0Channel(CCP0,CCPxA);									/*���ò���ͨ��ΪCCPA0*/
	GPIO_PinAFInConfig(CCP0AINCFG, CCP0ACFG_P00);				/*����P04ΪCCPA0����ͨ��*/

	GPIO_Init(PORT0,PIN0,INPUT);
	/*
	(4)����CCP�����ж�
	*/	
	CCP_EnableOverflowInt(CCP0);					/*����CCP0ģ���������ж�*/
	CCP_EnableCAPMode0Int(CCP0);				    /*����CCP0ģ�鲶��ģʽ0�ж�*/
	NVIC_EnableIRQ(CCP_IRQn);		
	/*
	(5)����CCP �ж����ȼ�
	*/	
	NVIC_SetPriority(CCP_IRQn,3);					/*���ȼ�0~3�� 0��ߡ�3���*/		
	/*
	(6)����CCPģ��
	*/	
	CCP_EnableRun(CCP0);			
	CCP_Start(CCP0);			/*CCP0ģ��ʹ��*/			
}




