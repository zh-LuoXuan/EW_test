/***********************************************************************************************************************
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : main.c
* Version      :
* Device(s)    : BAT32G439
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
#include "cgc.h"
#include "gpio.h"
#include "pcbz.h"
#include "demo_lsitimer.h"
//#define  USED_FMX_AS_FCLK // HSE
#define  USED_FIH_AS_FCLK
//#define  USED_FIL_AS_FCLK
//#define  USED_PLL_AS_FCLK
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
    uint32_t msCnt;     // count value of 1ms

    //-----------------------------------------------------------------------
    // clock setting
    //-----------------------------------------------------------------------
/*使用外部高速系统时钟作为cpu运行时钟以及外围电路时钟,注意需要外接晶振*/	
#ifdef USED_FMX_AS_FCLK 
	CGC_OSC_Selet(_01_CMC_OSCSEL_X1);
	CGC_HSE_CFG_AS_FCLK();  //外部高速系统时钟作为cpu运行时钟以及外围电路时钟

    PCBZIO_Init();	
	UART0_Config();
	printf("Select FMX as system clock\n");
#endif	
/*内部高速系统时钟作为cpu运行时钟以及外围电路时钟*/	
#ifdef USED_FIH_AS_FCLK 
    SystemCoreClockUpdate();   
    msCnt = SystemCoreClock / 1000;
		CGC_HSI_CFG_AS_FCLK();
		CGC_HSE_Disable();
//    SysTick_Config(msCnt); 
		PCBZIO_Init();	
#endif
/*内部低速速系统时钟作为cpu运行时钟以及外围电路时钟*/
#ifdef USED_FIL_AS_FCLK 
	CGC_LSI_CFG_AS_FCLK();
	LSITIMER_Config();
#endif

/*设置PLL时钟作为cpu运行时钟和时钟输出*/
#ifdef USED_PLL_AS_FCLK 
	CGC_OSC_Selet(_01_CMC_OSCSEL_X1);
	CGC_HSE_CFG_AS_FCLK();  //外部高速系统时钟作为cpu运行时钟以及外围电路时钟
	
	CGC_PLL_Sel(PLL_SR_fMX);
	CGC_PLL_Multi(PLL_MUL_6);
	CGC_MCLK_PLLSel(CGC_MCLK_PLL);
//	CGC_PLL_Div(PLL_DIV_2);
	CGC_PLL_Enable();
	CGC_PLL_CFG_AS_FCLK();		//选择PLL作为MAIN clock
	UART0_Config();
	PCBZIO_Init();	
	msCnt=250;
	while(msCnt--);
	printf("Select PLL as system clock\n");
	
	   

#endif
	while(1)
	{
		;
	}

}



