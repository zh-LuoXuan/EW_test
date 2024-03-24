/***********************************************************************************************************************
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : main.c
* Version      :
* Device(s)    : CMS32L032
* Tool-Chain   : MDK(armcc)
* Description  : This file is a template.
* Creation Date: 2022/5/30
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro Definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <stdio.h>
#include "gpio_demo.h"
#include "demo_uart.h"
#include "iica_demo.h"
#include "delay_demo.h"
//#define USING_24C02

#define SLVADDR                                 (0xA0U)


extern volatile uint8_t   g_iica_tx_end;             /* iica0 send data end */
extern volatile uint8_t   g_iica_rx_end;             /* iica0 receive data end */


/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
uint8_t rx_buf[3];


int main()
{
    uint32_t msCnt;     // count value of 1ms
    uint32_t err;
    uint32_t i = 0, j = 100;;
    uint8_t tx_buf[3] = {0xAb, 0x55, 0x5A};
    uint8_t tx_buf1[4] = {0x01, 0xA5, 0x55, 0x5A};

    //-----------------------------------------------------------------------
    // Systick setting
    //-----------------------------------------------------------------------
    SystemCoreClockUpdate();
    msCnt = SystemCoreClock / 1000;
    SysTick_Config(msCnt);
    delay_init(SystemCoreClock); //—” ±≥ı ºªØ

//    UART0_Config();
    Iica0_Init();
//    printf("IICA0 Start\n");
#ifdef USING_24C02
#ifdef I2CA_USING_POLLING/*offer two ways to driver 24C02*/

    I2CA_Master_WriteData(SLVADDR, 0x01, tx_buf, 3);
    delayMS(20);
    I2CA_Master_ReadData(SLVADDR, 0x01, rx_buf, 3);
    delayMS(2);
#else
    IICA_MasterWrite(SLVADDR, tx_buf1, 4, 20);

    while (g_iica_tx_end == 0);

    delayMS(20);

    IICA_MasterWrite(SLVADDR, tx_buf1, 1, 20);

    while (g_iica_tx_end == 0);

    IICA_MasterReceive(SLVADDR, rx_buf, 3, 20);

    while (g_iica_rx_end == 0);

    delayMS(20);

#endif
#else

    while (1)
    {
        IICA_MasterWrite(SLVADDR, tx_buf1, 4, 20);

        while (g_iica_tx_end == 0);

        delayMS(20);

        IICA_MasterWrite(SLVADDR, tx_buf1, 1, 20);

        while (g_iica_tx_end == 0);

        IICA_MasterReceive(SLVADDR, rx_buf, 3, 20);

        while (g_iica_rx_end == 0);

        delayMS(20);
    }

#endif

}





