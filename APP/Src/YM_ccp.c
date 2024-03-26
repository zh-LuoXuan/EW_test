#include "YM_ccp.h"

void CCP_PWM_Config(uint32_t campler)
{
	/*
	设置CCP的时钟
	*/
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);				/*开启CCP模块时钟*/
	CCP_ConfigCLK(CCP0,CCP_CLK_DIV_1,CCP_RELOAD_CCPLOAD,100);			/*Fccp = 72Mhz ->捕获计数周期 = 100/72M = 1.38us*/
																		/*CCP0模块溢出后重载值为100*/
	/*
	设置CCP运行模式
	*/
	CCP_EnablePWMMode(CCP0);											/*设置CCP0的工作模式为PWM*/
	/*
	设置CCP输出通道
	*/
	CCP_ConfigCompare(CCP0,CCP->D0A,campler);									/*设置输出通道为CCP0*/

	GPIO_Init(PORT0,PIN6,OUTPUT);
	GPIO_PinAFOutConfig(P06CFG,IO_OUTCFG_P06_CCP0A);		
	/*
	开启CCP模块
	*/	
	CCP_EnableRun(CCP0);			
	CCP_Start(CCP0);			/*CCP0模块使能*/	

	CCP->LOCK = CCP_P1A_WRITE_KEY;		
	
}




