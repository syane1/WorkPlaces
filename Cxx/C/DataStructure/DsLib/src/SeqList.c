#include "SeqList.h"

//初始化表
bool SList_InitList(SList* l){
    l->length=0;
    l->maxSize = MAXSIZE;
    l->data = (int*) malloc(sizeof(int)*MAXSIZE);
    return true;
}

//求表长
int SList_Length(SList l)
{
    return l.length;
}

//删除表元素，并返回给e
void SList_Delete(SList* l,int i,int* e)
{
    *e = l->data[i];
    for(int idx = i;idx < l->length;idx++)
    {
        l->data[idx] = l->data[idx+1];
    }
    l->length--;
}

//打印表
void SList_Print(SList l)
{
    printf("[ ");
    for(int i = 0;i<l.length;i++)
        printf("%d ",l.data[i]);
    printf("]\n");
}

//定位元素下标
int SList_LocateElem(SList l,int e)
{
    int rt = -1;
    for(int i=0;i<l.length;i++)
        rt = l.data[i]==e?i:rt;
    return rt;
}

//判空
bool SList_Empty(SList l)
{
    return l.length == 0 ;
}

//获取i下标元素
int SList_GetElem(SList l,int i)
{
    return l.data[i];
}

//销毁表
void SList_Destroy(SList* l)
{
    free(l->data);
    l->length=0;
}

//表插入
void SList_Insert(SList* l,int i,int e)
{
    if(i<0||i>l->maxSize)return;
    for(int idx =l->length;idx>=i;idx--)
        l->data[idx] = l->data[idx-1];
    l->data[i] = e;
    l->length++;
}

//顺序表测试
void SList_Test()
{
    SList list;
    printf("初始化列表中…\n");
    if (!SList_InitList(&list))
    {
        printf("初始化失败!");
        return ;
    }
    printf("list是否为空(Y/N)?%c\n", SList_Empty(list) ? 'Y' : 'N');
    printf("生成数据中…\n");
    for (int i = 1; i <= 10; i++)
        SList_Insert(&list, list.length, i);
    printf("list是否为空(Y/N)?%c\n", SList_Empty(list) ? 'Y' : 'N');
    SList_Print(list);
    printf("测试在下标为1的位置插入11\n");
    SList_Insert(&list, 1, 11);
    SList_Print(list);
    printf("查找到元素11的下标位置为%d\n", SList_LocateElem(list, 11));
    printf("查找到元素下标位置为3的元素为%d\n", SList_GetElem(list, 3));
    printf("删除下标为5的表数据中…\n");
    int tail;
    SList_Delete(&list, 5, &tail);
    printf("删除成功，数据为%d\n", tail);
    printf("此时表长为%d\n", SList_Length(list));
    printf("销毁表中…\n");
    SList_Destroy(&list);
}