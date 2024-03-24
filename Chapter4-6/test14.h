#include <stdio.h>
#include <stdlib.h>

// 孩子表示法 (顺序+链式存储)
#define MaxSize 100
struct CTNode {
    int child;
    struct CTNode* next;
};
typedef struct {
    int data;
    struct CTNode* firstchild;
} CTBox;
typedef struct {
    CTBox nodes[MaxSize];
    int n, r; // 结点数和根的位置
} CTree;

// 孩子兄弟表示法 (二叉链表)
typedef struct CSNode {
    int data; // 结点数据
    struct CSNode *firstchild, *nextsibling; // 第一个孩子结点和右兄弟结点
} CSNode, *CSTree;
