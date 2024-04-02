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
/** \file gpio.h
**
** History:
** 
*****************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "common.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
 #define assert_param(expr) ((void)0)
/*----------------------------------------------------------------------------
 **GPIO PORT & PIN
-----------------------------------------------------------------------------*/
typedef enum {
	PORT0 = 0,
	PORT1 = 1,
	PORT2 = 2,	
	PORT3 = 3,
	PORT4 = 4,
	PORT5 = 5,
}PORT_TypeDef;

typedef enum {
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,	
}PIN_TypeDef;

typedef enum {
	INPUT = 0,
	PULLUP_INPUT,
	TTL_INPUT,
	ANALOG_INPUT,
	OUTPUT,
	OPENDRAIN_OUTPUT,
	PULLDOWN_INPUT,
}PIN_ModeDef;

typedef enum
{ 
	GPIO_Control_DIG   = 0, /*!< GPIO Control Digital */
	GPIO_Control_ANA	 = 1, /*!< GPIO Control Analogy  */
}GPIOControl_TypeDef;
#define IS_GPIO_Control(Ctrl) (((Ctrl) == GPIO_Control_ANA)  || ((Ctrl) == GPIO_Control_DIG) )? 1:0

typedef enum
{ 
	GPIO_Mode_OUT  = 0, /*!< GPIO Output Mode */
	GPIO_Mode_IN	 = 1, /*!< GPIO Input Mode */
}GPIOMode_TypeDef;
#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IN)  || ((MODE) == GPIO_Mode_OUT) )? 1:0

typedef enum
{ 
	GPIO_OType_PP = 0,//普通输出
	GPIO_OType_OD = 1 //开漏输出
}GPIOOType_TypeDef;
#define IS_GPIO_OTYPE(OTYPE) (((OTYPE) == GPIO_OType_PP) || ((OTYPE) == GPIO_OType_OD))? 1:0
typedef enum
{ 
	GPIO_PuPd_NOPULL = 0x00,
	GPIO_PuPd_UP     = 0x01,
	GPIO_PuPd_DOWN   = 0x02
}GPIOPuPd_TypeDef;
#define IS_GPIO_PUPD(PUPD) (((PUPD) == GPIO_PuPd_NOPULL) || ((PUPD) == GPIO_PuPd_UP) || \
                            ((PUPD) == GPIO_PuPd_DOWN))? 1:0
typedef enum
{ 
	GPIO_Level_LOW	= 0x00,
	GPIO_Level_HIGH = 0x01,
}GPIOInit_Level;
/*----------------------------------------------------------------------------
 **System  IO复用输出/输入配置
-----------------------------------------------------------------------------*/
/*----------GPIO_P00输出复用-----------------------------------------------*/
#define 	IO_OUTCFG_P00_GPIO			(0x00UL)
#define		IO_OUTCFG_P00_TXD0 		(0x01UL)
#define		IO_OUTCFG_P00_CCP0A			(0x02UL)
#define		IO_OUTCFG_P00_ADCTRIG			(0x03UL)
/*----------GPIO_P00输入复用-----------------------------------------------*/
#define 	IO_INCFG_P00_HALLIN0			(0x00UL)
//#define 	IO_INCFG_P00_RXD0			(0x00UL)

#define 	IO_INCFG_P00_BKIN			(0x00UL)
//#define 	IO_INCFG_P00_ECAP13			(0x00UL)
#define		IO_INCFG_P00_INTP0			(0x00UL)
#define		IO_INCFG_P00_INTP1			(0x00UL)
#define		IO_INCFG_P00_INTP2			(0x00UL)
#define		IO_INCFG_P00_INTP3			(0x00UL)
#define		IO_INCFG_P00_TAU0			(0x00UL)
#define		IO_INCFG_P00_TAU1			(0x00UL)
#define		IO_INCFG_P00_TAU2			(0x00UL)
#define		IO_INCFG_P00_TAU3			(0x00UL)

/*----------GPIO_P01输出复用-----------------------------------------------*/
#define 	IO_OUTCFG_P01_GPIO			(0x00UL)
#define		IO_OUTCFG_P01_TXD0			(0x01UL)
#define		IO_OUTCFG_P01_CCP0B			(0x02UL)
#define		IO_OUTCFG_P01_ADCTRIG			(0x03UL)
/*----------GPIO_P01输入复用-----------------------------------------------*/
#define		IO_INCFG_P01_NRST			(0x00UL)
//#define		IO_INCFG_P01_RXD0			(0x00UL)

#define		IO_INCFG_P01_INTP0			(0x01UL)
#define		IO_INCFG_P01_INTP1			(0x01UL)
#define		IO_INCFG_P01_INTP2			(0x01UL)
#define		IO_INCFG_P01_INTP3			(0x01UL)
#define		IO_INCFG_P01_TAU0			(0x01UL)
#define		IO_INCFG_P01_TAU1			(0x01UL)
#define		IO_INCFG_P01_TAU2			(0x01UL)
#define		IO_INCFG_P01_TAU3			(0x01UL)

/*----------GPIO_P02输出复用-------------------------------------------------*/
//当配置此引脚时，需要配置RSTM
#define 	IO_OUTCFG_P02_GPIO			(0x00UL)
#define 	IO_OUTCFG_P02_HALL750			(0x01UL)
#define		IO_OUTCFG_P02_SSIO			(0x02UL)
#define		IO_OUTCFG_P02_PCBUZ0		(0x03UL)
//#define		IO_OUTCFG_P02_CCP1A_O		(0x04UL)

