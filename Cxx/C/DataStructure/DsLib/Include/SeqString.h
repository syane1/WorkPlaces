#ifndef SEQ_STRING_H
#define SEQ_STRING_H

#include "global_var.h"
#include "global_inc.h"

typedef struct _SString
{
    char data[_MAXSIZE];
}SString;

//将字符数组赋值给SString
void SString_StrAssign(SString*,const char*);

//将参数2赋值给参数1
void SString_Copy(SString*,SString);

//字符串判空
bool SString_Empty(SString);

//字符串(逐字符)比较
int SString_StrCompare(SString,SString);

//求字符串长
int SString_Length(SString);

//求子串
SString SString_SubString(SString,int,int);

//参数2和参数3拼接后字符串赋值给参数1
void SString_Concat(SString*,SString,SString);

//定位，无则传0
int SString_Index(SString,SString);

//清除字符串
void SString_ClearString(SString*);

//销毁字符串
void SString_DestroyString(SString*);

//直接将char*字符数组转为SString
SString SString_CToSS(const char*);

//直接将SString转为char*字符数组
char* SString_SSToC(SString );

//顺序字符串测试函数
void SString_Test();
#endif