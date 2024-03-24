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
/** \file pga.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "pga.h"
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

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	 OPA_ConfigGain
 **			 ����PGA����
 ** \param [in] pga :PGA0x ��PGA1x��PGA2x��PGA2x
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


void PGA_ConfigGain(PGA_TypeDef PGAUnit, uint32_t Gain)
{
	uint32_t Temp=0;
	
	if(PGAUnit == PGA0x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGA0CON0;
		Temp &= ~(PGA0_CON_PS_Msk);
		Temp |= Gain;
		PGA0->PGA0CON0 = Temp;
		PGA0->PGALOCK = PGALOCKVal;
	}

	else
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGANCON1;
		Temp &= ~(PGAN_CON_PGA123S_Msk);
		Temp |= Gain << PGAN_CON_PGA123S_Pos;
		PGA0->PGANCON1 = Temp;
		PGA0->PGALOCK = PGALOCKVal;
	}
}

/*****************************************************************************
 ** \brief	 PGA_ConfigResistorPAD
 **			 ����PGA0�����������
 ** \param [in] pga :PGA0 
 **				GndMode:	(1) PGA_R_None������������
 **							    (2) PGA_R_10K	������10K�ĵ���
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_ConfigResistorPAD(uint32_t GndMode)
{
	uint32_t Temp=0;
	
//	CGC->RSTM = 1;	//close P02 reset
	PGA0->PGALOCK = PGAUNLOCK;
	Temp = PGA0->PGA0CON0;
	Temp &= ~(PGA0_CON_OTSELR_Msk);
	Temp |= GndMode;
	PGA0->PGA0CON0 = Temp;	
	PGA0->PGALOCK = PGALOCKVal;
}

/*****************************************************************************
 ** \brief	 PGA_ConfigDriveCurrent
 **			 ����PGA�����������
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x 
 **				GndMode:	(1) PGA_C_20uA	����������20ua
 **							    (2) PGA_C_40uA	����������40ua
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_ConfigDriveCurrent(PGA_TypeDef PGAUnit,uint32_t DCurrent)
{
	uint32_t Temp=0;
	if(PGAUnit == PGA0x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGA0CON0;
		Temp &= ~(PGA0_CON_DRV_Msk);
		Temp |= DCurrent << PGA0_CON_DRV_Pos;
		PGA0->PGA0CON0 = Temp;	
		PGA0->PGALOCK = PGALOCKVal;
	}
	else
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGANCON1;
		Temp &= ~(PGAN_CON_PGA123DRV_Msk);
		Temp |= DCurrent << PGAN_CON_PGA123DRV_Pos;
		PGA0->PGANCON1 = Temp;	
		PGA0->PGALOCK = PGALOCKVal;
	}
		
}

/*****************************************************************************
 ** \brief	 PGA_EnableOutput
 **			 ����PGA���
 ** \param NONE
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_EnableOutput(void)
{

		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGA0CON0 |=( 0x1<< PGA0_CON_OTEN_Pos);
		PGA0->PGALOCK = PGALOCKVal;

}

/*****************************************************************************
 ** \brief	 PGA_DisableOutput
 **			 �ر�PGA���
 ** \param none
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_DisableOutput(PGA_TypeDef PGAUnit)
{

		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGA0CON0 &= ~( 0x1<< PGA0_CON_OTEN_Pos);
		PGA0->PGALOCK = PGALOCKVal;

}

/*****************************************************************************
 ** \brief	 PGA_VrefCtrl
 **			 PGA0�ο���ѹ����
 ** \param [in] VrefStat :
**                  VrefHalf:VREF/2
**                  PGA0BG:BG(0.8V)
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_VrefCtrl(PGAVref_TypeDef VrefStat)
{

		PGA0->PGALOCK = PGAUNLOCK;
		if(VrefStat == VrefHalf)
			PGA0->PGA0CON0 &= ~PGA0_CON_VREF_Msk;
		else
			PGA0->PGA0CON0 |= PGA0_CON_VREF_Msk;
		PGA0->PGALOCK = PGALOCKVal;

}

/*****************************************************************************
 ** \brief	 PGA_FBCap_Config
 **			 ����PGA�������ݽ���򲻽���
 ** \param [in] pga :PGA0x,PGA1x,PGA2x,PGA3x 
 **				   Para:	(1) ENABLE	�����벹������
 **							    (2) DISABLE	�������벹������
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_FBCap_Config(PGA_TypeDef PGAUnit,uint32_t Para)
{
	uint32_t Temp=0;
	if(PGAUnit == PGA0x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGA0CON0;
//		Temp &= ~(PGA0_CON_FBCMP_Msk);
//		Temp |= Para << PGA0_CON_FBCMP_Pos;
		PGA0->PGA0CON0 = Temp;	
		PGA0->PGALOCK = PGALOCKVal;
	}
	else
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGANCON1;
//		Temp &= ~(PGAN_CON_PGA123FBCNP_Msk);
//		Temp |= Para << PGAN_CON_PGA123FBCNP_Pos;
		PGA0->PGANCON1 = Temp;	
		PGA0->PGALOCK = PGALOCKVal;
	}
}

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
void PGA_Filter_Set(PGA_TypeDef PGAUnit,uint8_t FltBand)
{
	uint32_t Temp=0;
	FltBand = FltBand & 0x07;
	if(PGAUnit == PGA0x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGA0CON0;
		Temp &= ~(PGA0_CON_BW_Msk);
		Temp |= FltBand << PGA0_CON_BW_Pos;
		PGA0->PGA0CON0 = Temp;	
		PGA0->PGALOCK = PGALOCKVal;
	}
	else if(PGAUnit == PGA1x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGANCON0;
		Temp &= ~(PGAN_CON_PGA1BW_Msk);
		Temp |= FltBand << PGAN_CON_PGA1BW_Pos;
		PGA0->PGANCON0 = Temp;	
	
		PGA0->PGALOCK = PGALOCKVal;
	}
	else if(PGAUnit == PGA2x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGANCON0;
		Temp &= ~(PGAN_CON_PGA2BW_Msk);
		Temp |= FltBand << PGAN_CON_PGA2BW_Pos;
		PGA0->PGANCON0 = Temp;	
	
		PGA0->PGALOCK = PGALOCKVal;
	}	
	else if(PGAUnit == PGA3x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		Temp = PGA0->PGANCON1;
		Temp &= ~(PGAN_CON_PGA3BW_Msk);
		Temp |= FltBand << PGAN_CON_PGA3BW_Pos;
		PGA0->PGANCON1 = Temp;	
	
		PGA0->PGALOCK = PGALOCKVal;
	}	
}

/*****************************************************************************
 ** \brief	 PGA_Start
 **			 ����PGA
 ** \param [in] pga :PGA0x ��PGA1x��PGA2x
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Start(PGA_TypeDef PGAUnit)
{
	if(PGAUnit == PGA0x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGA0CON0 |= PGA0_CON_EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}
	else if(PGAUnit == PGA1x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGANCON0 |= PGAN_CON_PGA1EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}	
	else if(PGAUnit == PGA2x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGANCON0 |= PGAN_CON_PGA2EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}	
	else 
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGANCON1 |= PGAN_CON_PGA3EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}		
}

/*****************************************************************************
 ** \brief	 PGA_Stop
 **			 �ر�PGA
 ** \param [in] pga :PGA0 ��PGA1
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_Stop(PGA_TypeDef PGAUnit)
{
	if(PGAUnit == PGA0x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGA0CON0 &= ~PGA0_CON_EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}
	else if(PGAUnit == PGA1x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGANCON0 &= ~PGAN_CON_PGA1EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}	
	else if(PGAUnit == PGA2x)
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGANCON0 &= ~PGAN_CON_PGA2EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}	
	else 
	{
		PGA0->PGALOCK = PGAUNLOCK;
		PGA0->PGANCON1 &= ~PGAN_CON_PGA3EN_Msk;
		PGA0->PGALOCK = PGALOCKVal;
	}	

}

/*****************************************************************************
 ** \brief	 PGA_ClampOut_Set
 **			 ����PGA123ǯλ������ʹ��
 ** \param [in] PGAUnit :PGA1x��PGA2x��PGA3x
 **				   Para:	(1) ENABLE	��PGAx��IO����ǯλ������ʹ��
 **							    (2) DISABLE	��PGAx��IO����ǯλ�����ܽ�ֹ
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA_ClampOut_Set(PGA_TypeDef PGAUnit,FunctionalState Para)
{
	PGA0->PGALOCK = PGAUNLOCK;
	if(Para == ENABLE)
	{
		PGA0->PGANSW |= 1 << (PGAN_CON_PGA1IOEN_Pos + PGAUnit - 1);
	}
	else
	{
		PGA0->PGANSW &= ~(1 <<(PGAN_CON_PGA1IOEN_Pos + PGAUnit - 1));
	}
	PGA0->PGALOCK = PGALOCKVal;	
}	
	
/*****************************************************************************
 ** \brief	 PGA0_SampleHold_Set
 **			 ����PGA0��������ʹ��
 ** \param [in] Para:
 **				   	     (1) ENABLE	��ʹ��PGA0�Ĳ�������
 **							   (2) DISABLE	����ֹPGA0�Ĳ�������
 ** \return  none	
 ** \note    
 *****************************************************************************/
void PGA0_SampleHold_Set(FunctionalState Para)	
{
	PGA0->PGALOCK = PGAUNLOCK;
	if(Para == ENABLE)
		PGA0->PGA0CON0 |= PGA0_CON_HOLD_Msk;
	else
		PGA0->PGA0CON0 &= ~PGA0_CON_HOLD_Msk;
	PGA0->PGALOCK = PGALOCKVal;	
	
}	
	
	
	




