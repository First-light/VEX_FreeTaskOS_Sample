/**
 ******************************************************************************
 * @file           : freetask.h
 * @brief          : 自由任务的头文件
 ******************************************************************************
 * @attention      ：
 *
 *
 ******************************************************************************
 */
#ifndef FREETASK_H_
#define FREETASK_H_

#include "v5.h"
#include "v5_vcs.h"
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>

#define MIN_DEC_TIME 50                                 // 最小检测时间 msc
#define DEC_FQC (1000 / MIN_DEC_TIME)                   // 检测频率
#define MAX_DELAY_TIME 4000                             // 最大延迟时间 msc
#define MAX_DELAY_COUNT (MAX_DELAY_TIME / MIN_DEC_TIME) // 最大时间检测次数 msc
// 定义回调函数类型
typedef int (*Callback)(void *);




template <typename Func, typename... Args>
void BlockUntil(Func condition, Args... args);
void BlockUntil(bool (*condition)());
void BlockUntil(int *param);
void BlockUntil(int param);

#endif
