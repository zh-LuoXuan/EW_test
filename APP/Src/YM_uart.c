/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-25 12:22:03
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-25 14:40:34
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Template\APP\Src\YM_uart.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_uart.h"


void  UART0_Config(void)
{	
	
	CGC_PER12PeriphClockCmd(CGC_PER12Periph_UART0,ENABLE);
	UART_ConfigRunMode(UART0, 9600, UART_WLS_8, UART_PARITY_NONE,UART_STOP_BIT_1);
	
	GPIO_PinAFOutConfig(P00CFG,IO_OUTCFG_P00_TXD0);	
	GPIO_Init(PORT0,PIN0,OUTPUT);
	
	RESTPinGpio_Set(ENABLE);
	GPIO_PinAFInConfig(UART0RXDCFG,UART0CFG_P01_RXD);	
	GPIO_Init(PORT0,PIN1,INPUT);

}


void Uart0_putchar(char ch)
{
	while(!(UART0->LSR & UART_LSR_THRE_Msk));
	UART0->THR = ch;
}


char Uart0_getchar(void)
{
	while(!(UART0->LSR & UART_LSR_RDR_Msk));
	return  UART0->RBR;
}
