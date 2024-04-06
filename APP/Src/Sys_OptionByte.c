/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-04-05 21:38:15
 * @LastEditors: zh-LuoXuan 1153589792@qq.com
 * @LastEditTime: 2024-04-07 01:23:59
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\EW_test_RGB_Done\APP\Src\Sys_OptionByte.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Sys_OptionByte.h"
#include "flash.h"


#if defined (__CC_ARM)
#pragma arm section code = "ram_fetch_code"   // Arm Compiler 5
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION > 6010050)
#pragma clang section text = "ram_fetch_code" // Arm Compiler 6
#endif

void Option_Byte_Config(OPB_Type Option_Byte, uint8_t Config_Data)
{
    uint8_t* SectorPoint = (uint8_t*)SECTOR_1_BASE;
    uint8_t  SectorBuff[SECTOR_SIZE];
    flashRead(SectorPoint, SECTOR_SIZE, SectorBuff);
    SectorBuff[Option_Byte] = Config_Data;
    __DI;
    FMC->FLERMD = 0x10;
    FMC->FLPROT = 0xF1;
    FMC->FLOPMD1 = 0x55; 
    FMC->FLOPMD2 = 0xAA;  
    *SectorPoint = 0xFF;
    while((FMC->FLSTS & FMC_FLSTS_OVF_Msk) == 0);
    FMC->FLSTS = FMC_FLSTS_OVF_Msk;
    FMC->FLERMD = 0x00;
    if(FMC->FLSTS & FMC_FLSTS_EVF_Msk)
    {
        FMC->FLPROT = 0xF0;
        FMC->FLSTS = FMC_FLSTS_EVF_Msk;
        __EI;
        return; 
    }

    for(uint16_t i = 0; i < SECTOR_SIZE; i++) 
    {
        FMC->FLOPMD1 = 0xAA;
        FMC->FLOPMD2 = 0x55;
        *SectorPoint++ = SectorBuff[i]; 
        __EI;	
        while((FMC->FLSTS & FMC_FLSTS_OVF_Msk) == 0);
        FMC->FLSTS = FMC_FLSTS_OVF_Msk;
    }
    FMC->FLPROT = 0xF0;

}