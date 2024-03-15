#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义栈中元素的最大个数
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize]; //静态数组存放栈中元素
    int top; //栈顶指针
} SqStack;

//初始化栈。构造一个空栈S,分配内存空间。
void InitStack(SqStack& S) {
    S.top = -1;
}

//判断栈是否为空
bool StackEmpty(SqStack& S) {
    if (S.top == -1) {
        return true; //栈为空
    }
    return false; //栈不为空
}

//进栈，若栈S未满，则将x加入使之成为新栈顶
bool Push(SqStack& S, ElemType x) {
    if (S.top == MaxSize - 1) {
        return false;
    }
    S.data[++S.top] = x; // 先++在入栈
    return true;
}

//出栈，若栈S非空，则弹出栈顶元素，并用x返回。
bool Pop(SqStack& S, ElemType x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top--]; //先出栈，指针再减1
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, ElemType& x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top]; //x记录栈顶元素
    return true;
}

void testStack() {
    SqStack S;
    bool b;
    int i = 0;
    InitStack(S);
    printf("%d\n", StackEmpty(S));
    printf("%d\n", Push(S, i));
    printf("%d\n", GetTop(S, i));
    printf("%d\n", Pop(S, i));
}

int main() {
    testStack();
    return 0;
}