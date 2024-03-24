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
/** \file demo_extint.h
**
** History:
** 
*****************************************************************************/
#ifndef __DEMO_EXTINT_H_
#define __DEMO_EXTINT_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "common.h"
#include "gpio.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/

							
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

/*****************************************************************************
 ** \brief	EXTInt_Init
 **			��ʼ���ⲿ�ж�
 ** \param [in] Channel:
 **			               EXTINT_Rising: �����ش����ж�
 **										 EXTINT_Falling: �½��ش����ж�	 
 **										 EXTINT_DoublEdge: ˫�ش����ж� 
 **						  INTCH:(0~3)
 **										 EXTINT_INT0: INT0
 **										 EXTINT_INT1: INT1
 **										 EXTINT_INT2: INT2
 **										 EXTINT_INT3: INT3 
 ** \return  none
 ** \note	
*****************************************************************************/
void EXTInt_Edge(uint8_t EXTINTEdge, uint8_t INTCH);
	
/*****************************************************************************
 ** \brief	EXTInt_Init
 **			��ʼ���ⲿ�ж�
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void EXTInt_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* __DEMO_EXTINT_H_ */

