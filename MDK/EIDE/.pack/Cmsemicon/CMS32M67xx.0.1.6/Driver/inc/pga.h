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
 **PGA	����ѡ��
-----------------------------------------------------------------------------*/
#define		PGA_GAIN_1			(0x00UL)					/*��������Ϊ1x*/
#define		PGA_GAIN_2			(0x01UL)					/*��������Ϊ2x*/
#define		PGA_GAIN_2d5		(0x02UL)					/*��������Ϊ2.5x*/
#define		PGA_GAIN_5			(0x03UL)					/*��������Ϊ5x*/			
#define		PGA_GAIN_7d5		(0x04UL)					/*��������Ϊ7.5x*/
#define		PGA_GAIN_10			(0x05UL)					/*��������Ϊ10x*/	
#define		PGA_GAIN_15			(0x06UL)					/*��������Ϊ15x*/
/*----------------------------------------------------------------------------
 **PGA	��������ӵض�ѡ��
-----------------------------------------------------------------------------*/
#define		PGA_R_None			(0x00UL)					/*��������ӵ���*/
#define		PGA_R_10K			  (0x01UL)	        /*�������10K����*/

/*----------------------------------------------------------------------------
 **PGA	��������ѡ��
-----------------------------------------------------------------------------*/
#define		PGA_C_20uA			(0x00UL)					/*��������ӵ���*/
#define		PGA_C_40uA			(0x01UL)	        /*�������10K����*/

/*----------------------------------------------------------------------------
 **PGA	����
-----------------------------------------------------------------------------*/
#define		PGA_POSSEL_P0		(0x00UL)					/*�ӵ�PGA P0*/
#define		PGA_POSSEL_P1		(0x01UL<<PGA_CON_PS_Pos)	/*�ӵ�PGA P1*/
#define		PGA_POSSEL_P2		(0x02UL<<PGA_CON_PS_Pos)	/*�ӵ�PGA P2*/
#define		PGA_POSSEL_P3		(0x03UL<<PGA_CON_PS_Pos)	/*�ӵ�PGA P3*/							
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

AXO:�ڲ�ģ�飨x:1/2/3��
******************************************************************************/
/*****************************************************************************
 ** \brief	 OPA_ConfigGain
 **			 ����PGA����
 ** \param [in] pga :PGA0 ��PGA1��PGA2
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
 **			 ����PGA��������ӵض�
 ** \param [in] pga :PGA0 ��PGA1
 **				GndMode:	(1)PGA_R_GND
 **							(2)PGA_R_PIN
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_ConfigResistorPAD(uint32_t GndMode);

/*****************************************************************************
 ** \brief	 PGA_EnableOutput
 **			 ����PGA���
 ** \param NONE
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_EnableOutput(void);
/*****************************************************************************
 ** \brief	 PGA_DisableOutput
 **			 �ر�PGA���
 ** \param [in] pga :PGA0 ��PGA1
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_DisableOutput(PGA_TypeDef PGAUnit);

/*****************************************************************************
 ** \brief	 PGA_VrefCtrl
 **			 PGA0�ο���ѹ����
 ** \param [in] pga :PGA0x ��PGA1x��PGA2x
 ** \param [in] VrefStat :
**                  VrefHalf:VREF/2
**                  PGA0BG:BG(0.8V)
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_VrefCtrl(PGAVref_TypeDef VrefStat);

/*****************************************************************************
 ** \brief	 PGA_Start
 **			 ����PGA
 ** \param [in] pga :PGA0 ��PGA1
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Start(PGA_TypeDef PGAUnit);

/*****************************************************************************
 ** \brief	 PGA_Stop
 **			 �ر�PGA
 ** \param [in] pga :PGA0 ��PGA1
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Stop(PGA_TypeDef PGAUnit);
	
/*****************************************************************************
 ** \brief	 PGA_ConfigDriveCurrent
 **			 ����PGA�����������
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x 
 **				GndMode:	(1) PGA_C_20uA	����������20ua
 **							    (2) PGA_C_40uA	����������40ua
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_ConfigDriveCurrent(PGA_TypeDef PGAUnit,uint32_t DCurrent);

/*****************************************************************************
 ** \brief	 PGA_FBCap_Config
 **			 ����PGA�������ݽ���򲻽���
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x 
 **				   Para:	(1) ENABLE	�����벹������
 **							    (2) DISABLE	�������벹������
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_FBCap_Config(PGA_TypeDef PGAUnit,uint32_t Para);

/*****************************************************************************
 ** \brief	 PGA_Filter_Set
 **			 ����PGAǰ���˲�����ѡ��
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x
 **				   FltBand :	30ns~290ns (������37ns)��
 **                      000�� 290ns
 **                      111�� 30ns
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Filter_Set(PGA_TypeDef PGAUnit,uint8_t FltBand);

/*****************************************************************************
 ** \brief	 PGA_ClampOut_Set
 **			 ����PGA123ǯλ������ʹ��
 ** \param [in] PGAUnit :PGA1x��PGA2x��PGA3x
 **				   Para:	(1) ENABLE	��PGAx��IO����ǯλ������ʹ��
 **							    (2) DISABLE	��PGAx��IO����ǯλ�����ܽ�ֹ
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_ClampOut_Set(PGA_TypeDef PGAUnit,FunctionalState Para);

/*****************************************************************************
 ** \brief	 PGA0_SampleHold_Set
 **			 ����PGA0��������ʹ��
 ** \param [in] Para:
 **				   	     (1) ENABLE	��ʹ��PGA0�Ĳ�������
 **							   (2) DISABLE	����ֹPGA0�Ĳ�������
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_SampleHold_Set(FunctionalState Para);
	

#ifdef __cplusplus
}
#endif

#endif /* ____ */

