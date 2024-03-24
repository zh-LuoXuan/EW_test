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

/****************************************************************************/
/** \file uart.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "common.h"
#include <stdio.h>
/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/


/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/
#if defined ( __CC_ARM )
struct __FILE { int handle; /* Add whatever you need here */ };
#endif

FILE __stdout;
FILE __stdin;
/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

//#pragma import(__use_no_semihosting_swi)

/*****************************************************************************
 ** \brief	
 **			
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
int fputc(int ch, FILE *f) {
  while(!(UART0->LSR&UART_LSR_THRE_Msk));
  UART0->THR = ch;
  return ch;
}

int fgetc(FILE *f) {
  while(!(UART0->LSR&UART_LSR_RDR_Msk));
  return (UART0->RBR);
}


//void _sys_exit(int return_code) {
//  while (1);    /* endless loop */
//}
















