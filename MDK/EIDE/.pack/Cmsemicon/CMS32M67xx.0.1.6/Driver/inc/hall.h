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
	HALL_DIV_1,  //����Ƶ
	HALL_DIV_2,  //2��Ƶ 
	HALL_DIV_4,  //4��Ƶ
	HALL_DIV_8   //8��Ƶ
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
 **			ʹ��HALLģ�� 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Enable(void);

/*****************************************************************************
 ** \brief	HALL_Disable
 **			��ֹHALLģ�� 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Disable(void);

/*****************************************************************************
 ** \brief	HALL_Enable
 **			ʹ��HALL 75�˲� 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Filter75Enable(void);

/*****************************************************************************
 ** \brief	HALL_Disable
 **			��ֹHALLģ�� 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_Filter75Disable(void);


/*****************************************************************************
 ** \brief	HALL_CLKDiv
 **			����HALL�ķ�Ƶ
 ** \param CDiv:
**								HALL_DIV_1: ����Ƶ
**			          HALL_DIV_2: 2��Ƶ 
**			          HALL_DIV_4: 4��Ƶ
**			          HALL_DIV_8: 8��Ƶ
 ** \note	 
*****************************************************************************/
void HALL_CLKDiv(uint8_t CDiv);


/*****************************************************************************
 ** \brief	HALL_FilterLEN_Set
 **			����HALL�˲����
 ** \param FiltPara: 0~0xffff
 ** \note	 
*****************************************************************************/
void HALL_FilterLEN_Set(uint16_t FiltPara);

/*****************************************************************************
 ** \brief	HALL_SoftTrigINT_Enable
 **			ʹ��HALL��������ж�
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrigINT_Enable(void);

/*****************************************************************************
 ** \brief	HALL_SoftTrigINT_Disable
 **			��ֹHALL��������ж� 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrigINT_Disable(void);

/*****************************************************************************
 ** \brief	HALL_SoftTrig_Start
 **			����HALL�������
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_SoftTrig_Start(void);

/*****************************************************************************
 ** \brief	HALL_OVINT_Enable
 **			ʹ��HALL��������ж�
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVINT_Enable(void);

/*****************************************************************************
 ** \brief	HALL_OVINT_Disable
 **			��ֹHALL����ж� 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVINT_Disable(void);

/*****************************************************************************
 ** \brief	HALL_CHGINT_Enable
 **			ʹ��HALL�źű仯�����ж�
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGINT_Enable(void);

/*****************************************************************************
 ** \brief	HALL_CHGINT_Disable
 **			��ֹHALL�źű仯�����ж� 
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGINT_Disable(void);

/*****************************************************************************
 ** \brief	HALL_Threshod_Set
 **			  HALL����������ֵ����
 ** \param CountThrd: 0~0xffffffff
 ** \note	 
*****************************************************************************/
void HALL_Threshod_Set(uint32_t CountThrd);

/*****************************************************************************
 ** \brief	HALL_Counter_Clear
 **			  ���HALL������ֵ
 ** \param CountThrd: 0~0xffffffff��д����ֵ�����
 ** \note	 
*****************************************************************************/
void HALL_Counter_Clear(uint32_t CountD);

/*****************************************************************************
 ** \brief	HALL_Counter_Read
 **			  ��ȡHALL��������ֵ
 ** \param none
 ** \return CNT����ֵ
 ** \note	 
*****************************************************************************/
uint32_t HALL_Counter_Read(void);
	
/*****************************************************************************
 ** \brief	HALL_RAW_DATA
 **			����HALLʵʱֵ
 ** \param none
 ** \note	 
*****************************************************************************/
uint8_t HALL_RAW_DATA(void);

/*****************************************************************************
 ** \brief	HALL_FIT_DATA
 **			����HALL�˲�ֵ
 ** \param none
 ** \note	 
*****************************************************************************/
uint8_t HALL_FIT_DATA(void);

/*****************************************************************************
 ** \brief	HALL_RDWidth_DATA
 **			����HALL��¼�Ŀ��ֵ
 ** \param none
 ** \note	 
*****************************************************************************/
uint32_t HALL_RDWidth_DATA(void);
	
/*****************************************************************************
 ** \brief	HALL_OVIF_Clear
 **			���HALL�����־
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_OVIF_Clear(void);

/*****************************************************************************
 ** \brief	HALL_CHGIF_Clear
 **			���HALL�źű仯��־
 ** \param none
 ** \note	 
*****************************************************************************/
void HALL_CHGIF_Clear(void);

/*****************************************************************************
 ** \brief	HALL_GetFlagStaus
 **			����HALL��־
 ** \param HALL_FLAG�� HALL_OVFLAG�� HALL_CHGFLAG
 ** \note	 
*****************************************************************************/
FlagStatus HALL_GetFlagStaus(uint8_t HALL_FLAG);




#ifdef __cplusplus
}
#endif

#endif /* __HALL_H_*/

