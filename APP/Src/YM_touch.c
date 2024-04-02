/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-01 09:30:33
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-01 19:14:06
 * @FilePath: \EIDE (工作区)c:\Users\xuan.luo\Desktop\EW_test\APP\Src\YM_touch.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "YM_touch.h"

void Touch_Init_Config(void)
{
    GPIO_Init(TOUCH_PORT, TOUCH_PIN, INPUT);
}