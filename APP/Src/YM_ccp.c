/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-28 18:02:00
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_ccp.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_ccp.h"
#include "YM_rgb.h"
#include "gpio.h"
#include "CMS32M67xx.h"

uint16_t LED5TestVal = 0;

/**
 * @brief CCP0中断配置
 * 
 * @param config：ENABLE / DISABLE
 * 
 * @return void
 */
void CCP_Int_Config(FunctionalState config)
{
	switch(config)
	{
		case ENABLE:
			CCP_EnableCompareInt(CCP0);
			NVIC_SetPriority(CCP_IRQn, 3);
			NVIC_EnableIRQ(CCP_IRQn);
			break;
		case DISABLE:
		default:
			CCP_DisableCompareInt(CCP0);
			NVIC_DisableIRQ(CCP_IRQn);
			break;
	}
}

/**
 * @brief 取消IO端口复用为CCP0x功能
 * 
 * @param [in] CCP0x：CCP0A / CCP0B
 * 
 * @return void
 */
void Pmn_AF_CCP0x_Disable(CCP0x_e CCP0x)
{
	switch(CCP0x)
	{
		case CCP0A:
			if(PORT->P06CFG != 0x00)
			PORT->P06CFG = 0x00;
			break;
		case CCP0B:
			if(PORT->P23CFG != 0x00)
			PORT->P23CFG = 0x00;
			break;
		default:
			break;
	}
}

/**
 * @brief CCP0A初始化配置
 * 
 * @param void
 * 
 * @return void
 */
void CCP0A_Init_Config(void)
{
    GPIO_PinAFOutConfig(P06CFG, IO_OUTCFG_P06_CCP0A);
    
	GPIO_Init(PORT0, PIN6, OUTPUT);

	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);
																		
	CCP_EnablePWMMode(CCP0);				
					
	CCP_ConfigCLK(CCP0, CCP_CLK_DIV_1, CCP_RELOAD_CCPLOAD, CCP0_PERIPH);
	
	CCP_EnableReverseOutput(CCP0, CCPxA);			
	
	CCP_ConfigCompare(CCP0, CCPxA, CCP0_PERIPH);

#if CCP_IT_CHANS
	CCP_Int_Config(ENABLE);	
#endif
	
	CCP_EnableRun(CCP0);
	CCP_Start(CCP0);
	CCP->LOCK = CCP_P1A_WRITE_KEY;
}

/**
 * @brief CCP0B初始化配置
 * 
 * @param void
 * 
 * @return void
 */
void CCP_Config_as_LED_B_Breath(void)
{
	GPIO_PinAFOutConfig(P23CFG, IO_OUTCFG_P23_CCP0B);

	GPIO_Init(PORT2, PIN3, OUTPUT);

	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);
																		
	CCP_EnablePWMMode(CCP0);				
					
	CCP_ConfigCLK(CCP0, CCP_CLK_DIV_1, CCP_RELOAD_CCPLOAD, CCP0_PERIPH);
	
	CCP_EnableReverseOutput(CCP0, CCPxB);			
	
	CCP_ConfigCompare(CCP0, CCPxB, CCP0_PERIPH);

	CCP_Int_Config(DISABLE);		

	CCP_EnableRun(CCP0);
	CCP_Start(CCP0);
	CCP->LOCK = CCP_P1A_WRITE_KEY;
}

/**
 * @brief 设置LED5亮度
 * 
 * @param [in] brightness：LED亮度
 * 
 * @note brightness的值应属于[0:255]。
 * 
 * @return void
 */
void Set_LED_B(uint8_t brightness)
{
	if(brightness > 255)
	brightness = 255;
	else if(brightness < 0)
	brightness = 0;

	CCP->D0B = (uint32_t)(CCP0_PERIPH - (CCP0_PERIPH * (uint32_t)brightness / 256));
}



/**
 * @brief CCP0中断服务函数
 * 
 * @param void
 * 
 * @return void
 */
void CCP_IRQHandler(void)
{
	static uint8_t  camplerTicks = 0,
                	rgb_num = 0,
					control_times = 0;
	CCP_ClearCompareIntFlag(CCP0);
	if(RGB_DataStracture.Lock != Lock)
	{
		if(camplerTicks >= 24)
		{
			rgb_num++;
			if(rgb_num >= THE_NUMBER_OF_LIGHT)
			{
				CCP->D0A = (uint32_t)CCP0_PERIPH | 0xF0000;
				camplerTicks++;
				if(camplerTicks == 25)
					RGB_DataStracture.SendState = Finish;
				if(camplerTicks >= 78) 
				{
					rgb_num = 0;
					camplerTicks = 0;
					control_times++;
					if(control_times >= 3)
					{
						CCP_Stop(CCP0);
						CCP_DisableRun(CCP0);	
						RGB_DataStracture.Lock = Lock;
						control_times = 0;
					}
				}
			}
			else
			{
				camplerTicks = 0;

#if CCP_IT_CHANS
				CCP->D0A = (uint32_t)(*(RGB_DataStracture.RGB_CCPBuff + camplerTicks));
#endif
				camplerTicks++;
			}
		}
		else
		{
#if CCP_IT_CHANS
			CCP->D0A = (uint32_t)(*(RGB_DataStracture.RGB_CCPBuff + camplerTicks));;
#endif
			camplerTicks++;
		}
	}	
}