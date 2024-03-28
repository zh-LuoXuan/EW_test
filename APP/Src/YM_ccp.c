/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: zh-LuoXuan 1153589792@qq.com
 * @LastEditTime: 2024-03-29 03:25:29
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_ccp.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_ccp.h"
#include "YM_rgb.h"

void CCP_PWM_Config(uint32_t campler)
{
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);				
	CCP_ConfigCLK(CCP0,CCP_CLK_DIV_1,CCP_RELOAD_CCPLOAD,100);			
																		
	CCP_EnablePWMMode(CCP0);											
	
	CCP_ConfigCompare(CCP0,CCP->D0A,campler);	

	// CCP_EnableCompareInt(CCP0);
	CCP_EnableOverflowInt(CCP0);

	NVIC_EnableIRQ(CCP_IRQn);
	NVIC_SetPriority(CCP_IRQn,2);								

	GPIO_Init(PORT0,PIN6,OUTPUT);
	GPIO_PinAFOutConfig(P06CFG,IO_OUTCFG_P06_CCP0A);		
	
	CCP_EnableRun(CCP0);			
	CCP_Start(CCP0);
	CCP->LOCK = CCP_P1A_WRITE_KEY;			
	
}

void CCP_IRQHandler(void)
{	
	static uint8_t camplerTicks = 0;
	uint32_t* ccpCamplerDataPoint = testData;
	if(CCP_GetOverflowIntFlag(CCP0))
	{
		// CCP_DisableRun(CCP0);
		// CCP_Stop(CCP0);
		CCP_ClearOverflowIntFlag(CCP0);
        if(camplerTicks >= 24)
        {
            camplerTicks = 0;
        }
	    // CCP->LOCK = CCP_P1A_WRITE_KEY;		
		CCP->D0A = *(ccpCamplerDataPoint += camplerTicks);
	    // CCP->LOCK = 0x00;
		camplerTicks++;
		// CCP_EnableRun(CCP0);			
		// CCP_Start(CCP0);
	}
}




