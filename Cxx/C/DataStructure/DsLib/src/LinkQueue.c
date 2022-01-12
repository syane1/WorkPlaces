#include "LinkQueue.h"

//初始化链式队列
LQueue LQueue_Init()
{
    LQueue tmp = (LQueue)malloc(sizeof(LQueue));
    LQueueNode* tmpNode = (LQueueNode*)malloc(sizeof(LQueueNode*));
    tmpNode->data = 0;
    tmpNode->next = NULL;
    tmp->front = tmpNode;
    tmp->tail = tmpNode;
    return tmp;
}

//链式队列判空
bool LQueue_Empty(LQueue q)
{
    return q->front==q->tail;
}

//链式队列入队
void LQueue_EnQueue(LQueue q,int e)
{
    LQueueNode* tmp = (LQueueNode*)malloc(sizeof(LQueue));
    tmp->data = e;
    tmp->next = NULL;
    q->tail->next = tmp;
    q->tail = tmp;
}

//链式队列出队
bool LQueue_DeQueue(LQueue q,int* e)
{
    if(LQueue_Empty(q))return false;
    LQueueNode* qn = q->front->next;
    *e = qn->data;
    q->front->next = qn->next;
    if(qn==q->tail)
        q->tail = q->front;
    qn->next = NULL;
    free(qn);
    return true;
}

//链式队列获取头部
int LQueue_GetHead(LQueue q)
{
    return q->front->next->data;
}

//链式队列测试函数
void LQueue_Test()
{
    printf("链式队列初始化中…\n");
    LQueue q = LQueue_Init();
    printf("链式队列是否为空?%c\n",LQueue_Empty(q)?'Y':'N');
    printf("入队1~10");
    for(int i = 1;i<=10;i++)
    {
        LQueue_EnQueue(q,i);
    }
    printf("链式队列是否为空?%c\n",LQueue_Empty(q)?'Y':'N');
    printf("此时队头元素为%d\n",LQueue_GetHead(q));
    printf("出队[ ");
    int deInt;
    while(!LQueue_Empty(q))
    {
        LQueue_DeQueue(q,&deInt);
        printf("%d ",deInt);
    }
    printf("]\n");
    printf("链式队列是否为空?%c\n",LQueue_Empty(q)?'Y':'N');
}
