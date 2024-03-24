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
/** \file adc.h
**
** History:
** 
*****************************************************************************/
#ifndef __ADC_H_
#define __ADC_H_

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
 **ADC ת��ģʽ
-----------------------------------------------------------------------------*/
#define 	ADC_MODE_HIGH		(0x00UL)						/*����ת��ģʽ*/
#define 	ADC_MODE_LOW		(0x03UL<<ADC_CON_ADMODE10_Pos)	/*�͵���ģʽ*/

#define 	ADC_CONVERT_SINGLE		(0x00UL)						/*����ģʽ*/
#define 	ADC_CONVERT_CONTINUOUS		(0x01UL<<ADC_CON_ADCMS_Pos)	/*����ģʽ*/

#define 	ADC_SWITCH_HARDWARE	(0x00UL)						/*Ӳ���Զ��л�ģʽ*/
#define 	ADC_SWITCH_SOFTWARE	(0x1UL<<ADC_CON_ADCSWCHE_Pos)	/*����л�ģʽ*/

/*----------------------------------------------------------------------------
 **ADC ʱ�ӷ�Ƶ
-----------------------------------------------------------------------------*/
#define 	ADC_CLK_DIV_1		(0x00UL)			/*ADC ʱ�ӷ�ƵΪ 1*/
#define 	ADC_CLK_DIV_2		(0x01UL)			/*ADC ʱ�ӷ�ƵΪ 2*/
#define 	ADC_CLK_DIV_4		(0x02UL)			/*ADC ʱ�ӷ�ƵΪ 4*/
#define 	ADC_CLK_DIV_8		(0x03UL)			/*ADC ʱ�ӷ�ƵΪ 8*/
#define 	ADC_CLK_DIV_16		(0x04UL)			/*ADC ʱ�ӷ�ƵΪ 16*/
#define 	ADC_CLK_DIV_32		(0x05UL)			/*ADC ʱ�ӷ�ƵΪ 32*/
#define 	ADC_CLK_DIV_64		(0x06UL)			/*ADC ʱ�ӷ�ƵΪ 64*/
#define 	ADC_CLK_DIV_128	(0x07UL)			/*ADC ʱ�ӷ�ƵΪ 128*/

/*----------------------------------------------------------------------------
 **ADC ��硢�ŵ�ʱ��
-----------------------------------------------------------------------------*/
#define 	ADC_CG_2			(0x02UL)				/* 2*ADCCLK*/
#define 	ADC_CG_3			(0x03UL)				/* 3*ADCCLK*/
#define 	ADC_CG_4			(0x04UL)				/* 4*ADCCLK*/
#define 	ADC_CG_5			(0x05UL)				/* 5*ADCCLK*/
#define 	ADC_CG_6			(0x06UL)				/* 6*ADCCLK*/
#define 	ADC_CG_7			(0x07UL)				/* 7*ADCCLK*/
#define 	ADC_CG_8			(0x08UL)				/* 8*ADCCLK*/
#define 	ADC_CG_9			(0x09UL)				/* 9*ADCCLK*/
#define 	ADC_CG_10			(0x0AUL)				/* 10*ADCCLK*/
#define 	ADC_CG_11			(0x0BUL)				/* 11*ADCCLK*/
#define 	ADC_CG_12			(0x0CUL)				/* 12*ADCCLK*/
#define 	ADC_CG_13			(0x0DUL)				/* 13*ADCCLK*/
#define 	ADC_CG_14			(0x0EUL)				/* 14*ADCCLK*/
#define 	ADC_CG_15			(0x0FUL)				/* 15*ADCCLK*/

/*----------------------------------------------------------------------------
 **ADC �ο�Դ
-----------------------------------------------------------------------------*/
#define		ADC_VREFP_VDD		(0x00UL)						/*ѡ��VDD��Ϊ���˲ο�*/
#define     ADC_VREFP_BG		(0x02UL<<ADC_CON_ADCVS_Pos)	/*ѡ��BG1.45V��Ϊ���˲ο�*/

/*---------------------------------------------------------------------------*/
#define		ADC_VREFP_AVREFP	(0x01UL<<ADC_CON_ADCVS_Pos)	/*ѡ��VREF(ADCLDO ���)��Ϊ���˲ο�	*/

