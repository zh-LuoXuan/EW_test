/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-08 15:52:51
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-25 17:40:56
 * @FilePath: \EIDE (工作区)e:\ZL\Git_Clone\EW_test_breath\APP\Src\YM_uart.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_uart.h"
#include "YM_rgb.h"

volatile uint8_t rxTimes = 0;
volatile uint8_t rx_ind = 0;
volatile uint8_t UART1RxBuffer[UART1_REC_MAX_LEN];

/**
 * @brief UART1 初始化配置
 * 
 * @param [in] bitRate: 波特率
 * 
 * @return void
 */
void UART1_Init_Config(uint32_t bitRate)
{	
	
	CGC_PER12PeriphClockCmd(CGC_PER12Periph_UART1, ENABLE);
	UART_ConfigRunMode(UART1, bitRate, UART_WLS_8, UART_PARITY_NONE,UART_STOP_BIT_1);
	
//	GPIO_PinAFOutConfig(P24CFG, IO_OUTCFG_P24_TXD1);	
//	GPIO_Init(PORT2, PIN4, OUTPUT);
	
	GPIO_PinAFInConfig(UART1RXDCFG, UART1CFG_P23_RXD);	
	GPIO_Init(PORT2, PIN3, INPUT);

	UART_EnableRBRInt(UART1);
	NVIC_SetPriority(UART1_IRQn, 2);
	NVIC_EnableIRQ(UART1_IRQn);

}

/**
 * @brief 获取UART1接收的数据
 * 
 * @param void
 * 
 * @return void
 */
void get_Uart1_RxData(void)
{
	uint8_t Checksum;
	uint8_t payload[4];
    if(UART1RxBuffer[rx_ind] == SOF)
    {
		
        uint8_t begin_ind = rx_ind;
        for (uint8_t i = 0; i < 4; i++)
		{
			begin_ind++;
			begin_ind &= BUFFER_LEN_MSK;
			payload[i] = UART1RxBuffer[begin_ind];
		}
        begin_ind++;
        begin_ind &= BUFFER_LEN_MSK;
        Checksum = UART1RxBuffer[begin_ind];
        if(Checksum == 0xA5)
        {
			RGB_DataStracture.ColorRGB[Current] = payload[0];
            RGB_DataStracture.ColorRGB[Current] <<= 8;
            RGB_DataStracture.ColorRGB[Current] += payload[1];
            RGB_DataStracture.ColorRGB[Current] <<= 8;
            RGB_DataStracture.ColorRGB[Current] += payload[2];
            RGB_DataStracture.ColorRGB[Current] <<= 8;
            RGB_DataStracture.ColorRGB[Current] += payload[3];
            
            UART1RxBuffer[rx_ind] = 0;
            rx_ind++;
			rx_ind &= BUFFER_LEN_MSK;
            UART1RxBuffer[rx_ind] = 0;
            rx_ind++;
			rx_ind &= BUFFER_LEN_MSK;
            UART1RxBuffer[rx_ind] = 0;
            rx_ind++;
			rx_ind &= BUFFER_LEN_MSK;
            UART1RxBuffer[rx_ind] = 0;
            rx_ind++;
			rx_ind &= BUFFER_LEN_MSK;
            UART1RxBuffer[rx_ind] = 0;
            rx_ind++;
			rx_ind &= BUFFER_LEN_MSK;
            UART1RxBuffer[rx_ind] = 0;
        } 
		
    }
    rx_ind++;
	rx_ind &= BUFFER_LEN_MSK;
}

void UART1_IRQHandler(void)
{
	UART1RxBuffer[rxTimes++] = UART1->RBR;
	if(rxTimes == UART1_REC_MAX_LEN)
		rxTimes = 0;
}