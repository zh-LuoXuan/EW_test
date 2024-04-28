/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-25 09:16:17
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-28 18:01:00
 * @FilePath: \EIDE (工作区)c:\Users\xuan.luo\Desktop\EW_test\MAIN\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "init_config.h"


int main(void)
{
	Init_Cinfig();

	while(1)
	{	
//		Set_LED_B(LED5TestVal);
		get_Uart1_RxData();
		RGB_Status_Update(&RGB_DataStracture);

	}
}


