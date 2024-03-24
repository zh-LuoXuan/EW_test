#include <stdio.h>
#include "YM_ccp.h"
#include "YM_rgb.h"
#include "YM_dma.h"
#include "YM_timer.h"
#include "YM_uart.h"


volatile uint32_t g_ticks;
volatile uint32_t  CaptureTime = 0;		

void delayMS(uint32_t n)
{
		g_ticks = n;
		while(g_ticks);
}

int main()
{
	uint32_t msCnt; 	// count value of 1ms
	g_ticks = 1000; 	// 1000ms
	SystemCoreClockUpdate();
	msCnt = SystemCoreClock / 1000;
	SysTick_Config(msCnt); 


	RGB_Init_Config();
	CCP_PWM_Config(75);
	DMA_CCP0A_Config();
	TIMER0_Init_Config();

	while(1)
	{
		;		
	}
}

/***********************************************************************************************************************
* Function Name: SysTick Handler
* Description  : Decreament the g_ticks value
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void SysTick_Handler(void)
{
	g_ticks--;
}


