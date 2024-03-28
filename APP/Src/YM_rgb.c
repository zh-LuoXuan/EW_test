/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-03-26 22:21:43
 * @LastEditors: zh-LuoXuan 1153589792@qq.com
 * @LastEditTime: 2024-03-29 01:59:40
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\YM502_Test_Demo\APP\Src\YM_rgb.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_rgb.h"


#define Test_H_DATA   (75)
#define Test_M_DATA   (50)
#define Test_L_DATA   (25)
uint8_t breath;
RGB_DataTypdef RGB_DataStracture;

uint32_t testData[24] = {Test_H_DATA,Test_H_DATA,Test_H_DATA,Test_H_DATA,Test_H_DATA,Test_H_DATA,Test_H_DATA,Test_H_DATA, \
                         Test_M_DATA,Test_M_DATA,Test_M_DATA,Test_M_DATA,Test_M_DATA,Test_M_DATA,Test_M_DATA,Test_M_DATA, \
						 Test_L_DATA,Test_L_DATA,Test_L_DATA,Test_L_DATA,Test_L_DATA,Test_L_DATA,Test_L_DATA,Test_L_DATA};

static void getCamplarBuff(RGB_DataTypdef* RGB_Stracture)
{
    if(RGB_Stracture == NULL)
    {
        return;
    }

		uint8_t i, j;
    uint32_t GRB[3];

    RGBTOGRB(WHITE, GRB[0])
    RGBTOGRB(CYAN, GRB[1]) 
    RGBTOGRB(PURPLE, GRB[2])

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 24; j++)
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
    RGB_Stracture->Color = Purple;
    RGB_Stracture->breath_val = 255;
    getCamplarBuff(RGB_Stracture);
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