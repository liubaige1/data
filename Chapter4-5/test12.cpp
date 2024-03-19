#include <stdio.h>
#define MaxSize 100
#define ElemType int

// 二叉树的二叉链表结点结构定义
typedef struct BiTNode{
    ElemType data;  // 结点数据
    BiTNode *left;  // 左孩子指针
    BiTNode *right;  // 右孩子指针
}BiTNode, *BiTree;

// 初始化二叉树的二叉链表
void InitBiTree(BiTree &T){
    T = new BiTNode;
    T->data = 'A';
    T->left = NULL;
    T->right = NULL;
}

// 插入新结点
void InsertNode(BiTree &T, ElemType e, ElemType e1, ElemType e2){
    BiTree p = T;
    if(p != NULL){
        if(p->data == e){
            if(e1 != 0){
                BiTree p1 = new BiTNode;
                p1->data = e1;
                p1->left = NULL;
                p1->right = NULL;
                p->left = p1;
            }
            if(e2 != 0){
                BiTree p2 = new BiTNode;
                p2->data = e2;
                p2->left = NULL;
                p2->right = NULL;
                p->right = p2;
            }
        }else{
            InsertNode(p->left, e, e1, e2);
            InsertNode(p->right, e, e1, e2);
        }
    }
}

// 二叉树的前序遍历递归算法
void PreOrder(BiTree T){
    if(T != NULL){
        printf("%c", T->data); // 显示结点数据
        PreOrder(T->left); // 再先序遍历左子树
        PreOrder(T->right); // 最后先序遍历右子树
    }
}

// 二叉树的中序遍历递归算法
void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->left); // 中序遍历左子树
        printf("%c", T->data); // 显示结点数据
        InOrder(T->right); // 最后中序遍历右子树
    }
}

// 二叉树的后序遍历递归算法
void PostOrder(BiTree T){
    if(T != NULL){
        PostOrder(T->left); // 后序遍历左子树
        PostOrder(T->right); // 后序遍历右子树
        printf("%c", T->data); // 显示结点数据
    }
}

// 二叉树的层次遍历
void LevelOrder(BiTree T){
    BiTree p;
    BiTree qu[MaxSize]; // 定义一个顺序栈
    int front = 0, rear = 0; // 初始化队首和队尾指针
    if(T != NULL){
        rear = (rear + 1) % MaxSize; // 入队
        qu[rear] = T; // 根结点入队
        while(front != rear){
            front = (front + 1) % MaxSize; // 出队
            p = qu[front]; // 出队结点
            printf("%c", p->data); // 显示结点数据
            if(p->left != NULL){
                rear = (rear + 1) % MaxSize; // 入队
                qu[rear] = p->left; // 左孩子入队
            }
            if(p->right != NULL){
                rear = (rear + 1) % MaxSize; // 入队
                qu[rear] = p->right; // 右孩子入队
            }
        }
    }
}

// 二叉树的后序遍历非递归算法
void PostOrder2(BiTree T){
    BiTree p;
    BiTree qu[MaxSize]; // 定义一个顺序栈
    int top = -1; // 初始化栈顶指针
    int flag[MaxSize]; // 定义一个标志数组
    if(T != NULL){
        top = top + 1; // 根结点入栈
        qu[top] = T;
        while(top != -1){
            while(qu[top] != NULL){
                top = top + 1; // 向左走到尽头
                qu[top] = qu[top - 1]->left;
                flag[top] = 0; // 标志左结点
            }
            top = top - 1; // 回退一步
            if(top != -1){
                if(flag[top] == 0){
                    qu[top] = qu[top]->right; // 转向右子树
                    flag[top] = 1; // 标志右结点
                    top = top + 1; // 右结点入栈
                    qu[top] = qu[top - 1]->right;
                    flag[top] = 0; // 标志左结点
                }else{
                    p = qu[top]; // 访问根结点
                    printf("%c", p->data); // 显示结点数据
                    top = top - 1; // 出栈
                }
            }
        }
    }
}


int main(){
    BiTree T;
    InitBiTree(T);
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
    printf("二叉树的后序遍历非递归算法：");
    PostOrder2(T);
    printf("\n");
    return 0;
}