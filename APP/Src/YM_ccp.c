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
#include "YM_ccp.h"

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
void CCP_PWM_Config(uint32_t campler)
{
	/*
	设置CCP的时钟
	*/
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);				/*开启CCP模块时钟*/
	CCP_ConfigCLK(CCP0,CCP_CLK_DIV_1,CCP_RELOAD_CCPLOAD,100);			/*Fccp = 72Mhz ->捕获计数周期 = 100/72M = 1.38us*/
																		/*CCP0模块溢出后重载值为100*/
	/*
	设置CCP运行模式
	*/
	CCP_EnablePWMMode(CCP0);											/*设置CCP0的工作模式为PWM*/
	/*
	设置CCP输出通道
	*/
	CCP_ConfigCompare(CCP0,CCP->D0A,campler);									/*设置输出通道为CCP0*/

	GPIO_Init(PORT0,PIN6,OUTPUT);
	GPIO_PinAFOutConfig(P06CFG,IO_OUTCFG_P06_CCP0A);
			
	/*
	开启CCP模块
	*/	
	CCP_EnableRun(CCP0);			
	CCP_Start(CCP0);			/*CCP0模块使能*/	

	CCP->LOCK = CCP_P1A_WRITE_KEY;		
	
}




