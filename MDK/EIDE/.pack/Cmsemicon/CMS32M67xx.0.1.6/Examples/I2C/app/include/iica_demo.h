#ifndef __IICA_DEMO_H__

#include "i2ca.h"
#include "gpio.h"
#include "isr.h"

//#define I2CA_USING_POLLING
#define I2CA_USING_INTERRUPT

void iica0_interrupt(void *msg);
void Iica0_Init(void);

void IICA_SlaveSend(uint8_t adr, uint8_t *const tx_buf, uint16_t tx_num);
void IICA_SlaveReceive(uint8_t adr, uint8_t *const rx_buf, uint16_t rx_num);
int IICA_MasterWrite(uint8_t adr, uint8_t *tx_buf, uint16_t tx_num, uint8_t wait);
int IICA_MasterReceive(uint8_t adr, uint8_t *const rx_buf, uint16_t rx_num, uint8_t wait);



#endif
