/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-25 09:16:17
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-26 18:34:52
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
CGC_Type* CGCdata;

/***************************/
int main(void)
{
	
    CGCdata = CGC;
	
	Systick_Init_Config();
	// Touch_Init_Config();
    // EPWM_Init_Config();
	// LED_Init_Config();
	RGB_Init_Config();
	CCP_PWM_Config(20);
	DMA_CCP0A_Config();
	TIMER0_Init_Config();

	while(1)
	{
		touchVal = PORT_GetBitValue(TOUCH_PORT, TOUCH_PIN);
		if(!touchVal)
		{   
			Delay_ms(5);
			if(!touchVal)
			{				
				ALL_LED(ON)
			}
		}	
		else
		{
			Delay_ms(5);
			if(touchVal)
			{
				ALL_LED(OFF)
			}
		}	
	}
}


