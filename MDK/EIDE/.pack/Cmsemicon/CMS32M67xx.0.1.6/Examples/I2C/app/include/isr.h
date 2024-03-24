#ifndef _ISR_H__
#define _ISR_H__
#include <stdbool.h>
#include "common.h"


#define	ISR_SUCC   0
#define	ISR_ERR    1

typedef void(*isrFun_t)(void *msg);




typedef enum
{
	INT_IDLE = 0,
	INT_RX = 1,
	INT_TX = 2,
	INT_DMA =3,
}DATA_DIR_t;

typedef struct 
{
	DATA_DIR_t flag;
	uint32_t len;
	volatile uint8_t *data;
}ATE_FRAME_t;



/** @defgroup ISR_t 
  * @{
  */ 
typedef struct
{	
	bool IRQ_Flag;
	isrFun_t intHandle;
}ISR_t;


typedef struct
{
  IRQn_Type IRQ_Channel;  /*!< This member configures the IRQ channel. */
	
  ISR_t  IRQ[32];     /*!< This member configures the IRQ interrupt route and whether irq channel is used. 
							  This parameter can be a value of @ref ISR_t*/						
}ISR_InitTypeDef_t;

extern ATE_FRAME_t pData;
extern ISR_InitTypeDef_t IRQ_Fun;

int ISR_Register(IRQn_Type irq_num, void *interrupt);


#endif
