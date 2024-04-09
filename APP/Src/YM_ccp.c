/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-08 15:51:12
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_ccp.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_ccp.h"
#include "YM_rgb.h"
#include "CMS32M67xx.h"

void CCP_Init_Config(uint32_t campler)
{
	GPIO_PinAFOutConfig(P06CFG, IO_OUTCFG_P06_CCP0A);

	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);
																		
	CCP_EnablePWMMode(CCP0);				
					
	CCP_ConfigCLK(CCP0, CCP_CLK_DIV_1, CCP_RELOAD_CCPLOAD, CCP0A_PERIPH);
	
	CCP_EnableReverseOutput(CCP0, CCPxA);				
	
	CCP_ConfigCompare(CCP0, CCPxA, campler);	

	// CCP_EnableOverflowInt(CCP0);
	CCP_EnableCompareInt(CCP0);
	NVIC_SetPriority(CCP_IRQn, 3);
	NVIC_EnableIRQ(CCP_IRQn);
	
	CCP_EnableRun(CCP0);			
	CCP_Start(CCP0);
	CCP->LOCK = CCP_P1A_WRITE_KEY;			
	
}


void CCP_IRQHandler(void)
{
	static uint8_t  camplerTicks = 0,
                	rgb_num = 0,
					control_times = 0;

	if(CCP_GetCompareIntFlag(CCP0))
	{
		CCP_ClearCompareIntFlag(CCP0);
		if(RGB_DataStracture.State != Off)
		{
			if(camplerTicks >= 24)
			{
				rgb_num++;
				if(rgb_num >= 6)
				{
					CCP->D0A = ((uint32_t)CCP0A_PERIPH | 0xF0000);
					camplerTicks++;
					if(camplerTicks >= 78) 
					{
						rgb_num = 0;
						camplerTicks = 0;
						control_times++;
						if(control_times >= 3)
						{
							CCP_Stop(CCP0);
							CCP_DisableRun(CCP0);	
							RGB_DataStracture.State = Off;
							control_times = 0;
						}
					}
				}
				else
				{
					camplerTicks = 0;
					CCP->D0A = (((uint32_t)*(RGB_DataStracture.ColorBuffPoint + camplerTicks)) | 0xF0000);
					camplerTicks++;
				}
			}
			else
			{
				CCP->D0A = (((uint32_t)*(RGB_DataStracture.ColorBuffPoint + camplerTicks)) | 0xF0000);
				camplerTicks++;
			}
		}	
	}
}