/*----------------------------------------------------------------------------
 **ADC �ڲ�����Դѡ��
-----------------------------------------------------------------------------*/
//#define		ADC_TG_INTNEL_ADCA				(0x0UL | ADC_HWTG_ADCINTTGEN_Msk)		/*�ڲ�ADCA����*/	
#define		ADC_TG_INTNEL_ADC				((0x1UL<<ADC_HWTG_ADCINTTGSS_Pos)| ADC_HWTG_ADCINTTGEN_Msk)	/*�ڲ�ADC����*/		
#define		ADC_TG_INTNEL_ACMP0			((0x2UL<<ADC_HWTG_ADCINTTGSS_Pos)| ADC_HWTG_ADCINTTGEN_Msk)	/*�ڲ�ACMP0�¼�����*/					
#define		ADC_TG_INTNEL_ACMP1			((0x3UL<<ADC_HWTG_ADCINTTGSS_Pos)| ADC_HWTG_ADCINTTGEN_Msk)	/*�ڲ�ACMP1�¼�����*/	
#define		ADC_TG_INTNEL_TMR0				((0x4UL<<ADC_HWTG_ADCINTTGSS_Pos)| ADC_HWTG_ADCINTTGEN_Msk)	/*�ڲ�TMR0��ʹ���жϴ���*/			
#define		ADC_TG_INTNEL_TMR1				((0x5UL<<ADC_HWTG_ADCINTTGSS_Pos)| ADC_HWTG_ADCINTTGEN_Msk)	/*�ڲ�TMR1��ʹ���жϴ���*/	
//#define		ADC_TG_INTNEL_TMR2				((0x6UL<<ADC_HWTG_ADCINTTGSS_Pos)| ADC_HWTG_ADCINTTGEN_Msk)	/*�ڲ�TMR2��ʹ���жϴ���*/			
//#define		ADC_TG_INTNEL_TMR3				((0x7UL<<ADC_HWTG_ADCINTTGSS_Pos)| ADC_HWTG_ADCINTTGEN_Msk)	/*�ڲ�TMR3��ʹ���жϴ���*/	

/*----------------------------------------------------------------------------
 **ADC �ⲿ����Դѡ��
-----------------------------------------------------------------------------*/
#define		ADC_TG_ExtFALLING_ADC				( ADC_HWTG_ADCEXTEN_Msk)	/*�ⲿADC����*/	
#define		ADC_TG_ExtRISING_ADC				((0x1UL<<ADC_HWTG_ADCEXTES_Pos)| ADC_HWTG_ADCEXTEN_Msk)	/*�ⲿADC����*/	

/*----------------------------------------------------------------------------
 **ADC EPWM����Դѡ��
-----------------------------------------------------------------------------*/
#define		ADC_TG_EPWM_CMP0				(0x01UL<<ADC_HWTG_ADCPTG0EN_Pos)	/*EPWM�����Ƚ���0����*/
#define		ADC_TG_EPWM_CMP1				(0x01UL<<ADC_HWTG_ADCPTG1EN_Pos)	/*EPWM�����Ƚ���1����*/

