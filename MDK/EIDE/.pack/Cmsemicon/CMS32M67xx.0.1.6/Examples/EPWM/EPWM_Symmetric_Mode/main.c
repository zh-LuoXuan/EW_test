/***********************************************************************************************************************
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : main.c
* Version      :  
* Device(s)    : BAT32M6510
* Tool-Chain   : MDK(armcc)
* Description  : This file is a template.
* Creation Date: 2022/8/24
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro Definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <stdio.h>
#include "demo_epwm.h"
/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint32_t g_ticks;
volatile uint32_t  CaptureTime = 0;			/*�����ʱ��*/

void delayMS(uint32_t n)
{
		g_ticks = n;
		while(g_ticks);
}

int main()
{
	uint32_t msCnt; 	// count value of 1ms
    
//-----------------------------------------------------------------------
// Systick setting 
//-----------------------------------------------------------------------
	g_ticks = 1000; 	// 1000ms
	SystemCoreClockUpdate();
	msCnt = SystemCoreClock / 1000;
	SysTick_Config(msCnt); 

	
	EPWM_Config();
	
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


