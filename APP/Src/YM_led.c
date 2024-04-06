/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-25 14:51:46
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-29 14:41:06
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_led.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_led.h"

void LED_Init_Config(void)
{
    GPIO_Init(LED1_PORT, LED1_PIN, OUTPUT);
    GPIO_Init(LED2_PORT, LED2_PIN, OUTPUT);
    GPIO_Init(LED3_PORT, LED3_PIN, OUTPUT);
    GPIO_Init(LED4_PORT, LED4_PIN, OUTPUT);
    GPIO_Init(LED5_PORT, LED5_PIN, OUTPUT);
    ALL_LED(OFF)
}

void GPIO_Init_Config(void)
{
    GPIO_Init(PORT1, PIN0, OUTPUT);
    PORT_SetBit(PORT1, PIN0);
}