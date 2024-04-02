#include "YM_timer.h"


void TIMER0_Init_Config(void)
{
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_TIMER01,ENABLE);
	TMR_ConfigClk(TMR0,TMR_CLK_DIV_1);		
	
	TMR_ConfigRunMode(TMR0,TMR_COUNT_PERIOD_MODE, TMR_BIT_16_MODE);		
	
	TMR_DisableOneShotMode(TMR0);										
		
	TMR_SetPeriod(TMR0,100);				
	
	TMR_EnableOverflowInt(TMR0);

	NVIC_EnableIRQ(TIMER0_IRQn);	
	
	NVIC_SetPriority(TIMER0_IRQn,3);	
	
	TMR_Start(TMR0);			
}


void TIMER0_IRQHandler(void)
{
	if(TMR_GetOverflowIntFlag(TMR0))
	{
		TMR_ClearOverflowIntFlag(TMR0);		
	}			
}



























