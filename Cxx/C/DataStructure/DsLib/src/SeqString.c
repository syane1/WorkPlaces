#include "SeqString.h"

//将字符数组赋值给SString
void SString_StrAssign(SString* pss,const char* pcs)
{
    for(int i = 1;*pcs!='\0'&&i<=_MAXSIZE;pcs++,i++)
    {
        pss->data[i] = *pcs;
        ++pss->data[0];
    }
}

//将参数2赋值给参数1
void SString_Copy(SString* pss,SString ss)
{
    //若传入长度不够则退出
    //if(pss->data[0]<ss.data[0])return;
    pss->data[0] = 0;
    for(int i=1;i<=ss.data[0] && i<_MAXSIZE;i++)
    {
        pss->data[i] = ss.data[i];
        ++pss->data[0];
    }
}

//字符串判空
bool SString_Empty(SString ss)
{
    return ss.data[0]<=0;
}

//字符串(逐字符)比较
int SString_StrCompare(SString ss1,SString ss2)
{
    int len = ss1.data[0]>ss2.data[0]?ss2.data[0]:ss1.data[0];
    for(int i=1;i<=len;i++)
    {
        if(ss1.data[i]!=ss2.data[i])
            return ss1.data[i]-ss2.data[i];
    }
    return ss1.data[0]-ss2.data[0];
}

//求字符串长
int SString_Length(SString ss)
{
    return ss.data[0];
}

//求子串
SString SString_SubString(SString ss,int pos,int len)
{
    SString rss;
    rss.data[0] = 0;
    for(int i = 1;i<=len;i++)
    {
        rss.data[i] = ss.data[pos+i-1];
        rss.data[0]++;
    }
    return rss;
}

//参数2和参数3拼接后字符串赋值给参数1
void SString_Concat(SString* pss,SString ss1,SString ss2)
{
    if(ss1.data[0]+ss2.data[0]>_MAXSIZE)return;
    pss->data[0] = ss1.data[0]+ss2.data[0];
    for(int i = 1;i<=ss1.data[0];i++)
    {
        pss->data[i] = ss1.data[i];
    }
    for(int j = 1;j<=ss2.data[0];j++)
    {
        pss->data[ss1.data[0]+j] = ss2.data[j];
    }
}

//定位，无则传0
int SString_Index(SString S,SString T)
{
    SString ss = SString_CToSS("abaab");
    int next[ss.data[0]];
    SString_Index_KMP_GetNext(ss,next);
    return SString_NaiveSearch(S,T);
}

//朴素搜索算法
int SString_NaiveSearch(SString ss,SString t)
{
    //检查长度
    if(t.data[0]>ss.data[0])return 0;
    int i = 1,j = 1;
    // for(;i<=ss.data[0];i++)
    // {
    //     for(;j<t.data[0];j++)
    //     {
    //         if(ss.data[i]!=t.data[j])
    //         {
    //             i = i-j+1;
    //             break;
    //         }else{
    //             i++;
    //         }
    //     }
    //     if(j==t.data[0]&&ss.data[i]==t.data[j])
    //         return i-j+1; 
    // }
    while(i<=ss.data[0]&&j<=t.data[0])
    {
        if(ss.data[i]!=t.data[j])
        {
            i = i-j+2;
            j=1;
        }else{
            i++;j++;
        }
    }
    return j>t.data[0]?(i-j+1):0;
}

//KMP匹配算法
int SString_Index_KMP(SString ss,SString t,bool imprv)
{

}
// i:a b a a b
// j:  a b a a *
//  [0 1 1 2 2]
void SString_Index_KMP_GetNext(SString t,int* next)
{
    int i=1,j=0;
    next[1] = 0;
    while(i<t.data[0])
    {
        if(j==0||t.data[i]==t.data[j])
        {
            ++i,++j;
            next[i]=j;//若pi=pj，则next[j+1]=next[j]+1
        }else{
            j=next[j];//否则令j=next[j]，循环继续
        }
    }
}
// i:a b a a b
// j:  a b a a *
//  [0 1 1 2 2]
//  [0 1 ]
void SString_Index_KMP_GetNext1(SString t,int* next)
{
    int i=1,j=0;
    next[1] = 0;
    while(i<t.data[0])
    {
        if(j==0||t.data[i]==t.data[j])
        {
            ++i,++j;
            next[i]=j;//若pi=pj，则next[j+1]=next[j]+1
        }else{
            j=next[j];//否则令j=next[j]，循环继续
        }
    }
}

//清除字符串
void SString_ClearString(SString* pss)
{
    pss->data[0] = 0;
}

//销毁字符串
void SString_DestroyString(SString* pss)
{
    for(int i = 1;i<_MAXSIZE;i++)
    {
        pss->data[i] = '\0';
    }
    pss->data[0] = 0;
}

//直接将char*字符数组转为SString
SString SString_CToSS(const char* pcs)
{
    SString ss;
    ss.data[0] = 0;
    SString_StrAssign(&ss,pcs);
    return ss;
}

//直接将SString转为char*字符数组
char* SString_SSToC(SString ss)
{
    char* pc;
    for(int i = 1;i<=ss.data[0];i++,pc++)
    {
        pc = ss.data[i];
    }
    pc++;
    pc = '\0';
    return pc;
}

//顺序字符串测试函数
void SString_Test()
{
    SString ss1;
    SString_ClearString(&ss1);
    printf("将'asdfg'插入到ss1\n");
    SString_StrAssign(&ss1,"asdfg");
    SString ss2;
    printf("复制ss1的值到ss2\n");
    SString_Copy(&ss2,ss1);
    printf("此时ss2是否为空?%c\n",SString_Empty(ss2)?'Y':'N');
    printf("将'hjkl'插入到ss2后\n");
    SString_Concat(&ss2,ss2,SString_CToSS("hjkl"));
    int compared = SString_StrCompare(ss1,ss2);
    printf("ss1和ss2相比谁更大?%s\n",compared>0?"ss1":compared<0?"ss2":"相等");
    compared = SString_StrCompare(ss1,ss1);
    printf("ss1和ss1谁更大?%s\n",compared>0?"前一个ss1":compared<0?"后一个ss1":"相等");
    printf("此时ss2的长度为%d\n",SString_Length(ss2));
    printf(SString_SSToC(SString_SubString(ss2,1,5)));
    printf("ss2当中sdf的下标为？(若无则传0)%d\n",SString_Index(ss2,SString_CToSS("sdf")));
    printf("清除ss1…\n");
    SString_ClearString(&ss1);
    printf("销毁ss1…");
    SString_DestroyString(&ss1);
}
