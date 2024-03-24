#include "YM_rgb.h"

uint8_t breath;
RGB_DataTypdef RGB_DataStracture;

static void getCamplarBuff(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }

    uint32_t GRB[3];

    RGBTOGRB(WHITE, GRB[0])
    RGBTOGRB(CYAN, GRB[1]) 
    RGBTOGRB(PURPLE, GRB[2])

    for(uint8_t i = 0; i < 3; i++)
    {
        for(uint8_t j = 0; i < 23; j++)
        GETCOMPLAR(RGB_Stracture->campareBuff[i][j], (GRB[i] >> (23 - j)) & 0x01)
    }
}

static void RGB_DataInit(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }

    RGB_Stracture->Status = On;
    RGB_Stracture->Mode = Normal;
    RGB_Stracture->Color = White;
    RGB_Stracture->breath_val = 255;
    getCamplarBuff(RGB_Stracture);
}

uint32_t RGB_Normal_Output(RGB_DataTypdef* RGB_Stracture, uint32_t campler)
{
    getCamplarBuff(RGB_Stracture);
    return (255 * campler / 1000);
}
uint32_t RGB_Breath_Output(uint32_t campler, uint8_t breath)
{
    return (breath * campler / 1000);
}

uint32_t RGB_Output(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return 0;
    }
    static uint8_t addr_add_num = 0; 
    uint32_t* OutCampier;

    switch (RGB_Stracture->Mode)
    {
    case Normal:
        RGB_Stracture->breath_val = 255;
        break;
    case Breath:
        RGB_Stracture->breath_val = breath;
        break;
    default:
        break;
    }
    switch (RGB_Stracture->Color)
    {
    case White:
        OutCampier = RGB_Stracture->campareBuff[0];
        break;
    case Cyan:
        OutCampier = RGB_Stracture->campareBuff[1];
        break;
    case Purple:
        OutCampier = RGB_Stracture->campareBuff[2];
        break;
    default:
        break;
    }
    if(addr_add_num >= 23)
    addr_add_num = 0;
    addr_add_num++;
    return (uint32_t)(RGB_Stracture->breath_val * *(OutCampier += (addr_add_num - 1)) / 1000);
}

void RGB_Init_Config(void)
{
    GPIO_PinAFOutConfig(P06CFG, IO_OUTCFG_P06_CCP0A);
    GPIO_Init(PORT0, PIN6, OUTPUT);
    RGB_DataInit(&RGB_DataStracture);
}