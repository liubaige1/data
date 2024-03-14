#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义栈中元素的最大个数
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize]; //静态数组存放栈中元素
    int top; //栈顶指针
} SqStack;

//初始化栈
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

//括号匹配检查
bool bracketCheck(char str[], int length) {
    SqStack S;
    InitStack(S); //初始化一个栈
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            Push(S, str[i]); //扫描到左括号,入栈
        } else {
            if (StackEmpty(S)) { //扫描到右括号，且当前栈空
                return false; //匹配失败
            }
            char topElem;
            Pop(S, topElem); //栈顶元素出栈
            if (str[i] == ')' && topElem != '(') {
                return false;
            }
            if (str[i] == ']' && topElem != '[') {
                return false;
            }
            if (str[i] == '}' && topElem != '{') {
                return false;
            }
        }
    }
    return StackEmpty(S); //检索完全部括号后,栈空说明匹配成功
}

int main() {
    char str[] = "[(()])";
    int length = sizeof(str) / sizeof(str[0]);
    printf("%d\n", bracketCheck(str, length));
    return 0;
}