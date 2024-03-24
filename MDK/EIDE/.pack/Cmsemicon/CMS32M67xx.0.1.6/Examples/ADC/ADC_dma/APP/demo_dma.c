#include "demo_dma.h"
unsigned char CTRL_DATA_UART0 = 4;
unsigned char CTRL_DATA_ADC = 1;
/***********************************************************************************************************************
* Function Name: DMA_Uart0_Tx
* @brief  config DMA for uart tx
* @param  src_adr: dma source address
* @param  dst_adr: dma destine address
* @param  count: dma transform num
* @return None
***********************************************************************************************************************/
extern  volatile uint8_t  * sfr_addr;
void DMA_Uart0_Tx(DMA_VECTOR_t dma_vector, DMA_Mode_t mode,void *src_adr, void *dst_adr,uint16_t count)
{
	DMA_InitTypeDef  DMA_InitStructure ={0};
	unsigned int CTRL_DATA = 4;

	DMA_InitStructure.DMA_Vector = dma_vector;    //���ݹ���ѡ��ͬ��dma������
	DMA_InitStructure.DMA_CtrlId = CTRL_DATA;     //ѡ�����������
	DMA_InitStructure.DMA_SrcAddr = (uint32_t)src_adr;  //����dmaԴ��ַ
	DMA_InitStructure.DMA_DstAddr = (uint32_t)dst_adr;  //����dmaĿ���ַ
	DMA_InitStructure.DMA_BufferSize = count;
	DMA_InitStructure.DMA_SrcInc = DMA_SrcInc_Enable;//Դ��ַ����ģʽ
	DMA_InitStructure.DMA_DstInc = DMA_DstInc_Disable;//Ŀ���ַ�̶�
	DMA_InitStructure.DMA_DataSize = DMA_DataSize_Byte;//�������ݳ���ѡ��
	DMA_InitStructure.DMA_Mode = mode;//��ͨģʽ
	
	DMA_Init(&DMA_InitStructure);

	DMA_Start(DMA_InitStructure.DMA_Vector);
}

/***********************************************************************************************************************
* Function Name: DMA_ADC_Config
* @brief  config DMA for uart read
* @param  src_adr: dma source address
* @param  dst_adr: dma destine address
* @param  count: dma transform num
* @return None
***********************************************************************************************************************/
void DMA_ADC_Config(DMA_VECTOR_t dma_vector, DMA_Mode_t mode,void *src_adr, void *dst_adr,uint16_t count)
{
	DMA_InitTypeDef  DMA_InitStructure ={0};


	DMA_InitStructure.DMA_Vector = dma_vector;    //���ݹ���ѡ��ͬ��dma������
	DMA_InitStructure.DMA_CtrlId = CTRL_DATA_ADC;     //ѡ�����������
	DMA_InitStructure.DMA_SrcAddr = (uint32_t)src_adr;  //����dmaԴ��ַ
	DMA_InitStructure.DMA_DstAddr = (uint32_t)dst_adr;  //����dmaĿ���ַ
	DMA_InitStructure.DMA_BufferSize = count;
	DMA_InitStructure.DMA_SrcInc = DMA_SrcInc_Disable;//Դ��ַ�̶�ģʽ
	DMA_InitStructure.DMA_DstInc = DMA_DstInc_Enable;//Ŀ���ַ����
	DMA_InitStructure.DMA_DataSize = DMA_DataSize_HalfWord;//�������ݳ���ѡ��
	DMA_InitStructure.DMA_Mode = mode;
	DMA_InitStructure.DMA_RepeatAreaAddr = DMA_RepeatAreaAddr_Dst;//����ģʽ�£��ظ���ѡ����Ч���ظ�ģʽ����Ч������Ŀ��Ϊ�ظ���
	DMA_InitStructure.DMA_RepeatInt = DMA_RepeatInt_Disable;//�ظ�ģʽ����Ч�������ж�	
	DMA_Init(&DMA_InitStructure);
	DMA_Start(DMA_InitStructure.DMA_Vector);
}

