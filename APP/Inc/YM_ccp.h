/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-03-25 18:41:42
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-28 18:06:05
 * @FilePath: \EIDE (工作区)e:\ZL\CMS32M67xx_20240312\YM502_Test_Demo\APP\Inc\YM_ccp.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __YM_CCP_H_
#define __YM_CCP_H_

#ifdef __cplusplus
extern "C"
{
#endif


#include "common.h"
#include "cgc.h"
#include "ccp.h"
#include "gpio.h"
                             

#define CCP0_PERIPH                     (295)
#define COMPLAR_CODE_1                  ((CCP0_PERIPH - 75) | 0xF0000)
#define COMPLAR_CODE_0                  ((CCP0_PERIPH - 35) | 0xF0000)



typedef enum 
{
    CCP0A = 1,
    CCP0B,
}CCP0x_e;

extern uint16_t LED5TestVal;

void CCP0A_Init_Config(void);
void CCP_Config_as_LED_B_Breath(void);
void Set_LED_B(uint8_t brightness);
void CCP_Int_Config(FunctionalState config);
void Pmn_AF_CCP0x_Disable(CCP0x_e CCP0x);

#ifdef __cplusplus
}
#endif

#endif /* __YM_CCP_H_ */

