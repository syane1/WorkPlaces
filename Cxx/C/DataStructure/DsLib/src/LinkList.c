#include "LinkList.h"

//初始化链表
bool LList_Init(LList* l)
{
    //l = NULL;//不带头节点写法
    //带头节点写法
    *l = LList_NewNode(NULL,NULL);
    return *l==NULL?false:true;
}

//头插法插入节点
LList LList_HeadInsert(LList L)
{
    int quitnum = -9999999;
    LNode* toInsert;int in;
    L = LList_NewNode(NULL,NULL);
    printf("请输入要插入的结点的值（输入%d退出）：",quitnum);
    scanf("%d",&in);
    toInsert = L;
    while(in != quitnum){
        if(!LList_BInsertNext(toInsert,in)){
            printf("在节点%d后插%d节点时出错",toInsert->data,in);
            break;
        }
        toInsert = toInsert->next;
        printf("请输入要插入的结点的值（输入%d退出）：",quitnum);
        scanf("%d",&in);
    }
    return L;
}

//获取一个新节点
LNode* LList_NewNode(int e,LNode* nextPnd)
{
    LNode* pnd = (LNode*)malloc(sizeof(LNode));
    pnd->data = e;
    pnd->next = nextPnd;
    return pnd;
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

//删除表元素
bool LList_Delete(LList l,int i,int*e)
{
    //下标不正确,在1到长度之间(0为头结点不允许删除)
    if(!(1<=i && i<=LList_Length(l)))return false;
    LNode* tofree = LList_GetElem(l,i);
    if(tofree == NULL)return false;
    *e = tofree->data;
    return LList_DeleteNode(tofree);
}

//删除节点（类似于前插法思路）
bool LList_DeleteNode(LNode* tofree)
{
    if(tofree == NULL)return false;
    LNode* realfree = tofree->next;
    if(realfree == NULL)return false;
    tofree->data = realfree->data;
    tofree->next = realfree->next;
    free(realfree);
    return true;
}

//打印表
void LList_Print(LList l)
{
    LNode* tmp = l; 
    printf("[ ");
    while(tmp->next!=NULL)
    {
        tmp = tmp->next;
        printf("%d->",tmp->data);
    }
    printf("NULL ]\n");
}

//按元素获取节点指针
LNode* LList_Locate(LList l,int e)
{
    if(LList_Empty(l))return NULL;
    LNode* pNd = l->next;
    while(pNd->data!=e)
    {
        pNd = pNd->next;
        if(pNd==NULL)return NULL;
    }
    return pNd;
}

//判空
bool LList_Empty(LList l)
{
    return l->next == NULL;
}

//获取第i个元素(不算头结点)
LNode* LList_GetElem(LList l,int i)
{
    LNode* tmpNd = l;
    for(int idx = 1;idx<= i && tmpNd != NULL;idx++)
    {
        tmpNd = tmpNd->next;
    }
    return tmpNd;
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

//表插入(调用默认后插)
bool LList_Insert(LList l,int i,int e)
{
    if(i<1)return false;
    LNode* tarNd = LList_GetElem(l,i);
    if(tarNd == NULL)return false;
    if(!LList_BInsertNext(tarNd,e)){
        printf("%d后插%d时出错",tarNd->data,e);
    }
    return true;
}

//表插入(后插法)
bool LList_BInsertNext(LNode* curNode,int e)
{
    if(curNode == NULL)return false;
    LNode* tmp = LList_NewNode(e,curNode->next);
    if(tmp == NULL)return false;
    curNode->next = tmp;
    return true;
}

//表插入(前插法，可实现链表逆置)
bool LList_PInsertNext(LNode* curNode,int e)
{
    if(curNode == NULL) return false;
    LNode* tmp = LList_NewNode(curNode->data,curNode->next);
    if(tmp == NULL)return false;
    curNode->next = tmp;
    curNode->data = e;
    return true;
}

//表逆置(利用前插)
LList LList_Reverse(LList l)
{
    if(LList_Empty(l))return NULL;
    LList rvs;
    if(!LList_Init(&rvs)){
        printf("初始化逆置表失败");
        return NULL;
    }
    LNode* curNd = l;
    //由于头节点问题，先后插入第一个节点
    LList_BInsertNext(rvs,curNd->next->data);
    curNd = curNd->next;
    while(curNd->next != NULL){
        curNd = curNd->next;
        //前插当前节点（从第二个节点开始，此时第二个节点为传入的第一个节点）
        LList_PInsertNext(rvs->next,curNd->data);
    }
    //if(LList_PInsertNext(rvs->next,NULL))printf("插入逆置表头节点失败");
    return rvs;
}

//链表测试函数
void LList_Test()
{
    LList l ;
    printf("初始化链表…\n");
    if(!LList_Init(&l)) {printf("初始化链表失败");return;}
    l = LList_HeadInsert(l);
    if(l==NULL){
        printf("头插建表失败，正在退出…\n");
        return;
    }else{
        printf("建表成功！此时表长为%d\n",LList_Length(l));
    }
    printf("插入数据，10,20,30…100\n");
    int len  = LList_Length(l);
    for(int i = 10;i<=100;i+=10)
    {
        LList_Insert(l,len,i);
        len ++;
    }
    printf("此时的链表为:\n");
    LList_Print(l);
    printf("此时表长为%d，在元素10前插入11\n",LList_Length(l));
    LNode* loc10 =LList_Locate(l,10);
    if(loc10 == NULL)
        printf("找不到元素10的位置\n");
    else
        if(!LList_PInsertNext(loc10,11))printf("%d节点前插%d节点失败",loc10->data,11);
    
    printf("此时的链表为:\n");
    LList_Print(l);
    printf("删除第4个元素,");
    int deled;
    if(!LList_Delete(l,4,&deled)){
        printf("删除第4个元素失败\n");
    }else{
        printf("被删除的数据为%d,此时的链表为:\n",deled);
    }
    LList_Print(l);
    printf("此时列表中第6个元素为%d\n",LList_GetElem(l,6)->data);
    printf("测试逆置功能……\n");
    LList rvs = LList_Reverse(l);
    if(rvs != NULL)
        LList_Print(rvs);
    else
        printf("逆置失败，逆置列表为空\n");
    printf("销毁表中…\n");
    LList_DestroyList(l);
    printf("销毁成功！\n");
}