/*----------GPIO_P02输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P02_CCP0A_I		(0x00UL)
//#define		IO_INCFG_P02_CCP0B_I		(0x00UL)
//#define		IO_INCFG_P02_CCP1A_I		(0x00UL)
//#define		IO_INCFG_P02_CCP1B_I		(0x00UL)
#define		IO_INCFG_P02_INTP0			(0x02UL)
#define		IO_INCFG_P02_INTP1			(0x02UL)
#define		IO_INCFG_P02_INTP2			(0x02UL)
#define		IO_INCFG_P02_INTP3			(0x02UL)
#define		IO_INCFG_P02_TAU0				(0x02UL)
#define		IO_INCFG_P02_TAU1				(0x02UL)
#define		IO_INCFG_P02_TAU2				(0x02UL)
#define		IO_INCFG_P02_TAU3				(0x02UL)

/*----------GPIO_P03输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P03_GPIO			(0x00UL)
#define 	IO_OUTCFG_P03_HALL751			(0x01UL)
#define		IO_OUTCFG_P03_CCP1B			(0x02UL)
//#define		IO_OUTCFG_P03_LPF_ASYN		(0x04UL)
#define		IO_OUTCFG_P03_ADCTRIG			(0x03UL)

/*----------GPIO_P03输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P03_RXD				(0x00UL)
#define		IO_INCFG_P03_INTP0			(0x03UL)
#define		IO_INCFG_P03_INTP1			(0x03UL)
#define		IO_INCFG_P03_INTP2			(0x03UL)
#define		IO_INCFG_P03_INTP3			(0x03UL)
#define		IO_INCFG_P03_TAU0				(0x03UL)
#define		IO_INCFG_P03_TAU1				(0x03UL)
#define		IO_INCFG_P03_TAU2				(0x03UL)
#define		IO_INCFG_P03_TAU3				(0x03UL)

/*----------GPIO_P04输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P04_GPIO			(0x00UL)
#define 	IO_OUTCFG_P04_C0_O			(0x01UL)
#define		IO_OUTCFG_P04_CCP1A			(0x02UL)
#define		IO_OUTCFG_P04_SCL		(0x03UL)
//#define		IO_OUTCFG_P04_CCP1B_O		(0x04UL)
//#define		IO_OUTCFG_P04_SCL			(0x05UL)

/*----------GPIO_P04输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P04_CCP0A_I		(0x01UL)
//#define		IO_INCFG_P04_CCP0B_I		(0x01UL)
//#define		IO_INCFG_P04_CCP1A_I		(0x01UL)
//#define		IO_INCFG_P04_CCP1B_I		(0x01UL)
#define		IO_INCFG_P04_INTP0			(0x04UL)
#define		IO_INCFG_P04_INTP1			(0x04UL)
#define		IO_INCFG_P04_INTP2			(0x04UL)
#define		IO_INCFG_P04_INTP3			(0x04UL)
#define		IO_INCFG_P04_TAU0			(0x04UL)
#define		IO_INCFG_P04_TAU1			(0x04UL)
#define		IO_INCFG_P04_TAU2			(0x04UL)
#define		IO_INCFG_P04_TAU3			(0x04UL)

/*----------GPIO_P05输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P05_GPIO			(0x00UL)
#define		IO_OUTCFG_P05_HALL752		(0x01UL)
#define		IO_OUTCFG_P05_CCP1B			(0x02UL)
#define		IO_OUTCFG_P05_SDA			(0x03UL)
/*----------GPIO_P05输入复用-----------------------------------------------*/
#define		IO_INCFG_P05_INTP0			(0x05UL)
#define		IO_INCFG_P05_INTP1			(0x05UL)
#define		IO_INCFG_P05_INTP2			(0x05UL)
#define		IO_INCFG_P05_INTP3			(0x05UL)
#define		IO_INCFG_P05_TAU0			(0x05UL)
#define		IO_INCFG_P05_TAU1			(0x05UL)
#define		IO_INCFG_P05_TAU2			(0x05UL)
#define		IO_INCFG_P05_TAU3			(0x05UL)


/*----------GPIO_P06输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P06_GPIO			(0x00UL)
#define		IO_OUTCFG_P06_NSS		    (0x01UL)
#define		IO_OUTCFG_P06_CCP0A		    (0x02UL)
#define		IO_OUTCFG_P06_SCL		    (0x03UL)

/*----------GPIO_P06输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P06_CCP0A_I		(0x02UL)
//#define	IO_INCFG_P06_CCP0B_I		(0x02UL)
//#define	IO_INCFG_P06_CCP1A_I		(0x02UL)
//#define	IO_INCFG_P06_CCP1B_I		(0x02UL)
//#define 	IO_INCFG_P06_RXD			(0x01UL)
#define		IO_INCFG_P06_INTP0			(0x06UL)
#define		IO_INCFG_P06_INTP1			(0x06UL)
#define		IO_INCFG_P06_INTP2			(0x06UL)
#define		IO_INCFG_P06_INTP3			(0x06UL)
#define		IO_INCFG_P06_TAU0			(0x06UL)
#define		IO_INCFG_P06_TAU1			(0x06UL)
#define		IO_INCFG_P06_TAU2			(0x06UL)
#define		IO_INCFG_P06_TAU3			(0x06UL)


/*----------GPIO_P07输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P07_GPIO		    (0x00UL)
#define		IO_OUTCFG_P07_SCLK		    (0x01UL)
#define 	IO_OUTCFG_P07_CCP0B		    (0x02UL)
#define		IO_OUTCFG_P07_SDA		    (0x03UL)

/*----------GPIO_P07输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P07_CCP0A_I		(0x03UL)
//#define	IO_INCFG_P07_CCP0B_I		(0x03UL)
//#define	IO_INCFG_P07_CCP1A_I		(0x03UL)
//#define	IO_INCFG_P07_CCP1B_I		(0x03UL)
#define		IO_INCFG_P07_INTP0			(0x07UL)
#define		IO_INCFG_P07_INTP1			(0x07UL)
#define		IO_INCFG_P07_INTP2			(0x07UL)
#define		IO_INCFG_P07_INTP3			(0x07UL)
#define		IO_INCFG_P07_TAU0			(0x07UL)
#define		IO_INCFG_P07_TAU1			(0x07UL)
#define		IO_INCFG_P07_TAU2			(0x07UL)
#define		IO_INCFG_P07_TAU3			(0x07UL)


/*----------GPIO_P10输出复用------------------------------------------------*/
#define 	IO_OUTCFG_P10_GPIO			(0x00UL)
#define 	IO_OUTCFG_P10_MOSI			(0x01UL)
#define 	IO_OUTCFG_P10_PCBUZ1			(0x02UL)
#define 	IO_OUTCFG_P10_HALRAW0			(0x03UL)
/*----------GPIO_P10输入复用-----------------------------------------------*/
#define		IO_INCFG_P10_ADET			(0x10UL)
#define		IO_INCFG_P10_INTP0			(0x10UL)
#define		IO_INCFG_P10_INTP1			(0x10UL)
#define		IO_INCFG_P10_INTP2			(0x10UL)
#define		IO_INCFG_P10_INTP3			(0x10UL)
#define		IO_INCFG_P10_TAU0				(0x10UL)
#define		IO_INCFG_P10_TAU1				(0x10UL)
#define		IO_INCFG_P10_TAU2				(0x10UL)
#define		IO_INCFG_P10_TAU3				(0x10UL)


/*----------GPIO_P11输出复用------------------------------------------------*/
#define 	IO_OUTCFG_P11_GPIO			(0x00UL)
#define		IO_OUTCFG_P11_MISO			(0x01UL)
#define		IO_OUTCFG_P11_CCP1A			(0x02UL)
#define		IO_OUTCFG_P11_C0_O			(0x03UL)
/*----------GPIO_P11输入复用-----------------------------------------------*/
#define		IO_INCFG_P11_INTP0			(0x11UL)
#define		IO_INCFG_P11_INTP1			(0x11UL)
#define		IO_INCFG_P11_INTP2			(0x11UL)
#define		IO_INCFG_P11_INTP3			(0x11UL)
#define		IO_INCFG_P11_TAU0				(0x11UL)
#define		IO_INCFG_P11_TAU1				(0x11UL)
#define		IO_INCFG_P11_TAU2				(0x11UL)
#define		IO_INCFG_P11_TAU3				(0x11UL)


