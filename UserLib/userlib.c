#include "userlib.h"


/**
 * @brief 数据限幅
 * 
 * @param [in] data：传入数据, [in] max：限幅上限, [in] min：限幅下限
 * 
 * @return 限幅后的数据
 */
int8_t limit_int8(int8_t data, int8_t max, int8_t min)
{
    static int8_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if(data > max)
    {
        return max;
    }
    else if(data < min)
    {
        return min;
    }
    else
        return data;
}

/**
 * @brief 数据限幅
 * 
 * @param [in] data：传入数据, [in] max：限幅上限, [in] min：限幅下限
 * 
 * @return 限幅后的数据
 */
int16_t limit_int16(int16_t data, int16_t max, int16_t min)
{
    static int16_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if(data > max)
    {
        return max;
    }
    else if(data < min)
    {
        return min;
    }
    else
        return data;
}

/**
 * @brief 数据限幅
 * 
 * @param [in] data：传入数据, [in] max：限幅上限, [in] min：限幅下限
 * 
 * @return 限幅后的数据
 */
int32_t limit_int32(int32_t data, int32_t max, int32_t min)
{
    static int32_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if(data > max)
    {
        return max;
    }
    else if(data < min)
    {
        return min;
    }
    else
        return data;
}

/**
 * @brief 数据限幅
 * 
 * @param [in] data：传入数据, [in] max：限幅上限, [in] min：限幅下限
 * 
 * @return 限幅后的数据
 */
uint8_t limit_uint8(uint8_t data, uint8_t max, uint8_t min)
{
    static uint8_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if(data > max)
    {
        return max;
    }
    else if(data < min)
    {
        return min;
    }
    else
        return data;
}

/**
 * @brief 数据限幅
 * 
 * @param [in] data：传入数据, [in] max：限幅上限, [in] min：限幅下限
 * 
 * @return 限幅后的数据
 */
uint16_t limit_uint16(uint16_t data, uint16_t max, uint16_t min)
{
    static uint16_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if(data > max)
    {
        return max;
    }
    else if(data < min)
    {
        return min;
    }
    else
        return data;
}

/**
 * @brief 数据限幅
 * 
 * @param [in] data：传入数据, [in] max：限幅上限, [in] min：限幅下限
 * 
 * @return 限幅后的数据
 */
uint32_t limit_uint32(uint32_t data, uint32_t max, uint32_t min)
{
    static uint32_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if(data > max)
    {
        return max;
    }
    else if(data < min)
    {
        return min;
    }
    else
        return data;
}

/**
 * @brief 数据限幅
 * 
 * @param [in] data：传入数据, [in] max：限幅上限, [in] min：限幅下限
 * 
 * @return 限幅后的数据
 */
float limit_float(float data, float max, float min)
{
    static float change = 0.0f;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if(data > max)
    {
        return max;
    }
    else if(data < min)
    {
        return min;
    }
    else
        return data;
}

/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/

/**
 * @brief 死区
 * 
 * @param [in] data：传入数据, [in] max：死区上限, [in] min：死区下限
 * 
 * @return data 
 */
int8_t int8_deadline(int8_t data, int8_t max, int8_t min)
{
    static int8_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if (data < max && data > min)
    {
        data = 0;
    }

    return data;
}

/**
 * @brief 死区
 * 
 * @param [in] data：传入数据, [in] max：死区上限, [in] min：死区下限
 * 
 * @return data 
 */
int16_t int16_deadline(int16_t data, int16_t max, int16_t min)
{
    static int16_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if (data < max && data > min)
    {
        data = 0;
    }

    return data;
}

/**
 * @brief 死区
 * 
 * @param [in] data：传入数据, [in] max：死区上限, [in] min：死区下限
 * 
 * @return data 
 */
int32_t int32_deadline(int32_t data, int32_t max, int32_t min)
{
    static int32_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if (data < max && data > min)
    {
        data = 0;
    }

    return data;
}

/**
 * @brief 死区
 * 
 * @param [in] data：传入数据, [in] max：死区上限, [in] min：死区下限
 * 
 * @return data 
 */
uint8_t uint8_deadline(uint8_t data, uint8_t max, uint8_t min)
{
    static uint8_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if (data < max && data > min)
    {
        data = 0;
    }

    return data;
}

/**
 * @brief 死区
 * 
 * @param [in] data：传入数据, [in] max：死区上限, [in] min：死区下限
 * 
 * @return data 
 */
uint16_t uint16_deadline(uint16_t data, uint16_t max, uint16_t min)
{
    static uint16_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if (data < max && data > min)
    {
        data = 0;
    }

    return data;
}

/**
 * @brief 死区
 * 
 * @param [in] data：传入数据, [in] max：死区上限, [in] min：死区下限
 * 
 * @return data 
 */
uint32_t uint32_deadline(uint32_t data, uint32_t max, uint32_t min)
{
    static uint32_t change = 0;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if (data < max && data > min)
    {
        data = 0;
    }

    return data;
}

/**
 * @brief 死区
 * 
 * @param [in] data：传入数据, [in] max：死区上限, [in] min：死区下限
 * 
 * @return data 
 */
float float_deadline(float data, float max, float min)
{
    static float change = 0.0f;
    if(min > max)
    {
        change = min;
        min = max;
        max = change;
    }
    if (data < max && data > min)
    {
        data = 0.0f;
    }

    return data;
}