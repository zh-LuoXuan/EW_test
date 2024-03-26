#include "YM_ccp.h"

void CCP_PWM_Config(uint32_t campler)
{
	/*
	����CCP��ʱ��
	*/
	CGC_PER11PeriphClockCmd(CGC_PER11Periph_CCP,ENABLE);				/*����CCPģ��ʱ��*/
	CCP_ConfigCLK(CCP0,CCP_CLK_DIV_1,CCP_RELOAD_CCPLOAD,100);			/*Fccp = 72Mhz ->����������� = 100/72M = 1.38us*/
																		/*CCP0ģ�����������ֵΪ100*/
	/*
	����CCP����ģʽ
	*/
	CCP_EnablePWMMode(CCP0);											/*����CCP0�Ĺ���ģʽΪPWM*/
	/*
	����CCP���ͨ��
	*/
	CCP_ConfigCompare(CCP0,CCP->D0A,campler);									/*�������ͨ��ΪCCP0*/

	GPIO_Init(PORT0,PIN6,OUTPUT);
	GPIO_PinAFOutConfig(P06CFG,IO_OUTCFG_P06_CCP0A);		
	/*
	����CCPģ��
	*/	
	CCP_EnableRun(CCP0);			
	CCP_Start(CCP0);			/*CCP0ģ��ʹ��*/	

	CCP->LOCK = CCP_P1A_WRITE_KEY;		
	
}




