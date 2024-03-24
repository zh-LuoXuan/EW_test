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
/** \file demo_epwm.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_epwm.h"

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
 ** \brief	EPWM_Config
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void EPWM_Config(void)
{
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_EPWM,ENABLE);	/*����EPWMʱ��*/
	/*
	(1)����EPWM����ģʽ
	*/
	EPWM_ConfigRunMode(  EPWM_COUNT_UP_DOWN 		| 		/*���¼���ģʽ(���Ķ���)*/
						 EPWM_OCU_SYMMETRIC 		|		/*�Գ�ģʽ*/
						 EPWM_WFG_COMPLEMENTARYK   |		/*����ģʽ*/
						 EPWM_OC_INDEPENDENT);				/*�������ģʽ*/
	/*
	(2)����EPWMʱ������������
	*/		
	
	EPWM_ConfigChannelClk( EPWM0, EPWM_CLK_DIV_1);			/*����EPWM0ʱ��ΪAPBʱ�ӵ�1��Ƶ*/
	EPWM_ConfigChannelClk( EPWM2, EPWM_CLK_DIV_1);			/*����EPWM2ʱ��ΪAPBʱ�ӵ�1��Ƶ*/
	EPWM_ConfigChannelClk( EPWM4, EPWM_CLK_DIV_1);			/*����EPWM4ʱ��ΪAPBʱ�ӵ�1��Ƶ*/
	EPWM_ConfigChannelClk( EPWM6, EPWM_CLK_DIV_1);			/*����EPWM6ʱ��ΪAPBʱ�ӵ�1��Ƶ*/

	EPWM_ConfigChannelPeriod(EPWM0,  4800);					/*EPWM0ͨ�������� = 4800/Fepwm  = 300us*/
	EPWM_ConfigChannelPeriod(EPWM2,  4800);					/*EPWM2ͨ�������� = 4800/Fepwm  = 300us*/
	EPWM_ConfigChannelPeriod(EPWM4,  4800);					/*EPWM4ͨ�������� = 4800/Fepwm  = 300us*/
	EPWM_ConfigChannelPeriod(EPWM6,  4800);					/*EPWM6ͨ�������� = 4800/Fepwm  = 300us*/
	
	EPWM_ConfigChannelSymDuty(EPWM0, 1200);					
	EPWM_ConfigChannelSymDuty(EPWM2, 2400);					
	EPWM_ConfigChannelSymDuty(EPWM4, 3600);		
  EPWM_ConfigChannelSymDuty(EPWM6, 3600);	

	EPWM_DisableDeadZone(EPWM_CH_0_MSK | EPWM_CH_1_MSK |
						 EPWM_CH_2_MSK | EPWM_CH_3_MSK |
						 EPWM_CH_4_MSK | EPWM_CH_5_MSK |
						 EPWM_CH_6_MSK | EPWM_CH_7_MSK);	/*�ر�����*/

	/*
	(3)����EPWM�������
	*/
	EPWM_DisableReverseOutput( EPWM_CH_0_MSK | EPWM_CH_1_MSK |
							   EPWM_CH_2_MSK | EPWM_CH_3_MSK |
							   EPWM_CH_4_MSK | EPWM_CH_5_MSK |
							   EPWM_CH_6_MSK | EPWM_CH_7_MSK  );				/*�رշ������*/

	/*
	(4)����EPWM���ط�ʽ
	*/
	EPWM_EnableAutoLoadMode(EPWM_CH_0_MSK | EPWM_CH_2_MSK | EPWM_CH_4_MSK | EPWM_CH_6_MSK );	/*����Ϊ�Զ�����ģʽ*/
	EPWM_ConfigLoadAndIntMode(EPWM0, EPWM_EACH_PERIOD_ZERO);			
	EPWM_ConfigLoadAndIntMode(EPWM2, EPWM_EACH_PERIOD_ZERO);
	EPWM_ConfigLoadAndIntMode(EPWM4, EPWM_EACH_PERIOD_ZERO);			
	EPWM_ConfigLoadAndIntMode(EPWM6, EPWM_EACH_PERIOD_ZERO);			/*���ص�����Ϊÿ�����ڵ�����*/
	

	/*
	(5)����EPWMɲ��
	*/
	EPWM_AllBrakeDisable();

	/*
	(6)�����ж�
	*/
	
	
	EPWM_EnableZeroInt(EPWM_CH_0_MSK);								/*��������ж�*/		
	
	NVIC_EnableIRQ(EPWM_IRQn);
	/*
	(6)�������ȼ�
	*/	
	NVIC_SetPriority(EPWM_IRQn,3);					/*���ȼ�0~3�� 0��ߡ�3���*/
	
	/*
	(7)����IO�����
	*/	
	GPIO_PinAFOutConfig(P36CFG, IO_OUTCFG_P36_EPWM0);				/*����P36ΪEPWM0ͨ��*/
	GPIO_PinAFOutConfig(P37CFG, IO_OUTCFG_P37_EPWM1);				/*����P37ΪEPWM1ͨ��*/
	GPIO_PinAFOutConfig(P40CFG, IO_OUTCFG_P40_EPWM2);				/*����P40ΪEPWM2ͨ��*/
	GPIO_PinAFOutConfig(P41CFG, IO_OUTCFG_P41_EPWM3);				/*����P41ΪEPWM3ͨ��*/
	GPIO_PinAFOutConfig(P42CFG, IO_OUTCFG_P42_EPWM4);				/*����P42ΪEPWM4ͨ��*/
	GPIO_PinAFOutConfig(P43CFG, IO_OUTCFG_P43_EPWM5);				/*����P43ΪEPWM5ͨ��*/
	GPIO_PinAFOutConfig(P44CFG, IO_OUTCFG_P44_EPWM6);				/*����P44ΪEPWM6ͨ��*/
	GPIO_PinAFOutConfig(P45CFG, IO_OUTCFG_P45_EPWM7);				/*����P45ΪEPWM7ͨ��*/

	GPIO_Init(PORT3,PIN6,OUTPUT);
	GPIO_Init(PORT3,PIN7,OUTPUT);
	GPIO_Init(PORT4,PIN0,OUTPUT);
	GPIO_Init(PORT4,PIN1,OUTPUT);
	GPIO_Init(PORT4,PIN2,OUTPUT);
	GPIO_Init(PORT4,PIN3,OUTPUT);
	GPIO_Init(PORT4,PIN4,OUTPUT);
	GPIO_Init(PORT4,PIN5,OUTPUT);
	
	EPWM_EnableOutput(EPWM_CH_0_MSK | EPWM_CH_1_MSK |
					  EPWM_CH_2_MSK | EPWM_CH_3_MSK |
					  EPWM_CH_4_MSK | EPWM_CH_5_MSK |
					  EPWM_CH_6_MSK | EPWM_CH_7_MSK);

	/*
	(8)����EPWM
	*/		
	EPWM_Start(EPWM_CH_0_MSK | EPWM_CH_2_MSK | EPWM_CH_4_MSK | EPWM_CH_6_MSK);
	
}


