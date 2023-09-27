// 在写代码之前.我先抒情一番,用指针控制的链表就是比索引控制的数组舒服啊
#include <stdio.h>
#include <stdlib.h>

// 定义链表(非队列)的节点结构
typedef struct Node
{ // 节点本质还是结构体,不能初学*节点指针的形式,因为结构体是没有值的
    int data;
    struct Node *next;
} Node;
// 创建节点的操作
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // 先分配内存
    // 别忘检查内存是否分配成功
    if (!newNode)
    {
        printf("分配内存失败分配内存失败\n");
    }
    newNode->data = data; // 再赋值
    newNode->next = NULL;
}

// 定义队列
typedef struct Queue
{ // 经典忘记typedef
    Node *front;
    Node *rear;
} Queue; // 它的本质也是一群指针组成的结构体
// 初始化队列
void initQueue(Queue *q)
{
    q->front = q->rear = NULL; // 真香啊,不用索引的感觉,直接指针为空,不过问题是要不要为它俩分配内存啊
} // 虽然指针为空,但后面创建节点的时候会赋予空间,到时候就把那个节点给这俩兄弟

// 查空查满,查满个毛啊,链表就不会满
int isEmpty(Queue *q)
{
    return (q->front == NULL);
}

// 入队!
void enqueue(Queue *q, int data)
{
    Node *node = createNode(data);

    if (isEmpty(q))
    {
        q->front = q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
}
// 头部出队
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("出毛线!\n");
        return -1;
    }
    int removedata = q->front->data;
    Node *temp = q->front;
    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next; // 万一只有一个元素呢
    }

    free(temp);
    return removedata;
}

// 获取头部元素,(懒得写了,就是开头检验一下是否为空就好了)
int getfront(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return -1;
    }
    return q->front->data;
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("队列头部元素:%d\n", getfront(&q));
    printf("出队给爷!:%d\n", dequeue(&q));
    printf("队列头部是甚!:%d\n", getfront(&q));

    return 0;
}