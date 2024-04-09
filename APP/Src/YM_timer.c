/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-07 09:15:15
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-08 10:28:37
 * @FilePath: \EIDE (工作区)e:\ZL\Git_Clone\EW_test\APP\Src\YM_timer.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_timer.h"
#include "YM_ccp.h"
#include "YM_rgb.h"

void TIMER0_Init_Config(void)
{
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_TIMER01,ENABLE);
	TMR_ConfigClk(TMR0,TMR_CLK_DIV_1);		
	
	TMR_ConfigRunMode(TMR0,TMR_COUNT_PERIOD_MODE, TMR_BIT_16_MODE);		
	
	TMR_DisableOneShotMode(TMR0);										
		
	TMR_SetPeriod(TMR0,2400*6);				
	
	// TMR_EnableOverflowInt(TMR0);

	// NVIC_EnableIRQ(TIMER0_IRQn);	
	
	// NVIC_SetPriority(TIMER0_IRQn,3);	
	
	TMR_Start(TMR0);			
}


void TIMER0_IRQHandler(void)
{
	if(TMR_GetOverflowIntFlag(TMR0))
	{
		TMR_ClearOverflowIntFlag(TMR0);		
	}			
}



























