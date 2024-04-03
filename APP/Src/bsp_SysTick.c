/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-30 02:34:51
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-03 10:55:21
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\EW_test\APP\Src\bsp_SysTick.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "bsp_SysTick.h"

#include "YM_ccp.h"
#include "YM_rgb.h"
#include "gpio.h"

static __IO uint32_t Ticks = 0;

void Systick_Init_Config(void)
{
    if(SysTick_Config(100))
    {
        while(1);
    }
}





void SysTick_Delay_us(__IO uint32_t us)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock / 1000000);
    for(i = 0; i < us; i++)
    {
        while(!((SysTick->CTRL) & (1 << 16)));
    }
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


void SysTick_Delay_ms(__IO uint32_t ms)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock / 1000);
    for(i = 0; i < ms; i++)
    {
        while(!((SysTick->CTRL) & (1 << 16)));
    }
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


void Delay_us(__IO uint32_t times)
{
    Ticks = times;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    while(Ticks);
}


void Delay_ms(__IO uint32_t times)
{
    Ticks = 1000 * times;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    while(Ticks);
}



void SysTick_Handler(void)
{
    static uint8_t camplerTicks = 0,
                   rgb_num = 0;
    if(camplerTicks >= 24)
    {
        rgb_num++;
        if(rgb_num >= 6)
        {
            CCP->D0A = ((uint32_t)CCP0A_PERIPH | 0xF0000);
            camplerTicks++;
            if(camplerTicks >= 185) 
            {
                rgb_num = 0;
                camplerTicks = 0;
            }
        }
        else
        {
            camplerTicks = 0;
            CCP->D0A = (((uint32_t)*(RGB_DataStracture.WhiteBuff + camplerTicks)) | 0xF0000);
            camplerTicks++;
        }
    }
    else
    {
        CCP->D0A = (((uint32_t)*(RGB_DataStracture.WhiteBuff + camplerTicks)) | 0xF0000);
        camplerTicks++;
    }
       
    // if(Ticks)
    // {
    //     Ticks--;
    // }
}