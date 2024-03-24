/***********************************************************************************************************************
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : main.c
* Version      :
* Device(s)    : CMS32M6510
* Tool-Chain   : MDK(armcc)
* Description  : This file is a template.
* Creation Date: 2022/5/30
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro Definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <stdio.h>
#include "demo_uart.h"
#include "demo_lsitimer.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile  uint32_t ADCValue = 0;

int main()
{
    uint32_t msCnt;     // count value of 1ms

    //-----------------------------------------------------------------------
    // Systick setting
    //-----------------------------------------------------------------------

    SystemCoreClockUpdate();
    msCnt = SystemCoreClock / 1000;
    SysTick_Config(msCnt);

    LSITIMER_Config();

		while(1)
		{
			;
		}
}