/*----------GPIO_P12输出复用-----------------------------------------------*/
#define 	IO_OUTCFG_P12_GPIO				(0x00UL)
#define		IO_OUTCFG_P12_CCP1B				(0x02UL)
#define		IO_OUTCFG_P12_HALRAW1				(0x03UL)
/*----------GPIO_P12输入复用-----------------------------------------------*/
#define		IO_INCFG_P12_INTP0			(0x12UL)
#define		IO_INCFG_P12_INTP1			(0x12UL)
#define		IO_INCFG_P12_INTP2			(0x12UL)
#define		IO_INCFG_P12_INTP3			(0x12UL)
#define		IO_INCFG_P12_TAU0				(0x12UL)
#define		IO_INCFG_P12_TAU1				(0x12UL)
#define		IO_INCFG_P12_TAU2				(0x12UL)
#define		IO_INCFG_P12_TAU3				(0x12UL)


/*----------GPIO_P13输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P13_GPIO			(0x00UL)
#define		IO_OUTCFG_P13_PCBUZ1			(0x02UL)
#define		IO_OUTCFG_P13_HALRW2			(0x03UL)
/*----------GPIO_P13输入复用-----------------------------------------------*/
//#define		IO_INCFG_P13_BKIN			(0x0UL)
#define		IO_INCFG_P13_INTP0			(0x13UL)
#define		IO_INCFG_P13_INTP1			(0x13UL)
#define		IO_INCFG_P13_INTP2			(0x13UL)
#define		IO_INCFG_P13_INTP3			(0x13UL)
#define		IO_INCFG_P13_TAU0				(0x13UL)
#define		IO_INCFG_P13_TAU1				(0x13UL)
#define		IO_INCFG_P13_TAU2				(0x13UL)
#define		IO_INCFG_P13_TAU3				(0x13UL)


/*----------GPIO_P14输出复用--------------------------------------------------*/
#define 	IO_OUTCFG_P14_GPIO			(0x00UL)
#define		IO_OUTCFG_P14_MISO		(0x01UL)
#define		IO_OUTCFG_P14_TXD0			(0x02UL)
#define		IO_OUTCFG_P14_SCL			(0x03UL)
/*----------GPIO_P14输入复用-----------------------------------------------*/
#define		IO_INCFG_P14_INTP0			(0x14UL)
#define		IO_INCFG_P14_INTP1			(0x14UL)
#define		IO_INCFG_P14_INTP2			(0x14UL)
#define		IO_INCFG_P14_INTP3			(0x14UL)
#define		IO_INCFG_P14_TAU0				(0x14UL)
#define		IO_INCFG_P14_TAU1				(0x14UL)
#define		IO_INCFG_P14_TAU2				(0x14UL)
#define		IO_INCFG_P14_TAU3				(0x14UL)


/*----------GPIO_P15输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P15_GPIO			(0x00UL)
#define		IO_OUTCFG_P15_MOSI			(0x01UL)
#define		IO_OUTCFG_P15_TXD0			(0x02UL)
#define		IO_OUTCFG_P15_SDA			(0x03UL)
/*----------GPIO_P15输入复用-----------------------------------------------*/
//#define		IO_INCFG_P15_RXD0			(0x0UL)
#define		IO_INCFG_P15_INTP0			(0x15UL)
#define		IO_INCFG_P15_INTP1			(0x15UL)
#define		IO_INCFG_P15_INTP2			(0x15UL)
#define		IO_INCFG_P15_INTP3			(0x15UL)
#define		IO_INCFG_P15_TAU0				(0x15UL)
#define		IO_INCFG_P15_TAU1				(0x15UL)
#define		IO_INCFG_P15_TAU2				(0x15UL)
#define		IO_INCFG_P15_TAU3				(0x15UL)


/*----------GPIO_P16输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P16_GPIO			(0x00UL)
#define		IO_OUTCFG_P16_SCLK			(0x01UL)
#define		IO_OUTCFG_P16_TXD0			(0x02UL)
#define		IO_OUTCFG_P16_HALCLKO			(0x03UL)
/*----------GPIO_P16输入复用-----------------------------------------------*/
//#define		IO_INCFG_P16_BKIN			(0x0UL)
//#define		IO_INCFG_P16_RXD0			(0x0UL)
#define		IO_INCFG_P16_INTP0			(0x16UL)
#define		IO_INCFG_P16_INTP1			(0x16UL)
#define		IO_INCFG_P16_INTP2			(0x16UL)
#define		IO_INCFG_P16_INTP3			(0x16UL)
#define		IO_INCFG_P16_TAU0				(0x16UL)
#define		IO_INCFG_P16_TAU1				(0x16UL)
#define		IO_INCFG_P16_TAU2				(0x16UL)
#define		IO_INCFG_P16_TAU3				(0x16UL)

/*----------GPIO_P17输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P17_GPIO			(0x00UL)
#define		IO_OUTCFG_P17_NSS			(0x01UL)
#define		IO_OUTCFG_P17_ADCTRIG1			(0x02UL)
#define		IO_OUTCFG_P17_ADCTRIG			(0x03UL)
/*----------GPIO_P17输入复用-----------------------------------------------*/
#define		IO_INCFG_P17_INTP0			(0x17UL)
#define		IO_INCFG_P17_INTP1			(0x17UL)
#define		IO_INCFG_P17_INTP2			(0x17UL)
#define		IO_INCFG_P17_INTP3			(0x17UL)
#define		IO_INCFG_P17_TAU0				(0x17UL)
#define		IO_INCFG_P17_TAU1				(0x17UL)
#define		IO_INCFG_P17_TAU2				(0x17UL)
#define		IO_INCFG_P17_TAU3				(0x17UL)

/*----------GPIO_P20输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P20_GPIO			(0x00UL)
#define 	IO_OUTCFG_P20_ADCTRIG1			(0x02UL)
/*----------GPIO_P20输入复用-----------------------------------------------*/
#define		IO_INCFG_P20_HALLIN0			(0x01UL)
#define		IO_INCFG_P20_INTP0			(0x20UL)
#define		IO_INCFG_P20_INTP1			(0x20UL)
#define		IO_INCFG_P20_INTP2			(0x20UL)
#define		IO_INCFG_P20_INTP3			(0x20UL)
#define		IO_INCFG_P20_TAU0				(0x20UL)
#define		IO_INCFG_P20_TAU1				(0x20UL)
#define		IO_INCFG_P20_TAU2				(0x20UL)
#define		IO_INCFG_P20_TAU3				(0x20UL)


/*----------GPIO_P21输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P21_GPIO			(0x00UL)
#define 	IO_OUTCFG_P21_T0O			(0x01UL)
#define 	IO_OUTCFG_P21_T1O			(0x02UL)
#define 	IO_OUTCFG_P21_ADCTRIG			(0x03UL)
/*----------GPIO_P21输入复用-----------------------------------------------*/
#define		IO_INCFG_P21_HALLIN1			(0x0UL)
#define		IO_INCFG_P21_INTP0			(0x21UL)
#define		IO_INCFG_P21_INTP1			(0x21UL)
#define		IO_INCFG_P21_INTP2			(0x21UL)
#define		IO_INCFG_P21_INTP3			(0x21UL)
#define		IO_INCFG_P21_TAU0				(0x21UL)
#define		IO_INCFG_P21_TAU1				(0x21UL)
#define		IO_INCFG_P21_TAU2				(0x21UL)
#define		IO_INCFG_P21_TAU3				(0x21UL)


