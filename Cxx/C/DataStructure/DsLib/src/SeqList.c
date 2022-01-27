#include "SeqList.h"

//初始化表
bool SList_InitList(SList* l){
    return SList_InitList_Len(l,MAXSIZE);
}

//带长度初始化表
bool SList_InitList_Len(SList* l,int len){
    l->length=0;
    l->maxSize = len;
    l->data = (int*) malloc(sizeof(int)*l->length);
    return true;
}

//删除表元素，并返回给e
bool SList_Delete(SList* l,int i,int* e)
{
    if(!(0<=i && i<= l->length-1))return false;
    *e = l->data[i];
    for(int idx = i;idx < l->length;idx++)
    {
        l->data[idx] = l->data[idx+1];
    }
    l->length--;
    return true;
}

//打印表
void SList_Print(SList l)
{
    printf("[ ");
    for(int i = 0;i<l.length;i++)
        printf("%d ",l.data[i]);
    printf("]\n");
}

//给定元素确定下标
int SList_LocateElem(SList l,int e)
{
    for(int i=0;i<l.length;i++)
        if(l.data[i]==e)return i;
        //rt = l.data[i]==e?i:rt; //取最后一个的逻辑
    return -1;
}

//判空
bool SList_Empty(SList l)
{
    return l.length <= 0 ;
}

//获取i下标元素
int SList_GetElem(SList l,int i)
{
    return l.data[i];
}

//销毁表
void SList_Destroy(SList* l)
{
    l->length=0;
    free(l->data);
}

//表插入
bool SList_Insert(SList* l,int i,int e)
{
    if(i<0||i>l->maxSize)return false;
    for(int idx =l->length;idx>=i;idx--)
        l->data[idx] = l->data[idx-1];
    l->data[i] = e;
    l->length++;
    return true;
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
        if(!SList_Insert(&list, list.length, i))break;
    printf("list是否为空(Y/N)?%c\n", SList_Empty(list) ? 'Y' : 'N');
    SList_Print(list);
    printf("测试在下标为1的位置插入11\n");
    if(!SList_Insert(&list, 1, 11)) printf("插入失败！");
    SList_Print(list);
    printf("查找到元素11的下标位置为%d\n", SList_LocateElem(list, 11));
    printf("查找到元素下标位置为3的元素为%d\n", SList_GetElem(list, 3));
    printf("删除下标为5的表数据中…\n");
    int tail;
    if(!SList_Delete(&list, 5, &tail))printf("删除下标为5的第6个元素失败");
    printf("删除成功，数据为%d\n", tail);
    printf("此时表长为%d\n", list.length);
    printf("销毁表中…\n");
    SList_Destroy(&list);
}