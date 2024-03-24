/***********************************************************************************************************************
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : main.c
* Version      :
* Device(s)    : BAT32G127
* Tool-Chain   : MDK(armcc)
* Description  : This file is a template.
* Creation Date: 2022/5/30
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro Definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <stdio.h>
#include "demo_uart.h"
#include "flash.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

uint8_t buf[512];
uint8_t readbuf[512];


int main()
{
    uint32_t msCnt;     // count value of 1ms
    uint32_t i, err;
    uint32_t exp_value[17] = {0xFFFFFF00, 0xFFFF1100, 0xFF221100, 0x33221100,
                              0xFFFF00FF, 0xFF1100FF, 0x221100FF, 0x221100FF,
                              0xFF00FF33, 0x1100FFFF, 0x1100FFFF, 0x1100FF22,
                              0x00FF3322, 0x00FFFFFF, 0x00FFFF11, 0x00FF2211,
                              0xFF332211
                             };
    uint8_t *w_ptr;
    uint32_t *r_ptr;
    uint8_t  *b_ptr;
    uint8_t tmp[] = "Use flash_write function is recommented!!";
    //-----------------------------------------------------------------------
    // Systick setting
    //-----------------------------------------------------------------------

    SystemCoreClockUpdate();
    msCnt = SystemCoreClock / 1000;
//    SysTick_Config(msCnt);

    UART0_Config();
    //-----------------------------------------------------------------------
    // Erase and Write Data Flash Area (0x500200 ~ 0x5005FF)
    //-----------------------------------------------------------------------
    EraseSector(0x500200);

    for (i = 0; i < 512; i++)
    {
        buf[i] = i%256;
    }


    ProgramPage(0x500200, sizeof(buf), (uint8_t *)buf);

    w_ptr = (uint8_t *)0x500200;

	flashRead(w_ptr,512,readbuf);

    printf("Sector 1 Erase/Write Done\n");

    EraseSector(0x500400);

    for (i = 0; i < 512; i++)
    {
        buf[i] = i%256;
    }

    ProgramPage(0x500400, sizeof(buf), (uint8_t *)buf);

    w_ptr = (uint8_t *)0x500400;

	flashRead(w_ptr,512,readbuf);


    printf("Sector 2 Erase/Write Done\n");

    //-----------------------------------------------------------------------
    // It is recommended to use the flash_write function for writting flash
    // It can determine if erasure is needed automatically.
    //-----------------------------------------------------------------------
    flash_write(0x500000, sizeof(tmp), (uint8_t *)tmp);
    b_ptr = (uint8_t *)0x500000;

    for (i = 0; i < sizeof(tmp); i++)
    {
        printf("%c", *b_ptr++);
    }

    printf("\n");

    //-----------------------------------------------------------------------
    // use the flash_write function write blank area
    //-----------------------------------------------------------------------
    tmp[0] = 0x00;
    tmp[1] = 0x11;
    tmp[2] = 0x22;
    tmp[3] = 0x33;
    tmp[4] = 0x44;
    tmp[5] = 0x55;
    tmp[6] = 0x66;
    tmp[7] = 0x88;
    EraseSector(0x8000);
    flash_write(0x8000, 1, (uint8_t *)tmp);
    flash_write(0x8004, 2, (uint8_t *)tmp);
    flash_write(0x8008, 3, (uint8_t *)tmp);
    flash_write(0x800C, 4, (uint8_t *)tmp);
    flash_write(0x8011, 1, (uint8_t *)tmp);
    flash_write(0x8015, 2, (uint8_t *)tmp);
    flash_write(0x8019, 3, (uint8_t *)tmp);
    flash_write(0x801D, 4, (uint8_t *)tmp);
    flash_write(0x8022, 1, (uint8_t *)tmp);
    flash_write(0x8026, 2, (uint8_t *)tmp);
    flash_write(0x802A, 3, (uint8_t *)tmp);
    flash_write(0x802E, 4, (uint8_t *)tmp);
    flash_write(0x8033, 1, (uint8_t *)tmp);
    flash_write(0x8037, 2, (uint8_t *)tmp);
    flash_write(0x803B, 3, (uint8_t *)tmp);
    flash_write(0x803F, 4, (uint8_t *)tmp);

    r_ptr = (uint32_t *)0x8000;
    err = 0;

    for (i = 0; i < sizeof(exp_value) / sizeof(exp_value[0]); i++)
    {
        if (*r_ptr++ != exp_value[i])
        {
            err++;
        }
    }

    if (err)
    {
        printf("Byte Write is ERROR!\n");
    }
    else
    {
        printf("Byte Write is DONE!\n");
    }

}


