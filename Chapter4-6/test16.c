#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <test16.h>
#define MaxVertexNum 100 // 图中顶点数目的最大值
bool visited[MaxVertexNum]; // 访问标志数组

// 对图G进行广度优先遍历
void BFSTraverse(ALGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; // 初始化访问标志数组
    }
    initQueue(Q); // 初始化辅助队列
    for (int i = 0; i < G.vexnum; i++) { // 从0号开始遍历
        if (!visited[i]) {
            BFS(G, i); // 若是未访问过就进行BFS
        }
    }
}

// 广度优先遍历
bool BFS(ALGraph G, int v) {
    visit(v); // 访问初始顶点v
    visited[v] = true; // 对v做已访问标记
    Enqueue(Q, v); // 顶点v入队列
    while (!IsEmpty(Q)) {
        Dequeue(v); // 顶点v出队列
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(w); // 访问顶点w
                visited[w] = true; // 对w做已访问标记
                Enqueue(w); // 顶点w入队列
            }
        }
    }
    return true;
}

// 深度优先遍历
bool visited[MaxVertexNum]; // 访问标志数组
void DFSTraverse(ALGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; // 初始化访问标志数组
    }
    for (int i = 0; i < G.vexnum; i++) { // 从0号开始遍历
        if (!visited[i]) {
            DFS(G, i); // 若是未访问过就进行DFS
        }
    }
}
// 深度优先遍历 邻接表
void DFS(ALGraph G, int v) {
    visit(v); // 访问初始顶点v
    visited[v] = true; // 对v做已访问标记
    for (p = G.vertices[i].firstarc; p; p = p->nextarc) { // 对每个顶点循环调用DFS
        j = p->adjvex; // j为顶点i的邻接点
        if (!visited[j]) {
            DFS(G, j); // 对未访问的邻接顶点递归调用DFS
        }
    }
    return true;
}
// 深度优先遍历 邻接矩阵
void DFS(ALGraph G, int v) {
    visit(v); // 访问初始顶点v
    visited[v] = true; // 对v做已访问标记
    for (int j = 0; j < G.vexnum; j++) {
        if (visited[j] == false && G.arcnum[v][j] == 1) {
            DFS(G, j); // 对v的尚未访问的邻接顶点w递归调用DFS
        }
    }
}

// 求顶点u到其他顶点的最短路径
void BFS_MIN_Distance(ALGraph G, int u) {
    // d[i]表示从u到i结点的最短路径
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false; // 初始化访问标志数组
        path[i] = -1; // 初始化路径数组
        distance[i] = INFINITY; // 初始化距离数组
    }
    initQueue(Q); // 初始化辅助队列
    visit(u); // 访问初始顶点u
    visited[u] = true; // 对u做已访问标记
    distance[u] = 0; // 初始顶点到自身的距离为0
    Enqueue(Q, u); // 顶点u入队列
    while (!IsEmpty(Q)) {
        Dequeue(u); // 顶点v出队列
        for (w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w)) {
            if (!visited[w]) {
                visit(w); // 访问顶点w
                path[w] = u; // 记录路径
                distance[w] = distance[u] + 1; // 更新顶点w的距离
                visited[w] = true; // 对w做已访问标记
                Enqueue(w); // 顶点w入队列
            }
        }
    }
}