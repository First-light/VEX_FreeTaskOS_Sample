/**
 ******************************************************************************
 * @file           : freetask.h
 * @brief          : ���������ͷ�ļ�
 ******************************************************************************
 * @attention      ��
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

#define MIN_DEC_TIME 50                                 // ��С���ʱ�� msc
#define DEC_FQC (1000 / MIN_DEC_TIME)                   // ���Ƶ��
#define MAX_DELAY_TIME 4000                             // ����ӳ�ʱ�� msc
#define MAX_DELAY_COUNT (MAX_DELAY_TIME / MIN_DEC_TIME) // ���ʱ������� msc
// ����ص���������
typedef int (*Callback)(void *);




template <typename Func, typename... Args>
void BlockUntil(Func condition, Args... args);
void BlockUntil(bool (*condition)());
void BlockUntil(int *param);
void BlockUntil(int param);

#endif
