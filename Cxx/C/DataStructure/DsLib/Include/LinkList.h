#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "global_var.h"
#include "global_inc.h"

typedef struct _LNode{
    int data;
    struct _LNode* next;
}LNode,*LList;

//初始化表
LList LList_Init();

//求表长
int LList_Length(LList l);

//删除表元素
void LList_Delete(LList l,int i,int*e);

//打印表
void LList_Print(LList l);

//获取元素的指针
LNode* LList_Locate(LList l,int e);

//判空
bool LList_Empty(LList l);

//获取第i个元素(不算头结点)
int LList_GetElem(LList l,int i);

//销毁表
void LList_DestroyList(LList l);

//表插入(后)
void LList_Insert_Back(LNode* curNode,int e);

//表插入(前，可实现链表逆置)
void LList_Insert_Pre(LNode* curNode,int e);

//链表测试函数
void LList_Test();
#endif