/*----------GPIO_P22输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P22_GPIO			(0x00UL)
#define 	IO_OUTCFG_P22_T2O			(0x01UL)
#define 	IO_OUTCFG_P22_T3O			(0x02UL)
#define 	IO_OUTCFG_P22_ADCTRIG			(0x03UL)
/*----------GPIO_P22输入复用-----------------------------------------------*/
#define		IO_INCFG_P22_HALLIN2			(0x0UL)
#define		IO_INCFG_P22_INTP0			(0x22UL)
#define		IO_INCFG_P22_INTP1			(0x22UL)
#define		IO_INCFG_P22_INTP2			(0x22UL)
#define		IO_INCFG_P22_INTP3			(0x22UL)
#define		IO_INCFG_P22_TAU0				(0x22UL)
#define		IO_INCFG_P22_TAU1				(0x22UL)
#define		IO_INCFG_P22_TAU2				(0x22UL)
#define		IO_INCFG_P22_TAU3				(0x22UL)


/*----------GPIO_P23输出复用-----------------------------------------------*/
#define 	IO_OUTCFG_P23_GPIO			(0x00UL)
#define		IO_OUTCFG_P23_TXD1		(0x01UL)
#define		IO_OUTCFG_P23_CCP0B		(0x02UL)
#define		IO_OUTCFG_P23_C1_O		(0x03UL)
/*----------GPIO_P23输入复用-----------------------------------------------*/
//#define		IO_INCFG_P23_BKIN			(0x0UL)
//#define		IO_INCFG_P23_RXD1			(0x0UL)
#define		IO_INCFG_P23_INTP0			(0x23UL)
#define		IO_INCFG_P23_INTP1			(0x23UL)
#define		IO_INCFG_P23_INTP2			(0x23UL)
#define		IO_INCFG_P23_INTP3			(0x23UL)
#define		IO_INCFG_P23_TAU0				(0x23UL)
#define		IO_INCFG_P23_TAU1				(0x23UL)
#define		IO_INCFG_P23_TAU2				(0x23UL)
#define		IO_INCFG_P23_TAU3				(0x23UL)


/*----------GPIO_P24输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P24_GPIO			(0x00UL)
#define		IO_OUTCFG_P24_TXD1		(0x01UL)
#define		IO_OUTCFG_P24_CCP0A		(0x02UL)
#define		IO_OUTCFG_P24_ADCTRIG		(0x03UL)
/*----------GPIO_P24输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P24_RXD1			(0x00UL)
#define		IO_INCFG_P24_INTP0			(0x24UL)
#define		IO_INCFG_P24_INTP1			(0x24UL)
#define		IO_INCFG_P24_INTP2			(0x24UL)
#define		IO_INCFG_P24_INTP3			(0x24UL)
#define		IO_INCFG_P24_TAU0				(0x24UL)
#define		IO_INCFG_P24_TAU1				(0x24UL)
#define		IO_INCFG_P24_TAU2				(0x24UL)
#define		IO_INCFG_P24_TAU3				(0x24UL)


/*----------GPIO_P25输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P25_GPIO			(0x00UL)
#define 	IO_OUTCFG_P25_TXD1			(0x01UL)
#define 	IO_OUTCFG_P25_CCP1A			(0x02UL)
#define 	IO_OUTCFG_P25_C1_O			(0x03UL)
/*----------GPIO_P25输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P25_RXD1			(0x00UL)
#define		IO_INCFG_P25_INTP0			(0x25UL)
#define		IO_INCFG_P25_INTP1			(0x25UL)
#define		IO_INCFG_P25_INTP2			(0x25UL)
#define		IO_INCFG_P25_INTP3			(0x25UL)
#define		IO_INCFG_P25_TAU0				(0x25UL)
#define		IO_INCFG_P25_TAU1				(0x25UL)
#define		IO_INCFG_P25_TAU2				(0x25UL)
#define		IO_INCFG_P25_TAU3				(0x25UL)


///*----------GPIO_P26输出复用-------------------------------------------------*/
//#define 	IO_OUTCFG_P26_GPIO			(0x00UL)
//#define 	IO_OUTCFG_P26_C1_O			(0x01UL)
//#define		IO_OUTCFG_P26_CCP0A_O		(0x03UL)
//#define		IO_OUTCFG_P26_CCP1A_O		(0x04UL)

///*----------GPIO_P26输入复用-----------------------------------------------*/
//#define 	IO_INCFG_P26_BKIN			(0x02UL)
//#define 	IO_INCFG_P26_CCP0A_I		(0x04UL)
//#define		IO_INCFG_P26_CCP0B_I		(0x04UL)
//#define		IO_INCFG_P26_CCP1A_I		(0x04UL)
//#define		IO_INCFG_P26_CCP1B_I		(0x04UL)
//#define		IO_INCFG_P26_INTP0			(0x26UL)
//#define		IO_INCFG_P26_INTP1			(0x26UL)
//#define		IO_INCFG_P26_INTP2			(0x26UL)
//#define		IO_INCFG_P26_INTP3			(0x26UL)
//#define		IO_INCFG_P26_TAU0				(0x26UL)
//#define		IO_INCFG_P26_TAU1				(0x26UL)
//#define		IO_INCFG_P26_TAU2				(0x26UL)
//#define		IO_INCFG_P26_TAU3				(0x26UL)


///*----------GPIO_P27输出复用--------------------------------------------------*/
//#define 	IO_OUTCFG_P27_GPIO			(0x00UL)

///*----------GPIO_P27输入复用-----------------------------------------------*/
//#define		IO_INCFG_P27_INTP0			(0x27UL)
//#define		IO_INCFG_P27_INTP1			(0x27UL)
//#define		IO_INCFG_P27_INTP2			(0x27UL)
//#define		IO_INCFG_P27_INTP3			(0x27UL)
//#define		IO_INCFG_P27_TAU0				(0x27UL)
//#define		IO_INCFG_P27_TAU1				(0x27UL)
//#define		IO_INCFG_P27_TAU2				(0x27UL)
//#define		IO_INCFG_P27_TAU3				(0x27UL)

/*----------GPIO_P30输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P30_GPIO			(0x00UL)
#define 	IO_OUTCFG_P30_HALFIL2IN0			(0x03UL)
/*----------GPIO_P30输入复用-----------------------------------------------*/
#define		IO_INCFG_P30_INTP0			(0x30UL)
#define		IO_INCFG_P30_INTP1			(0x30UL)
#define		IO_INCFG_P30_INTP2			(0x30UL)
#define		IO_INCFG_P30_INTP3			(0x30UL)
#define		IO_INCFG_P30_TAU0				(0x30UL)
#define		IO_INCFG_P30_TAU1				(0x30UL)
#define		IO_INCFG_P30_TAU2				(0x30UL)
#define		IO_INCFG_P30_TAU3				(0x30UL)