#define		ADC_TG_EPWM0_RISING			(0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)	/*EPWM0�����ش����ж�*/
#define		ADC_TG_EPWM0_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))	/*EPWM0�½��ش����ж�*/		
#define		ADC_TG_EPWM0_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))	/*EPWM0���ڵ㴥���ж�*/	
#define		ADC_TG_EPWM0_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))	/*EPWM0��㴥���ж�*/
#define		ADC_TG_EPWM1_RISING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x1<<ADC_HWTG_ADCEPWMTSS_Pos))
#define		ADC_TG_EPWM1_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x1<<ADC_HWTG_ADCEPWMTSS_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM1_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)| (0x1<<ADC_HWTG_ADCEPWMPSS_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM1_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)| (0x1<<ADC_HWTG_ADCEPWMZSS_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM2_RISING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x2<<ADC_HWTG_ADCEPWMTSS_Pos))
#define		ADC_TG_EPWM2_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x2<<ADC_HWTG_ADCEPWMTSS_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM2_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)| (0x2<<ADC_HWTG_ADCEPWMPSS_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM2_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)| (0x2<<ADC_HWTG_ADCEPWMZSS_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM3_RISING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x3<<ADC_HWTG_ADCEPWMTSS_Pos))
#define		ADC_TG_EPWM3_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x3<<ADC_HWTG_ADCEPWMTSS_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM3_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)| (0x3<<ADC_HWTG_ADCEPWMPSS_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM3_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)| (0x3<<ADC_HWTG_ADCEPWMZSS_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM4_RISING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x4<<ADC_HWTG_ADCEPWMTSS_Pos))
#define		ADC_TG_EPWM4_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x4<<ADC_HWTG_ADCEPWMTSS_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM4_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)| (0x4<<ADC_HWTG_ADCEPWMPSS_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM4_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)| (0x4<<ADC_HWTG_ADCEPWMZSS_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM5_RISING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x5<<ADC_HWTG_ADCEPWMTSS_Pos))
#define		ADC_TG_EPWM5_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x5<<ADC_HWTG_ADCEPWMTSS_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM5_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)| (0x5<<ADC_HWTG_ADCEPWMPSS_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM5_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)| (0x5<<ADC_HWTG_ADCEPWMZSS_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM6_RISING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x6<<ADC_HWTG_ADCEPWMTSS_Pos))
#define		ADC_TG_EPWM6_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x6<<ADC_HWTG_ADCEPWMTSS_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM6_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)| (0x6<<ADC_HWTG_ADCEPWMPSS_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM6_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)| (0x6<<ADC_HWTG_ADCEPWMZSS_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM7_RISING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x7<<ADC_HWTG_ADCEPWMTSS_Pos))
#define		ADC_TG_EPWM7_FALLING			((0x1UL<<ADC_HWTG_ADCEPWMTEN_Pos)| (0x7<<ADC_HWTG_ADCEPWMTSS_Pos)|(0x2<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM7_PERIOD			((0x1UL<<ADC_HWTG_ADCEPWMPEN_Pos)| (0x7<<ADC_HWTG_ADCEPWMPSS_Pos)|(0x1<<ADC_HWTG_ADCEPWMTPS_Pos))
#define		ADC_TG_EPWM7_ZERO				((0x1UL<<ADC_HWTG_ADCEPWMZEN_Pos)| (0x7<<ADC_HWTG_ADCEPWMZSS_Pos)|(0x3<<ADC_HWTG_ADCEPWMTPS_Pos))

/*----------------------------------------------------------------------------
 **ADC ����ͨ��
-----------------------------------------------------------------------------*/
#define		ADC_CH_0					(0x0UL)					
#define		ADC_CH_1					(0x1UL)			
#define		ADC_CH_2					(0x2UL)			
#define		ADC_CH_3					(0x3UL)			
#define		ADC_CH_4					(0x4UL)			
#define		ADC_CH_5					(0x5UL)			
#define		ADC_CH_6					(0x6UL)			
#define		ADC_CH_7					(0x7UL)			
#define		ADC_CH_8					(0x8UL)			
#define		ADC_CH_9					(0x9UL)			
#define		ADC_CH_10					(0xAUL)			
#define		ADC_CH_11					(0xBUL)			
#define		ADC_CH_12					(0xCUL)			
#define		ADC_CH_13					(0xDUL)			
#define		ADC_CH_14					(0xEUL)			
#define		ADC_CH_15					(0xFUL)			
#define		ADC_CH_16					(0x10UL)		
#define		ADC_CH_17					(0x11UL)			
#define		ADC_CH_18					(0x12UL)		
#define		ADC_CH_19					(0x13UL)		
#define		ADC_CH_20					(0x14UL)		
#define		ADC_CH_21					(0x15UL)		
#define		ADC_CH_22					(0x16UL)	  
#define		ADC_CH_23					(0x17UL)			//VDD	
#define		ADC_CH_24					(0x18UL)			//GND		
#define		ADC_CH_25					(0x19UL)			//BG2AD	
#define		ADC_CH_26					(0x1AUL)			//Internal Channel

