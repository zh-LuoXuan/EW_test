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
#include "hall.h"
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
 ** \brief	HALL_Enable
 **			使能HALL模块 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Enable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG |= HALL_CFG_HALLEN_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_Disable
 **			禁止HALL模块 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Disable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG &= ~HALL_CFG_HALLEN_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_Enable
 **			使能HALL 75滤波 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Filter75Enable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG |= HALL_CFG_FIT75_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_Disable
 **			禁止HALL模块 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Filter75Disable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG &= ~HALL_CFG_FIT75_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}


/*****************************************************************************
 ** \brief	HALL_CLKDiv
 **			设置HALL的分频
 ** \param CDiv:
**								HALL_DIV_1: 不分频
**			          HALL_DIV_2: 2分频 
**			          HALL_DIV_4: 4分频
**			          HALL_DIV_8: 8分频
 ** \note	 
*****************************************************************************/
void HALL_CLKDiv(uint8_t CDiv)
{
	uint32_t Temp;
	HALL->LOCK = HALL_LOCKKEY;
	
	Temp = HALL->CFG;
	Temp &= ~HALL_CFG_CLKDIV_Msk;
	Temp |= CDiv << HALL_CFG_CLKDIV_Pos;
	HALL->CFG = Temp;
	
	HALL->LOCK = HALL_UNLOCKKEY;
}


/*****************************************************************************
 ** \brief	HALL_FilterLEN_Set
 **			设置HALL滤波宽度
 ** \param FiltPara: 0~0xffff
 ** \note	 
*****************************************************************************/
void HALL_FilterLEN_Set(uint16_t FiltPara)
{
	uint32_t Temp;
	HALL->LOCK = HALL_LOCKKEY;
	
	Temp = HALL->CFG;
	Temp &= ~HALL_CFG_FITLEN_Msk;
	Temp |= FiltPara << HALL_CFG_FITLEN_Pos;
	HALL->CFG = Temp;
	
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_SoftTrigINT_Enable
 **			使能HALL软件触发中断
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrigINT_Enable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG |= HALL_CFG_SWIE_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_SoftTrigINT_Disable
 **			禁止HALL软件触发中断 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrigINT_Disable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG &= ~HALL_CFG_SWIE_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_SoftTrig_Start
 **			启动HALL软件触发
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrig_Start(void)
{
//	HALL->LOCK = HALL_LOCKKEY;
	HALL->CLRF |= HALL_CLRF_SETSWF_Msk;
//	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_OVINT_Enable
 **			使能HALL溢出触发中断
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVINT_Enable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG |= HALL_CFG_OVIE_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_OVINT_Disable
 **			禁止HALL溢出中断 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVINT_Disable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG &= ~HALL_CFG_OVIE_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_CHGINT_Enable
 **			使能HALL信号变化触发中断
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGINT_Enable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG |= HALL_CFG_CHGIE_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_CHGINT_Disable
 **			禁止HALL信号变化触发中断 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGINT_Disable(void)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CFG &= ~HALL_CFG_CHGIE_Msk;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_Threshod_Set
 **			  HALL计数器门限值设置
 ** \param CountThrd: 0~0xffffffff
 ** \note	 
*****************************************************************************/
void HALL_Threshod_Set(uint32_t CountThrd)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->TH = CountThrd;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_Counter_Clear
 **			  清除HALL计数器值
 ** \param CountThrd: 0~0xffffffff（写任意值清除）
 ** \note	 
*****************************************************************************/
void HALL_Counter_Clear(uint32_t CountD)
{
	HALL->LOCK = HALL_LOCKKEY;
	HALL->CNT = CountD;
	HALL->LOCK = HALL_UNLOCKKEY;
}

/*****************************************************************************
 ** \brief	HALL_Counter_Read
 **			  读取HALL计数器的值
 ** \param none
 ** \return CNT计数值
 ** \note	 
*****************************************************************************/
uint32_t HALL_Counter_Read(void)
{
	uint32_t RDData=0;
	
	HALL->LOCK = HALL_LOCKKEY;
	RDData = HALL->CNT;	
	HALL->LOCK = HALL_UNLOCKKEY;
	
	return RDData;
}
/*****************************************************************************
 ** \brief	HALL_RAW_DATA
 **			返回HALL实时值
 ** \param none
 ** \note	 
*****************************************************************************/
uint8_t HALL_RAW_DATA(void)
{
	uint8_t RTData = 0;
	
	RTData = ((HALL->INFO) & HALL_INFO_RAWDATA_Msk) >> HALL_INFO_RAWDATA_Pos;
	
	return RTData;
}

/*****************************************************************************
 ** \brief	HALL_FIT_DATA
 **			返回HALL滤波值
 ** \param none
 ** \note	 
*****************************************************************************/
uint8_t HALL_FIT_DATA(void)
{
	uint8_t RTData = 0;
	
	RTData = ((HALL->INFO) & HALL_INFO_FITDATA_Msk) >> HALL_INFO_FITDATA_Pos;
	
	return RTData;
}

/*****************************************************************************
 ** \brief	HALL_RDWidth_DATA
 **			返回HALL记录的宽度值
 ** \param none
 ** \note	 
*****************************************************************************/
uint32_t HALL_RDWidth_DATA(void)
{
	uint32_t RTData = 0;
	
	RTData = HALL->WIDTH;
	
	return RTData;
}

/*****************************************************************************
 ** \brief	HALL_OVIF_Clear
 **			清除HALL溢出标志
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVIF_Clear(void)
{

	HALL->CLRF |= HALL_CLRF_CLROVF_Msk;

}

/*****************************************************************************
 ** \brief	HALL_CHGIF_Clear
 **			清除HALL信号变化标志
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGIF_Clear(void)
{

	HALL->CLRF |= HALL_CLRF_CLRCHGF_Msk;

}

/*****************************************************************************
 ** \brief	HALL_GetFlagStaus
 **			返回HALL标志
 ** \param HALL_FLAG： HALL_OVFLAG， HALL_CHGFLAG
 ** \note	 
*****************************************************************************/
FlagStatus HALL_GetFlagStaus(uint8_t HALL_FLAG)
{
    FlagStatus bitstatus;
	  uint8_t tmp_reg = 0;
    uint8_t tmp_flag = 0;

    /* Check the parameters */
    assert_param(IS_HALL_STATUS(HALL_FLAG));


		tmp_reg = HALL->INFO;
		tmp_flag = (uint8_t)(HALL_FLAG);

    if ((tmp_reg & tmp_flag) != (uint16_t)RESET)
        bitstatus = SET;
    else
        bitstatus = RESET;

    return bitstatus;
}
