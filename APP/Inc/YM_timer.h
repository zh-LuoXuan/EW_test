/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-08 15:52:51
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-24 10:58:15
 * @FilePath: \EIDE (工作区)e:\ZL\Git_Clone\EW_test_breath\APP\Inc\YM_timer.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
/** \file YM_timer.h
**
** History:
** 
*****************************************************************************/
#ifndef __YM_TIMER_H_
#define __YM_TIMER_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "common.h"
#include "cgc.h"
#include "gpio.h"
#include "timer.h"

void TIMER0_Init_Config(void);
void TMR0_Int_Config(void);
void TIMER1_Init_Config(void);
void TMR1_Int_Config(void);



#ifdef __cplusplus
}
#endif

#endif /* __DEMO_TIMER_H_ */

