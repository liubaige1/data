//静态链表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10//静态链表的最大长度
typedef int ElemType;
//定义一个结构体数组，可用SlinkList初始化长度为10的结构体数组，为静态链表
typedef struct {//静态链表结构类型定义
    ElemType data;//存储数据元素
    int next;//下一个元素的下标
}SLinkList[MaxSize];

//初始化静态链表
void InitList(SLinkList a){
    a[0].next=-1;
}

void testSLinkList(){
    SLinkList a;
    InitList(a);
    
}
int main(){   
    testSLinkList();
    return 0;
}