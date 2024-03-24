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
/** \file pga.h
**
** History:
** 
*****************************************************************************/
#ifndef __PGA_H_
#define __PGA_H_

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
typedef enum {
	PGA0x = 0,
	PGA1x = 1,
	PGA2x = 2,	
	PGA3x = 3,
}PGA_TypeDef;

typedef enum {
	VrefHalf = 0,
	PGA0BG = 1,	
}PGAVref_TypeDef;


#define PGAUNLOCK		(0x55UL)
#define PGALOCKVal		  (0x00UL)

/*----------------------------------------------------------------------------
 **PGA	增益选择
-----------------------------------------------------------------------------*/
#define		PGA_GAIN_1			(0x00UL)					/*设置增益为1x*/
#define		PGA_GAIN_2			(0x01UL)					/*设置增益为2x*/
#define		PGA_GAIN_2d5		(0x02UL)					/*设置增益为2.5x*/
#define		PGA_GAIN_5			(0x03UL)					/*设置增益为5x*/			
#define		PGA_GAIN_7d5		(0x04UL)					/*设置增益为7.5x*/
#define		PGA_GAIN_10			(0x05UL)					/*设置增益为10x*/	
#define		PGA_GAIN_15			(0x06UL)					/*设置增益为15x*/
/*----------------------------------------------------------------------------
 **PGA	反馈电阻接地端选择
-----------------------------------------------------------------------------*/
#define		PGA_R_None			(0x00UL)					/*接输出不接电阻*/
#define		PGA_R_10K			  (0x01UL)	        /*输出串联10K电阻*/

/*----------------------------------------------------------------------------
 **PGA	驱动电流选择
-----------------------------------------------------------------------------*/
#define		PGA_C_20uA			(0x00UL)					/*接输出不接电阻*/
#define		PGA_C_40uA			(0x01UL)	        /*输出串联10K电阻*/

/*----------------------------------------------------------------------------
 **PGA	正端
-----------------------------------------------------------------------------*/
#define		PGA_POSSEL_P0		(0x00UL)					/*接到PGA P0*/
#define		PGA_POSSEL_P1		(0x01UL<<PGA_CON_PS_Pos)	/*接到PGA P1*/
#define		PGA_POSSEL_P2		(0x02UL<<PGA_CON_PS_Pos)	/*接到PGA P2*/
#define		PGA_POSSEL_P3		(0x03UL<<PGA_CON_PS_Pos)	/*接到PGA P3*/							
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/********************PGA PIN**************************************************
P50: A0P
P51: A0GND
P52: A0O

P46: A1P
P47: A1GND

P32: A2P
P33: A2GND

P30: A3P
P31: A3GND

AXO:内部模块（x:1/2/3）
******************************************************************************/
/*****************************************************************************
 ** \brief	 OPA_ConfigGain
 **			 设置PGA增益
 ** \param [in] pga :PGA0 、PGA1、PGA2
 **				Gain:  (1)	PGA_GAIN_1		
 **					     (2)  PGA_GAIN_2	
 **					     (3)  PGA_GAIN_2d5
 **					     (4)  PGA_GAIN_5	
 **					     (5)  PGA_GAIN_7d5
 **					     (6)  PGA_GAIN_10	
 **					     (6)  PGA_GAIN_15	
 ** \return  none
 ** \note    
 *****************************************************************************/
void PGA_ConfigGain(PGA_TypeDef PGAUnit, uint32_t Gain);

/*****************************************************************************
 ** \brief	 PGA_ConfigResistorPAD
 **			 设置PGA反馈电阻接地端
 ** \param [in] pga :PGA0 、PGA1
 **				GndMode:	(1)PGA_R_GND
 **							(2)PGA_R_PIN
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_ConfigResistorPAD(uint32_t GndMode);

/*****************************************************************************
 ** \brief	 PGA_EnableOutput
 **			 开启PGA输出
 ** \param NONE
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_EnableOutput(void);
/*****************************************************************************
 ** \brief	 PGA_DisableOutput
 **			 关闭PGA输出
 ** \param [in] pga :PGA0 、PGA1
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_DisableOutput(PGA_TypeDef PGAUnit);

/*****************************************************************************
 ** \brief	 PGA_VrefCtrl
 **			 PGA0参考电压设置
 ** \param [in] pga :PGA0x 、PGA1x、PGA2x
 ** \param [in] VrefStat :
**                  VrefHalf:VREF/2
**                  PGA0BG:BG(0.8V)
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_VrefCtrl(PGAVref_TypeDef VrefStat);

/*****************************************************************************
 ** \brief	 PGA_Start
 **			 开启PGA
 ** \param [in] pga :PGA0 、PGA1
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Start(PGA_TypeDef PGAUnit);

/*****************************************************************************
 ** \brief	 PGA_Stop
 **			 关闭PGA
 ** \param [in] pga :PGA0 、PGA1
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Stop(PGA_TypeDef PGAUnit);
	
/*****************************************************************************
 ** \brief	 PGA_ConfigDriveCurrent
 **			 设置PGA输出驱动电流
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x 
 **				GndMode:	(1) PGA_C_20uA	：驱动电流20ua
 **							    (2) PGA_C_40uA	：驱动电流40ua
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_ConfigDriveCurrent(PGA_TypeDef PGAUnit,uint32_t DCurrent);

/*****************************************************************************
 ** \brief	 PGA_FBCap_Config
 **			 设置PGA补偿电容接入或不接入
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x 
 **				   Para:	(1) ENABLE	：接入补偿电容
 **							    (2) DISABLE	：不接入补偿电容
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_FBCap_Config(PGA_TypeDef PGAUnit,uint32_t Para);

/*****************************************************************************
 ** \brief	 PGA_Filter_Set
 **			 设置PGA前端滤波带宽选择
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x
 **				   FltBand :	30ns~290ns (步进是37ns)。
 **                      000： 290ns
 **                      111： 30ns
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Filter_Set(PGA_TypeDef PGAUnit,uint8_t FltBand);

/*****************************************************************************
 ** \brief	 PGA_ClampOut_Set
 **			 设置PGA123钳位二极管使能
 ** \param [in] PGAUnit :PGA1x、PGA2x、PGA3x
 **				   Para:	(1) ENABLE	：PGAx的IO接入钳位二极管使能
 **							    (2) DISABLE	：PGAx的IO接入钳位二极管禁止
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_ClampOut_Set(PGA_TypeDef PGAUnit,FunctionalState Para);

/*****************************************************************************
 ** \brief	 PGA0_SampleHold_Set
 **			 设置PGA0采样保持使能
 ** \param [in] Para:
 **				   	     (1) ENABLE	：使能PGA0的采样保持
 **							   (2) DISABLE	：禁止PGA0的采样保持
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_SampleHold_Set(FunctionalState Para);
	

#ifdef __cplusplus
}
#endif

#endif /* ____ */

