/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-08 15:41:54
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_rgb.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_rgb.h"

uint8_t breath;
uint8_t WhiteBuff[24];
uint8_t PurpleBuff[24];
uint8_t CyanBuff[24];
RGB_DataTypdef RGB_DataStracture;


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
        WhiteBuff[i] = GETCOMPLAR((GRB >> (23 - i)) & 0x01);
    GRB = RGBTOGRB(CYAN);
    for(i = 0; i < 24; i++)
        CyanBuff[i] = GETCOMPLAR((GRB >> (23 - i)) & 0x01);
    GRB = RGBTOGRB(PURPLE);
    for(i = 0; i < 24; i++)
        PurpleBuff[i] = GETCOMPLAR((GRB >> (23 - i)) & 0x01);
}


void RGB_GetColorBuffPoint(RGB_DataTypdef* RGB_Stracture)
{
    switch(RGB_Stracture->Color)
    {
        case Cyan:
            RGB_Stracture->ColorBuffPoint = CyanBuff;
            break;
        case Purple:
            RGB_Stracture->ColorBuffPoint = PurpleBuff;
            break;
        case White:
        default:
            RGB_Stracture->ColorBuffPoint = WhiteBuff;
            break;
    }
    if(RGB_Stracture->Last_Color != RGB_Stracture->Color)
    {
        RGB_Stracture->State = On;
        CCP_EnableRun(CCP0);			
        CCP_Start(CCP0);
        CCP->LOCK = CCP_P1A_WRITE_KEY;	
        RGB_Stracture->Last_Color = RGB_Stracture->Color;
    }
}


static void RGB_DataInit(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }

    RGB_Stracture->State = On;
    RGB_Stracture->Mode = Normal;
    RGB_Stracture->Color = Cyan;
    RGB_Stracture->Last_Color = RGB_Stracture->Color;
    RGB_Stracture->breath_val = 255;
    getCamplarBuff(RGB_Stracture);
    RGB_GetColorBuffPoint(RGB_Stracture);
}




void RGB_Init_Config(void)
{
    GPIO_PinAFOutConfig(P06CFG, IO_OUTCFG_P06_CCP0A);
    GPIO_Init(PORT0, PIN6, OUTPUT);
    RGB_DataInit(&RGB_DataStracture);
}

