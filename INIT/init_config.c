#include "init_config.h"

void Init_Cinfig(void)
{
	Systick_Init_Config();
	Touch_Init_Config();
	LED_Init_Config();
	GPIO_Init_Config();
	EPWM_Init_Config();
	RGB_Init_Config();
	UART1_Init_Config(115200);
	KEY_Init_Config();
	// CCP_Config_as_LED_B_Breath();
	// Pmn_AF_CCP0x_Disable(CCP0B);
	CCP0A_Init_Config();
	TIMER0_Init_Config();
#if DMA_TGR_CHANS
	TIMER1_Init_Config();
	DMA_CCP0A_Config();
#endif
}