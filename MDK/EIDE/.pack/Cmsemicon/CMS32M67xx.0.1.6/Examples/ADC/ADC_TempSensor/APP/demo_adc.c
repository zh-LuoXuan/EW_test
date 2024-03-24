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
/** \file demo_adcb.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_adc.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/
extern double voltage;
/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/


/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	ADCB_Software_Trigger_Mode
 **			����ADC�������ת��
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void ADC_TempSensor_Mode(void)
{
	/*
	(1)����ADCʱ��
	*/
	CGC_PER13PeriphClockCmd(CGC_PER13Periph_ADCEN,ENABLE);

	ADC_ConfigRunMode(ADC_MODE_HIGH,ADC_CONVERT_SINGLE,ADC_CLK_DIV_32,100);	/*����ģʽ+����ģʽ+32��Ƶ+100.5 ADCClk��������ʱ��*/
	
	ADC_ConfigChannelSwitchMode(ADC_SWITCH_HARDWARE);	/*Ӳ���Զ��л�*/
	
	ADC_DisableChargeAndDischarge();					/*�رճ��\�ŵ繦��*/
	
	ADC_ConfigVREF(ADC_VREFP_VDD);		/*���òο�Դ*/

	/*
	(2)����ADCͨ��ʹ��
	*/	
	ADC_EnableScanChannel(ADC_CH_25_MSK);				/*ѡ��AN25*/	
	ADC_SelAN25Source(ADC_AN25_SEL_TS);
	/*
	(3)����ADC�ж�
	*/		
	
	ADC_EnableChannelInt(ADC_CH_25_MSK);				/*��AN25ת���ж�*/	
	NVIC_EnableIRQ(ADC_IRQn);
	/*
	(4)�������ȼ�
	*/	
	NVIC_SetPriority(ADC_IRQn,2);					/*���ȼ�0~3�� 0��ߡ�3���*/	
	/*
	(5)����ADCB
	*/		
	ADC_Start();
			
}

/***********************************************************************************************************************
* Function Name: adc_get_temperature
* @brief  ADC Get temperature
* @param  dat - the adc conversion value of ADC_TEMPERSENSOR0 channel
* @return temperature
***********************************************************************************************************************/
#if 0
double adc_get_temperature(float dat)
{
	double temp;    /* temperature value */

	temp = (double)(dat - ADCTempSensor_Judge(TSN->TSN25))/(-0.0035) + 25;   /* 12bit dat */
	return (temp);
}
#else
int16_t adc_get_temperature(float dat)
{
	int16_t temp;   /* temperature value */

  temp = (int16_t)((dat - ADCTempSensor_Judge(TSN->TSN25))/(-0.0035)) + 25;     /* 12bit dat */

	return (temp);
}
#endif


double ADCTempSensor_Judge(int16_t AdcVal)
{
	double RtValue=0;
	RtValue = (double)AdcVal * voltage / 4096;
//	RtValue = RtValue * 4096/3;
	return(RtValue);
}