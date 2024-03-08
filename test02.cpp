// 循环链表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Data;
typedef struct Node
{
    Data data;                 // 数据域
    struct Node *prior, *next; // 头指针和尾指针
} DNode, *DNodeList;

// 初始化循环双链表
void InitDNodeList(DNodeList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    L->next = L;
    L->prior = L;
}

// 判断循环双链表是否为空
bool Empty(DNodeList &L)
{
    if (L->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 判断结点p是否为循环双链表的表尾结点
bool isTail(DNodeList &L, DNode *p)
{
    if (p->next == L)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 在p结点之后插入s结点
void InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
}

// 删除p的后继节点q
void DeleteNestDNode(DNode *p, DNode *q)
{
    p->next = q->next;
    q->next->prior = p;
    free(q);
}

void testDNodeList()
{
    DNodeList L;
    InitDNodeList(L);
    // 后续代码
}
int main()
{
    testDNodeList();
    printf("test");
    return 0;
}
