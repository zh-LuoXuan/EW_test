#include "iica_demo.h"
volatile uint8_t   g_iica_tx_end;             /* iica0 send data end */
volatile uint8_t   g_iica_rx_end;             /* iica0 receive data end */
uint16_t  g_iica_rx_cnt;                     /* iica1 receive data count */

#define _80_IICA_ADDRESS_COMPLETE                     (0x80U)
#define _00_IICA_MASTER_FLAG_CLEAR                    (0x00U)

void Iica0_Init(void)
{
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
    I2CA_InitTypeDef I2CA_InitStructure;

    /*SCLA0 GPIO CONFIG*/
		GPIO_PinAFOutConfig(P04CFG,IO_OUTCFG_P04_SCL);	
		GPIO_Init(PORT0,PIN4,OPENDRAIN_OUTPUT);
		PORT_PullUp(PORT0,PIN4); //PULL UP P04
		PORT_ClrBit(PORT0,PIN4);


    /*SDAA0 GPIO CONFIG*/ 
		GPIO_PinAFOutConfig(P05CFG,IO_OUTCFG_P05_SDA);	
		GPIO_Init(PORT0,PIN5,OPENDRAIN_OUTPUT);
		PORT_PullUp(PORT0,PIN5); //PULL UP P04
		PORT_ClrBit(PORT0,PIN5);
		

    I2CA_InitStructure.I2C_ClockSpeed = 10000;
    I2CA_InitStructure.I2C_Ack = I2CA_Ack_Enable;
    I2CA_InitStructure.I2C_DutyCycle = 50;
    I2CA_InitStructure.I2C_OwnAddress = 0xA0;
    I2CA_InitStructure.I2C_Mode = I2CA_Mode_SMBusMaster;
    I2CA_Init(&I2CA_InitStructure);
#ifdef I2CA_USING_INTERRUPT
//		ISR_Register(I2C0_IRQn, iica0_interrupt);

#endif
}


/***********************************************************************************************************************
* Function Name: IICA_MasterWrite
* @brief  This function starts to write data by interrupt as master mode.
* @param  adr - send address
* @param  tx_buf - transfer buffer pointer
* @param  tx_num - buffer size
* @param  wait :wait for start condition
* @return status
*             - MD_OK or MD_ERROR1 or MD_ERROR2
***********************************************************************************************************************/
int IICA_MasterWrite(uint8_t adr, uint8_t *tx_buf, uint16_t tx_num, uint8_t wait)
{
    I2CA_Status status = OK;

    if (I2CA_GetFlagStaus(I2CA_STATUS_BUSBSY) != RESET)
    {
        status = BUSY;
    }
    else
    {
			I2C->IICA0 = adr;      // write address
        I2CA_GenerateSTART();

        /* Wait */
        while (wait--)
        {
            ;
        }

        if (RESET == I2CA_GetFlagStaus(I2CA_STATUS_STD))   //if start condition does not occur
        {
            status = NSTART;
        }

        /* Set parameter */
        pData.data = tx_buf;
        pData.len = tx_num;
        pData.flag = INT_IDLE;
        g_iica_tx_end = 0;

        adr &= (uint8_t)0xFE;    // set write mode
        I2C->IICA0 = adr;      // write address
    }

    return (status);
}
/***********************************************************************************************************************
* Function Name: IICA_MasterRead
* @brief  This function starts to read data as master mode.
* @param  adr - receive address
* @param  rx_buf - transfer buffer pointer
* @param  rx_num - buffer size
* @param  wait :wait for start condition
* @return status
*             - MD_OK or MD_ERROR1 or MD_ERROR2
***********************************************************************************************************************/
int IICA_MasterReceive(uint8_t adr, uint8_t *const rx_buf, uint16_t rx_num, uint8_t wait)
{
    I2CA_Status status = OK;


    NVIC_DisableIRQ(I2C0_IRQn);   // disable INTIICA0 interrupt

    if (I2CA_GetFlagStaus(I2CA_STATUS_BUSBSY) != RESET)
    {
        /* Check bus busy */
        NVIC_EnableIRQ(I2C0_IRQn);   // enable INTIICA0 interrupt
        status = BUSY;
    }
    else
    {
        I2CA_GenerateSTART();     //generate a start condition
        NVIC_EnableIRQ(I2C0_IRQn);   // enable INTIICA0 interrupt

        /* Wait */
        while (wait--)
        {
            ;
        }

        if (RESET == I2CA_GetFlagStaus(I2CA_STATUS_STD))   //check no start condition occurs
        {
            status = NSTART;
        }

        /* Set parameter */
        pData.data = rx_buf;
        pData.len = rx_num;
        pData.flag = INT_IDLE;

        g_iica_rx_end = 0;
        g_iica_rx_cnt = 0;
        adr |= (uint8_t)0x01;       // set receive mode
        I2C->IICA0 = adr;       // write address
    }

    return (status);
}
#if 0
/***********************************************************************************************************************
* Function Name: IICA0_SlaveSend
* @brief  This function sends data as slave mode.
* @param  adr - send address
* @param  tx_buf - transfer buffer pointer
* @param  tx_num - buffer size
* @return None
***********************************************************************************************************************/
void IICA_SlaveSend(IICA_FUNC func, uint8_t adr, uint8_t *const tx_buf, uint16_t tx_num)
{
    IICA_RegSetting(func);

    pData.len = tx_num;
    pData.data = tx_buf;
    g_iica_tx_end = 0;
    pData.flag = INT_IDLE;
    *iica_reg.SVA = adr; /* slave address */
}
/***********************************************************************************************************************
* Function Name: IICA0_SlaveReceive
* @brief  This function receives data as slave mode.
* @param  adr - send address
* @param  tx_buf - receive buffer pointer
* @param  rx_num - buffer size
* @return None
***********************************************************************************************************************/
void IICA_SlaveReceive(IICA_FUNC func, uint8_t adr, uint8_t *const rx_buf, uint16_t rx_num)
{
    IICA_RegSetting(func);

    g_iica_rx_cnt = 0;
    g_iica_rx_end = 0;
    pData.len = rx_num;
    pData.data = rx_buf;
    pData.flag = INT_IDLE;
    *iica_reg.SVA = adr; /* slave address */
}
#endif
/***********************************************************************************************************************
* Function Name: IICA0_Clear_Wakeup
* @brief  This function clears the WUPn bit of IICCTL01 register.
* @param  None
* @return None
***********************************************************************************************************************/
void IICA0_Clear_Wakeup()
{
    I2C->IICCTL1 &= ~0x80; // WUP = 0
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
}