/*----------GPIO_P31输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P31_GPIO			(0x00UL)
#define 	IO_OUTCFG_P31_HALFIL2IN1			(0x03UL)
/*----------GPIO_P31输入复用-----------------------------------------------*/
#define		IO_INCFG_P31_INTP0			(0x31UL)
#define		IO_INCFG_P31_INTP1			(0x31UL)
#define		IO_INCFG_P31_INTP2			(0x31UL)
#define		IO_INCFG_P31_INTP3			(0x31UL)
#define		IO_INCFG_P31_TAU0				(0x31UL)
#define		IO_INCFG_P31_TAU1				(0x31UL)
#define		IO_INCFG_P31_TAU2				(0x31UL)
#define		IO_INCFG_P31_TAU3				(0x31UL)

/*----------GPIO_P32输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P32_GPIO			(0x00UL)
#define 	IO_OUTCFG_P32_HALFIL2IN2			(0x03UL)
/*----------GPIO_P32输入复用-----------------------------------------------*/
#define		IO_INCFG_P32_INTP0			(0x32UL)
#define		IO_INCFG_P32_INTP1			(0x32UL)
#define		IO_INCFG_P32_INTP2			(0x32UL)
#define		IO_INCFG_P32_INTP3			(0x32UL)
#define		IO_INCFG_P32_TAU0				(0x32UL)
#define		IO_INCFG_P32_TAU1				(0x32UL)
#define		IO_INCFG_P32_TAU2				(0x32UL)
#define		IO_INCFG_P32_TAU3				(0x32UL)

/*----------GPIO_P33输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P33_GPIO			(0x00UL)
#define 	IO_OUTCFG_P33_HALCKO			(0x03UL)
/*----------GPIO_P33输入复用-----------------------------------------------*/
#define		IO_INCFG_P33_INTP0			(0x33UL)
#define		IO_INCFG_P33_INTP1			(0x33UL)
#define		IO_INCFG_P33_INTP2			(0x33UL)
#define		IO_INCFG_P33_INTP3			(0x33UL)
#define		IO_INCFG_P33_TAU0				(0x33UL)
#define		IO_INCFG_P33_TAU1				(0x33UL)
#define		IO_INCFG_P33_TAU2				(0x33UL)
#define		IO_INCFG_P33_TAU3				(0x33UL)

/*----------GPIO_P34输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P34_GPIO			(0x00UL)
#define 	IO_OUTCFG_P34_TXD0			(0x01UL)
#define 	IO_OUTCFG_P34_T0O			(0x02UL)
#define 	IO_OUTCFG_P34_SDA			(0x03UL)
/*----------GPIO_P34输入复用-----------------------------------------------*/
//#define		IO_INCFG_P34_RXD0			(0x0UL)
#define		IO_INCFG_P34_INTP0			(0x34UL)
#define		IO_INCFG_P34_INTP1			(0x34UL)
#define		IO_INCFG_P34_INTP2			(0x34UL)
#define		IO_INCFG_P34_INTP3			(0x34UL)
#define		IO_INCFG_P34_TAU0				(0x34UL)
#define		IO_INCFG_P34_TAU1				(0x34UL)
#define		IO_INCFG_P34_TAU2				(0x34UL)
#define		IO_INCFG_P34_TAU3				(0x34UL)

/*----------GPIO_P35输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P35_GPIO			(0x00UL)
#define 	IO_OUTCFG_P35_TXD0			(0x01UL)
#define 	IO_OUTCFG_P35_T1O			(0x02UL)
#define 	IO_OUTCFG_P35_SCL			(0x03UL)
/*----------GPIO_P35输入复用-----------------------------------------------*/
//#define		IO_INCFG_P35_RXD0			(0x0UL)
#define		IO_INCFG_P35_INTP0			(0x35UL)
#define		IO_INCFG_P35_INTP1			(0x35UL)
#define		IO_INCFG_P35_INTP2			(0x35UL)
#define		IO_INCFG_P35_INTP3			(0x35UL)
#define		IO_INCFG_P35_TAU0				(0x35UL)
#define		IO_INCFG_P35_TAU1				(0x35UL)
#define		IO_INCFG_P35_TAU2				(0x35UL)
#define		IO_INCFG_P35_TAU3				(0x35UL)

/*----------GPIO_P36输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P36_GPIO			(0x00UL)
#define 	IO_OUTCFG_P36_EPWM0			(0x01UL)
#define 	IO_OUTCFG_P36_T2O			(0x02UL)
#define 	IO_OUTCFG_P36_HALRAW0			(0x03UL)
/*----------GPIO_P36输入复用-----------------------------------------------*/
#define		IO_INCFG_P36_INTP0			(0x36UL)
#define		IO_INCFG_P36_INTP1			(0x36UL)
#define		IO_INCFG_P36_INTP2			(0x36UL)
#define		IO_INCFG_P36_INTP3			(0x36UL)
#define		IO_INCFG_P36_TAU0				(0x36UL)
#define		IO_INCFG_P36_TAU1				(0x36UL)
#define		IO_INCFG_P36_TAU2				(0x36UL)
#define		IO_INCFG_P36_TAU3				(0x36UL)

/*----------GPIO_P37输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P37_GPIO			(0x00UL)
#define 	IO_OUTCFG_P37_EPWM1			(0x01UL)
#define 	IO_OUTCFG_P37_T3O			(0x02UL)
#define 	IO_OUTCFG_P37_HALRAW1			(0x03UL)
/*----------GPIO_P37输入复用-----------------------------------------------*/
#define		IO_INCFG_P37_INTP0			(0x37UL)
#define		IO_INCFG_P37_INTP1			(0x37UL)
#define		IO_INCFG_P37_INTP2			(0x37UL)
#define		IO_INCFG_P37_INTP3			(0x37UL)
#define		IO_INCFG_P37_TAU0				(0x37UL)
#define		IO_INCFG_P37_TAU1				(0x37UL)
#define		IO_INCFG_P37_TAU2				(0x37UL)
#define		IO_INCFG_P37_TAU3				(0x37UL)

/*----------GPIO_P40输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P40_GPIO			(0x00UL)
#define 	IO_OUTCFG_P40_EPWM2			(0x01UL)
#define 	IO_OUTCFG_P40_C0_O1			(0x02UL)
#define 	IO_OUTCFG_P40_HALRAW2			(0x03UL)
/*----------GPIO_P40输入复用-----------------------------------------------*/
#define		IO_INCFG_P40_INTP0			(0x40UL)
#define		IO_INCFG_P40_INTP1			(0x40UL)
#define		IO_INCFG_P40_INTP2			(0x40UL)
#define		IO_INCFG_P40_INTP3			(0x40UL)
#define		IO_INCFG_P40_TAU0				(0x40UL)
#define		IO_INCFG_P40_TAU1				(0x40UL)
#define		IO_INCFG_P40_TAU2				(0x40UL)
#define		IO_INCFG_P40_TAU3				(0x40UL)

