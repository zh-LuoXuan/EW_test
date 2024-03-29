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
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_EPWM,ENABLE);	/*开启EPWM时钟*/
	/*
	(1)设置EPWM运行模式
	*/
	EPWM_ConfigRunMode(  EPWM_COUNT_UP_DOWN 		| 		/*上下计数模式(中心对齐)*/
						 EPWM_OCU_SYMMETRIC 		|		/*对称模式*/
						 EPWM_WFG_COMPLEMENTARYK   |		/*互补模式*/
						 EPWM_OC_INDEPENDENT);				/*独立输出模式*/
	/*
	(2)设置EPWM时钟周期与死区
	*/		
	
	EPWM_ConfigChannelClk( EPWM0, EPWM_CLK_DIV_1);			/*设置EPWM0时钟为APB时钟的1分频*/
	EPWM_ConfigChannelClk( EPWM2, EPWM_CLK_DIV_1);			/*设置EPWM2时钟为APB时钟的1分频*/
	EPWM_ConfigChannelClk( EPWM4, EPWM_CLK_DIV_1);			/*设置EPWM4时钟为APB时钟的1分频*/
	EPWM_ConfigChannelClk( EPWM6, EPWM_CLK_DIV_1);			/*设置EPWM6时钟为APB时钟的1分频*/

	EPWM_ConfigChannelPeriod(EPWM0,  4800);					/*EPWM0通道的周期 = 4800/Fepwm  = 300us*/
	EPWM_ConfigChannelPeriod(EPWM2,  4800);					/*EPWM2通道的周期 = 4800/Fepwm  = 300us*/
	EPWM_ConfigChannelPeriod(EPWM4,  4800);					/*EPWM4通道的周期 = 4800/Fepwm  = 300us*/
	EPWM_ConfigChannelPeriod(EPWM6,  4800);					/*EPWM6通道的周期 = 4800/Fepwm  = 300us*/
	
	EPWM_ConfigChannelSymDuty(EPWM0, 1200);					
	EPWM_ConfigChannelSymDuty(EPWM2, 2400);					
	EPWM_ConfigChannelSymDuty(EPWM4, 3600);		
  EPWM_ConfigChannelSymDuty(EPWM6, 3600);	

	EPWM_DisableDeadZone(EPWM_CH_0_MSK | EPWM_CH_1_MSK |
						 EPWM_CH_2_MSK | EPWM_CH_3_MSK |
						 EPWM_CH_4_MSK | EPWM_CH_5_MSK |
						 EPWM_CH_6_MSK | EPWM_CH_7_MSK);	/*关闭死区*/

	/*
	(3)设置EPWM反向输出
	*/
	EPWM_DisableReverseOutput( EPWM_CH_0_MSK | EPWM_CH_1_MSK |
							   EPWM_CH_2_MSK | EPWM_CH_3_MSK |
							   EPWM_CH_4_MSK | EPWM_CH_5_MSK |
							   EPWM_CH_6_MSK | EPWM_CH_7_MSK  );				/*关闭反相输出*/

	/*
	(4)设置EPWM加载方式
	*/
	EPWM_EnableAutoLoadMode(EPWM_CH_0_MSK | EPWM_CH_2_MSK | EPWM_CH_4_MSK | EPWM_CH_6_MSK );	/*设置为自动加载模式*/
	EPWM_ConfigLoadAndIntMode(EPWM0, EPWM_EACH_PERIOD_ZERO);			
	EPWM_ConfigLoadAndIntMode(EPWM2, EPWM_EACH_PERIOD_ZERO);
	EPWM_ConfigLoadAndIntMode(EPWM4, EPWM_EACH_PERIOD_ZERO);			
	EPWM_ConfigLoadAndIntMode(EPWM6, EPWM_EACH_PERIOD_ZERO);			/*加载点设置为每个周期点和零点*/
	

	/*
	(5)设置EPWM刹车
	*/
	EPWM_AllBrakeDisable();

	/*
	(6)设置中断
	*/
	
	
	EPWM_EnableZeroInt(EPWM_CH_0_MSK);								/*开启零点中断*/		
	
	NVIC_EnableIRQ(EPWM_IRQn);
	/*
	(6)设置优先级
	*/	
	NVIC_SetPriority(EPWM_IRQn,3);					/*优先级0~3， 0最高、3最低*/
	
	/*
	(7)设置IO口输出
	*/	
	GPIO_PinAFOutConfig(P36CFG, IO_OUTCFG_P36_EPWM0);				/*设置P36为EPWM0通道*/
	GPIO_PinAFOutConfig(P37CFG, IO_OUTCFG_P37_EPWM1);				/*设置P37为EPWM1通道*/
	GPIO_PinAFOutConfig(P40CFG, IO_OUTCFG_P40_EPWM2);				/*设置P40为EPWM2通道*/
	GPIO_PinAFOutConfig(P41CFG, IO_OUTCFG_P41_EPWM3);				/*设置P41为EPWM3通道*/
	GPIO_PinAFOutConfig(P42CFG, IO_OUTCFG_P42_EPWM4);				/*设置P42为EPWM4通道*/
	GPIO_PinAFOutConfig(P43CFG, IO_OUTCFG_P43_EPWM5);				/*设置P43为EPWM5通道*/
	GPIO_PinAFOutConfig(P44CFG, IO_OUTCFG_P44_EPWM6);				/*设置P44为EPWM6通道*/
	GPIO_PinAFOutConfig(P45CFG, IO_OUTCFG_P45_EPWM7);				/*设置P45为EPWM7通道*/

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
	(8)开启EPWM
	*/		
	EPWM_Start(EPWM_CH_0_MSK | EPWM_CH_2_MSK | EPWM_CH_4_MSK | EPWM_CH_6_MSK);
	
}


