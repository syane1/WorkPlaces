#include "SeqStack.h"

//顺序栈初始化
void SStack_Init(SStack s)
{
    s->top = -1;
}

//顺序栈判空
bool SStack_Empty(SStack s)
{
    return s->top<0;
}

//顺序栈压入
bool SStack_Push(SStack s,int e)
{
    if(s->top>=MAX_SIZE-1)return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

//顺序栈弹出
bool SStack_Pop(SStack s,int* e)
{
    if(SStack_Empty(s)){
        return false;
    }
    else{
        *e = s->data[s->top];
        s->top--;
    }
    return true;
}

//顺序栈获取栈顶元素
int SStack_GetTop(SStack s)
{
    return s->data[s->top];
}

//顺序栈测试函数
void SStack_Test()
{
    SStack stack = (SStack)malloc(sizeof(SStack));
    printf("初始化顺序栈中…\n");
    SStack_Init(stack);
    printf("初始化成功，此时栈是否为空?%c\n",SStack_Empty(stack)?'Y':'N');
    printf("正在对栈进行0~20的Push\n");
    for (int i = 0; i <= 20; i++)
    {
        if(!SStack_Push(stack,i)) {
            printf("在Push%d的时候失败\n",i);
            break;
        }
    }
    printf("已全部Push完毕!\n");
    printf("此时栈是否为空?%c\n",SStack_Empty(stack)?'Y':'N');
    printf("此时栈顶元素为%d\n",SStack_GetTop(stack));
    printf("开始Pop,如下\n[");
    int pop;
    while(SStack_Pop(stack,&pop))
    {
        printf(" %d",pop);
    }
    printf(" ]\n已经全部Pop成功!正在退出…\n");
}
