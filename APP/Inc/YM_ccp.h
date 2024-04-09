/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-03-25 18:41:42
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-08 15:00:04
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
                             

#define CCP0A_PERIPH         (265)
#define COMPLAR_CODE_1       (CCP0A_PERIPH - 65)
#define COMPLAR_CODE_0       (CCP0A_PERIPH - 25)


void CCP_Init_Config(uint32_t campler);


#ifdef __cplusplus
}
#endif

#endif /* __DEMO_CCP_H_ */

