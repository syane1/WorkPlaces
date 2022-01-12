#include "DsLib/Include/global_head.h"
#include "DsLib/Include/global_inc.h"

int main()
{
    int sel;
    printf("请输入一个测试项:(11:SeqList\t12:LinkList\t21:SeqStack\t22:LinkStack\t31:LinkQueue\t32:SeqQueue\n");
    printf("41:SeqString\tothers:exit)\n");
    while(scanf("%d",&sel))
    {
        switch (sel)
        {
        case 11:
            SList_Test();
            break;
        
        case 12: 
            LList_Test();
            break;
        
        case 21:
            SStack_Test();
            break;
        
        case 22:
            LStack_Test();
            break;

        case 31:
            LQueue_Test();
            break;

        case 32:
            SQueue_Test();
            break;

        case 41:
            SString_Test();
            break;

        default:
            printf("输个p，根本就没有");
            continue;
        }
        break;
    }
    return 0;
}
