#ifndef B_TREE_H
#define B_TREE_H

#include "global_var.h"
#include "global_inc.h"

typedef struct _BTNode
{
    int data;
    struct _BTNode * LChild, * RChild;
}BTNode, * BTree;

//判空
bool BTree_Empty(BTree);

//前序遍历
void BTree_PreOrder(BTree);

//中序遍历
void BTree_InOrder(BTree);

//后序遍历
void BTree_PostOrder(BTree);

//层次遍历
void BTree_LvlOrder(BTree);

//线索化二叉树
BTree BTree_Cueing(BTree);

//二叉排序树
BTree BTree_Rank(BTree);

//是否是满二叉树
bool BTree_IsFull(BTree);

//是否是完全二叉树
bool BTree_IsComplete(BTree);

//转为平衡二叉树
BTree BTree_Balanced(BTree);

#endif