#include "freetask.h"

/**
 * @brief ����������ֱ��ָ���������㡣
 * @param callback һ���ص����������ص�����������ʱ���˳�����
 * @param args һ��ָ�룬���ݸ��ص�����
 * @param max_count ����ӳٴ���
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
 * @brief ����������ֱ��ָ���������㡣
 * @param param һ������ָ�룬��ָ��ָ���ֵΪ��ʱ���˳�����
 * @param max_count ����ӳٴ���
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
 * @brief �ظ�ִ�к�����ֱ��ָ���������㡣
 * @param func ��Ҫִ�еĺ���
 * @param targetFunc һ���ص����������ص�����������ʱ���˳�����
 * @param args һ��ָ�룬���ݸ��ص�����
 * @param max_count ����ӳٴ���
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
 * @brief �ظ�ִ�к�����ֱ��ָ����������
 * @param func ��Ҫִ�еĺ���
 * @param param һ������ָ�룬��ָ��ָ���ֵΪ��ʱ���˳�����
 * @param max_count ����ӳٴ���
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


