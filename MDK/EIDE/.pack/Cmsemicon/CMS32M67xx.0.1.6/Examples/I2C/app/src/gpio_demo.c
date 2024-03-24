#include "gpio_demo.h"
/**
  * @brief  Demo code of operation about gpio.
  * @param  No parameter.
  * @return void
*/
void Gpio_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.GPIO_Pin    = GPIO_Pin_1 | GPIO_Pin_2 ;
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_OUT;

    GPIO_Init(GPIO_PORT7, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin    = GPIO_Pin_6 | GPIO_Pin_7 ;
    GPIO_InitStruct.GPIO_Mode   = GPIO_Mode_OUT;

    GPIO_Init(GPIO_PORT1, &GPIO_InitStruct);
}

void led_onoff(unsigned char on)
{
    if (on)
    {
        GPIO_SetBits(GPIO_PORT7, GPIO_Pin_1);
        //      GPIO_SetBits(GPIO_PORT7,GPIO_Pin_8);
    }
    else
    {
        GPIO_ResetBits(GPIO_PORT7, GPIO_Pin_1);
        //      GPIO_ResetBits(GPIO_PORT7,GPIO_Pin_8);
    }
}