#define		ADC_CH_0_MSK				(0x1UL)			
#define		ADC_CH_1_MSK				(0x2UL)	
#define		ADC_CH_2_MSK				(0x4UL)			
#define		ADC_CH_3_MSK				(0x8UL)			
#define		ADC_CH_4_MSK				(0x10UL)		
#define		ADC_CH_5_MSK				(0x20UL)			
#define		ADC_CH_6_MSK				(0x40UL)	
#define		ADC_CH_7_MSK				(0x80UL)			
#define		ADC_CH_8_MSK				(0x100UL)			
#define		ADC_CH_9_MSK				(0x200UL)		
#define		ADC_CH_10_MSK				(0x400UL)			
#define		ADC_CH_11_MSK				(0x800UL)	
#define		ADC_CH_12_MSK				(0x1000UL)			
#define		ADC_CH_13_MSK				(0x2000UL)			
#define		ADC_CH_14_MSK				(0x4000UL)		
#define		ADC_CH_15_MSK				(0x8000UL)			
#define		ADC_CH_16_MSK				(0x10000UL)	
#define		ADC_CH_17_MSK				(0x20000UL)			
#define		ADC_CH_18_MSK				(0x40000UL)			
#define		ADC_CH_19_MSK				(0x80000UL)	
#define		ADC_CH_20_MSK				(0x100000UL)			
#define		ADC_CH_21_MSK				(0x200000UL)	
#define		ADC_CH_22_MSK				(0x400000UL)			
#define		ADC_CH_23_MSK				(0x800000UL)			
#define		ADC_CH_24_MSK				(0x1000000UL)	
#define		ADC_CH_25_MSK				(0x2000000UL)	
#define		ADC_CH_26_MSK				(0x4000000UL)	

/*----------------------------------------------------------------------------
 **ADC  AN22ѡ��
-----------------------------------------------------------------------------*/
#define    ADC_AN25_SEL_TS				(0x0UL)			/*�ڲ��¶ȴ�����*/
//#define    ADC_AN25_SEL_BG				(0x1UL)			/*�ڲ�BG 1.45V*/

/*----------------------------------------------------------------------------
 **ADC  AN23ѡ��
-----------------------------------------------------------------------------*/
#define    ADC_AN26_SEL_DAC     	(0x4UL)			/*DAC���*/


/*----------------------------------------------------------------------------
 **ADC1   �Ƚ�
-----------------------------------------------------------------------------*/
#define		ADC_CMP_LESS_THAN_RESULT		(0x00UL)		/*ADC ���<Ԥ��ֵ*/
#define		ADC_CMP_NOT_LESS_THAN_RESULT	(0x01UL<<ADC_CMP_ADCCMPCOND_Pos)		/*ADC ���>=Ԥ��ֵ*/

#define		ADC_CMP0						(0x00UL)		/*ADC�Ƚ���0*/
#define		ADC_CMP1						(0x01UL)		/*ADC�Ƚ���1*/
	

/*----------------------------------------------------------------------------
 **ADC1   д����
-----------------------------------------------------------------------------*/
#define		ADC_LOCK_WRITE_KEY		(0x55UL)

/*****************************************************************************
 ** \brief	ADC_IS_BUSY
 **			��ȡADCת������/���б�־λ
 ** \param [in] none
 ** \return  1��æ   0������/ת�����
 ** \note	 
*****************************************************************************/
#define	ADC_IS_BUSY()		((ADC->CON2&ADC_CON2_ADCST_Msk)? 1:0)


