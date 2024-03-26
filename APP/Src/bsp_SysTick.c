/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-03-26 12:07:13
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-26 15:51:00
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\bsp_SysTick.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "bsp_SysTick.h"

static __IO uint32_t Ticks = 0;

void Systick_Init_Config(void)
{
    if(SysTick_Config(SystemCoreClock / 1000000))
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
        // 当计数器的值减小到0的时候，CRTL寄存器的位16会置1
        while(!((SysTick->CTRL) & (1 << 16)));
    }
    //关闭SysTick定时器
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


void SysTick_Delay_ms(__IO uint32_t ms)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock / 1000);
    for(i = 0; i < ms; i++)
    {
        // 当计数器的值减小到0的时候，CRTL寄存器的位16会置1
        while(!((SysTick->CTRL) & (1 << 16)));
    }
    //关闭SysTick定时器
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
    if(Ticks)
    {
        Ticks--;
    }
}