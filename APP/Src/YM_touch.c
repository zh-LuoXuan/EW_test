#include "YM_touch.h"

void Touch_Init_Config(void)
{
    GPIO_Init(TOUCH_PORT, TOUCH_PIN, INPUT);
}