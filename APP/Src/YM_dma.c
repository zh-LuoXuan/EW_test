/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-08 15:52:51
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-28 16:42:42
 * @FilePath: \EIDE (工作区)e:\ZL\Git_Clone\EW_test_breath\APP\Src\YM_dma.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_dma.h"
#include "YM_rgb.h"
#include "YM_ccp.h"
#include "timer.h"

uint32_t test[24] = {1, 2, 3, 4, 5, 6, 7, 8,  \
					10, 11, 12, 13, 14, 15, 16, 17,  \
					20, 21, 22, 23, 24, 25, 26, 27};
DMA_InitTypeDef  DMA_InitStructure = {0};
void DMA_CCP0A_Config(void)
{
    

	DMATRG->DMATGS |= 1 << 7;
	DMA_InitStructure.DMA_Vector = DMA_VECTOR_TIMER0;    
	DMA_InitStructure.DMA_CtrlId = 7;     
    DMA_InitStructure.DMA_SrcAddr = (uint32_t)(RGB_DataStracture.RGB_DMABuff);
//	DMA_InitStructure.DMA_SrcAddr = (uint32_t)test;
	DMA_InitStructure.DMA_DstAddr = (uint32_t)(&(CCP->D0A));  
	DMA_InitStructure.DMA_BufferSize = DMA_CCP_MAX_RECV_LEN;
	DMA_InitStructure.DMA_SrcInc = DMA_SrcInc_Enable;
	DMA_InitStructure.DMA_DstInc = DMA_DstInc_Disable;
	DMA_InitStructure.DMA_DataSize = DMA_DataSize_Word;
//	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Repeat;
	DMA_InitStructure.DMA_RepeatAreaAddr = DMA_RepeatAreaAddr_Src;
	DMA_InitStructure.DMA_RepeatInt = DMA_RepeatInt_Disable;
	DMA_Init(&DMA_InitStructure);
	DMA_Start(DMA_InitStructure.DMA_Vector);
}
