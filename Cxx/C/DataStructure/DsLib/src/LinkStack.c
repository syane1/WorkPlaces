#include "LinkStack.h"

//链栈初始化
LStack LStack_Init()
{
    LStack r = (LStack)malloc(sizeof(LStack));
    r->data = NULL;
    r->next = NULL;
    return r;
}

//链栈判空
bool LStack_Empty(LStack stack)
{
    return stack->next==NULL; 
}

//链栈压入
bool LStack_Push(LStack stack,int e)
{
    LStackNode* node = LStack_GetTop(stack);
    if(node == NULL)return false;
    LStackNode* newNode = (LStackNode*)malloc(sizeof(LStackNode));
    if(newNode == NULL)return false;
    newNode->data = e;
    newNode->next = NULL;
    node->next = newNode;
    return true;
}

//链栈弹出
bool LStack_Pop(LStack stack,int* e)
{
    LStackNode* tail,*tail_p;
    tail = stack;
    while(tail->next!=NULL)
    {
        tail_p = tail;
        tail = tail->next;
    }
    if(tail == NULL)return false;
    *e = tail->data;
    tail->data = NULL;
    if(tail==stack)return false;
    free(tail);
    tail_p->next = NULL;
    return true;
}

//链栈获取栈顶元素
LStackNode* LStack_GetTop(LStack stack)
{
    LStackNode* node = stack;
    while(node->next!=NULL)
    {
        node = node->next;
    }
    return node;
}

//链栈测试函数
void LStack_Test()
{
    printf("初始化链栈中…\n");
    LStack stack = LStack_Init(stack);
    printf("初始化成功，此时栈是否为空?%c\n",LStack_Empty(stack)?'Y':'N');
    printf("正在对栈进行0~20的Push\n");
    for (int i = 1; i <= 10; i++)
    {
        if(!LStack_Push(stack,i)) {
            printf("在Push%d的时候失败\n",i);
            break;
        }
    }
    printf("已全部Push完毕!\n");
    printf("此时栈是否为空?%c\n",LStack_Empty(stack)?'Y':'N');
    printf("此时栈顶元素为%d\n",LStack_GetTop(stack)->data);
    printf("开始Pop,如下\n[");
    int pop;
    while(LStack_Pop(stack,&pop))
    {
        printf(" %d",pop);
    }
    printf(" ]\n已经全部Pop成功!正在退出…\n");
    //free(stack);//此处不释放
}
