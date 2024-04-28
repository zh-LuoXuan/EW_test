/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-03-25 18:41:42
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-28 15:34:57
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\YM_dma.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_DMA_H_
#define __YM_DMA_H_

#include <stdint.h>
#include "dma.h"
#include "ccp.h"

#define DMA_CCP_MAX_RECV_LEN  (128)
#define DMA_EN0            *((volatile unsigned short *)(0x40005000))


extern DMA_InitTypeDef  DMA_InitStructure;

void DMA_CCP0A_Config(void);

#endif