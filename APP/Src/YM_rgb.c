/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: zh-LuoXuan 1153589792@qq.com
 * @LastEditTime: 2024-04-03 00:31:31
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_rgb.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_rgb.h"

uint8_t breath;
RGB_DataTypdef RGB_DataStracture;


/*****************************************************************************   White   ***********************************************************************************/

// uint16_t testData[24] = {COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, \
// 	                     COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, \
// 	                     COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1};


/*****************************************************************************   Purple   ***********************************************************************************/

// uint16_t testData[24] = {COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, \
// 	                     COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_0, \
// 	                     COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_0};



/*****************************************************************************   Cyan   ***********************************************************************************/

// uint16_t testData[24] = {COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, \
// 	                     COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_1, \
// 	                     COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_1, COMPLAR_CODE_0, COMPLAR_CODE_0};


static void getCamplarBuff(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }

	uint8_t i;
    uint32_t GRB;

    GRB = RGBTOGRB(WHITE);
    for(i = 0; i < 24; i++)
        RGB_Stracture->WhiteBuff[i] = GETCOMPLAR((GRB >> (23 - i)) & 0x01);
    GRB = RGBTOGRB(CYAN);
    for(i = 0; i < 24; i++)
        RGB_Stracture->CyanBuff[i] = GETCOMPLAR((GRB >> (23 - i)) & 0x01);
    GRB = RGBTOGRB(WHITE);
    for(i = 0; i < 24; i++)
        RGB_Stracture->PurpleBuff[i] = GETCOMPLAR((GRB >> (23 - i)) & 0x01);
}



static void RGB_DataInit(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }

    RGB_Stracture->Status = On;
    RGB_Stracture->Mode = Normal;
    RGB_Stracture->Color = Purple;
    RGB_Stracture->breath_val = 1;
    getCamplarBuff(RGB_Stracture);
}



const uint8_t* RGB_GetColorBuffPoint(void)
{
    switch(RGB_DataStracture.Color)
    {
        case Cyan:
            return RGB_DataStracture.CyanBuff;
            break;
        case Purple:
            return RGB_DataStracture.PurpleBuff;
            break;
        case White:
        default:
            return RGB_DataStracture.WhiteBuff;
            break;
    }
}


void RGB_Init_Config(void)
{
    GPIO_PinAFOutConfig(P06CFG, IO_OUTCFG_P06_CCP0A);
    GPIO_Init(PORT0, PIN6, OUTPUT);
    RGB_DataInit(&RGB_DataStracture);
}

