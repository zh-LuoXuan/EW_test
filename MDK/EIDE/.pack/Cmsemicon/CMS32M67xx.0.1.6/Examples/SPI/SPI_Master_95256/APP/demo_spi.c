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
/** \file demo_spi.c
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_spi.h"
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
/*****************************************************************************
 ** \brief	SPI_M95256_Start		
 ** \param [in] none
 ** \return  none
 ** \note	
*****************************************************************************/
void SPI_M95256_Start(void)
{
	SSP_MasterClearCS();
}
/*****************************************************************************
 ** \brief	SPI_M95256_Stop
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_M95256_Stop(void)
{
	SSP_MasterSetCS();
}
/*****************************************************************************
 ** \brief	SPI_Transmit
 **			
** \param [in] SendData: ���͵�ֵ
 ** \return  16bit ��ȡ��ֵ
 ** \note	
*****************************************************************************/
uint32_t  SPI_Transmit(uint32_t  Data)
{
	while(SSP_GetBusyFlag());			
//	while(!SSP_GetTFEFlag());
	SSP_SendData(Data);
//	while(!SSP_GetRNEFlag());
	return (SSP_GetData());			
}
/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/***************************************************************************
 ** \brief	 SPI_Master_Mode
 **
 ** \param [in]  none   
 ** \return none
 ** \note
***************************************************************************/
void SPI_Master_Mode(void)
{
	/*
	(1)����SSP��ʱ��
	*/
	CGC_PER12PeriphClockCmd(CGC_PER12Periph_SPI,ENABLE);		/*����SSPģ��ʱ��*/
	SSP_ConfigClk(23,2);					/*Fapb = 48Mhz,  sclk = 1Mhz*/								
	/*
	(2)����SSP ΪSPIģʽ
	*/							
	SSP_ConfigRunMode(SSP_FRAME_SPI,SSP_CPO_0,SSP_CPHA_0,SSP_DAT_LENGTH_8);	/*����ΪSPIģʽ������95256��ʱ������λ����CPHA =0, CP0 = 0(ʱ�ӿ���ʱΪ0)*/																		
	/*
	(3)����SPI ����ģʽ
	*/
	SSP_EnableMasterMode();							/*����SPIΪ����ģʽ*/
	SSP_DisableMasterAutoControlCS();			
	/*
	(4)����SPI IO
	*/
	GPIO_PinAFOutConfig(P07CFG,IO_OUTCFG_P07_SCLK);
	GPIO_Init(PORT0,PIN7,OUTPUT);
	
	GPIO_PinAFOutConfig(P14CFG,IO_OUTCFG_P14_MISO);
	GPIO_Init(PORT1,PIN4,INPUT);	
	
	GPIO_PinAFOutConfig(P15CFG,IO_OUTCFG_P15_MOSI);
	GPIO_Init(PORT1,PIN5,OUTPUT);	
	CGC->RSTM = 1;
	GPIO_PinAFOutConfig(P06CFG,IO_OUTCFG_P06_NSS);
	GPIO_Init(PORT0,PIN6,OUTPUT);	

	/*
	(5)����SPI
	*/	
	SPI_M95256_Stop();	
	SSP_Start();
	
}
/***************************************************************************
 ** \brief	 SPI_M95256_Write
 **			 
 ** \param [in]  addr: 
 **				 buf:
 ** \return 
 ** \note
***************************************************************************/
void SPI_M95256_Write(uint32_t addr, uint32_t buf)
{
	uint32_t temp;
	
	SPI_M95256_Start();
	SPI_Transmit(M95256_WREN);
	SPI_M95256_Stop();			
	for(temp=2;temp>0;temp--);	
	
	SPI_M95256_Start();
	SPI_Transmit(M95256_WRITE);	
	SPI_Transmit(addr>>16);
	SPI_Transmit(addr>>8);
	SPI_Transmit(addr);		
	SPI_Transmit(buf);	
	SPI_M95256_Stop();	

	for(temp=2;temp>0;temp--);	
	SPI_M95256_Start();
	SPI_Transmit(M95256_WRDI);
	SPI_M95256_Stop();		

}
/***************************************************************************
 ** \brief	 SPI_M95256_Read_Data
 **			
** \param [in]  addr :   
 ** \return 8bit Data
 ** \note
***************************************************************************/
uint32_t SPI_M95256_Read_Data(uint32_t addr)
{
	uint32_t temp;
	SPI_M95256_Start();
	SPI_Transmit(M95256_READ);
	SPI_Transmit(addr>>16);	
	SPI_Transmit(addr>>8);
	SPI_Transmit(addr);
	temp = SPI_Transmit(0x00);		
	SPI_M95256_Stop();
	return temp;
}

/***************************************************************************
 ** \brief	 SPI_M95256_Read_SFR
 **			
 ** \param [in]  cmd:	
 ** \return 8bit Data
 ** \note
***************************************************************************/
uint32_t  SPI_M95256_Read_SFR(uint32_t cmd)
{
	uint8_t temp;
	SPI_M95256_Start();
	SPI_Transmit(cmd);
	temp = SPI_Transmit(0x00);
	SPI_M95256_Stop();	
	return temp;	
}



