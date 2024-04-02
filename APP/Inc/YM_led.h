/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-03-25 18:41:42
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-03-29 14:38:21
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\YM_led.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_LED_H_
#define __YM_LED_H_

#include <stdint.h>
#include "gpio.h"


#define LED1_PORT       (PORT2)
#define LED2_PORT       (PORT0)
#define LED3_PORT       (PORT3)
#define LED4_PORT       (PORT2)
#define LED5_PORT       (PORT2)
    
#define LED1_PIN        (PIN1)
#define LED2_PIN        (PIN5)
#define LED3_PIN        (PIN1)
#define LED4_PIN        (PIN0)
#define LED5_PIN        (PIN3)
    
#define ON              (1U)
#define OFF             (0U)
    
    
#define LED1(SW)        {   \
                        if(SW)   \
                        PORT_ClrBit(LED1_PORT, LED1_PIN);   \
                        else   \
                        PORT_SetBit(LED1_PORT, LED1_PIN);   \
                        }
    
#define LED2(SW)        {   \
                        if(SW)   \
                        PORT_ClrBit(LED2_PORT, LED2_PIN);   \
                        else   \
                        PORT_SetBit(LED2_PORT, LED2_PIN);   \
                        }
    
#define LED3(SW)        {   \
                        if(SW)   \
                        PORT_ClrBit(LED3_PORT, LED3_PIN);   \
                        else   \
                        PORT_SetBit(LED3_PORT, LED3_PIN);   \
                        }
    
#define LED4(SW)        {     \
                        if(SW)   \
                        PORT_ClrBit(LED4_PORT, LED4_PIN);   \
                        else   \
                        PORT_SetBit(LED4_PORT, LED4_PIN);   \
                        }
    
#define LED5(SW)        {     \
                        if(SW)   \
                        PORT_ClrBit(LED5_PORT, LED5_PIN);   \
                        else     \
                        PORT_SetBit(LED5_PORT, LED5_PIN);   \
                        }
    
#define ALL_LED(SW)     {   \
                        if(SW) {  \
                        PORT_ClrBit(LED1_PORT, LED1_PIN);   \
                        PORT_ClrBit(LED2_PORT, LED2_PIN);   \
                        PORT_ClrBit(LED3_PORT, LED3_PIN);   \
                        PORT_ClrBit(LED4_PORT, LED4_PIN);   \
                        PORT_ClrBit(LED5_PORT, LED5_PIN);   \
                        }   \
                        else  {  \
                        PORT_SetBit(LED1_PORT, LED1_PIN);   \
                        PORT_SetBit(LED2_PORT, LED2_PIN);   \
                        PORT_SetBit(LED3_PORT, LED3_PIN);   \
                        PORT_SetBit(LED4_PORT, LED4_PIN);   \
                        PORT_SetBit(LED5_PORT, LED5_PIN);   \
                        }   \
                        }


void LED_Init_Config(void);
void GPIO_Init_Config(void);

#endif