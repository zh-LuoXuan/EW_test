/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-25 09:16:17
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-01 18:24:32
 * @FilePath: \EIDE (工作区)c:\Users\xuan.luo\Desktop\EW_test\MAIN\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include "YM_ccp.h"
#include "YM_rgb.h"
#include "YM_dma.h"
#include "YM_timer.h"
#include "YM_uart.h"
#include "YM_led.h"
#include "YM_touch.h"
#include "YM_epwm.h"
#include "bsp_SysTick.h"

/**用于 Debug 监控的全局变量**/

char touchVal = 1;
char P02Val;
CGC_Type* CGCdata;
TMR_T* TIMER0Data;
CCP_Type* CCPdata;
PORT_Type* PORTdata;
SysTick_Type* SysTickdata;

/***************************/
int main(void)
{
    CGCdata = CGC;
	TIMER0Data = TMR0;
	CCPdata = CCP;
	PORTdata = PORT;
	SysTickdata = SysTick;

	// Touch_Init_Config();
    // EPWM_Init_Config();
	// LED_Init_Config();
	
	RGB_Init_Config();
	CCP_Init_Config(80);
	GPIO_Init_Config();
	Systick_Init_Config();
	
	// DMA_CCP0A_Config();
	// TIMER0_Init_Config();

	while(1)
	{	
		;
	}
}


