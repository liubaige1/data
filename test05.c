//链栈
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode, *LinkList;

//初始化
void InitStack(LinkList L){
   L->next =NULL;
}

//进栈
void pushStack(LinkList L,ElemType x){
    LinkNode *s=(LinkList)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=L;
    L=s;
}

//取栈顶元素
ElemType GetTopStack1(LinkList L){
    if (L==NULL){
        return (ElemType) NULL;
    }
    return L->data;
}

//出栈
ElemType GetTopStack(LinkList L){
    if (L==NULL){
        return (ElemType) NULL; //栈空
    }
    ElemType x;
    x=L->data;
    LinkNode *s;
    s=L;
    L=L->next;
    free(s);
    return x;
}


int main(){
    LinkNode L;
    InitStack(&L);
    // 入栈
    int n=0;
    printf("请输入栈的元素个数:");
    scanf("%d",&n);
    for (int i = 0; i < n;)
    {
        int e;
        printf("请输入第%d个入栈的元素:",++i);
        scanf("%d", &e);
        pushStack(&L, e);
    }
    return 0;
}
