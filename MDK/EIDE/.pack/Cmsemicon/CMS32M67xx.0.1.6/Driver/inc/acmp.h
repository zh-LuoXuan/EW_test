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
/** \file acmp.h
**
** History:
** 
*****************************************************************************/
#ifndef _ACMP_H_
#define _ACMP_H_

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

/*----------------------------------------------------------------------------
 **ACMP Channel
-----------------------------------------------------------------------------*/
#define ACMP0 					(0x00)			/* ACMP channel 0 number */
#define ACMP1					(0x01)			/* ACMP channel 1 number */
/*----------------------------------------------------------------------------
 **ACMP ����˲�
-----------------------------------------------------------------------------*/
#define ACMP_NFCLK_1_TSYS		(0x00UL)		/*(0~1)*Tsys*/
#define ACMP_NFCLK_2_TSYS		(0x01UL)		/*(1~2)*Tsys*/
#define ACMP_NFCLK_3_TSYS		(0x02UL)		/*(2~3)*Tsys*/
#define ACMP_NGCLK_5_TSYS		(0x03UL)		/*(4~5)*Tsys*/
#define ACMP_NFCLK_9_TSYS		(0x04UL)		/*(8~9)*Tsys*/
#define ACMP_NFCLK_17_TSYS		(0x05UL)		/*(16~17)*Tsys*/
#define ACMP_NFCLK_33_TSYS		(0x06UL)		/*(32~33)*Tsys*/
#define ACMP_NGCLK_65_TSYS		(0x07UL)		/*(64~65)*Tsys*/
#define ACMP_NFCLK_129_TSYS		(0x08UL)		/*(128~129)*Tsys*/
#define ACMP_NFCLK_257_TSYS		(0x09UL)		/*(256~257)*Tsys*/
#define ACMP_NFCLK_513_TSYS		(0x0aUL)		/*(512~513)*Tsys*/
/*----------------------------------------------------------------------------
 **ACMP Positive Sel
-----------------------------------------------------------------------------*/
#define ACMP_POSSEL_PGA0P			(0x00UL)		/*ACMP P0*/
#define ACMP_POSSEL_A0O 			(0x01UL)		/*ACMP A0O*/
#define ACMP_POSSEL_PGA13P			(0x02UL)		/*ACMP PGA1P/PAG3P*/
#define ACMP_POSSEL_AXO		  	(0x03UL)		/*ACMP AXO*/
#define ACMP_POSSEL_CxP0			(0x04UL)		/*ACMP C0P0*/
#define ACMP_POSSEL_CxP1			(0x05UL)		/*ACMP C0P1*/
#define ACMP_POSSEL_CxP2			(0x06UL)		/*ACMP C0P2*/
#define ACMP_POSSEL_CxP3			(0x07UL)		/*ACMP C0P3*/

/*----------------------------------------------------------------------------
 **ACMP Negative Sel
-----------------------------------------------------------------------------*/
#define ACMP_NEGSEL_CxN			(0x00UL)		/*ACMP C0N/C1N*/
#define ACMP_NEGSEL_DACO			(0x01UL)		/*ACMP DAC*/
#define ACMP_NEGSEL_BG			(0x02UL)		/*ACMP BG*/
#define ACMP_NEGSEL_BEFx_U			(0x03UL)		/*ACMP C0P0/C1P0*/
#define ACMP_NEGSEL_BEFx_V			(0x04UL)		/*ACMP C0P1/C1P1*/
#define ACMP_NEGSEL_BEFx_W			(0x05UL)		/*ACMP C0P2/C1P2*/
#define ACMP_NEGSEL_BEFx_N			(0x06UL)		/*ACMP N*/

/*----------------------------------------------------------------------------
 **ACMP  �¼����жϲ���ģʽ
-----------------------------------------------------------------------------*/
#define ACMP_EVENT_INT_RISING		(0x0UL)			/*ACMPx���������(0->1����)����*/
#define ACMP_EVENT_INT_FALLING		(0x1UL )			/*ACMPx����½���(1->0����)����*/
#define ACMP_EVENT_INT_BOTH_EDGE	(0x2UL)				/*ACMPx�����0->1��������1->0���������*/

/*----------------------------------------------------------------------------
 **ACMP  �ж�����
-----------------------------------------------------------------------------*/
#define ACMP_INT_Compx_Event		  (0x0UL)			/*ACMPx�¼��ж�*/
#define ACMP_INT_Compx_OutHigh		(0x1UL)			/*ACMPx������ж�*/
#define ACMP_INT_Compx_OutLow		  (0x2UL)			/*ACMPx������ж�*/

