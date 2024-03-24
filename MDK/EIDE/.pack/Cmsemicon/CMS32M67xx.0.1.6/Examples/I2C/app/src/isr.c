#include "isr.h"
volatile uint32_t g_ticks = 0xFFFFFFFFU;

ATE_FRAME_t pData = {0};
ISR_InitTypeDef_t IRQ_Fun;

/**
  * @brief  SysTick Handler Decreament the g_ticks value
  * @param  TM13 IRQ
  * @retval None
  */
void SysTick_Handler(void)
{
	g_ticks--;
}

/**
  * @brief  IRQ00_Handler
  * @param  LVI IRQ
  * @retval None
  */
//void IRQ00_Handler(void)
//{
//	IRQ_Fun.IRQ[LVI_IRQn].intHandle(&pData);
//}



/**
  * @brief  IRQ10_Handler
  * @param  ST0/SPI00/IIC00 IRQ  
  * @note   the num of ST0_IRQn is same as SPI00_IRQn and IIC00_IRQ, so SPI00_IRQn or IIC00_IRQ
  *			interrupt quote this function handler IRQ10_Handler
  * @retval None
  */
void IRQ10_Handler(void)
{
	IRQ_Fun.IRQ[10].intHandle(&pData);
}



/**
  * @brief  register interrupt function according to  IRQn num.
  * @param  irq_num: it relates to irq handler 
  * @param	interrupt:interrupt server function
  * @retval regiseter status 
  */
int ISR_Register(IRQn_Type irq_num, void *interrupt)
{
	int res = ISR_SUCC;
	IRQn_Type IRQ_Channel;

	if(IRQ_Fun.IRQ[irq_num].IRQ_Flag)
	{
		return ISR_ERR;
	}
	else
	{		
		if(irq_num > FMC_IRQn)
		{
			IRQ_Channel = (IRQn_Type)(irq_num % 32);
		}
		else
		{
			IRQ_Channel = irq_num;
		}
		IRQ_Fun.IRQ[irq_num].IRQ_Flag = 1;
		IRQ_Fun.IRQ[IRQ_Channel].intHandle = (isrFun_t)interrupt;
//		INTC_ClearPendingIRQ(irq_num); // clear  interrupt flag 
		NVIC_ClearPendingIRQ(irq_num); // clear  interrupt flag 
		NVIC_EnableIRQ(irq_num);
	}

	return res;
}
