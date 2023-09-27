//和数组整体差不多,只不过涉及到的取余操作更妙
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

// 检查队列是否为空,是否为满
int isEmpty(Queue *q)
{
    return (q->front == -1);
}
int isFull(Queue *q)
{
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// 入队操作
void enqueue(Queue *q, int item)
{
    if (isFull(q))
    {
        printf("队列满啦,下次再来哦\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
        // 赋值,return
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE; // 此处的取余是真秒啊
    }
    // 前面已经把末尾移动了,该赋值了
    q->data[q->rear] = item;
    return;
}

// 入队操作
int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("空咯,还出什么啊\n");
        return -1;
    }
    item = q->data[q->front];
    if (q->front == q->rear)
    {
        // 此时队列中仅仅有一个元素
        initQueue(q); // 哈哈初始化就好了
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return item;
}

int main()
{
    Queue q; // 懒得分批额内存了
    initQueue(&q);

    enqueue(&q, 2);
    printf("出队元素:%d\n", dequeue(&q));
    enqueue(&q, 1);
    enqueue(&q, 3);
    printf("出队元素:%d\n", dequeue(&q));

    return 0;
}