/***********************************************************************************************************************
* Function Name: iica0_master_send_end
* @brief  This function is a callback function when IICA0 finishes master transmission.
* @param  None
* @return None
***********************************************************************************************************************/
static void iica_master_send_end()
{

    I2C->IICCTL0 |= IICA_IICCTL00_SPT_Msk;             // stop condition is generated

    while (0U == I2CA_GetFlagStaus(I2CA_STATUS_SPD));   // stop condition is detected

    g_iica_tx_end = 1;
}

/***********************************************************************************************************************
* Function Name: iica0_master_recv_end
* @brief  This function is a callback function when IICA0 finishes master reception.
* @param  None
* @return None
***********************************************************************************************************************/
static void iica_master_recv_end()
{
    I2C->IICCTL0 |= IICA_IICCTL00_SPT_Msk;             /* stop condition is generated */

    while (0U == I2CA_GetFlagStaus(I2CA_STATUS_SPD));   /* stop condition is detected */

    g_iica_rx_end = 1;
}


/***********************************************************************************************************************
* Function Name: iica0_masterhandler
* @brief   This function is IICA0 master handler.
* @param  None
* @return None
***********************************************************************************************************************/
static void iica_master_error(I2CA_Status flag)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

static void iica0_masterhandler(void *msg)
{
    ATE_FRAME_t *pFrame = (ATE_FRAME_t *)msg;


    if ((I2CA_GetFlagStaus(I2CA_STATUS_BUSBSY) == RESET) && (pFrame->len != 0U))// Control for communication
    {
        iica_master_error(NSTOP);//IICSTOP
    }
    else // Control for sended address
    {
        if ((pFrame->flag & _80_IICA_ADDRESS_COMPLETE) == 0U) //write address uncompleted
        {
            if (I2CA_GetFlagStaus(I2CA_STATUS_ACK) != RESET)    //check iic received askd signal
            {
                pFrame->flag |= _80_IICA_ADDRESS_COMPLETE;  //write address completed

                if (I2CA_GetFlagStaus(I2CA_STATUS_TRC))  //sendding status
                {
                    I2C->IICCTL0 |= IICA_IICCTL00_WTIM_Msk;     // interrupt request is generated at the ninth clock's falling edge

                    if (pFrame->len > 0)
                    {
                        I2C->IICA0 = *pFrame->data;
                        pFrame->data++;
                        pFrame->len--;
                    }
                    else
                    {
                        iica_master_send_end();//iic master send finished
                    }
                }
                else          //receiving status
                {
                    I2C->IICCTL0 |= IICA_IICCTL00_ACKE_Msk;      // enable acknowledgment
                    I2C->IICCTL0 &= ~IICA_IICCTL00_WTIM_Msk;    // interrupt request is generated at the eighth clock's falling edge
                    I2C->IICCTL0 |= IICA_IICCTL00_WREL_Msk;     // cancel wait
                }
            }
            else
            {
                iica_master_error(NACK);//iic no ack
            }
        }
        else    //write address completed
        {
            if (I2CA_GetFlagStaus(I2CA_STATUS_TRC))  // master in sending status
            {
                if ((0U == I2CA_GetFlagStaus(I2CA_STATUS_ACK)) && (pFrame->len != 0U))
                {
                    iica_master_error(NACK);//iic no ack
                }
                else
                {
                    if (pFrame->len > 0U)
                    {
                        I2C->IICA0 = *pFrame->data;
                        pFrame->data++;
                        pFrame->len--;
                    }
                    else
                    {
                        iica_master_send_end();//iic master send finished
                    }
                }
            }
            else     //master receive control
            {
                if (g_iica_rx_cnt < pFrame->len)
                {
                    *pFrame->data = I2C->IICA0;
                    pFrame->data++;
                    g_iica_rx_cnt++;

                    if (g_iica_rx_cnt == pFrame->len)
                    {
                        I2C->IICCTL0 &= ~IICA_IICCTL00_ACKE_Msk;   // disable acknowledgment
                        I2C->IICCTL0 |= IICA_IICCTL00_WREL_Msk;    // cancel wait
                        I2C->IICCTL0 |= IICA_IICCTL00_WTIM_Msk;    //interrupt request is generated at the eighth clock's falling edge
                    }
                    else
                    {
                        I2C->IICCTL0 |= IICA_IICCTL00_WREL_Msk;     // cancel wait
                    }
                }
                else
                {
                    iica_master_recv_end();//iic received finished
                }
            }
        }
    }
}


void iica0_interrupt(void *msg)
{
    NVIC_ClearPendingIRQ(I2C0_IRQn);
    IICA0_Clear_Wakeup();

    if ((I2C->IICS & 0x80) == 0x80U)
    {
        iica0_masterhandler((void *)msg);
    }
    else
    {

    }
}
