/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-25 17:40:50
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-26 10:48:19
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\YM_epwm.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_EPWM_H_
#define __YM_EPWM_H_
#include <stdint.h>
#include "gpio.h"
#include "cgc.h"
#include "common.h"

/********************************************************************************
 *                                  IO端口定义
********************************************************************************/
//IO  分组
#define HO_U_PORT                       (PORT4)
#define LO_U_PORT                       (PORT4)
#define HO_V_PORT                       (PORT4)
#define LO_V_PORT                       (PORT4)
#define HO_W_PORT                       (PORT3)
#define LO_W_PORT                       (PORT3)

//IO  PIN
#define HO_U_PIN                        (PIN3)
#define LO_U_PIN                        (PIN2)
#define HO_V_PIN                        (PIN1)
#define LO_V_PIN                        (PIN0)
#define HO_W_PIN                        (PIN7)
#define LO_W_PIN                        (PIN6)

/******************************************************************************/

/********************************************************************************
 *                                  IO端口复用
********************************************************************************/
//IO  复用管脚
#define HO_U_AFIO                       (P43CFG)
#define LO_U_AFIO                       (P42CFG)
#define HO_V_AFIO                       (P41CFG)
#define LO_V_AFIO                       (P40CFG)
#define HO_W_AFIO                       (P37CFG)
#define LO_W_AFIO                       (P36CFG)

//IO  复用功能
#define HO_U_IO_EPWM                    (IO_OUTCFG_P43_EPWM5)
#define LO_U_IO_EPWM                    (IO_OUTCFG_P42_EPWM4)
#define HO_V_IO_EPWM                    (IO_OUTCFG_P41_EPWM3)
#define LO_V_IO_EPWM                    (IO_OUTCFG_P40_EPWM2)
#define HO_W_IO_EPWM                    (IO_OUTCFG_P37_EPWM1)
#define LO_W_IO_EPWM                    (IO_OUTCFG_P36_EPWM0)

/******************************************************************************/

/********************************************************************************
 *                                  EPWM
********************************************************************************/
//EPWM  分配
#define HO_U_EPWM                       (EPWM5)
#define LO_U_EPWM                       (EPWM4)
#define HO_V_EPWM                       (EPWM3)
#define LO_V_EPWM                       (EPWM2)
#define HO_W_EPWM                       (EPWM1)
#define LO_W_EPWM                       (EPWM0)

/******************************************************************************/

void EPWM_Init_Config(void);

#endif