/*----------------------------------------------------------------------------
 **ACMP ����ģʽ
------------------------------------------------------------------------------*/
#define ACMP_HYS_POS			(0x01UL)			/*������*/
#define ACMP_HYS_NEG			(0x02UL)			/*������*/
#define ACMP_HYS_BOUTH			(0x03UL)			/*˫�߳���*/

/*----------------------------------------------------------------------------
 **ACMP ��������
------------------------------------------------------------------------------*/
#define ACMP_HYS_S_00			(0x00UL)			/*0mV����*/
#define ACMP_HYS_S_10			(0x01UL)			/*10mV����*/
#define ACMP_HYS_S_20			(0x02UL)			/*20mV����*/
#define ACMP_HYS_S_60			(0x03UL)			/*60mV����*/

/*----------------------------------------------------------------------------
 **ACMP ��������
------------------------------------------------------------------------------*/
#define ACMP_POL_Pos			(0x00UL)			/*�������*/
#define ACMP_POL_Neg			(0x01UL)			/*�������*/

/*----------------------------------------------------------------------------
 **ACMP д����
------------------------------------------------------------------------------*/
#define ACMP_WRITE_KEY 			(0x55UL)
				  										 
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **ACMP ���˻�׼��ѹ VDD / BG ϵ�� K
-----------------------------------------------------------------------------*/
typedef enum V_B_Coefficient{
	V_B_COF_2 =0, 
	V_B_COF_3 =1, 
	V_B_COF_4 =2, 
	V_B_COF_5 =3, 
	V_B_COF_6 =4,
	V_B_COF_7 =5,    
	V_B_COF_8 =6, 
	V_B_COF_9 =7, 
	V_B_COF_10 =8, 
	V_B_COF_11 =9,
	V_B_COF_12 =10,  
	V_B_COF_13 =11, 
	V_B_COF_14 =12, 
	V_B_COF_15 =13, 
	V_B_COF_16 =14,
	V_B_COF_17 =15,
}V_B_Coefficient_T;

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

/******************************************************************************
 ** \brief	 ACMP_ConfigPositive
 **			 ���ñȽ�����������
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \param [in] Common PositiveSource:  (1)ACMP_POSSEL_P0		:CnP0
 **								 (2)ACMP_POSSEL_P1		:CnP1
 **								 (3)ACMP_POSSEL_P2		:CnP2
 **				for ACMP0:       (4)ACMP_POSSEL_0PGA1P		
 **								 (5)ACMP_POSSEL_0PGA1O		
 **								 (6)ACMP_POSSEL_0PGA2P		
 **								 (7)ACMP_POSSEL_0PGA2O		
 **				for ACMP1:       (4)ACMP_POSSEL_1P3			
 **								 (5)ACMP_POSSEL_PGA0O	 
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_ConfigPositive( uint32_t ACMPx, uint32_t PositiveSource);

/*****************************************************************************
 ** \brief	 ACMP_ConfigNegative
 **			 ���ñȽ�����������
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				NegativeSource:  (1)ACMP_NEGSEL_N		:CnN  ACMP N����˿�			 
 **								 (2)ACMP_NEGSEL_DAC_O	:DAC �����ѹ	
 **								 (3)ACMP_NEGSEL_BEF_N��	 �Ƚ����ڲ��ź�
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_ConfigNegative( uint32_t ACMPx, uint32_t NegativeSource);

/*****************************************************************************
 ** \brief	 ACMP_EnableEventOut
 **			 �����Ƚ����¼����
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
 *****************************************************************************/
