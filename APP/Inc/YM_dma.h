#ifndef __YM_DMA_H_
#define __YM_DMA_H_

#include <stdint.h>
#include "dma.h"
#include "ccp.h"

#define CCP0A_MAX_RECV_LEN  (24U)



void DMA_CCP0A_Config(void);

#endif