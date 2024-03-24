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
/** \file demo_hall.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_hall.h"

/****************************************************************************/
/*	Local pre-processor symbols('#define')
****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
****************************************************************************/
uint8_t HALL_FILVal=0; //hall 滤波值
uint8_t HALL_RAWValL=0; //hall 实时值
uint32_t HALL_Width=0; //hall 宽度
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
 ** \brief	 HALL_Init
 ** \param [in] DatA：DIVALUA （dividend）
 ** \param [in] DatA：DIVALUB （divisor）
 **            	
 ** \return  none
 ** \note  
 ******************************************************************************/
void HALL_Init(Div_Param* DIVPar)
{
	uint32_t i=0xffff;
	//设置div时钟
	CGC_PER12PeriphClockCmd(CGC_PER12Periph_HALL,ENABLE);
	while(i--);

	//HALL时钟分频1分频
	HALL_CLKDiv(HALL_DIV_1);
	
	//二阶滤波
	HALL_FilterLEN_Set(0x100);
	
	//使能75滤波
	HALL_Filter75Enable();
	
	//使能溢出中断
	HALL_OVINT_Enable();
	
	//使能信号变化中断
	HALL_CHGINT_Enable();
	
	//设置门限值
	HALL_Threshod_Set(0xffffffff);
	
	//使能HALL
	HALL_Enable();
/*中断设置*/
	NVIC_ClearPendingIRQ(HALL_IRQn);
	NVIC_EnableIRQ(HALL_IRQn);
	NVIC_SetPriority(HALL_IRQn,0);
	
	/*IO HALL IN0设置*/
	GPIO_PinAFInConfig(HALL0CFG,IO_INCFG_P00_HALLIN0);	
	GPIO_Init(PORT0,PIN0,INPUT);
	
	/*IO HALL IN1设置*/
	GPIO_PinAFInConfig(HALL1CFG,IO_INCFG_P57_HALLIN1);	
	GPIO_Init(PORT5,PIN7,INPUT);
	
	/*IO HALL IN2设置*/
	GPIO_PinAFInConfig(HALL2CFG,IO_INCFG_P56_HALLIN2);	
	GPIO_Init(PORT5,PIN6,INPUT);
	
}



