//顺序存储队列
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义队列中的最大元素数
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize]; //用静态数组存放队列元素
    int front, rear; //队头指针和队尾指针
} SeQueue;

// //方案二
// typedef struct {
//     ElemType data[MaxSize]; //用静态数组存放队列元素
//     int front,rear; //队头指针和队尾指针
//     int size; //队列当前长度
// } SeQueue;

//方案三
// typedef struct {
//     ElemType data[MaxSize]; //用静态数组存放队列元素
//     int front,rear; //队头指针和队尾指针
//     int tag; //最近进行的是插入/删除
// } SeQueue;
//初始化队列
void InitQueue(SeQueue& Q) {
    //初始时队头和队尾指针指向0
    Q.front = Q.rear = 0;
}

//判断队列是否为空
bool QueueEmpty(SeQueue& Q) {
    // 队空条件
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

// // 方案二判断队列是否为空
// bool QueueEmpty(SeQueue *Q){
//     // 队空条件
//     if (Q.size==0){
//         return true;
//     }
//     return false;
// }

// // 方案三判断队列是否为空
// bool QueueEmpty(SeQueue *Q){
//     // 队空条件
//     if (Q.front==Q.rear&&tag==1){
//         return true;
//     }
//     return false;
// }

//入队
void EnQueue(SeQueue& Q, ElemType x) {
    if (Q.front == (Q.rear + 1) % MaxSize) {
        printf("队列已满，无法入队");
    }
    Q.data[Q.rear] = x; //将x插入队尾
    Q.rear = (Q.rear + 1) % MaxSize; //队尾指针+1取模
}

//出队
void DeQueue(SeQueue& Q, ElemType& x) {
    if (Q.front == Q.rear) {
        printf("队列为空,无法弹出"); //判断队列为空
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize; //队头指针后移
}

//读队头元素,不删除
void GetHead(SeQueue& Q, ElemType& x) {
    if (Q.front == Q.rear) {
        printf("队列为空,无法弹出"); //判断队列为空
    }
    x = Q.data[Q.front];
}

void testSeQueue() {
    //声明一个队列(顺序存储)
    SeQueue sq;
    ElemType num = 100;
    InitQueue(sq); //初始化队列
    EnQueue(sq, 10);
    GetHead(sq, num);
    DeQueue(sq, num);
    printf("%d", num);
}

int main() {
    testSeQueue();
    return 0;
}