/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: zh-LuoXuan 1153589792@qq.com
 * @LastEditTime: 2024-03-28 01:09:42
 * @FilePath: \EIDE (������)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_ccp.c
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_ccp.h"

void CCP_PWM_Config(uint32_t campler)
{
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);				
	CCP_ConfigCLK(CCP0,CCP_CLK_DIV_1,CCP_RELOAD_CCPLOAD,100);			
																		
	CCP_EnablePWMMode(CCP0);											
	
	CCP_ConfigCompare(CCP0,CCP->D0A,campler);									

	GPIO_Init(PORT0,PIN6,OUTPUT);
	GPIO_PinAFOutConfig(P06CFG,IO_OUTCFG_P06_CCP0A);		
	
	CCP_EnableRun(CCP0);			
	CCP_Start(CCP0);			

	CCP->LOCK = CCP_P1A_WRITE_KEY;		
	
}




