#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "global_var.h"
#include "global_inc.h"

//单链表
typedef struct _LNode{
    int data;
    struct _LNode* next;
}LNode,*LList;

//初始化表（带头节点）
/// 直接将传入的list变为空值即可
bool LList_Init(LList*);

//头插法插入节点（可用于建表
/// 0.设定离开值
/// 1.创建一个空结点指针toInsert，一个变量in用来接收输入
/// 2.给传入的list分配空间（值为NULL）并将其next设为NULL
/// 3.用in来接收输入
///     3.1 若输入!=离开值则用LList_BInsertNext在toInsert节点后插入值为in的节点，然后令toInsert为它的next指针，继续用in来接收输入
///     3.2 若输入为离开值则不满足循环条件，退出循环
/// 4.返回链表L
LList LList_HeadInsert(LList);

//获取一个新节点
/// 1.创建一个LNode并给其分配空间
/// 2.将参数1赋值给data
/// 3.将参数2给新创建的node的next
/// 4.返回Node（若为空则有问题）
LNode* LList_NewNode(int,LNode*);

//求表长
/// 1.设一个临时节点（初始为头节点），一个长度变量
/// 2.临时节点的next若不为空，则用临时节点接它的下一节点，长度+1
/// 3.若下一节点为空，则说明到末尾，可以返回长度
/// *O(n)
int LList_Length(LList l);

//删除表元素
/// 1.待删除下标是否在区间内（1～length）
/// 2.获取待删除下标节点
/// 3.将待删除节点的data回传给参数3
/// 4.调用LList_DeleteNode删除节点
/// *O(n)
bool LList_Delete(LList l,int i,int*e);

//删除节点（类似于前插法思路）
/// 1.将待删除节点下一节点存储（作为实际删除节点）并检查其是否空
/// 2.将实际删除节点的next给“待删除”节点的next
/// 3.将实际删除节点的data给“待删除”节点的data
/// 4.释放实际删除节点
/// *O(n)
bool LList_DeleteNode(LNode*);

//打印表
// [ 1->2->…->n->NULL ]
/// *O(n)
void LList_Print(LList l);

//按元素获取节点指针
/// 1.若表为空的则返回NULL
/// 2.新建一个Node接头节点的next
/// 3.从头节点后一个开始遍历
/// 3.1.若每一个节点的data ≠ e，则继续遍历
/// 3.1.1若data≠e且next为NULL了（已经到最后），说明没找到，则返回NULL
/// 4.若退出遍历，则说明找到，返回该节点指针
/// *O(n)
LNode* LList_Locate(LList l,int e);

//判空
/// *头节点不存数据，若next指针为空则代表表空
bool LList_Empty(LList l);

//获取第i个元素(不算头结点)
/// 1.创建一个空临时节点指针，赋值为参数1
/// 2.for循环（从1到i且节点不为空）找出第i个节点指针
/// 3.返回临时节点指针
/// *O(n)
LNode* LList_GetElem(LList l,int i);

//销毁表
void LList_DestroyList(LList l);

//表插入(调用默认后插)
/// 1.调用LList_GetElem函数获取目标节点
/// 2.调用LList_Insert_Back进行后插
/// *O(n)
bool LList_Insert(LList,int,int);

//表插入(后)
/// 1.创建新节点，参数1（当前节点）的next作为新节点的next，参数2作为新节点的data
/// 2.将参数1（当前节点）的next改为新节点的地址
bool LList_BInsertNext(LNode* curNode,int e);

//表插入(前，可实现链表逆置)
/// 1.用传入节点的数据和next指针创建一个和传入节点一样的节点
/// 2.将传入节点的next指向新创建的副本节点
/// 3.将传入的数据写到传入节点的data
bool LList_PInsertNext(LNode* curNode,int e);

//表逆置(利用前插)
/// 1.传入列表判空，空则返回NULL
/// 2.创建并初始化逆置列表，若初始化失败则返回NULL
/// 3.把头节点给临时变量当前节点
/// 4.后插传入列表的（不含头节点的）第一个节点
/// 5.将当前节点变为它的下一节点
/// 6.若当前节点的next不为空时，进入循环
/// 6.1 将当前节点变成下一节点，并后插入逆置列表的（不含头节点的）第一个节点
/// 7.返回逆置节点
LList LList_Reverse(LList l);

//链表测试函数
/// 测试函数先后涉及：
/// 1.LList_Init（初始化）
/// 2.LList_HeadInsert（头节点的插入）
/// 3.LList_Length（获取链表长度）
/// 4.LList_Insert（按位序插入）
/// 5.LList_Print（打印链表）
/// 6.LList_Locate（获取元素下标）
/// 7.LList_PInsertNext（前插法插入下一个节点）
/// 8.LList_Delete（删除第i个元素并回传该元素的值）
/// 9.LList_GetElem（获取第i哥节点）
/// 10.LList_DestroyList（销毁链表）
/// 11.LList_Reverse（列表逆置）
/// ……
/// 等函数的测试
void LList_Test();
#endif