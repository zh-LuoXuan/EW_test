/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-07 17:47:30
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\YM_rgb.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_RGB_H_
#define __YM_RGB_H_

#include <stdint.h>
#include "gpio.h"
#include "YM_ccp.h"

#define WHITE                (uint32_t) (0xFFFFFF)
#define CYAN                 (uint32_t) (0xABEFF4)
#define PURPLE               (uint32_t) (0xB2ADEA)

// #define WHITE                 (uint32_t) (0x555555)
// #define CYAN                  (uint32_t) (0xA4A5A6)
// #define PURPLE                (uint32_t) (0xA7A8A9)




#define RGBTOGRB(DEFINE_COLOR) ({   \
                uint32_t GRB_VAL;  \
                GRB_VAL = (uint32_t)((((uint8_t)((DEFINE_COLOR >> 16) & 0xFF)) << 8) |    \
                                     (((uint8_t)((DEFINE_COLOR >> 8) & 0xFF)) << 16) |    \
                                     ((uint8_t)(DEFINE_COLOR & 0xFF)));   \
                GRB_VAL;   \
})

#define GETCOMPLAR(RGB_BIT) ({   \
                uint8_t COMPLAR_VAL;   \
                if(RGB_BIT)   \
                COMPLAR_VAL = (uint8_t)COMPLAR_CODE_1;   \
                else   \
                COMPLAR_VAL = (uint8_t)COMPLAR_CODE_0;   \
                COMPLAR_VAL;   \
})

                
typedef enum
{
    Off,
    On,
}RGB_State_e;

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
    uint8_t* ColorBuffPoint;
    uint8_t breath_val;
    RGB_State_e State;
    RGB_Mode_e Mode;
    RGB_Color_e Color;
    RGB_Color_e Last_Color;
}RGB_DataTypdef;

extern RGB_DataTypdef RGB_DataStracture;

void RGB_Init_Config(void);
void RGB_GetColorBuffPoint(RGB_DataTypdef* RGB_Stracture);

#endif