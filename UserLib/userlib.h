/*
 * @Author: EW_Luo 1153589792@qq.com
 * @Date: 2024-04-26 14:12:53
 * @LastEditors: EW_Luo 1153589792@qq.com
 * @LastEditTime: 2024-04-26 16:36:48
 * @FilePath: \EIDE (工作区)e:\ZL\Git_Clone\MD_RGB_UART\UserLib\userlib.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __USERLIB_H_
#define __USERLIB_H_

#include <stdint.h>
#include <float.h>

#ifdef __cplusplus
extern "C"
{
#endif


int8_t limit_int8(int8_t data, int8_t max, int8_t min);
int16_t limit_int16(int16_t data, int16_t max, int16_t min);
int32_t limit_int32(int32_t data, int32_t max, int32_t min);
uint8_t limit_uint8(uint8_t data, uint8_t max, uint8_t min);
uint16_t limit_uint16(uint16_t data, uint16_t max, uint16_t min);
uint32_t limit_uint32(uint32_t data, uint32_t max, uint32_t min);
int8_t int8_deadline(int8_t data, int8_t max, int8_t min);
int16_t int16_deadline(int16_t data, int16_t max, int16_t min);
int32_t int32_deadline(int32_t data, int32_t max, int32_t min);
uint8_t uint8_deadline(uint8_t data, uint8_t max, uint8_t min);
uint16_t uint16_deadline(uint16_t data, uint16_t max, uint16_t min);
uint32_t uint32_deadline(uint32_t data, uint32_t max, uint32_t min);
float float_deadline(float data, float max, float min);
float limit_float(float data, float max, float min);


#ifdef __cplusplus
}
#endif

#endif