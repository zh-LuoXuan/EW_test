#ifndef __INIT_CONFIG_H_
#define __INIT_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdint.h>
#include "CMS32M67xx.h"
#include "system_CMS32M67xx.h"
#include "YM_ccp.h"
#include "YM_rgb.h"
#include "YM_dma.h"
#include "YM_timer.h"
#include "YM_uart.h"
#include "YM_gpio.h"
#include "YM_epwm.h"
#include "bsp_SysTick.h"
#include "Sys_OptionByte.h"
#include "flash.h"
 

void Init_Cinfig(void);

#ifdef __cplusplus
}
#endif

#endif 