/*****************************************************************************
 ** \brief	ADC_Go
 **			����ADC1ת��
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
__STATIC_INLINE	void ADC_Go(void)
{
	ADC->LOCK = ADC_LOCK_WRITE_KEY;
	ADC->CON2 |= ADC_CON2_ADCST_Msk;
	ADC->LOCK = 0x00;
}

							
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
 ** \brief	ADC_ConfigRunMode
 **			����ADC����ģʽ
 ** \param [in] RunMode: (1)ADC_MODE_HIGH
 **						 (2)ADC_MODE_LOW
 **				ConvertMode:(1)ADC_CONVERT_SINGLE			
 **							(2)ADC_CONVERT_CONTINUOUS				
 **				ClkDiv :(1)ADC_CLK_DIV_1
 **						(2)ADC_CLK_DIV_2
 **						(3)ADC_CLK_DIV_4
 **						(4)ADC_CLK_DIV_8
 **						(5)ADC_CLK_DIV_16
 **						(6)ADC_CLK_DIV_32
 **						(7)ADC_CLK_DIV_64
 **						(8)ADC_CLK_DIV_128
 **				Holdtime: 5~255 		
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_ConfigRunMode(uint32_t RunMode, uint32_t ConvertMode,uint32_t ClkDiv, uint32_t Holdtime);

/*****************************************************************************
 ** \brief	ADC_ConfigChannelSwitchMode
 **			����ADCͨ���л�ģʽ
 ** \param [in] 	ChSwitch:(1)ADC_SWITCH_HARDWARE	
 **							 (2)ADC_SWITCH_SOFTWARE 
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_ConfigChannelSwitchMode(uint32_t ChSwitch);

/*****************************************************************************
 ** \brief	ADC_EnableCharge
 **			����ADC��繦��
 ** \param [in] ChargeTime:	ADC_CG_2...... ADC_CG_30
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableCharge(uint32_t ChargeTime);
/*****************************************************************************
 ** \brief	ADC_EnableDischarge
 **			����ADC�ŵ繦��
 ** \param [in] ChargeTime:	ADC_CG_2...... ADC_CG_30
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableDischarge(uint32_t ChargeTime);

/*****************************************************************************
 ** \brief	ADC_DisableChargeAndDischarge
 **			�ر�ADC�ŵ硢��繦��
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_DisableChargeAndDischarge(void);

/*****************************************************************************
 ** \brief	ADC_ConfigVREF
 **			����ADC�Ĳο�Դ
 ** \param [in]  VrefPos:  (1)ADC_VREFP_VDD		ѡ��VDD��Ϊ���˲ο�
 **						   (2)ADC_VREFP_BG			ѡ��BG��Ϊ���˲ο�
 **						   (3)ADC_VREFP_AVREFP		ѡ��VREF(ADCLDO ���)��Ϊ���˲ο�	
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_ConfigVREF(uint32_t VrefPos);


/*****************************************************************************
 ** \brief	ADC_ConfigSampleTime
 **			���ò���ʱ��
 ** \param [in]  sampletime: 5 ~ 255;
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_ConfigSampleTime(uint32_t sampletime);

/*****************************************************************************
 ** \brief	ADC_EnableSampleWait
 **			ʹ��ADC���ֲ���״̬
 ** \param [in]  none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableSampleWait(void);
/*****************************************************************************
 ** \brief	ADC_DisableSampleWait
 **			�ر�ADC���ֲ���״̬
 ** \param [in]  none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_DisableSampleWait(void);

/*****************************************************************************
 ** \brief	ADC_SelSoftwareSwitchChannel
 **			ѡ������л�ת����ͨ��
 ** \param [in] Channel: ADC_CH_0 ~ ADC_CH_30
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_SelSoftwareSwitchChannel(uint32_t Channel);

/*****************************************************************************
 ** \brief	ADC_SelAN25Source
 **			   ѡ��AN25ͨ����ת��Դ
 ** \param [in] AN25Sel : (1)ADC_AN25_SEL_TS
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_SelAN25Source(uint8_t AN25Sel);

/*****************************************************************************
 ** \brief	ADC_EnableScanChannel
 **			����ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableScanChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_AN26Select
 **			AN26ͨ��ѡ��
 ** \param [in] AN26Sel : 
 **						  (1)ADC_AN26_SEL_DAC
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_AN26Select(uint32_t AN26Sel);

/*****************************************************************************
 ** \brief	ADC_DisableScanChannel
 **			�ر�ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_DisableScanChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_GetResult
 **			��ȡADCת�����
 ** \param [in] Channel: ADC1_CH_0 ~ ADC1_CH_30
 ** \return  12 bits Value
 ** \note	
*****************************************************************************/
uint32_t ADC_GetResult(uint32_t Channel);

