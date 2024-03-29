// 双链表
#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node {
    Data data; // 数据域
    struct Node *prior, *next; // 头指针和尾指针
} DNode, *DNodeList;

// 初始化双向单链表
void InitDNodeLIst(DNodeList& L) {
    L = (DNode*)malloc(sizeof(DNode));
    printf("sizeof(L)=%d\n", sizeof(L));
    L->prior = NULL; // 头节点的prior始终指向NULL
    L->next = NULL;
}

// 判断双向单链表是否为空
bool Empty(DNodeList& L) {
    if (L->next == NULL) {
        return true;
    } else {
        return false;
    }
}

// 在p结点之后插入s结点
void InsertNextDNode(DNode* p, DNode* s) {
    s->next = p->next;
    if (p->next != NULL) {
        s->prior = p;
    }
    p->next->prior = s;
    p->next = s;
}
// 删除p结点的后继结点
void DeleteNextDNote(DNode* p) {
    if (p == NULL) {
        return;
    }
    DNode* q = p->next;
    if (q != NULL || q->next != NULL) {
        p->next = q->next;
        q->next->prior = p;
    }
    free(q);
}

// 循环释放链表
void FreeDNodeList(DNodeList& L) {
    DNode* p = L;
    while (p->next != NULL) {
        DeleteNextDNote(p);
    }
    free(L);
    L = NULL;
}

// 遍历
// 后向遍历
//  while (p!=NULL){
//      p=p->next;
//  }

// 前向遍历
//  while (p!=NULL){
//      p=p->prior;
//  }

// 前向遍历,跳过头节点
//  while (p->prior!=NULL){
//      p=p->prior;
//  }

void testDLinkList() {
    // 初始化单链表
    DNodeList L;
    InitDNodeLIst(L);
}
int main() {
    testDLinkList();
    printf("Hello World\n");
    return 0;
}