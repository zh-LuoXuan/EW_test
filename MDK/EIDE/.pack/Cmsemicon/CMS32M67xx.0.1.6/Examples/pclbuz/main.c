/***********************************************************************************************************************
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : main.c
* Version      :
* Device(s)    : CMS32L051
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
#include "common.h"
#include "gpio.h"
#include "cgc.h"
#include "pcbz.h"


/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

void PCBZIO_Init()
{
    PCBZ_InitTypeDef PCBZ_InitStructure = {0};

    /*CLKBUZ0 GPIO CONFIG*/
		GPIO_PinAFOutConfig(P56CFG, IO_OUTCFG_P56_PCBUZ0);				// CLKBUZ0
		GPIO_Init(PORT5,PIN6,OUTPUT);
	
	PCBZ_InitStructure.PCBZ_ChanSelect = PCBZ_CHANNEL_0;  //选择clkbuz 的通道0
	PCBZ_InitStructure.PCBZ_ClkSource =  PCBZ_FMAIN;
	PCBZ_InitStructure.PCBZ_Freqscaler = PCBZ_FMAIN_3;	
	PCBZ_Init(&PCBZ_InitStructure);	
	
    /*CLKBUZ1 GPIO CONFIG*/
		GPIO_PinAFOutConfig(P57CFG, IO_OUTCFG_P57_PCBUZ1);				// CLKBUZ1
		GPIO_Init(PORT5,PIN7,OUTPUT);
	
	PCBZ_InitStructure.PCBZ_ChanSelect = PCBZ_CHANNEL_1;  //选择clkbuz 的通道1
	PCBZ_InitStructure.PCBZ_ClkSource =  PCBZ_FMAIN;
	PCBZ_InitStructure.PCBZ_Freqscaler = PCBZ_FMAIN_0;	
	PCBZ_Init(&PCBZ_InitStructure);		
}
int main()
{
	
	uint32_t msCnt; 	// count value of 1ms
    
//-----------------------------------------------------------------------
// Systick setting 
//-----------------------------------------------------------------------
	SystemCoreClockUpdate();
	msCnt = SystemCoreClock / 1000;
	SysTick_Config(msCnt); 
	
	PCBZIO_Init();	   

}



