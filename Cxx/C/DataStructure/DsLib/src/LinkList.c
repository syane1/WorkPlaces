#include "LinkList.h"

//初始化链表
LList LList_Init()
{
    LList l = (LNode*)malloc(sizeof(LNode));
    if(l == NULL)return NULL;
    l->data = NULL;
    l->next = NULL;
    return l;
}

//求表长
int LList_Length(LList l)
{
    int length = 0;
    LNode* curNode = l;
    while(curNode->next!=NULL)
    {
        curNode = curNode->next;
        length++;
    }
    return length;
}

//删除表元素(打印出来的表的第i个)
void LList_Delete(LList l,int i,int*e)
{
    //下标不正确,在1到长度之间(0为头结点不允许删除)
    if(i<=0||i>LList_Length(l))return;
    LNode* tmp = l;
    for(int idx = 1;idx<i;idx++)
        tmp = tmp->next;
    LNode* tofree = tmp->next;
    *e = tmp->next->data;
    tmp->next = tmp->next->next; 
    free(tofree);
}

//打印表
void LList_Print(LList l)
{
    LNode* tmp = l; 
    printf("[ ");
    do
    {
        if(tmp->next!=NULL){
            tmp = tmp->next;
            printf("%d->",tmp->data);
        }
    }while(tmp->next!=NULL);
    printf("NULL ]\n");
}

//获取元素的指针
LNode* LList_Locate(LList l,int e)
{
    if(l->next==NULL)return NULL;
    LNode* tmp = l->next;
    while(tmp->data!=e)
    {
        tmp = tmp->next;
        if(tmp==NULL)break;
    }
    return tmp;
}

//判空
bool LList_Empty(LList l)
{
    return l->next == NULL;
}

//获取第i个元素(不算头结点)
int LList_GetElem(LList l,int i)
{
    LNode* tmp = l;
    for(int idx = 1;idx<= i;idx++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

//销毁表
void LList_DestroyList(LList l)
{
    LNode* tmp= l;
    LNode* nextToFree= tmp->next;
    while (tmp->next!=NULL)
    {
        free(tmp);
        tmp = nextToFree;
        nextToFree = nextToFree->next;
    }
}

//表插入(后插法)
void LList_Insert_Back(LNode* curNode,int e)
{
    LNode* tmp = (LNode*)malloc(sizeof(LNode));
    tmp->data = e;
    tmp->next = curNode->next;
    curNode->next = tmp;
}

//表插入(前插法，可实现链表逆置)
void LList_Insert_Pre(LNode* curNode,int e)
{
    LNode* tmp = (LNode*)malloc(sizeof(LNode));
    tmp->data = curNode->data;
    tmp->next = curNode->next;
    curNode->next = tmp;
    curNode->data = e;
}


//链表测试函数
void LList_Test()
{
    LList l = LList_Init();
    printf("初始化链表…\n");
    if(l==NULL){
        printf("初始化失败，正在退出…\n");
        return;
    }else{
        printf("初始化成功！此时表长为%d\n",LList_Length(l));
    }
    printf("插入数据，10,20,30…100\n");
    LNode* tail = l;
    for(int i = 0;i<=100;i+=10)
    {
        LList_Insert_Back(tail,i);
        tail= tail->next;
    }
    printf("此时的链表为:\n");
    LList_Print(l);
    printf("此时表长为%d，在元素10前插入11\n",LList_Length(l));
    LNode* locate10 =LList_Locate(l,10);
    if(locate10 == NULL)
        printf("找不到元素10的位置\n");
    else
        LList_Insert_Pre(locate10,11);
    printf("此时的链表为:\n");
    LList_Print(l);
    printf("删除第5个元素,");
    int deled;
    LList_Delete(l,5,&deled);
    printf("被删除的数据为%d,此时的链表为:\n",deled);
    LList_Print(l);
    printf("此时列表中第6个元素为%d\n",LList_GetElem(l,6));
    printf("销毁表中…\n");
    LList_DestroyList(l);
    printf("销毁成功！\n");
}
