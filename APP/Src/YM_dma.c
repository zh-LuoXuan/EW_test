#include "YM_dma.h"
#include "YM_rgb.h"

void DMA_CCP0A_Config(void)
{
    DMA_InitTypeDef  DMA_InitStructure;
	DMA_InitStructure.DMA_Vector = DMA_VECTOR_TIMER0;    
	DMA_InitStructure.DMA_CtrlId = DMA_VECTOR_TIMER0;     
	DMA_InitStructure.DMA_SrcAddr = RGB_Output(&RGB_DataStracture);  
	DMA_InitStructure.DMA_DstAddr = CCP->D0A;  
	DMA_InitStructure.DMA_BufferSize = CCP0A_MAX_RECV_LEN;
	DMA_InitStructure.DMA_SrcInc = DMA_SrcInc_Disable;
	DMA_InitStructure.DMA_DstInc = DMA_DstInc_Disable;
	DMA_InitStructure.DMA_DataSize = DMA_DataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Repeat;
	DMA_InitStructure.DMA_RepeatAreaAddr = DMA_RepeatAreaAddr_Dst;
	DMA_InitStructure.DMA_RepeatInt = DMA_RepeatInt_Disable;
	DMA_Init(&DMA_InitStructure);
	DMA_Start(DMA_InitStructure.DMA_Vector);
}