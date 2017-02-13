/**
 * @file bubbleSort.h
 * @Synopsis  bubble sort 
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2013-02-06
 */
#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

#include <cstdlib>

#ifdef __cplusplus
extern "C"
{
#endif
/// 测试无效参数，返回警告信息
/// 用于无返回值的函数
#define return_if_fail(p) if(!(p)) \
    {printf("%s:%d Warning: "#p" failed.\n", \
            __func__, __LINE__); return;}
 
/// 用于有返回值的函数
#define return_val_if_fail(p, ret) if(!(p)) \
    {printf("%s:%d Warning: "#p" failed.\n", \
            __func__, __LINE__); return (ret);}
typedef enum _Ret
{	
	RET_OK,
    RET_OOM,
    RET_STOP,
    RET_PARAMS,
    RET_FAIL,
} Ret;

typedef int* (*DataCompareFunc)(void*ctx, void* data);
Ret bubble_sort(void** array, size_t nr, DataCompareFunc cmp);
#ifdef __cplusplus
}

#endif
#endif
