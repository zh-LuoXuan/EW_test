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
#include "common.h"
#include "gpio.h"


/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint32_t g_ticks;
uint8_t crcin[4]={0x78,0x56,0x34,0x12};
uint32_t CRCResult=0;

void delayMS(uint32_t n)
{
		g_ticks = n;
		while(g_ticks);
}


int main()
{
	uint32_t msCnt,i; 	// count value of 1ms
    
//-----------------------------------------------------------------------
// Systick setting 
//-----------------------------------------------------------------------
	g_ticks = 1000; 	// 1000ms
	SystemCoreClockUpdate();
	msCnt = SystemCoreClock / 1000;
	SysTick_Config(msCnt); 

/*****************************************************************************************************
	*        判断CRC结果是不是08F6H
*****************************************************************************************************/
	CRC->CRCD = 0x00;
	for(i=0;i<4;i++)
	{
		CRC->CRCIN = crcin[i];
	}
														 
   CRCResult = CRC->CRCD;	
	
	while (1)
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


