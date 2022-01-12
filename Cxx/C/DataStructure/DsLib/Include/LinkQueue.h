#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include "global_var.h"
#include "global_inc.h"

typedef struct _LinkQueueNode
{
    int data;
    struct _LinkQueueNode* next;
}LQueueNode;

typedef struct{
    LQueueNode* front,*tail;
}*LQueue;

//初始化链式队列
LQueue LQueue_Init();

//链式队列判空
bool LQueue_Empty(LQueue);

//链式队列入队
void LQueue_EnQueue(LQueue,int);

//链式队列出队
bool LQueue_DeQueue(LQueue,int*);

//链式队列获取头部
int LQueue_GetHead(LQueue);

//链式队列测试函数
void LQueue_Test();

#endif