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

/*****************************************************************************/
/** \file hall.h
**
** History:
** 
*****************************************************************************/
#ifndef __HALL_H_
#define __HALL_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "CMS32M67xx.h"
#include "common.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
#define HALL_LOCKKEY    0x55
#define HALL_UNLOCKKEY    0x00
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/
typedef enum
{
	HALL_DIV_1,  //不分频
	HALL_DIV_2,  //2分频 
	HALL_DIV_4,  //4分频
	HALL_DIV_8   //8分频
}	HALL_Clkdiv_t;



#define HALL_OVFLAG     0x02
#define HALL_CHGFLAG    0x01


//typedef enum {RESET = 0, SET = !RESET} FlagStatus;
#define IS_HALL_STATUS(FLAG)			(((FLAG ==HALL_OVFLAG ) || (FLAG ==HALL_CHGFLAG )))

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/


	  
/*****************************************************************************
 ** \brief	HALL_Enable
 **			使能HALL模块 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Enable(void);

/*****************************************************************************
 ** \brief	HALL_Disable
 **			禁止HALL模块 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Disable(void);

/*****************************************************************************
 ** \brief	HALL_Enable
 **			使能HALL 75滤波 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Filter75Enable(void);

/*****************************************************************************
 ** \brief	HALL_Disable
 **			禁止HALL模块 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Filter75Disable(void);


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
void HALL_CLKDiv(uint8_t CDiv);


/*****************************************************************************
 ** \brief	HALL_FilterLEN_Set
 **			设置HALL滤波宽度
 ** \param FiltPara: 0~0xffff
 ** \note	 
*****************************************************************************/
void HALL_FilterLEN_Set(uint16_t FiltPara);

/*****************************************************************************
 ** \brief	HALL_SoftTrigINT_Enable
 **			使能HALL软件触发中断
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrigINT_Enable(void);

/*****************************************************************************
 ** \brief	HALL_SoftTrigINT_Disable
 **			禁止HALL软件触发中断 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrigINT_Disable(void);

/*****************************************************************************
 ** \brief	HALL_SoftTrig_Start
 **			启动HALL软件触发
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrig_Start(void);

/*****************************************************************************
 ** \brief	HALL_OVINT_Enable
 **			使能HALL溢出触发中断
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVINT_Enable(void);

/*****************************************************************************
 ** \brief	HALL_OVINT_Disable
 **			禁止HALL溢出中断 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVINT_Disable(void);

/*****************************************************************************
 ** \brief	HALL_CHGINT_Enable
 **			使能HALL信号变化触发中断
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGINT_Enable(void);

/*****************************************************************************
 ** \brief	HALL_CHGINT_Disable
 **			禁止HALL信号变化触发中断 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGINT_Disable(void);

/*****************************************************************************
 ** \brief	HALL_Threshod_Set
 **			  HALL计数器门限值设置
 ** \param CountThrd: 0~0xffffffff
 ** \note	 
*****************************************************************************/
void HALL_Threshod_Set(uint32_t CountThrd);

/*****************************************************************************
 ** \brief	HALL_Counter_Clear
 **			  清除HALL计数器值
 ** \param CountThrd: 0~0xffffffff（写任意值清除）
 ** \note	 
*****************************************************************************/
void HALL_Counter_Clear(uint32_t CountD);

/*****************************************************************************
 ** \brief	HALL_Counter_Read
 **			  读取HALL计数器的值
 ** \param none
 ** \return CNT计数值
 ** \note	 
*****************************************************************************/
uint32_t HALL_Counter_Read(void);
	
/*****************************************************************************
 ** \brief	HALL_RAW_DATA
 **			返回HALL实时值
 ** \param none
 ** \note	 
*****************************************************************************/
uint8_t HALL_RAW_DATA(void);

/*****************************************************************************
 ** \brief	HALL_FIT_DATA
 **			返回HALL滤波值
 ** \param none
 ** \note	 
*****************************************************************************/
uint8_t HALL_FIT_DATA(void);

/*****************************************************************************
 ** \brief	HALL_RDWidth_DATA
 **			返回HALL记录的宽度值
 ** \param none
 ** \note	 
*****************************************************************************/
uint32_t HALL_RDWidth_DATA(void);
	
/*****************************************************************************
 ** \brief	HALL_OVIF_Clear
 **			清除HALL溢出标志
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVIF_Clear(void);

/*****************************************************************************
 ** \brief	HALL_CHGIF_Clear
 **			清除HALL信号变化标志
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGIF_Clear(void);

/*****************************************************************************
 ** \brief	HALL_GetFlagStaus
 **			返回HALL标志
 ** \param HALL_FLAG： HALL_OVFLAG， HALL_CHGFLAG
 ** \note	 
*****************************************************************************/
FlagStatus HALL_GetFlagStaus(uint8_t HALL_FLAG);




#ifdef __cplusplus
}
#endif

#endif /* __HALL_H_*/