/*****************************************************************************
 ** \brief	ADC_EnableHardwareTrigger
 **			����Ӳ������ADCת������
 ** \param [in] TriggerSource: (1)ADC_TG_EXT_FALLING
 **							(2)ADC_TG_EXT_RISING
 **							(3)ADC_TG_INTNEL_ADCA
 **							(4)ADC_TG_INTNEL_ADC
 **							(5)ADC_TG_INTNEL_ACMP0
 **							(6)ADC_TG_INTNEL_ACMP1
 **							(7)ADC_TG_INTNEL_TMR0
 **							(8)ADC_TG_INTNEL_TMR1
 **							(9)ADC_TG_EPWM_CMP0
 **							(10)ADC_TG_EPWM_CMP1
 **							(11)ADC_TG_EPWM0_RISING
 **							(12)ADC_TG_EPWM0_FALLING
 **							(13)ADC_TG_EPWM0_PERIOD
 **							(14)ADC_TG_EPWM0_ZERRO
 **							(15)ADC_TG_EPWM1_RISING
 **							(16)ADC_TG_EPWM1_FALLING
 **							(17)ADC_TG_EPWM1_PERIOD
 **							(18)ADC_TG_EPWM1_ZERRO
 **							(19)ADC_TG_EPWM2_RISING
 **							(20)ADC_TG_EPWM2_FALLING
 **							(21)ADC_TG_EPWM2_PERIOD
 **							(22)ADC_TG_EPWM2_ZERRO
 **							(23)ADC_TG_EPWM3_RISING
 **							(24)ADC_TG_EPWM3_FALLING
 **							(25)ADC_TG_EPWM3_PERIOD
 **							(26)ADC_TG_EPWM3_ZERRO
 **							(27)ADC_TG_EPWM4_RISING
 **							(28)ADC_TG_EPWM4_FALLING
 **							(29)ADC_TG_EPWM4_PERIOD
 **							(30)ADC_TG_EPWM4_ZERRO
 **							(31)ADC_TG_EPWM5_RISING
 **							(32)ADC_TG_EPWM5_FALLING
 **							(33)ADC_TG_EPWM5_PERIOD
 **							(34)ADC_TG_EPWM5_ZERRO 
 **							(35)ADC_TG_INTNEL_TMR2
 **							(36)ADC_TG_INTNEL_TMR3	
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableHardwareTrigger(uint32_t TriggerSource);
/*****************************************************************************
 ** \brief	ADC1_DisableHardwareTrigger
 **			�ر�Ӳ������ADC1ת������
 ** \param [in] TriggerSource: (1)ADC_TG_EXT_FALLING
 **							(2)ADC_TG_EXT_RISING
 **							(3)ADC_TG_INTNEL_ADCA
 **							(4)ADC_TG_INTNEL_ADC
 **							(5)ADC_TG_INTNEL_ACMP0
 **							(6)ADC_TG_INTNEL_ACMP1
 **							(7)ADC_TG_INTNEL_TMR0
 **							(8)ADC_TG_INTNEL_TMR1
 **							(9)ADC_TG_EPWM_CMP0
 **							(10)ADC_TG_EPWM_CMP1
 **							(11)ADC_TG_EPWM0_RISING
 **							(12)ADC_TG_EPWM0_FALLING
 **							(13)ADC_TG_EPWM0_PERIOD
 **							(14)ADC_TG_EPWM0_ZERRO
 **							(15)ADC_TG_EPWM1_RISING
 **							(16)ADC_TG_EPWM1_FALLING
 **							(17)ADC_TG_EPWM1_PERIOD
 **							(18)ADC_TG_EPWM1_ZERRO
 **							(19)ADC_TG_EPWM2_RISING
 **							(20)ADC_TG_EPWM2_FALLING
 **							(21)ADC_TG_EPWM2_PERIOD
 **							(22)ADC_TG_EPWM2_ZERRO
 **							(23)ADC_TG_EPWM3_RISING
 **							(24)ADC_TG_EPWM3_FALLING
 **							(25)ADC_TG_EPWM3_PERIOD
 **							(26)ADC_TG_EPWM3_ZERRO
 **							(27)ADC_TG_EPWM4_RISING
 **							(28)ADC_TG_EPWM4_FALLING
 **							(29)ADC_TG_EPWM4_PERIOD
 **							(30)ADC_TG_EPWM4_ZERRO
 **							(31)ADC_TG_EPWM5_RISING
 **							(32)ADC_TG_EPWM5_FALLING
 **							(33)ADC_TG_EPWM5_PERIOD
 **							(34)ADC_TG_EPWM5_ZERRO 
 **							(35)ADC_TG_INTNEL_TMR2
 **							(36)ADC_TG_INTNEL_TMR3	
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_DisableHardwareTrigger(uint32_t TriggerSource);

/*****************************************************************************
 ** \brief	ADC_SetTriggerDelayTime
 **			����ADC EPWM��������ʱʱ��
 ** \param [in] DelayTime: 0x00~ 0x1ff;
 ** \return  none
 ** \note  Time = (DelayTime+2)*PCLK
*****************************************************************************/
void ADC_SetTriggerDelayTime(uint32_t DelayTime);
/*****************************************************************************
 ** \brief	ADC_EnableEPWMTriggerChannel
 **			ʹ�� EPWM ���������ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMTriggerChannel(uint32_t ChannelMask);
/*****************************************************************************
 ** \brief	ADC_DisableEPWMTriggerChannel
 **			�ر� EPWM ���������ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_DisableEPWMTriggerChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_EnableEPWMZeroTriggerChannel
 **			ʹ�� EPWM ��㴥����ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_26_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMZeroTriggerChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_DisableEPWMZeroTriggerChannel
 **			�ر� EPWM ��㴥����ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_26_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_DisableEPWMZeroTriggerChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_EnableEPWMPerioTriggerChannel
 **			ʹ�� EPWM ���ڵ㴥����ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_26_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMPerioTriggerChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_DisableEPWMPerioTriggerChannel
 **			�ر� EPWM ���ڵ㴥����ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_26_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_DisableEPWMPerioTriggerChannel(uint32_t ChannelMask);
	
/*****************************************************************************
 ** \brief	ADC_EnableEPWMCmp0TriggerChannel
 **			ʹ�� EPWM �Ƚ���0 ������ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_26_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMCmp0TriggerChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_EnableEPWMCmp0TriggerChannel
 **			ʹ�� EPWM �Ƚ���0 ������ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMCmp0TriggerChannel(uint32_t ChannelMask);
/*****************************************************************************
 ** \brief	ADC_DisableEPWMCmp0TriggerChannel
 **			�ر� EPWM �Ƚ���0 ������ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_DisableEPWMCmp0TriggerChannel(uint32_t ChannelMask);

/*****************************************************************************
 ** \brief	ADC_EnableEPWMCmp1TriggerChannel
 **			ʹ�� EPWM �Ƚ���1 ������ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMCmp1TriggerChannel(uint32_t ChannelMask);
/*****************************************************************************
 ** \brief	ADC_DisableEPWMCmp1TriggerChannel
 **			�ر� EPWM �Ƚ���1 ������ADCת��ͨ��
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_DisableEPWMCmp1TriggerChannel(uint32_t ChannelMask);


/*****************************************************************************
 ** \brief	ADC_EnableCompare
 **			����ADC�ȽϹ���
 ** \param [in] Compare : ADC_CMP0 ��ADC_CMP1
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableCompare(uint8_t ACMPx, uint32_t Compare);
/*****************************************************************************
 ** \brief	ADC_DisableCompare
 **			�ر�ADC�ȽϹ���
 ** \param [in] Compare : ADC_CMP0 ��ADC_CMP1
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_DisableCompare(uint8_t ACMPx);
/*****************************************************************************
 ** \brief	ADC_ConfigCompare
 **			����ADC�ȽϹ���
 ** \param [in]  Compare : ADC_CMP0 ��ADC_CMP1
 **				 CmpMode:(1)ADC_CMP_LESS_THAN_RESULT
 **						 (2)ADC_CMP_NOT_LESS_THAN_RESULT
 **				 CmpCount: 0x00~0xf  Ԥ��Ƚϴ���
 **				 CmpChannel: ADC_CH_0 ~ ADC_CH_30
 **				 CmpData : 12 bit �Ƚ�ֵ
 ** \return  none
 ** \note	���ڲ�����������ADCCMPxMCNT+1��ֵʱ����ADC�Ƚ��¼���
*****************************************************************************/
void ADC_ConfigCompare(uint8_t ACMPx, uint32_t CmpMode, uint32_t CmpCount,  
						uint32_t CmpChannel, uint32_t CmpData);

