//不管怎么说线性有界数组还是比较严格的,环状应该好一些
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef struct
{
    int data[MAX_SIZE]; // 以数组的形式储存队列的数据,数组有容量限制,操,data不如dates直观
    int front;
    int rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1; // 创建队列的同时把他的首尾元素给初始化
    return q;
}

int isEmpty(Queue *q)
{
    return q->front == q->rear; // 有点离谱哈哈,预计返回的布尔值会被自动转化为int哈哈
}
_Bool isFull(Queue *q)
{
    // return (q->rear+1)%MAX_SIZE==q->front;//不得不说,新必应这里写的代码质量真高
    return (q->rear == MAX_SIZE - 1); // 这个队列是否已满并不是广义上的满,而是无法进入
}

// 开始入队
void enqueue(Queue *q, int data)
{ // 一个是要入哪个队,一个是什么数据要入队
    if (isFull(q))
    {
        printf("队列(结尾)已满,无法插入元素\n");
        return; // void函数居然可以这末搞
    }
    if (q->front == q->rear && q->front == -1)
    {
        q->front++;
        q->rear++;
        q->data[0] = data;
    }
    else
    {
        q->data[++q->rear] = data; // 这个设计到++的前后关系了,一会再看
        return;
    }
}
// 出队出队!弹出的是头背部元素
int dequeue(Queue *q)
{
    int removedata;
    if (isEmpty(q))
    {
        printf("队列是空的,你出去个毛啊\n");
        return -1;
    }
    else if (q->front == q->rear)
    {
        removedata = q->data[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        removedata = q->data[q->front];
        q->front++;
    }
    return removedata;
}

// 但是如果你仅仅是想获取头部元素,而不是弹出,那就考虑的情况少了一步
int getfront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("空了!空了!\n");
        return -1; // 用-1表示运行失败(哈哈,实际上还是运行成功的,毕竟还是能够返回-1这个值的,而不是直接程序爆炸什么的)
    }
    return q->data[q->front];
}

// 奶奶的,终于搞完了,数组的限制真多,不过还是很符合生活场景的,不过感觉循环数组的效率应该会爆炸!,循环链表可能就差点意思
int main()
{
    // Queue q;//不用指针的原因是还需要为它分配内存,虽然但是还是有点麻烦
    // 我忘了我已经设计了一个函数了
    Queue *q = createQueue(); // 这个函数里已经有了分配内存的操作了

    enqueue(q, 10);
    enqueue(q, 20);

    printf("队列头部元素:%d\n", getfront(q));
    printf("出队列:%d\n", dequeue(q));
    printf("出对后的头部元素:%d\n", getfront(q));
}