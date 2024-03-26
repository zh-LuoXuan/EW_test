/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-03-25 18:41:42
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-26 17:31:23
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_dma.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_dma.h"
#include "YM_rgb.h"
uint32_t testData[24] = {75,75,25,75,25,25,25,25, \
                         75,75,25,75,25,75,25,75, \
						 25,75,25,25,25,75,25,75};

void DMA_CCP0A_Config(void)
{
    DMA_InitTypeDef  DMA_InitStructure;
	DMA_InitStructure.DMA_Vector = DMA_VECTOR_TIMER0;    
	DMA_InitStructure.DMA_CtrlId = (0x07U);     
	DMA_InitStructure.DMA_SrcAddr = (uint32_t)testData;  
	DMA_InitStructure.DMA_DstAddr = CCP->D0A;  
	DMA_InitStructure.DMA_BufferSize = CCP0A_MAX_RECV_LEN;
	DMA_InitStructure.DMA_SrcInc = DMA_SrcInc_Enable;
	DMA_InitStructure.DMA_DstInc = DMA_DstInc_Disable;
	DMA_InitStructure.DMA_DataSize = DMA_DataSize_Word;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Repeat;
	DMA_InitStructure.DMA_RepeatAreaAddr = DMA_RepeatAreaAddr_Src;
	DMA_InitStructure.DMA_RepeatInt = DMA_RepeatInt_Disable;
	DMA_Init(&DMA_InitStructure);
	DMA_Start(DMA_InitStructure.DMA_Vector);
}