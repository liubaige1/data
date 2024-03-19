#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ElemType int

// 二叉树的二叉链表结点结构定义
typedef struct BiTNode {
    ElemType data; // 结点数据
    BiTNode* left; // 左孩子指针
    BiTNode* right; // 右孩子指针
} BiTNode, *BiTree;

// 初始化二叉树的二叉链表
void InitBiTree(BiTree& T) {
    T = new BiTNode;
    T->data = 'A';
    T->left = NULL;
    T->right = NULL;
}

// 二叉树的前序遍历递归算法
void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%c", T->data); // 显示结点数据
        PreOrder(T->left); // 再先序遍历左子树
        PreOrder(T->right); // 最后先序遍历右子树
    }
}

// 二叉树的中序遍历递归算法
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->left); // 中序遍历左子树
        printf("%c", T->data); // 显示结点数据
        InOrder(T->right); // 最后中序遍历右子树
    }
}

// 二叉树的后序遍历递归算法
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->left); // 后序遍历左子树
        PostOrder(T->right); // 后序遍历右子树
        printf("%c", T->data); // 显示结点数据
    }
}

// 二叉树的层次遍历
void LevelOrder(BiTree T) {
    BiTree p;
    BiTree qu[MaxSize]; // 定义一个顺序栈
    int front = 0, rear = 0; // 初始化队首和队尾指针
    if (T != NULL) {
        rear = (rear + 1) % MaxSize; // 入队
        qu[rear] = T; // 根结点入队
        while (front != rear) { // 队列不空
            front = (front + 1) % MaxSize; // 出队
            p = qu[front]; // 出队结点
            printf("%c", p->data); // 显示结点数据
            if (p->left != NULL) {
                rear = (rear + 1) % MaxSize; // 入队
                qu[rear] = p->left; // 左孩子入队
            }
            if (p->right != NULL) {
                rear = (rear + 1) % MaxSize; // 入队
                qu[rear] = p->right; // 右孩子入队
            }
        }
    }
}

// 生成一个测试二叉树
void CreateTestBiTree(BiTree* T) {
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    if (*T) {
        (*T)->data = 'A';
        (*T)->left = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->right = (BiTNode*)malloc(sizeof(BiTNode));
        if ((*T)->left) {
            (*T)->left->data = 'B';
            (*T)->left->left = NULL;
            (*T)->left->right = NULL;
        }
        if ((*T)->right) {
            (*T)->right->data = 'C';
            (*T)->right->left = NULL;
            (*T)->right->right = NULL;
        }
    }
}

int main() {
    BiTree T;
    // InitBiTree(T);
    CreateTestBiTree(&T);
    printf("二叉树的前序遍历递归算法：");
    PreOrder(T);
    printf("\n");
    printf("二叉树的中序遍历递归算法：");
    InOrder(T);
    printf("\n");
    printf("二叉树的后序遍历递归算法：");
    PostOrder(T);
    printf("\n");
    printf("二叉树的层次遍历：");
    LevelOrder(T);
    printf("\n");
    // printf("二叉树的后序遍历非递归算法：");
    // PostOrder2(T);
    // printf("\n");
    return 0;
}