/*----------GPIO_P41输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P41_GPIO			(0x00UL)
#define 	IO_OUTCFG_P41_EPWM3			(0x01UL)
#define 	IO_OUTCFG_P41_C0_O1			(0x02UL)
#define 	IO_OUTCFG_P41_HALFIL750			(0x03UL)
/*----------GPIO_P41输入复用-----------------------------------------------*/
#define		IO_INCFG_P41_INTP0			(0x41UL)
#define		IO_INCFG_P41_INTP1			(0x41UL)
#define		IO_INCFG_P41_INTP2			(0x41UL)
#define		IO_INCFG_P41_INTP3			(0x41UL)
#define		IO_INCFG_P41_TAU0				(0x41UL)
#define		IO_INCFG_P41_TAU1				(0x41UL)
#define		IO_INCFG_P41_TAU2				(0x41UL)
#define		IO_INCFG_P41_TAU3				(0x41UL)

/*----------GPIO_P42输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P42_GPIO			(0x00UL)
#define 	IO_OUTCFG_P42_EPWM4			(0x01UL)
#define 	IO_OUTCFG_P42_C0_O1			(0x02UL)
#define 	IO_OUTCFG_P42_HALFIL751			(0x03UL)
/*----------GPIO_P42输入复用-----------------------------------------------*/
#define		IO_INCFG_P42_INTP0			(0x42UL)
#define		IO_INCFG_P42_INTP1			(0x42UL)
#define		IO_INCFG_P42_INTP2			(0x42UL)
#define		IO_INCFG_P42_INTP3			(0x42UL)
#define		IO_INCFG_P42_TAU0				(0x42UL)
#define		IO_INCFG_P42_TAU1				(0x42UL)
#define		IO_INCFG_P42_TAU2				(0x42UL)
#define		IO_INCFG_P42_TAU3				(0x42UL)

/*----------GPIO_P43输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P43_GPIO			(0x00UL)
#define 	IO_OUTCFG_P43_EPWM5			(0x01UL)
#define 	IO_OUTCFG_P43_C0_O1			(0x02UL)
#define 	IO_OUTCFG_P43_HALFIL752			(0x03UL)
/*----------GPIO_P43输入复用-----------------------------------------------*/
#define		IO_INCFG_P43_INTP0			(0x43UL)
#define		IO_INCFG_P43_INTP1			(0x43UL)
#define		IO_INCFG_P43_INTP2			(0x43UL)
#define		IO_INCFG_P43_INTP3			(0x43UL)
#define		IO_INCFG_P43_TAU0				(0x43UL)
#define		IO_INCFG_P43_TAU1				(0x43UL)
#define		IO_INCFG_P43_TAU2				(0x43UL)
#define		IO_INCFG_P43_TAU3				(0x43UL)

/*----------GPIO_P44输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P44_GPIO			(0x00UL)
#define 	IO_OUTCFG_P44_EPWM6			(0x01UL)
#define 	IO_OUTCFG_P44_HALFIL2IN0			(0x03UL)
/*----------GPIO_P44输入复用-----------------------------------------------*/
#define		IO_INCFG_P44_INTP0			(0x44UL)
#define		IO_INCFG_P44_INTP1			(0x44UL)
#define		IO_INCFG_P44_INTP2			(0x44UL)
#define		IO_INCFG_P44_INTP3			(0x44UL)
#define		IO_INCFG_P44_TAU0				(0x44UL)
#define		IO_INCFG_P44_TAU1				(0x44UL)
#define		IO_INCFG_P44_TAU2				(0x44UL)
#define		IO_INCFG_P44_TAU3				(0x44UL)

/*----------GPIO_P45输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P45_GPIO			(0x00UL)
#define 	IO_OUTCFG_P45_EPWM7			(0x01UL)
#define 	IO_OUTCFG_P45_HALFIL2IN1			(0x03UL)
/*----------GPIO_P45输入复用-----------------------------------------------*/
#define		IO_INCFG_P45_INTP0			(0x45UL)
#define		IO_INCFG_P45_INTP1			(0x45UL)
#define		IO_INCFG_P45_INTP2			(0x45UL)
#define		IO_INCFG_P45_INTP3			(0x45UL)
#define		IO_INCFG_P45_TAU0				(0x45UL)
#define		IO_INCFG_P45_TAU1				(0x45UL)
#define		IO_INCFG_P45_TAU2				(0x45UL)
#define		IO_INCFG_P45_TAU3				(0x45UL)

/*----------GPIO_P46输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P46_GPIO			(0x00UL)
#define 	IO_OUTCFG_P46_HALFIL2IN2			(0x03UL)
/*----------GPIO_P46输入复用-----------------------------------------------*/
#define		IO_INCFG_P46_INTP0			(0x46UL)
#define		IO_INCFG_P46_INTP1			(0x46UL)
#define		IO_INCFG_P46_INTP2			(0x46UL)
#define		IO_INCFG_P46_INTP3			(0x46UL)
#define		IO_INCFG_P46_TAU0				(0x46UL)
#define		IO_INCFG_P46_TAU1				(0x46UL)
#define		IO_INCFG_P46_TAU2				(0x46UL)
#define		IO_INCFG_P46_TAU3				(0x46UL)

/*----------GPIO_P47输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P47_GPIO			(0x00UL)
#define 	IO_OUTCFG_P47_HALCLKO			(0x03UL)
/*----------GPIO_P47输入复用-----------------------------------------------*/
#define		IO_INCFG_P47_INTP0			(0x47UL)
#define		IO_INCFG_P47_INTP1			(0x47UL)
#define		IO_INCFG_P47_INTP2			(0x47UL)
#define		IO_INCFG_P47_INTP3			(0x47UL)
#define		IO_INCFG_P47_TAU0				(0x47UL)
#define		IO_INCFG_P47_TAU1				(0x47UL)
#define		IO_INCFG_P47_TAU2				(0x47UL)
#define		IO_INCFG_P47_TAU3				(0x47UL)

/*----------GPIO_P50输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P50_GPIO			(0x00UL)
/*----------GPIO_P50输入复用-----------------------------------------------*/
#define		IO_INCFG_P50_INTP0			(0x50UL)
#define		IO_INCFG_P50_INTP1			(0x50UL)
#define		IO_INCFG_P50_INTP2			(0x50UL)
#define		IO_INCFG_P50_INTP3			(0x50UL)
#define		IO_INCFG_P50_TAU0				(0x50UL)
#define		IO_INCFG_P50_TAU1				(0x50UL)
#define		IO_INCFG_P50_TAU2				(0x50UL)
#define		IO_INCFG_P50_TAU3				(0x50UL)

