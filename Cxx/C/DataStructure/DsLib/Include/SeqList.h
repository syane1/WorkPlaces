#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include "global_var.h"
#include "global_inc.h"
#define MAXSIZE 100

//顺序表
typedef struct{
    //顺序存储
    //int data[MAXSIZE];    //顺序表的元素
    //动态存储
    int* data;              //动态分配数组的指针
    int maxSize,length;     //数组的最大表长和当前长度
}SList;

//初始化表
/// 1.调用带长度的初始化函数
/// * 默认长度 MAXSIZE = 100，长度可变
bool SList_InitList(SList* l);

//带长度初始化表
/// 1.初始化最大表长、当前长度等数据
/// 2.动态分配（若存储方式为动态分配）
bool SList_InitList_Len(SList* l,int len);

//删除表数据（下标从0开始）
/// 1.判断范围（0 ≤ i ≤ length-1）
/// 2.将数值赋给回传的e
/// 3.从i开始，到length-1，每一个都赋值为下一个下标的值
/// 4.length-1
/// * bst:O(1)    wst:O(n)    avg:O(n)
bool SList_Delete(SList* l,int i,int* e);

//打印表
/// * [ 1 2 3 … n ]
void SList_Print(SList l);

//给定元素确定下标（从0开始）
/// 1.从0～length-1查找是否存在
/// 2.若相等，则返回下标
/// * 若为-1则查找失败
int SList_LocateElem(SList l,int e);

//判空（length≤0，逻辑上的空即可）
bool SList_Empty(SList l);

//获取i下标（从0开始）元素
///* O(1)
int SList_GetElem(SList l,int i);

//销毁表
void SList_Destroy(SList* l);

//表插入（下标从0开始）
/// 1.判断长度范围（0 ≤ i ≤ length-1）
/// 2.判断空间是否满 length ≥ MAXSIZE
/// 3.从最后一个(length)开始到第i个，每个元素赋值给下一个元素
/// 4.将i下标的元素变为传入的e，长度+1
/// * bst:O(1)    wst:O(n)    avg:O(n)
bool SList_Insert(SList* l,int i,int e);

//顺序表测试
/// 先后涉及
/// 1.SList_InitList（初始化）
/// 2.SList_Empty（判空）
/// 3.SList_Insert（插入）
/// 4.SList_Print（打印）
/// 5.SList_LocateElem（按元素找下标）
/// 6.SList_GetElem（按下标找元素）
/// 7.SList_Delete（按下标删除元素并返回）
/// 8.SList_Destroy（销毁表）
/// ……
/// 等测试
void SList_Test();
#endif