#include <stdio.h>
#define MaxVertexNum 100 // 邻接表的最大顶点数
#define INFINITY 65535 // 定义无穷大
typedef char VertexType; // 顶点的数据类型
typedef int EdgeType; // 边的权值类型

// 邻接矩阵
typedef struct {
    VertexType vexs[MaxVertexNum]; // 顶点
    EdgeType edges[MaxVertexNum][MaxVertexNum]; // 边的权值
    int vexnum, arcnum; // 图的当前顶点数和边数
} MGraph;

// 边表节点
typedef struct ArcNode {
    int adjvex; // 邻接点域，存储该顶点对应的下标
    struct ArcNode* nextarc; // 指向下一个邻接点的指针
    EdgeType weight; // 边的权值
} ArcNode;

// 顶点表结点
typedef struct VNode {
    VertexType data; // 顶点信息
    ArcNode* first; // 指向第一个邻接点
} VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices; // 邻接表
    int vexnum, arcnum; // 图的顶点数和边数
} ALGraph;