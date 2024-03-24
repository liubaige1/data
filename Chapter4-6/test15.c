#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int UFSets[MAX]; // Define the array to store the set
void Initialize(int n) {
    for (int i = 0; i < n; i++)
        UFSets[i] = -1;
}

// // Find the root of the tree
// int Find(int x, int S[]) {
//     while (S[x] >= 0) {
//         x = S[x]; // Find the root
//     }
//     return x;
// }

// 查优化，先找到根节点，然后再压缩路径
int find (int x, int S[]) {
    int root = x;
    while (S[root] >= 0) { // Find the root
        root = S[root];
    }
    while (x != root) { // 压缩路径
        int parent = S[x]; // Store the parent
        S[x] = root; // Update the parent
        x = parent; // Move to the parent
    }
    return root;
}

// // Union two sets
// void Union(int S[], int Root1, int Root2) {
//     if (Root1 != Root2) {
//         S[Root2] = Root1; // Root2 is merged to Root1
//     }
// }

// 并操作优化，小树并到大树上
void Union(int S[], int Root1, int Root2) {
    if (S[Root2] == S[Root1]) {
        return;
    } else if (S[Root2] < S[Root1]) { // Root2 is larger
        S[Root2] += S[Root1]; // Update the size of the set
        S[Root1] = Root2; // Root1 is merged to Root2
    } else { // Root1 is larger
        S[Root1] += S[Root2]; // Update the size of the set
        S[Root2] = Root1; // Root2 is merged to Root1
    }
}