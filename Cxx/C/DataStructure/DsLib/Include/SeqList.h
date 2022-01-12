#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include "global_var.h"
#include "global_inc.h"
#define MAXSIZE 100

typedef struct{
    int* data;
    int maxSize,length;
}SList;

//初始化表
bool SList_InitList(SList* l);

//求表长
int SList_Length(SList l);

//删除表
void SList_Delete(SList* l,int i,int* e);

//打印表
void SList_Print(SList l);

//定位元素下标
int SList_LocateElem(SList l,int e);

//判空
bool SList_Empty(SList l);

//获取i下标元素
int SList_GetElem(SList l,int i);

//销毁表
void SList_Destroy(SList* l);

//表插入
void SList_Insert(SList* l,int i,int e);

//顺序表测试
void SList_Test();
#endif