/*----------GPIO_P51输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P51_GPIO			(0x00UL)
#define 	IO_OUTCFG_P51_HALFDT0			(0x03UL)
/*----------GPIO_P51输入复用-----------------------------------------------*/
#define		IO_INCFG_P51_INTP0			(0x51UL)
#define		IO_INCFG_P51_INTP1			(0x51UL)
#define		IO_INCFG_P51_INTP2			(0x51UL)
#define		IO_INCFG_P51_INTP3			(0x51UL)
#define		IO_INCFG_P51_TAU0				(0x51UL)
#define		IO_INCFG_P51_TAU1				(0x51UL)
#define		IO_INCFG_P51_TAU2				(0x51UL)
#define		IO_INCFG_P51_TAU3				(0x51UL)

/*----------GPIO_P52输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P52_GPIO			(0x00UL)
#define 	IO_OUTCFG_P52_T0O		(0x01UL)
#define 	IO_OUTCFG_P52_CCP0B			(0x02UL)
#define 	IO_OUTCFG_P52_HALFDT1			(0x03UL)
/*----------GPIO_P52输入复用-----------------------------------------------*/
#define		IO_INCFG_P52_INTP0			(0x52UL)
#define		IO_INCFG_P52_INTP1			(0x52UL)
#define		IO_INCFG_P52_INTP2			(0x52UL)
#define		IO_INCFG_P52_INTP3			(0x52UL)
#define		IO_INCFG_P52_TAU0				(0x52UL)
#define		IO_INCFG_P52_TAU1				(0x52UL)
#define		IO_INCFG_P52_TAU2				(0x52UL)
#define		IO_INCFG_P52_TAU3				(0x52UL)

/*----------GPIO_P53输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P53_GPIO			(0x00UL)
#define 	IO_OUTCFG_P53_TXD1		(0x01UL)
#define 	IO_OUTCFG_P53_CCP1B			(0x02UL)
#define 	IO_OUTCFG_P53_HALFDT2			(0x03UL)
/*----------GPIO_P53输入复用-----------------------------------------------*/
//#define		IO_INCFG_P53_RXD1			(0x0UL)
#define		IO_INCFG_P53_INTP0			(0x53UL)
#define		IO_INCFG_P53_INTP1			(0x53UL)
#define		IO_INCFG_P53_INTP2			(0x53UL)
#define		IO_INCFG_P53_INTP3			(0x53UL)
#define		IO_INCFG_P53_TAU0				(0x53UL)
#define		IO_INCFG_P53_TAU1				(0x53UL)
#define		IO_INCFG_P53_TAU2				(0x53UL)
#define		IO_INCFG_P53_TAU3				(0x53UL)

/*----------GPIO_P54输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P54_GPIO			(0x00UL)
#define 	IO_OUTCFG_P54_TXD1		(0x01UL)
#define 	IO_OUTCFG_P54_SCL			(0x03UL)
/*----------GPIO_P54输入复用-----------------------------------------------*/
//#define		IO_INCFG_P54_RXD1			(0x0UL)
#define		IO_INCFG_P54_INTP0			(0x54UL)
#define		IO_INCFG_P54_INTP1			(0x54UL)
#define		IO_INCFG_P54_INTP2			(0x54UL)
#define		IO_INCFG_P54_INTP3			(0x54UL)
#define		IO_INCFG_P54_TAU0				(0x54UL)
#define		IO_INCFG_P54_TAU1				(0x54UL)
#define		IO_INCFG_P54_TAU2				(0x54UL)
#define		IO_INCFG_P54_TAU3				(0x54UL)

/*----------GPIO_P55输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P55_GPIO			(0x00UL)
#define 	IO_OUTCFG_P55_TXD1		(0x01UL)
#define 	IO_OUTCFG_P55_SDA			(0x03UL)
/*----------GPIO_P54输入复用-----------------------------------------------*/
//#define		IO_INCFG_P55_BKIN			(0x0UL)
//#define		IO_INCFG_P55_RXD1			(0x0UL)
#define		IO_INCFG_P55_INTP0			(0x55UL)
#define		IO_INCFG_P55_INTP1			(0x55UL)
#define		IO_INCFG_P55_INTP2			(0x55UL)
#define		IO_INCFG_P55_INTP3			(0x55UL)
#define		IO_INCFG_P55_TAU0				(0x55UL)
#define		IO_INCFG_P55_TAU1				(0x55UL)
#define		IO_INCFG_P55_TAU2				(0x55UL)
#define		IO_INCFG_P55_TAU3				(0x55UL)

/*----------GPIO_P56输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P56_GPIO			(0x00UL)
#define 	IO_OUTCFG_P56_PCBUZ0		(0x01UL)
#define 	IO_OUTCFG_P56_CCP1A			(0x02UL)
#define 	IO_OUTCFG_P56_T0O			(0x03UL)
/*----------GPIO_P56输入复用-----------------------------------------------*/
#define		IO_INCFG_P56_HALLIN2			(0x01UL)
#define		IO_INCFG_P56_INTP0			(0x56UL)
#define		IO_INCFG_P56_INTP1			(0x56UL)
#define		IO_INCFG_P56_INTP2			(0x56UL)
#define		IO_INCFG_P56_INTP3			(0x56UL)
#define		IO_INCFG_P56_TAU0				(0x56UL)
#define		IO_INCFG_P56_TAU1				(0x56UL)
#define		IO_INCFG_P56_TAU2				(0x56UL)
#define		IO_INCFG_P56_TAU3				(0x56UL)

/*----------GPIO_P57输出复用-------------------------------------------------*/
#define 	IO_OUTCFG_P57_GPIO			(0x00UL)
#define 	IO_OUTCFG_P57_PCBUZ1		(0x01UL)
#define 	IO_OUTCFG_P57_CCP1B			(0x02UL)
#define 	IO_OUTCFG_P57_T1O			(0x03UL)
/*----------GPIO_P57输入复用-----------------------------------------------*/
#define		IO_INCFG_P57_HALLIN1			(0x01UL)
#define		IO_INCFG_P57_INTP0			(0x57UL)
#define		IO_INCFG_P57_INTP1			(0x57UL)
#define		IO_INCFG_P57_INTP2			(0x57UL)
#define		IO_INCFG_P57_INTP3			(0x57UL)
#define		IO_INCFG_P57_TAU0				(0x57UL)
#define		IO_INCFG_P57_TAU1				(0x57UL)
#define		IO_INCFG_P57_TAU2				(0x57UL)
#define		IO_INCFG_P57_TAU3				(0x57UL)

/*----------UART0RXD引脚复用-------------------------------------------------------*/
#define		UART0CFG_P00_RXD				(0x00UL)
#define		UART0CFG_P01_RXD				(0x01UL)
#define		UART0CFG_P15_RXD				(0x02UL)
#define		UART0CFG_P16_RXD				(0x03UL)
#define		UART0CFG_P34_RXD				(0x04UL)
#define		UART0CFG_P35_RXD				(0x05UL)

/*----------UART1RXD引脚复用-------------------------------------------------------*/
#define		UART1CFG_P23_RXD				(0x00UL)
#define		UART1CFG_P24_RXD				(0x01UL)
#define		UART1CFG_P25_RXD				(0x02UL)
#define		UART1CFG_P53_RXD				(0x03UL)
#define		UART1CFG_P54_RXD				(0x04UL)
#define		UART1CFG_P55_RXD				(0x05UL)

