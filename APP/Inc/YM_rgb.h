/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-28 17:49:50
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\YM_rgb.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_RGB_H_
#define __YM_RGB_H_

#include <stdint.h>
#include "gpio.h"


#define CCP_IT_CHANS      (0)
#define DMA_TGR_CHANS     (!CCP_IT_CHANS)

#define WHITE                (uint32_t) (0xFFFFFFUL)
#define CYAN                 (uint32_t) (0x00FFFFUL)
#define PURPLE               (uint32_t) (0xFF00FFUL)


#define BREATH_PER             (1U)


#define THE_NUMBER_OF_LIGHT             (4)


#define RGBTOGRB(DEFINE_COLOR) ({   \
                            uint32_t GRB_VAL;  \
                            GRB_VAL = (uint32_t)((((uint8_t)((DEFINE_COLOR >> 16) & 0xFF)) << 8) |    \
                                                 (((uint8_t)((DEFINE_COLOR >> 8) & 0xFF)) << 16) |    \
                                                 ((uint8_t)(DEFINE_COLOR & 0xFF)));   \
                            GRB_VAL;   \
})

#define GETCOMPLAR(RGB_BIT) ({   \
                            uint32_t COMPLAR_VAL;   \
                            if(RGB_BIT)   \
                            COMPLAR_VAL = (uint32_t) COMPLAR_CODE_1;   \
                            else   \
                            COMPLAR_VAL = (uint32_t) COMPLAR_CODE_0;   \
                            COMPLAR_VAL;   \
})


enum
{
    Current,
    Last
};

typedef enum
{
    Lock = 1,
    Unlock,
}RGB_Lock_e;

typedef enum
{
    Normal = 1,
    Breath,
}RGB_Mode_e;

typedef enum
{
    Off,
	On,
}RGB_Power_e;

typedef enum
{
    White = 1,
    Cyan,
    Purple,
}RGB_Color_e;

typedef enum
{
    Busy = 1,
    Finish,
}SendState_e;



typedef struct
{
#if CCP_IT_CHANS
    uint32_t* RGB_CCPBuff;
#elif DMA_TGR_CHANS
	uint32_t* RGB_DMABuff;
#endif
    uint32_t ColorGRB;
    uint32_t ColorRGB[2];
    RGB_Lock_e Lock;
    RGB_Power_e Power;
    RGB_Mode_e Mode[2];
    RGB_Color_e Color[2];
    SendState_e SendState;
}RGB_DataTypdef;


extern RGB_DataTypdef RGB_DataStracture;


void RGB_Init_Config(void);
void RGB_Mode_Set(RGB_Mode_e mode);
void RGB_Color_Set(RGB_Color_e color);
void RGB_ColorRGB_Set(uint32_t color_rgb);
void RGB_Power_Set(RGB_Power_e power);
void RGB_Breath_Update(RGB_DataTypdef* RGB_Stracture, uint32_t breath_val);
void RGB_Power_Update(RGB_DataTypdef* RGB_Stracture);
void RGB_Color_Update(RGB_DataTypdef* RGB_Stracture);
void RGB_Mode_Update(RGB_DataTypdef* RGB_Stracture);    
void RGB_ColorRGB_Update(RGB_DataTypdef* RGB_Stracture);
void RGB_Status_Update(RGB_DataTypdef* RGB_Stracture);

#endif