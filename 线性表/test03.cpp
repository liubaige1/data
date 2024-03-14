//静态链表
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 //静态链表的最大长度
typedef int ElemType;

//定义一个结构体数组，可用SlinkList初始化长度为10的结构体数组，为静态链表
typedef struct { //静态链表结构类型定义
    ElemType data; //存储数据元素
    int next; //下一个元素的下标
} SLinkList[MaxSize]; // 可用SLinkList定义一个长度为MaxSize的"数组"

//初始化静态链表
void InitList(SLinkList& a) {
    a[0].next = -1;
}

// 输出静态链表
void PrintList(SLinkList& a) {
    int i = a[0].next;
    while (i != -1) {
        printf("%d ", a[i].data);
        i = a[i].next;
    }
    printf("\n");
}

void testSLinkList() {
    SLinkList a;
    InitList(a);
    PrintList(a);
}

//主函数
int main() {
    testSLinkList();
    printf("test\n");
    return 0;
}