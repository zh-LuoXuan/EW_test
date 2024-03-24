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
/** \file demo_pga.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_pga.h"
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
 ** \brief	PGA_PGA0_Config
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/

void PGA_PGA0_Config(void)
{
	/*
	(1)设置PGA 时钟
	*/
	CGC_PER13PeriphClockCmd(CGC_PER13Periph_PGAEN,ENABLE);	
	/*
	(2)设置PGA 参考电压
	*/	
	PGA0_VrefCtrl(PGA0BG);
	/*
	(3)设置PGA 输出
	*/		
	PGA0_EnableOutput();
	
	/*
	(4)设置PGA 增益
	*/	
	PGA_ConfigGain(PGA0x,PGA_GAIN_2);		
	/*
	(5)设置PGA输出电阻选择
	*/	
	PGA0_ConfigResistorPAD(PGA_R_None);
	/*
	(6)设置PGA驱动电流
	*/	
	PGA_ConfigDriveCurrent(PGA0x,PGA_C_20uA);

	/*
	(7)设置PGA滤波
	*/
	PGA_Filter_Set(PGA0x,0x00);
	
	/*
	(8)开启PGA
	*/
	PGA_Start(PGA0x);

}




