#include <stdio.h>

// int func1(int x) {
//     if (x == 0 || x == 1) {
//         return 1;
//     } else {
//         return x * func1(x - 1);
//     }
// }

int func1(int a) {
    if (a == 0) {
        return 1;
    } else if (a == 1) {
        return 1;
    } else {
        return func1(a - 1) + func1(a - 2);
    }
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("func(%d)=%d\n", x, func1(x));
    return 0;
}