/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-08 15:52:51
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-25 16:53:32
 * @FilePath: \EIDE (工作区)e:\ZL\Git_Clone\EW_test_breath\APP\Inc\YM_uart.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_UART_H_
#define __YM_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "uart.h"
#include "common.h"
#include "cgc.h"
#include "gpio.h"


#define UART1_REC_MAX_LEN                   (32U)
#define SOF                                 (0xCA)
#define BUFFER_LEN_MSK                      (0x1F)


void get_Uart1_RxData(void);
void UART1_Init_Config(uint32_t bitRate);

#ifdef __cplusplus
}
#endif

#endif /* __DEMO_UART_H_ */

