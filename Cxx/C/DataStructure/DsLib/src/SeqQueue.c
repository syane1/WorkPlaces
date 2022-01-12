#include "SeqQueue.h"

//初始化顺序队列
bool SQueue_Init(SQueue* q)
{
    q->data[0] = 0;
    return true;
}

//顺序队列判空
bool SQueue_Empty(SQueue q)
{
    return !q.data[0];
}

//顺序队列入队
void SQueue_EnQueue(SQueue* q,int e)
{
    if(q->data[0]+1>=_MAXSIZE)return;
    q->data[++q->data[0]] = e;
}

//顺序队列出队
bool SQueue_DeQueue(SQueue* q,int* e)
{
    if(q->data[0]<=0)return false;
    *e = q->data[1];
    for(int i=1;i<q->data[0];i++)
    {
        q->data[i] = q->data[i+1];
    }
    q->data[0]--;
    return false;
}

//顺序队列获取头部
int SQueue_GetHead(SQueue q)
{
    return q.data[1];
}

//顺序队列测试函数
void SQueue_Test()
{
    printf("顺序队列初始化中…\n");
    SQueue q;
    if(!SQueue_Init(&q)){
        printf("顺序队列初始化失败,正在退出…\n");
        return;
    }
    printf("顺序队列是否为空?%c\n",SQueue_Empty(q)?'Y':'N');
    printf("入队1~10");
    for(int i = 1;i<=10;i++)
    {
        SQueue_EnQueue(&q,i);
    }
    printf("顺序队列是否为空?%c\n",SQueue_Empty(q)?'Y':'N');
    printf("此时队头元素为%d\n",SQueue_GetHead(q));
    printf("出队[ ");
    int deInt;
    while(!SQueue_Empty(q))
    {
        SQueue_DeQueue(&q,&deInt);
        printf("%d ",deInt);
    }
    printf("]\n");
    printf("顺序队列是否为空?%c\n",SQueue_Empty(q)?'Y':'N');
}
