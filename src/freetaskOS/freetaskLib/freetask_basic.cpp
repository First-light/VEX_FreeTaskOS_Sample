#include "freetask.h"

/**
 * @brief 阻塞函数，直到指定条件满足。
 * @param callback 一个回调函数，当回调函数返回真时，退出阻塞
 * @param args 一个指针，传递给回调函数
 * @param max_count 最大延迟次数
 */
void BlockUntil(Callback callback,void *args,int max_count = MAX_DELAY_COUNT)
{
    int count = 0;
    while (!callback(args) && count < max_count)
    {
        vex::wait(MIN_DEC_TIME, vex::msec);
        count++;
    }
}


/**
 * @brief 阻塞函数，直到指定条件满足。
 * @param param 一个整数指针，当指针指向的值为真时，退出阻塞
 * @param max_count 最大延迟次数
 */
void BlockUntil(int *param,int max_count = MAX_DELAY_COUNT)
{
    int count = 0;
    while (!(*param) && count < max_count)
    {
        vex::wait(MIN_DEC_TIME, vex::msec);
        count++;
    }
}


/**
 * @brief 重复执行函数，直到指定条件满足。
 * @param func 需要执行的函数
 * @param targetFunc 一个回调函数，当回调函数返回真时，退出运行
 * @param args 一个指针，传递给回调函数
 * @param max_count 最大延迟次数
 */
void RepeatRunUntil(void (* func)(),Callback targetFunc,void *args, int max_count = MAX_DELAY_COUNT)
{
    int count = 0;
    while (!targetFunc(args) && count < max_count)
    {
        func();
        vex::wait(MIN_DEC_TIME, vex::msec);
        count++;
    }
}

/**
 * @brief 重复执行函数，直到指定条件满足
 * @param func 需要执行的函数
 * @param param 一个整数指针，当指针指向的值为真时，退出运行
 * @param max_count 最大延迟次数
 */
void RepeatRunUntil(void (* func)(),int* param, int max_count = MAX_DELAY_COUNT)
{
    int count = 0;
    while (!(*param) && count < max_count)
    {
        func();
        vex::wait(MIN_DEC_TIME, vex::msec);
        count++;
    }
}