/*****************************************************************************
 ** \brief	ADC_GetCompareResult
 **			��ȡADC�Ƚ������
 ** \param [in] Compare : ADC_CMP0 ��ADC_CMP1
 ** \return  1 /0
 ** \note	
*****************************************************************************/
uint32_t ADC_GetCompareResult(uint8_t ACMPx);


/*****************************************************************************
 ** \brief	ADC_Start
 **			����ADC
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_Start(void);
/*****************************************************************************
 ** \brief	ADC_Stop
 **			�ر�ADC
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_Stop(void);

/*****************************************************************************
 ** \brief	ADC_EnableReset
 **			��λADC
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableReset(void);

/*****************************************************************************
 ** \brief	ADC_EnableCompareInt
 **			����ADC�Ƚ��ж�
 ** \param [in] none
 ** \return  none
 ** \note	ֻ֧�ֱȽ��� 0 
*****************************************************************************/
void ADC_EnableCompareInt(void);
/*****************************************************************************
 ** \brief	ADC_DisableCompareInt
 **			�ر�ADC�Ƚ��ж�
 ** \param [in] none
 ** \return  none
 ** \note	ֻ֧�ֱȽ��� 0 
*****************************************************************************/
void ADC_DisableCompareInt(void);
/*****************************************************************************
 ** \brief	ADC_GetCompareIntFlag
 **			��ȡADC�Ƚ��ж�ʹ�ܲ��Ҳ����жϱ�־λ
 ** \param [in] none
 ** \return  1:�ж�ʹ�ܲ��Ҳ����ж� 0�����ж�
 ** \note	ֻ֧�ֱȽ��� 0 
*****************************************************************************/
uint32_t ADC_GetCompareIntFlag(void);
/*****************************************************************************
 ** \brief	ADC_ClearCompareIntFlag
 **			���ADC�Ƚ��жϱ�־λ
 ** \param [in] none
 ** \return  none
 ** \note	ֻ֧�ֱȽ��� 0 
*****************************************************************************/
void ADC_ClearCompareIntFlag(void);

