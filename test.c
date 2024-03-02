#include <stdio.h>
int main(){
    // int sum = 0;
    // int n=16;
    // for (int i=1;i<n;i*=2){
    //     for (int j=0;j<i;j++){
    //         sum++;
    //         printf("sum=%d",sum);
    //     }
    // }
    int x= 0;
    int n=16;
    while (n>=(x+1)*(x+1)){
        x+=1;
    }
        printf("x=%d",x);
    return 0;
}