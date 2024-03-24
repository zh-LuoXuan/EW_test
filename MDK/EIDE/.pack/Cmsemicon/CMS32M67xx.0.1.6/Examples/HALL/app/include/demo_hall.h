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
/** \file demo_div.h
**
**
**
** History:
** - 
*****************************************************************************/
#ifndef __DEMO_HALL_H__
#define __DEMO_HALL_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "hall.h"
#include "cgc.h"
#include "gpio.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/


/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/
typedef struct { 
int32_t	Div_DivA;			  //dividend
int32_t	Div_DivB;				//divisor
int32_t	Div_Result;			//quotient
int32_t	Div_remainder;	//remainder
}Div_Param;


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/

/******************************************************************************
 ** \brief	 HALL_Init
 ** \param [in] DatA£ºDIVALUA £¨dividend£©
 ** \param [in] DatA£ºDIVALUB £¨divisor£©
 **            	
 ** \return  none
 ** \note  
 ******************************************************************************/
void HALL_Init(Div_Param* DIVPar);


#endif /* __DEMO_DIV_H__ */



