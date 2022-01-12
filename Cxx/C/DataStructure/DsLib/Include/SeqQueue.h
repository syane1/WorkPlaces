#ifndef SEQ_QUEUE_H
#define SEQ_QUEUE_H
#include "global_var.h"
#include "global_inc.h"

typedef struct _SQueue{
    int data[_MAXSIZE];
}SQueue;

//初始化顺序队列
bool SQueue_Init(SQueue*);

//顺序队列判空
bool SQueue_Empty(SQueue);

//顺序队列入队
void SQueue_EnQueue(SQueue*,int);

//顺序队列出队
bool SQueue_DeQueue(SQueue*,int*);

//顺序队列获取头部
int SQueue_GetHead(SQueue);

//顺序队列测试函数
void SQueue_Test();

#endif