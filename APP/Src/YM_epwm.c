/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-25 17:47:04
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-26 15:21:32
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_epwm.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_epwm.h"
#include "epwm.h"


void EPWM_Init_Config(void)
{
    CGC_PER11PeriphClockCmd(CGC_PER11Periph_EPWM,ENABLE);	/*开启EPWM时钟*/
	/*
	(1)设置EPWM运行模式
	*/
	EPWM_ConfigRunMode(  EPWM_COUNT_UP_DOWN 		| 		/*上下计数模式(中心对齐)*/
						 EPWM_OCU_SYMMETRIC 		|		/*对称模式*/
						 EPWM_WFG_COMPLEMENTARYK    |		/*互补模式*/
						 EPWM_OC_INDEPENDENT);				/*独立输出模式*/
	/*
	(2)设置EPWM时钟周期与死区
	*/		
	
	EPWM_ConfigChannelClk(HO_U_EPWM, EPWM_CLK_DIV_1);		
	EPWM_ConfigChannelClk(LO_U_EPWM, EPWM_CLK_DIV_1);		
	EPWM_ConfigChannelClk(HO_V_EPWM, EPWM_CLK_DIV_1);		
	EPWM_ConfigChannelClk(LO_V_EPWM, EPWM_CLK_DIV_1);		
    EPWM_ConfigChannelClk(HO_W_EPWM, EPWM_CLK_DIV_1);		
	EPWM_ConfigChannelClk(LO_W_EPWM, EPWM_CLK_DIV_1);		


	EPWM_ConfigChannelPeriod(HO_U_EPWM,  2000);      
	EPWM_ConfigChannelPeriod(LO_U_EPWM,  2000);
	EPWM_ConfigChannelPeriod(HO_V_EPWM,  2000);			
	EPWM_ConfigChannelPeriod(LO_V_EPWM,  2000);
	EPWM_ConfigChannelPeriod(HO_W_EPWM,  2000);			
	EPWM_ConfigChannelPeriod(LO_W_EPWM,  2000);			
	
	EPWM_ConfigChannelSymDuty(HO_U_EPWM, 1000);					
	EPWM_ConfigChannelSymDuty(LO_U_EPWM, 1000);					
	EPWM_ConfigChannelSymDuty(HO_V_EPWM, 1000);		
    EPWM_ConfigChannelSymDuty(LO_V_EPWM, 1000);						
	EPWM_ConfigChannelSymDuty(HO_W_EPWM, 1000);		
    EPWM_ConfigChannelSymDuty(LO_W_EPWM, 1000);	

	EPWM_DisableDeadZone(EPWM_CH_0_MSK | EPWM_CH_1_MSK |
						 EPWM_CH_2_MSK | EPWM_CH_3_MSK |
						 EPWM_CH_4_MSK | EPWM_CH_5_MSK |
						 EPWM_CH_6_MSK | EPWM_CH_7_MSK);	/*关闭死区*/

	/*
	(3)设置EPWM反向输出
	*/
	EPWM_DisableReverseOutput( EPWM_CH_0_MSK | EPWM_CH_1_MSK |
							   EPWM_CH_2_MSK | EPWM_CH_3_MSK |
							   EPWM_CH_4_MSK | EPWM_CH_5_MSK |
							   EPWM_CH_6_MSK | EPWM_CH_7_MSK  );				/*关闭反相输出*/

	/*
	(4)设置EPWM加载方式
	*/
	EPWM_EnableAutoLoadMode(EPWM_CH_0_MSK | EPWM_CH_1_MSK | EPWM_CH_2_MSK | EPWM_CH_3_MSK | EPWM_CH_4_MSK | EPWM_CH_5_MSK );	/*设置为自动加载模式*/
	
	EPWM_ConfigLoadAndIntMode(HO_U_EPWM, EPWM_EACH_PERIOD_ZERO);			
	EPWM_ConfigLoadAndIntMode(LO_U_EPWM, EPWM_EACH_PERIOD_ZERO);
	EPWM_ConfigLoadAndIntMode(HO_V_EPWM, EPWM_EACH_PERIOD_ZERO);			
	EPWM_ConfigLoadAndIntMode(LO_V_EPWM, EPWM_EACH_PERIOD_ZERO);			/*加载点设置为每个周期点和零点*/
	EPWM_ConfigLoadAndIntMode(HO_W_EPWM, EPWM_EACH_PERIOD_ZERO);			
	EPWM_ConfigLoadAndIntMode(LO_W_EPWM, EPWM_EACH_PERIOD_ZERO);

	/*
	(5)设置EPWM刹车
	*/
	EPWM_AllBrakeDisable();

	/*
	(6)设置中断
	*/
	// EPWM_EnableZeroInt(EPWM_CH_0_MSK);								/*开启零点中断*/			
	// NVIC_EnableIRQ(EPWM_IRQn);

	/*
	(6)设置优先级
	*/	
	// NVIC_SetPriority(EPWM_IRQn,3);					/*优先级0~3， 0最高、3最低*/
	
	/*
	(7)设置IO口输出
	*/				
	GPIO_PinAFOutConfig(P43CFG, HO_U_IO_EPWM);						
	GPIO_PinAFOutConfig(P42CFG, LO_U_IO_EPWM);							
	GPIO_PinAFOutConfig(P41CFG, HO_V_IO_EPWM);				
	GPIO_PinAFOutConfig(P40CFG, LO_V_IO_EPWM);		
	GPIO_PinAFOutConfig(P37CFG, HO_W_IO_EPWM);
	GPIO_PinAFOutConfig(P36CFG, LO_W_IO_EPWM);		
	

	GPIO_Init(HO_U_PORT, HO_U_PIN, OUTPUT);
	GPIO_Init(LO_U_PORT, LO_U_PIN, OUTPUT);
	GPIO_Init(HO_V_PORT, HO_V_PIN, OUTPUT);
	GPIO_Init(LO_V_PORT, LO_V_PIN, OUTPUT);
	GPIO_Init(HO_W_PORT, HO_W_PIN, OUTPUT);
	GPIO_Init(LO_W_PORT, LO_W_PIN, OUTPUT);
	 
	EPWM_EnableOutput(EPWM_CH_0_MSK | EPWM_CH_1_MSK |
					  EPWM_CH_2_MSK | EPWM_CH_3_MSK |
					  EPWM_CH_4_MSK | EPWM_CH_5_MSK |
					  EPWM_CH_6_MSK | EPWM_CH_7_MSK);

	/*
	(8)开启EPWM
	*/		
	EPWM_Start(EPWM_CH_0_MSK | EPWM_CH_1_MSK | EPWM_CH_2_MSK | EPWM_CH_3_MSK | EPWM_CH_4_MSK | EPWM_CH_5_MSK);
}