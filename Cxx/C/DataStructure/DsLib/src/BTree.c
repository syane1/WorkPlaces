#include "BTree.h"

//判空
bool BTree_Empty(BTree t){
    if(t==NULL || (t->LChild==NULL && t->RChild==NULL))
        return false;
}

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