#ifndef SEQ_STACK_H
#define SEQ_STACK_H

#define MAX_SIZE 20
#include "global_var.h"
#include "global_inc.h"


typedef struct _SStack
{
    int data[MAX_SIZE];
    int top;
}SStackNode,*SStack;

//顺序栈初始化
void SStack_Init(SStack);

//顺序栈判空
bool SStack_Empty(SStack);

//顺序栈压入
bool SStack_Push(SStack,int);

//顺序栈弹出
bool SStack_Pop(SStack,int*);

//顺序栈获取栈顶元素
int SStack_GetTop(SStack);

//顺序栈测试函数
void SStack_Test();
#endif