/*****************************************************************************
 ** \brief	ADC_EnableChannelInt
 **			����ADCͨ��n�ж�
 ** \param [in]ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_EnableChannelInt(uint32_t ChannelMask);
/*****************************************************************************
 ** \brief	ADC_DisableChannelInt
 **			�ر�ADCͨ��n�ж�
 ** \param [in] ChannelMask: ADC_CH_0_MSK ~ ADC_CH_30_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_DisableChannelInt(uint32_t ChannelMask);
/*****************************************************************************
 ** \brief	ADC_GetChannelIntFlag
 **			��ȡADCͨ��n�ж�ʹ�ܲ��Ҳ����жϱ�־λ
 ** \param [in] Channel:ADC_CH_0 ~ ADC_CH_30
 ** \return  1:�ж�ʹ�ܲ��Ҳ����ж� 0�����ж�
 ** \note	
*****************************************************************************/
uint32_t ADC_GetChannelIntFlag(uint32_t Channel);
/*****************************************************************************
 ** \brief	ADC_ClearChannelIntFlag
 **			���ADCͨ��n�жϱ�־λ
 ** \param [in] Channel:ADC_CH_0 ~ ADC_CH_30
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_ClearChannelIntFlag(uint32_t Channel);

/*****************************************************************************
 ** \brief	ADC_EnableEPWMCmp0TriggerDelayTime
 **			ʹ��  EPWM �Ƚ���0 ������ADC ��ʱ
 ** \param [in] none
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMCmp0TriggerDelayTime(void);
/*****************************************************************************
 ** \brief	ADC_DisableEPWMCmp0TriggerDelayTime
 **			�ر� EPWM �Ƚ���0 ������ADC ��ʱ
 ** \param [in] none
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_DisableEPWMCmp0TriggerDelayTime(void);
/*****************************************************************************
 ** \brief	ADC_EnableEPWMCmp1TriggerDelayTime
 **			ʹ��  EPWM �Ƚ���1 ������ADC ��ʱ
 ** \param [in] none
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_EnableEPWMCmp1TriggerDelayTime(void);
/*****************************************************************************
 ** \brief	ADC_DisableEPWMCmp1TriggerDelayTime
 **			�ر� EPWM �Ƚ���1 ������ADC ��ʱ
 ** \param [in] none
 ** \return  none
 ** \note  
*****************************************************************************/
void ADC_DisableEPWMCmp1TriggerDelayTime(void);

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H_ */

