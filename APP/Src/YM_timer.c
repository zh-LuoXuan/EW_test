/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-08 15:52:51
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-28 17:33:55
 * @FilePath: \EIDE (工作区)e:\ZL\Git_Clone\MD_RGB_UART\APP\Src\YM_timer.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_timer.h"
#include "YM_ccp.h"
#include "YM_rgb.h"
#include "YM_dma.h"
#include "dma.h"

void TMR0_Int_Config(void)
{
	TMR_EnableOverflowInt(TMR0);

	NVIC_EnableIRQ(TIMER0_IRQn);	
	
	NVIC_SetPriority(TIMER0_IRQn,3);
	
	TMR_Start(TMR0);
} 

void TMR1_Int_Config(void)
{
	TMR_EnableOverflowInt(TMR1);

	NVIC_EnableIRQ(TIMER1_IRQn);	
	
	NVIC_SetPriority(TIMER1_IRQn,3);
	
	TMR_Start(TMR1);
} 

void TIMER0_Init_Config(void)
{
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_TIMER01,ENABLE);
	
	TMR_ConfigRunMode(TMR0, TMR_COUNT_PERIOD_MODE, TMR_BIT_16_MODE);		
	
#if CCP_IT_CHANS	
	TMR_ConfigClk(TMR0,TMR_CLK_DIV_256);

	TMR_SetPeriod(TMR0,5120);
#elif DMA_TGR_CHANS		
	TMR_ConfigClk(TMR0,TMR_CLK_DIV_1);	

	TMR_SetPeriod(TMR0,CCP0_PERIPH - 1);
#endif 	

	TMR_DisableOneShotMode(TMR0);										

	TMR0_Int_Config();
	
	TMR_Start(TMR0);

}

void TIMER1_Init_Config(void)
{
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_TIMER01,ENABLE);
	
	TMR_ConfigRunMode(TMR1, TMR_COUNT_PERIOD_MODE, TMR_BIT_16_MODE);		

#if DMA_TGR_CHANS	
	TMR_ConfigClk(TMR1,TMR_CLK_DIV_256);									
		
	TMR_SetPeriod(TMR1,1350);	
#endif
	
	TMR_DisableOneShotMode(TMR1);	

	TMR1_Int_Config();
	
	TMR_Start(TMR1);

}




void TIMER0_IRQHandler(void)
{
	TMR_ClearOverflowIntFlag(TMR0);
#if CCP_IT_CHANS	
	if(RGB_DataStracture.SendState == Finish)
	{
		if(RGB_DataStracture.Mode[Current] == Breath)
		{
			RGB_Breath_Update(&RGB_DataStracture, BREATH_PER);
		}
		RGB_DataStracture.SendState = Busy;
	}	
#endif
}


void TIMER1_IRQHandler(void)
{
	TMR_ClearOverflowIntFlag(TMR1);
#if DMA_TGR_CHANS	
	if(RGB_DataStracture.Mode[Current] == Breath)
	{
		RGB_Breath_Update(&RGB_DataStracture, BREATH_PER);
	}
	RGB_DataStracture.SendState = Busy;	
#endif
	
}

























