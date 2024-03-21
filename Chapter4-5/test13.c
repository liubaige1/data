#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ElemType int
ThreadNode* pre = NULL; // 全局变量pre，初始为NULL
// 线索二叉树的二叉链表结点结构定义
typedef struct ThreadNode {
    ElemType data; // 结点数据
    struct ThreadNode *left, *right; // 左右孩子指针
    int ltag, rtag; // 左右线索标志
} ThreadNode, *ThreadTree;

//中序线索化二叉树
void CreateInThread(ThreadTree T) {
    pre = NULL; // 初始为NULL
    if (T != NULL) { // 非空二叉树才能线索化
        InThread(T); // 中序线索化二叉树
        if (pre->right == NULL) { // 处理遍历的最后一个结点
            pre->rtag = 1; // 建立后继线索
        }
    }
}

// 访问节点q
void visit(ThreadNode* q) {
    if (!q->left) { // 没有左孩子
        q->ltag = 1; // 建立前驱线索
        q->left = pre; // 前驱线索
    }
    if (pre != NULL && !pre->right) { // 没有右孩子
        pre->rtag = 1; // 建立后继线索
        pre->right = q; // 后继线索
    }
    pre = q; // 标记当前结点为刚刚访问过的结点
}

// 中序遍历进行中序线索化
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->left); // 递归左子树线索化
        visit(T); // 访问当前结点
        InThread(T->right); // 递归右子树线索化
    }
}

// 先序遍历二叉树,进行线索化
void PreThread(ThreadTree T) {
    if (T != NULL) {
        visit(T); // 访问当前结点
        if (T->ltag == 0) { // 左孩子不是前驱线索
            PreThread(T->left); // 递归左子树线索化
        }
        if (T->rtag == 0) { // 右孩子不是后继线索
            PreThread(T->right); // 递归右子树线索化
        }
    }
}

void CreatePostThread (ThreadTree T){
    pre = NULL; // 初始为NULL
    if (T != NULL) { // 非空二叉树才能线索化
        PostThread(T); // 后序线索化二叉树
        if (pre->right == NULL) { // 处理遍历的最后一个结点
            pre->rtag = 1; // 建立后继线索
        }
    }
}

// 后序线索化
void PostThread(ThreadTree T){
    if (T != NULL) {
        if (T->ltag == 0) { // 左孩子不是前驱线索
            PostThread(T->left); // 递归左子树线索化
        }
        if (T->rtag == 0) { // 右孩子不是后继线索
            PostThread(T->right); // 递归右子树线索化
        }
        visit(T); // 访问当前结点
    }
}

// 找到以P为根的子树中，第一个被中序遍历的结点
ThreadNode* Firstnode(ThreadNode* p) {
    while (p->ltag == 0) {
        p = p->left;
    }
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode* Nextnode(ThreadNode* p) {
    if (p->rtag == 0) {
        return Firstnode(p->right);
    } else {
        return p->right;
    }
}

// 找到以P为根的子树中，最后一个被中序遍历的结点
ThreadNode* Lastnode(ThreadNode* p) {
    while (p->rtag == 0) {
        p = p->right;
    }
    return p;
}
