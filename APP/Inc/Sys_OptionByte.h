/*
 * @Author: zh-LuoXuan 1153589792@qq.com
 * @Date: 2024-04-05 21:38:57
 * @LastEditors: zh-LuoXuan 1153589792@qq.com
 * @LastEditTime: 2024-04-06 00:01:09
 * @FilePath: \EIDE (工作区)d:\evowera\CMS32M67xx_20240312\EW_test_RGB_Done\APP\Inc\Sys_OptionByte.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __SYS_OPTIONBYTE_H_
#define __SYS_OPTIONBYTE_H_

#include "CMS32M67xx.h"

/* =========================================================================================================================== */
/* ================                                  USER_Option_Byte                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief User_Option_Byte (OPB)
  */

typedef enum {                                  /*!<  OPB enum                                              */
  WDT_CTRL_BYTE   =  0x000000C0U,               /*!< (@ 0x000000C0) WDT Control BYTE                                           */
  LVD_CTRL_BYTE   =  0x000000C1U,               /*!< (@ 0x000000C1) LVD Control BYTE                                           */
  HOCO_CTRL_BYTE  =  0x000000C2U,               /*!< (@ 0x000000C2) HOCO Control BYTE                                          */
  FLASH_PRO_BYTE1 =  0x000000C3U,               /*!< (@ 0x000000C3) Flash Protect Control BYTE1                                */
  FLASH_PRO_BYTE2 =  0x00500004U,               /*!< (@ 0x000000C3) Flash Protect Control BYTE1                                */
  
} OPB_Type;                                      



#define SECTOR_1_BASE               (0x00000000UL)
#define OPB_BASE                    (0x000000C0UL)



void Option_Byte_Config(OPB_Type Option_Byte, uint8_t Config_Data);

#endif // __SYS_OPTIONBYTE_H_
