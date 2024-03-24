#ifndef __DMA_H__
#define __DMA_H__
#include <stdint.h>
#include "common.h"

typedef enum {
   DMA_VECTOR_FLASH     =  0U,  /* Flash擦除/写入结束 */
   DMA_VECTOR_ADC 	=  1U,  /*  A/D 转换结束  */
   DMA_VECTOR_SPI 	=  2U,  /* SPI转换结束  */
   DMA_VECTOR_IICA 	=  3U,  /*  IIC转换结束  */
   DMA_VECTOR_UART0 	=  4U,  /* UART0接收/发送完成 */
   DMA_VECTOR_UART1   	=  5U,  /* UART1接收/发送完成 */
   DMA_VECTOR_EPWM      =  6U,  /* epwm */
   DMA_VECTOR_TIMER0      =  7U,  /* timer0 */

}DMA_VECTOR_t;

#define DMA_SrcInc_Enable      (uint16_t)0x0004
#define DMA_SrcInc_Disable     (uint16_t)0x0000

#define DMA_DstInc_Enable      (uint16_t)0x0008
#define DMA_DstInc_Disable     (uint16_t)0x0000

#define DMA_DataSize_Byte                ((uint16_t)0x0000) 
#define DMA_DataSize_HalfWord            ((uint16_t)0x0040) 
#define DMA_DataSize_Word                ((uint16_t)0x0080)

typedef enum
{
	DMA_Mode_Normal,
	DMA_Mode_Repeat	
}DMA_Mode_t;


#define DMA_RepeatAreaAddr_Src           ((uint8_t)0x02) 
#define DMA_RepeatAreaAddr_Dst 			 ((uint8_t)0x00)

#define DMA_RepeatInt_Enable             ((uint8_t)0x20) 
#define DMA_RepeatInt_Disable            ((uint8_t)0x00)


#define DMA_ChainTrans_None             ((uint8_t)0x00) 
#define DMA_ChainTrans_Head             ((uint8_t)0x01) 
#define DMA_ChainTrans_Node             ((uint8_t)0x02) 
#define DMA_ChainTrans_Tail             ((uint8_t)0x03) 
typedef struct
{
	DMA_VECTOR_t DMA_Vector;            /*!< Specifies the Vector used for the dma start source . 
	                                    This parameter can be a value of @ref DMA_VECTOR_t */
											
	uint16_t DMA_CtrlId;			/*!< Specifies the control data area id for the dma */
										  											
	uint32_t DMA_SrcAddr; /*!< Specifies the peripheral source base address for DMA */

	uint32_t DMA_DstAddr;    /*!< Specifies the peripheral destion base address for DMA*/
	                                    

	uint16_t DMA_BufferSize;         /*!< Specifies the buffer size, in data unit, of the specified Stream. */ 
	                                    
//	uint16_t DMA_BlockSize;         /*!< Specifies the DMA block size when transmittion,it can be 0x0000~0xFFFF. */ 
	                                    
	uint16_t DMA_SrcInc;      /*!< Specifies whether the Peripheral source address register should be incremented or not.
	                                   This parameter can be a value of @ref DMA_peripheral_incremented_mode */

	uint16_t DMA_DstInc;          /*!< Specifies whether the destnation address register should be incremented or not.
	                                    This parameter can be a value of @ref DMA_memory_incremented_mode */

	uint16_t DMA_DataSize;    /*!< Specifies the Peripheral data width.
	                                    This parameter can be a value of @ref DMA_peripheral_data_size */

	uint8_t DMA_Mode;               /*!< Specifies the operation mode of the DMA.
	                                    This parameter can be a value of @ref DMA_circular_normal_mode
	                                    @note The circular buffer mode cannot be used if the memory-to-memory
	                                          data transfer is configured on the selected Stream */


	uint8_t DMA_RepeatAreaAddr;          /*!< Specifies if the source or destnation address will be used for repeat area in DMA_Mode_Repeat
	                                    This parameter can be a value of @ref DMA_RepeatAddr
	                                    @note The DMA_RepeatAddr cannot be configured in Normal mode */
	                                            
	uint8_t DMA_RepeatInt;		  /*!< Specifies if interrupt is occured when transimission is finished in repeat area
										  This parameter can be a value of @ref DMA_RepeatInt
										  @note The DMA_RepeatInt is not effective in Normal mode */

	uint8_t DMA_ChainTrans;		  /*!< multi-control data transimission is triggered by one vector 
										  This parameter can be a value of @ref DMA_ChainTranStart*/
										 
}DMA_InitTypeDef;

void DMA_Start(DMA_VECTOR_t vect_num);
void DMA_Init(DMA_InitTypeDef * DMA_InitStruct);
void DMA_Stop(DMA_VECTOR_t vect_num);
void DMA_Trigger(DMA_VECTOR_t vect_num);

#endif
