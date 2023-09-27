#include <stdio.h>
#include <stdlib.h> //本人故意制造了两个错误,看看能不能运行,能!

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = value; // 操,感觉这里会有变量冲突的风险
    node->next = NULL;
    return node;
}

typedef struct Stack
{
    Node *top;
    int size;
} Stack;

void init(Stack *s)
{
    s->top = NULL;
    s->size = 0;
}

void push(Stack *s, int data)
{
    Node *node = createNode(data);
    node->next = s->top;
    s->top = node;
    s->size++;
}

_Bool isEmpty(Stack *s)
{ // 操_Bool是什么鬼
    return s->top == NULL;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("栈是空的,弹什么弹!\n");
        return -1; // 操,什么时候用exit(-1)
    }
    Node *node = s->top;
    int data = node->data;
    s->top = s->top->next;
    free(node);
    s->size--;
    return data;
}

int getTop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data;
}

void destroyStack(Stack *s)
{
    while (s->top != NULL)
    {
        Node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->size = 0;
}

int main()
{
    // Stack*s=NULL;//先看看不知道要不要天上NULL,添上的话会不会不好改变了
    Stack *s = (Stack *)malloc(sizeof(Stack)); // 既然为s分配了内存就没必要赋值为NULL
    init(s);

    int capacity = 10;
    for (int i = 1; i <= capacity + 1; i++)
    {
        if ((*s).size >= capacity)
        { // 这里并没有用"指针->"模式
            printf("Stack is full.Cannot push nor elements.\n");
            break;
        }
        push(s, i);//巧用push构造栈
    }

    // 这里就不调用destroyStack函数释放内存了,就用pop一个一个弹走算了,嘿嘿弹奏的同时把他们都分行显示出来
    while (!isEmpty(s))
    {
        printf("%d\n", getTop(s));
        pop(s);
    }
}