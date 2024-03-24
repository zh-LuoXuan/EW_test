/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/*****************************************************************************/
/** \file demo_uart.h
**
** History:
** 
*****************************************************************************/
#ifndef __DEMO_UART_H_
#define __DEMO_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "uart.h"
#include "cgc.h"
#include "gpio.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/

							
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/*****************************************************************************
 ** \brief	UART0_Config
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void  UART0_Config(void);

/******************************************************************************
 ** \brief	 Uart0_putchar
 **			  
 ** \param [in] 
 ** \return  none
 ** \note   
*****************************************************************************/
void Uart0_putchar(char ch);

/******************************************************************************
 ** \brief	 Uart0_getchar
 **			 
 ** \param [in] 
 ** \return  
 ** \note   
*****************************************************************************/
char Uart0_getchar(void);


#ifdef __cplusplus
}
#endif

#endif /* __DEMO_UART_H_ */

