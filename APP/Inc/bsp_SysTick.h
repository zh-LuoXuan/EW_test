/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-03-26 12:08:51
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-26 14:45:15
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\bsp_SysTick.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __BSP_SYSTICK_H_
#define __BSP_SYSTICK_H_

#include "CMS32M67xx.h"

void SysTick_Delay_us(__IO uint32_t us);
void SysTick_Delay_ms(__IO uint32_t ms);
void Delay_us(__IO uint32_t times);
void Delay_ms(__IO uint32_t times);
void Systick_Init_Config(void);

#endif