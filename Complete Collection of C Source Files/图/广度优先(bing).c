#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// 定义图的结点结构体
typedef struct node
{
    int data;          // 结点的数据域
    struct node *next; // 结点的指针域，指向下一个邻接结点
} Node;

// 定义图的邻接链表结构体
typedef struct graph
{
    int n;          // 图的顶点数
    Node **adjList; // 图的邻接链表数组，每个元素是一个指向结点的指针
} Graph;

// 定义队列的结点结构体
typedef struct qnode
{
    int data;           // 队列结点的数据域，存储图的顶点编号
    struct qnode *next; // 队列结点的指针域，指向下一个队列结点
} QNode;

// 定义队列的结构体
typedef struct queue
{
    QNode *front; // 队列的头指针，指向队首结点
    QNode *rear;  // 队列的尾指针，指向队尾结点
} Queue;

// 创建一个空队列，返回队列的指针
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue)); // 分配内存空间
    q->front = NULL;                           // 初始化头指针为空
    q->rear = NULL;                            // 初始化尾指针为空
    return q;                                  // 返回队列的指针
}

// 判断队列是否为空，返回布尔值
bool isEmpty(Queue *q)
{
    return q->front == NULL; // 如果头指针为空，说明队列为空
}

// 入队操作，将一个顶点编号加入队列尾部，无返回值
void enqueue(Queue *q, int v)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode)); // 创建一个新的队列结点
    newNode->data = v;                               // 将顶点编号赋值给数据域
    newNode->next = NULL;                            // 将指针域设为NULL
    if (isEmpty(q))
    { // 如果队列为空，那么新结点既是队首也是队尾
        q->front = newNode;
        q->rear = newNode;
    }
    else
    { // 如果队列不为空，那么将新结点插入到队尾，并更新尾指针
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出队操作，将队首的顶点编号返回，并删除队首结点
int dequeue(Queue *q)
{
    if (isEmpty(q))
    { // 如果队列为空，返回-1表示错误
        return -1;
    }
    QNode *temp = q->front;    // 用一个临时变量保存队首结点的指针
    int v = temp->data;        // 用一个变量保存队首结点的数据域，即顶点编号
    q->front = q->front->next; // 将头指针后移一位，指向下一个队列结点
    if (q->front == NULL)
    { // 如果出队后队列为空，那么尾指针也要设为NULL
        q->rear = NULL;
    }
    free(temp); // 释放原来的队首结点的内存空间
    return v;   // 返回顶点编号
}

// 图的广度优先搜索算法，参数为图的指针和起始顶点编号，无返回值
void BFS(Graph *g, int s)
{
    bool *visited = (bool *)malloc(g->n * sizeof(bool)); // 创建一个布尔数组，用来记录每个顶点是否被访问过
    for (int i = 0; i < g->n; i++)
    { // 初始化所有顶点都未被访问过
        visited[i] = false;
    }
    Queue *q = createQueue(); // 创建一个空队列，用来存储待访问的顶点编号
    visited[s] = true;        // 将起始顶点标记为已访问
    enqueue(q, s);            // 将起始顶点编号入队
    while (!isEmpty(q))
    {                            // 当队列不为空时，循环执行以下操作
        int v = dequeue(q);      // 出队一个顶点编号，并赋值给变量v
        printf("%d ", v);        // 打印该顶点编号，表示访问该顶点
        Node *p = g->adjList[v]; // 用一个指针p指向该顶点的邻接链表的第一个结点
        while (p != NULL)
        {                    // 当p不为空时，循环执行以下操作
            int w = p->data; // 取出p指向的结点的数据域，即邻接顶点的编号，并赋值给变量w
            if (!visited[w])
            {                      // 如果该邻接顶点未被访问过，那么执行以下操作
                visited[w] = true; // 将该邻接顶点标记为已访问
                enqueue(q, w);     // 将该邻接顶点编号入队
            }
            p = p->next; // 将指针p后移一位，指向下一个邻接结点
        }
    }
    free(visited); // 释放布尔数组的内存空间
    free(q);       // 释放队列的内存空间
}
// 创建一个图，返回图的指针
Graph *createGraph(int n)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));        // 分配内存空间
    g->n = n;                                         // 将顶点数赋值给图的结构体
    g->adjList = (Node **)malloc(n * sizeof(Node *)); // 分配内存空间，创建邻接链表数组
    for (int i = 0; i < n; i++)
    { // 初始化每个邻接链表为空
        g->adjList[i] = NULL;
    }
    return g; // 返回图的指针
}

// 向图中添加一条无向边，参数为图的指针和两个顶点编号，无返回值
void addEdge(Graph *g, int u, int v)
{
    Node *newNode1 = (Node *)malloc(sizeof(Node)); // 创建一个新的结点，用来表示从u到v的边
    newNode1->data = v;                            // 将v赋值给结点的数据域
    newNode1->next = g->adjList[u];                // 将结点的指针域指向u的邻接链表的第一个结点
    g->adjList[u] = newNode1;                      // 将新结点插入到u的邻接链表的头部

    Node *newNode2 = (Node *)malloc(sizeof(Node)); // 创建一个新的结点，用来表示从v到u的边
    newNode2->data = u;                            // 将u赋值给结点的数据域
    newNode2->next = g->adjList[v];                // 将结点的指针域指向v的邻接链表的第一个结点
    g->adjList[v] = newNode2;                      // 将新结点插入到v的邻接链表的头部
}

// main函数，用来测试图的广度优先搜索算法
int main()
{
    Graph *g = createGraph(6); // 创建一个有6个顶点的图
    addEdge(g, 0, 1);          // 添加边0-1
    addEdge(g, 0, 2);          // 添加边0-2
    addEdge(g, 1, 3);          // 添加边1-3
    addEdge(g, 2, 3);          // 添加边2-3
    addEdge(g, 3, 4);          // 添加边3-4
    addEdge(g, 4, 5);          // 添加边4-5

    printf("从顶点0开始进行广度优先搜索，访问顺序为：\n");
    BFS(g, 0); // 从顶点0开始进行广度优先搜索，打印访问顺序

    free(g); // 释放图的内存空间

    return 0; // 返回0表示程序正常结束
}