void ACMP_EnableEventOut( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_ConfigEventAndIntMode
 **			 �����¼����жϲ���ģʽ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				EventAndIntMode: 	(1)ACMP_EVENT_INT_RISING 		: ACMPx����������ش���
 **				 			 		(2)ACMP_EVENT_INT_FALLING 		: ACMPx������½��ش���
 **						     		(3)ACMP_EVENT_INT_BOTH_EDGE 	: ACMPx�������0->1��������1->0�����䴥��
 ** \return  none
 ** \note   
 *****************************************************************************/

void ACMP_ConfigEventAndIntMode( uint32_t ACMPx, uint32_t EventAndIntMode);

/*****************************************************************************
 ** \brief	 ACMP_DisableEventOut
 **			 �رձȽ����¼����
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
 *****************************************************************************/
void ACMP_DisableEventOut( uint32_t ACMPx);

/******************************************************************************
 ** \brief	 ACMP_EnableInt
 **			 ����ACMP�ж�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  IntMod
 **       		ACMP_INT_Compx_Event���¼��ж�
 ** 					ACMP_INT_Compx_OutHigh��������ж�
 ** 					ACMP_INT_Compx_OutLow��������ж�
 ** \note   
 *****************************************************************************/
void ACMP_EnableInt(uint32_t ACMPx,uint8_t IntMod);
/*****************************************************************************
 ** \brief	 ACMP_DisableInt
 **			 �ر�ACMP�ж�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
*****************************************************************************/
void ACMP_DisableInt( uint32_t ACMPx,uint8_t IntMod);
/*****************************************************************************
 ** \brief	 ACMP_GetIntFlag
 **			 ��ȡACMP��ʹ���жϱ�־
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  0: ���жϲ��� �� 1���ж�ʹ�ܲ������ж�
 ** \note   
******************************************************************************/
uint32_t ACMP_GetIntFlag( uint32_t ACMPx,uint8_t IntMod);
/*****************************************************************************
 ** \brief	 ACMP_ClearIntFlag
 **			 ��ACMP�ж�
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
******************************************************************************/
void ACMP_ClearIntFlag( uint32_t ACMPx,uint8_t IntMod);

/*****************************************************************************
 ** \brief	 ACMP_Start
 **			 ����ACMP
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
******************************************************************************/
void ACMP_Start( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_Stop
 **			 �ر�ACMP
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
**********************************************************************?******/
void ACMP_Stop( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP0_CenterAliagn_Enable
 **			 ����ACMP0�����Ķ���
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void ACMP0_CenterAliagn_Enable(void);

/*****************************************************************************
 ** \brief	 ACMP0_CenterAliagn_Disable
 **			 �ر�ACMP0�����Ķ���
 ** \param [in] none
 ** \return  none
 ** \note   
**********************************************************************?******/
void ACMP0_CenterAliagn_Disable(void);
	
/*****************************************************************************
 ** \brief	 ACMPOut_Enable
 **			 ʹ��ACMP���
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
******************************************************************************/
void ACMPOut_Enable( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMPOut_Disable
 **			 �ر�ACMP���
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note   
**********************************************************************?******/
void ACMPOut_Disable( uint32_t ACMPx);
	
/*****************************************************************************
 ** \brief	 ACMP_GetResult
 **			 ��ȡ�Ƚ���ֵ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  0/1
 ** \note   
 *****************************************************************************/
uint32_t ACMP_GetResult( uint32_t ACMPx);


/*****************************************************************************
 ** \brief	 ACMP_EnableHYS
 **			 ���ñȽ�������ģʽ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 **				HYSSelect	:(1)ACMP_HYS_POS	: ������
 **							 (2)ACMP_HYS_NEG	: ������
 **							 (3)ACMP_HYS_BOUTH	: ˫�߳���
 **				HYSValue 	:(1)ACMP_HYS_S_10	: 10mV����
 **							 (2)ACMP_HYS_S_20	��20mV����
 **							 (3)ACMP_HYS_S_60	��60mV���� 
 ** \return  none
 ** \note  
*****************************************************************************/
void ACMP_EnableHYS( uint32_t ACMPx ,uint32_t HYSSelect, uint32_t HYSValue);

/*****************************************************************************
 ** \brief	 ACMP_DisableHYS
 **			 �رձȽ�������ģʽ
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \return  none
 ** \note  
*****************************************************************************/
void ACMP_DisableHYS( uint32_t ACMPx);

/*****************************************************************************
 ** \brief	 ACMP_Filter_Config
 **			    �����˲����غ��˲�ʱ��
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \param [in] FiltSta: ENABLE ,DISABLE
 ** \param [in] FlitTim: �˲�ʱ��ѡ��
 *                  ACMP_NFCLK_1_TSYS��(0~1)*Tsys
 *                       .......
 *                  ACMP_NFCLK_513_TSYS:(512~513)*Tsys
 ** \return  none
 ** \note  
*****************************************************************************/
void ACMP_Filter_Config( uint32_t ACMPx,FunctionalState FiltSta,uint8_t FlitTim);


/*****************************************************************************
 ** \brief	 ACMP_Polarity_Config
 **			    ��������ļ���
 ** \param [in] ACMPx: ACMP0 ,ACMP1
 ** \param [in] PolaritySet:  
 *               ACMP_POL_Pos���������
 *               ACMP_POL_Neg���������
 ** \return  none
 ** \note  
*****************************************************************************/
void ACMP_Polarity_Config( uint32_t ACMPx,uint8_t PolaritySet);
	
#ifdef __cplusplus
}
#endif

#endif /* _ACMP_H_ */

