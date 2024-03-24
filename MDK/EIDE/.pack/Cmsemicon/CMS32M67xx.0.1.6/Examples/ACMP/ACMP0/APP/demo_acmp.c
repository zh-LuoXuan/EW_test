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
/** \file demo_acmp.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_acmp.h"
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
 ** \brief	ACMP_ACMP0_Config
 **			ʵ��ACMP0�ıȽϹ���
 **			��1�����˵�ѹ(IO)>���˵�ѹ ���1(�ߵ�ƽ)
 **			��2�����˵�ѹ(IO)<���˵�ѹ ���0(�͵�ƽ)
 **			��3�������0���䵽1 �������������ж�
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ACMP_ACMP0_Config(void)
{
	/*
	(0)����ACMPģ��ʱ��
	*/
	CGC_PER13PeriphClockCmd(CGC_PER13Periph_ACMPEN,ENABLE);	
	
	/*
	(1)����ACMP IO��
	*/
	GPIO_Init(PORT5,PIN6,ANALOG_INPUT);/*����P56ΪACMP C0P2��������*/
//	GPIO_Init(PORT5,PIN5,ANALOG_INPUT);/*����P55ΪACMP C0N��������*/
	
	GPIO_Init(PORT0,PIN4,OUTPUT);/*����P04ΪACMP ���C0O*/
	GPIO_PinAFInConfig(P04CFG,IO_OUTCFG_P04_C0_O);
	/*
	(2)����ACMP ��������
	 */
	ACMP_ConfigPositive(ACMP0,ACMP_POSSEL_CxP2);
	/*
	(3)����ACMP �������� 
	*/	
	ACMP_ConfigNegative(ACMP0,ACMP_NEGSEL_BG);		/*����ѡ���ڲ���ѹ*/
	/*
	(4)ʹ��ACMP��� 
	*/
		ACMPOut_Enable(ACMP0);
	 /*
	 (5)�ر��¼����
	 */
	 ACMP_DisableEventOut(ACMP0);
	
	 /*
	 (6)�����ж�
	 */
	 ACMP_ConfigEventAndIntMode(ACMP0,ACMP_EVENT_INT_RISING);	/*�����ش����ж����¼����жϴ�����ʽ���¼�������ʽ����*/		 
	 ACMP_EnableInt(ACMP0,ACMP_INT_Compx_Event);						/*ACMP�¼������ж�*/				
	 NVIC_EnableIRQ(ACMP_IRQn);
	/*
	(7)�����ж����ȼ�
	*/	 	 
	 NVIC_SetPriority(ACMP_IRQn,0);
	/*
	(8)���ó���
	*/	 	 
	ACMP_DisableHYS(ACMP0);
	/*
	(9)����ACMP
	*/
  	ACMP_Start(ACMP0);		
}