/*----------PWMBKIN引脚复用-------------------------------------------------------*/
#define		PWMCFG_P13_BKIN				(0x00UL)
#define		PWMCFG_P16_BKIN				(0x01UL)
#define		PWMCFG_P23_BKIN				(0x02UL)
#define		PWMCFG_P55_BKIN				(0x03UL)

/*----------CCP0A引脚复用-------------------------------------------------------*/
#define		CCP0ACFG_P00				(0x00UL)
#define		CCP0ACFG_P06				(0x01UL)
#define		CCP0ACFG_P24				(0x02UL)

/*----------CCP0B引脚复用-------------------------------------------------------*/
#define		CCP0BCFG_P01				(0x00UL)
#define		CCP0BCFG_P07				(0x01UL)
#define		CCP0BCFG_P23				(0x02UL)
#define		CCP0BCFG_P52				(0x03UL)

/*----------CCP1A引脚复用-------------------------------------------------------*/
#define		CCP1ACFG_P02				(0x00UL)
#define		CCP1ACFG_P04				(0x01UL)
#define		CCP1ACFG_P11				(0x02UL)
#define		CCP1ACFG_P25				(0x03UL)
#define		CCP1ACFG_P56				(0x04UL)

/*----------CCP1B引脚复用-------------------------------------------------------*/
#define		CCP1BCFG_P03				(0x00UL)
#define		CCP1BCFG_P05				(0x01UL)
#define		CCP1BCFG_P12				(0x02UL)
#define		CCP1BCFG_P53				(0x03UL)
#define		CCP1BCFG_P57				(0x04UL)

/*----------HALL0引脚复用-------------------------------------------------------*/
#define		HALL0CFG_P00_IN				(0x00UL)
#define		HALL0CFG_P20_IN				(0x01UL)

/*----------HALL1引脚复用-------------------------------------------------------*/
#define		HALL1CFG_P21_IN				(0x00UL)
#define		HALL1CFG_P57_IN				(0x01UL)

/*----------HALL2引脚复用-------------------------------------------------------*/
#define		HALL2CFG_P22_IN				(0x00UL)
#define		HALL2CFG_P56_IN				(0x01UL)



/*----------外部中断输入引脚复用-------------------------------------------------------*/
#define		INTxCFGP00							(0x00UL)
#define		INTxCFGP01							(0x01UL)
#define		INTxCFGP02							(0x02UL)
#define		INTxCFGP03							(0x03UL)
#define		INTxCFGP04							(0x04UL)
#define		INTxCFGP05							(0x05UL)
#define		INTxCFGP06							(0x06UL)
#define		INTxCFGP07							(0x07UL)
#define		INTxCFGP10							(0x10UL)
#define		INTxCFGP11							(0x11UL)
#define		INTxCFGP12							(0x12UL)
#define		INTxCFGP13							(0x13UL)
#define		INTxCFGP14							(0x14UL)
#define		INTxCFGP15							(0x15UL)
#define		INTxCFGP16							(0x16UL)
#define		INTxCFGP20							(0x20UL)
#define		INTxCFGP21							(0x21UL)
#define		INTxCFGP22							(0x22UL)
#define		INTxCFGP23							(0x23UL)
#define		INTxCFGP24							(0x24UL)
#define		INTxCFGP25							(0x25UL)
//#define		INTxCFGP26							(0x26UL)
//#define		INTxCFGP27							(0x27UL)
#define		INTxCFGP30							(0x30UL)
#define		INTxCFGP31							(0x31UL)
#define		INTxCFGP32							(0x32UL)
#define		INTxCFGP33							(0x33UL)
#define		INTxCFGP34							(0x34UL)
#define		INTxCFGP35							(0x35UL)
#define		INTxCFGP36							(0x36UL)
#define		INTxCFGP37							(0x37UL)
#define		INTxCFGP40							(0x40UL)
#define		INTxCFGP41							(0x41UL)
#define		INTxCFGP42							(0x42UL)
#define		INTxCFGP43							(0x43UL)
#define		INTxCFGP44							(0x44UL)
#define		INTxCFGP45							(0x45UL)
#define		INTxCFGP46							(0x46UL)
#define		INTxCFGP47							(0x47UL)
#define		INTxCFGP50							(0x50UL)
#define		INTxCFGP51							(0x51UL)
#define		INTxCFGP52							(0x52UL)
#define		INTxCFGP53							(0x53UL)
#define		INTxCFGP54							(0x54UL)
#define		INTxCFGP55							(0x55UL)
#define		INTxCFGP56							(0x56UL)
#define		INTxCFGP57							(0x57UL)

#define		EXTINT_Rising							(0x00UL)		//外部中断上升沿触发
#define		EXTINT_Falling						(0x01UL)		//外部中断下降降沿触发
#define		EXTINT_DoublEdge					(0x02UL)		//外部中断双沿触发

#define		EXTINT_INT0						  (0x00UL)
#define		EXTINT_INT1						  (0x01UL)
#define		EXTINT_INT2						  (0x02UL)
#define		EXTINT_INT3						  (0x03UL)
/*****************************************************************************
 ** \brief	GPIO_PinAFOutConfig
 **			设置(设置IO口作为输出的复用功能)
 ** \param [in] PinCFG:	P00CFG ~ P27CFG寄存器
 **				MuxMode:
 ** \return none
 ** \note	 
*****************************************************************************/	
#define GPIO_PinAFOutConfig(PinCFG, MuxMode)	do{\
											PORT->PinCFG = MuxMode;\
											}while(0)

/*****************************************************************************
 ** \brief	GPIO_PinAFInConfig
 **			设置(设置IO口作为输入的复用功能)
 ** \param [in] PinCFG:	INT0CFG ~ CCP1BINCFG寄存器
 **				MuxMode:
 ** \return none
 ** \note	 
*****************************************************************************/	
#define GPIO_PinAFInConfig(PinCFG, MuxMode)	do{\
											PORT->PinCFG = MuxMode;\
											}while(0)											
											

void GPIO_Init(PORT_TypeDef PORTx,PIN_TypeDef PINx,PIN_ModeDef MODEx);
void PORT_SetBit(PORT_TypeDef PORTx,PIN_TypeDef PINx);
void PORT_ClrBit(PORT_TypeDef PORTx,PIN_TypeDef PINx);
void PORT_ToggleBit(PORT_TypeDef PORTx,PIN_TypeDef PINx);
uint8_t PORT_GetBit(PORT_TypeDef PORTx,PIN_TypeDef PINx);
uint8_t PORT_GetBitValue(PORT_TypeDef PORTx,PIN_TypeDef PINx);
void PORT_PullUp(PORT_TypeDef PORTx,PIN_TypeDef PINx);
void PORT_PullDown(PORT_TypeDef PORTx,PIN_TypeDef PINx);									
void RESTPinGpio_Set(uint8_t RStat);
											
#ifdef __cplusplus
}
#endif
#endif /* __GPIO_H__ */

