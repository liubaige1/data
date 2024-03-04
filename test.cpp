#include <stdio.h>
// void test(int &x){
//     x = 1024;
//     printf("test函数内部 x = %d\n",x);
//     printf("test函数内部地址 x = %p\n",&x);
// }
    #define MAX_SIZE 100
    typedef int ElemType;

    typedef struct {
        ElemType data[MAX_SIZE];
        int length;
    } SeqList;

    // 初始化顺序表
    void InitList(SeqList* L) {
        L->length = 0;
    }

    bool check_same(SeqList &L){
        if (L.length==0){
            return false;
        }
        int i,j;
        for (i=0,j=1;j<L.length;j++){
            if (L.data[i]!=L.data[j]){
                L.data[++i]=L.data[j];
            }
        }
         L.length=i+1;
        return true;

    }

    // 在顺序表的第i个位置插入元素e
    bool ListInsert(SeqList* L, int i, ElemType e) {
        if (L->length == MAX_SIZE) {
            printf("顺序表已满，无法插入。\n");
            return false;
        }
        if (i < 1 || i > L->length + 1) {
            printf("插入位置不合法。\n");
            return false;
        }
        for (int j = L->length; j >= i; j--) {
            L->data[j] = L->data[j - 1];
        }
        L->data[i - 1] = e;
        L->length++;
        return true;
    }
    // P24 6
    bool sum(SeqList &L, SeqList &Q, SeqList &S){
        int i=0, j=0;
        while (i+j<L.length+Q.length){
            if (L.data[i] <= Q.data[j]) {
                ListInsert(&S, S.length+1, L.data[i]);
                i++;
            } else if (L.data[i] > Q.data[j]) {
                ListInsert(&S, S.length+1, Q.data[j]);
                j++;
            }
            if (i==L.length){
                while (j<Q.length){
                    ListInsert(&S,S.length+1,Q.data[j]);
                    j++;
                }
            }
            if (j==Q.length){
                while (i<L.length){
                    ListInsert(&S,S.length+1,L.data[i]);
                    i++;
                }
            }
        }
        return true;
    }

int main(){
    // int sum = 0;
    // int n=16;
    // for (int i=1;i<n;i*=2){
    //     for (int j=0;j<i;j++){
    //         sum++;
    //         printf("sum=%d",sum);
    //     }
    // }
    // int x = 0;
    // int n = 16;
    // while (n >= (x + 1) * (x + 1))
    // {
    //     x += 1;
    // }
    // printf("x=%d", x);

    // int x=1023;
    // printf("调用前 x = %d\n",x);
    // printf("调用前地址 x = %p\n",&x);
    // test(x);
    // printf("调用后 x = %d\n",x);
    // printf("调用后地址 x = %p\n",&x);
    SeqList L,Q;
    InitList(&L);
    InitList(&Q);

    // for (int i = 0; i < 10; i++) {
        ListInsert(&L, 1, 1);
        ListInsert(&L, 2, 2);
        ListInsert(&L, 3, 2);
        ListInsert(&L, 4, 3);
        ListInsert(&L, 5, 3);
        ListInsert(&L, 6, 3);
        ListInsert(&L, 7, 4);
        ListInsert(&L, 8, 4);
        ListInsert(&L, 9, 4);
        ListInsert(&L, 10, 4);
        ListInsert(&Q, 1, 1);
        ListInsert(&Q, 2, 2);
        ListInsert(&Q, 3, 2);
        ListInsert(&Q, 4, 3);
        ListInsert(&Q, 5, 3);
        ListInsert(&Q, 6, 3);
        ListInsert(&Q, 7, 4);
        ListInsert(&Q, 8, 4);
        ListInsert(&Q, 9, 4);
        ListInsert(&Q, 10, 4);
    // }

    for (int i = 0; i < 10; i++) {
        printf("L.data[%d]=%d\n",i, L.data[i]);
    }
    for (int i = 0; i < 10; i++) {
        printf("Q.data[%d]=%d\n",i, Q.data[i]);
    }
    // check_same(L);
    printf("修改后\n");
    SeqList S;
    InitList(&S);
    sum(L,Q,S);
    for (int i = 0; i < L.length; i++) {
        printf("L.data[%d]=%d\n",i, L.data[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        printf("Q.data[%d]=%d\n",i, Q.data[i]);
    }
    for (int i = 0; i < S.length; i++) {
        printf("S.data[%d]=%d\n",i, S.data[i]);
    }
    



    return 0;
}