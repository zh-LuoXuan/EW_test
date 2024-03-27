/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: zh-LuoXuan 1153589792@qq.com
 * @LastEditTime: 2024-03-28 00:56:07
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\YM_rgb.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_RGB_H_
#define __YM_RGB_H_

#include <stdint.h>
#include "gpio.h"


#define WHITE     (uint32_t)(0xFFFFFFUL)
#define PURPLE    (uint32_t)(0xABCAFBUL)
#define CYAN      (uint32_t)(0xC8F578UL)

#define RGBTOGRB(DEFINE_COLOR, GRB_VAL) {   \
                GRB_VAL = (uint32_t)((((uint8_t)((DEFINE_COLOR >> 16) & 0xFF)) << 8) |    \
                                     (((uint8_t)((DEFINE_COLOR >> 8) & 0xFF)) << 16) |    \
                                     ((uint8_t)(DEFINE_COLOR & 0xFF)));  \
}

#define GETCOMPLAR(COMPLAR_VAL, RGB_BIT) {   \
                if(RGB_BIT)   \
                COMPLAR_VAL = (uint32_t)(75 * 1000 / 255);   \
                else   \
                COMPLAR_VAL = (uint32_t)(25 * 1000 / 255);   \
}

#define MODEOUTPUT(INPUT_VAL ,K_VAL) {   \
                uint32_t OUTPUT_VAL   \
                if(K_VAL > 255)   \
                K_VAL = 255;   \
                else if(K_VAL < 0)   \
                K_VAL = 0;   \
                else ;   \
                OUTPUT_VAL = K_VAL * INPUT_VAL;   \
}
                
typedef enum
{
    Off,
    On,
}RGB_Status_e;

typedef enum
{
    Normal,
    Breath,
}RGB_Mode_e;

typedef enum
{
    White,
    Cyan,
    Purple,
}RGB_Color_e;

typedef struct
{
    RGB_Status_e Status;
    RGB_Mode_e Mode;
    RGB_Color_e Color;
    uint32_t campareBuff[3][24];
    uint8_t breath_val;
}RGB_DataTypdef;

extern RGB_DataTypdef RGB_DataStracture;
extern uint32_t testData[24];

void RGB_Init_Config(void);
uint32_t RGB_Output(RGB_DataTypdef* RGB_Stracture);

#endif