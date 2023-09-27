#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// 判断栈是否已满
bool isFull()
{
    return top == MAX_SIZE - 1;
}
// 判断栈是否为空
bool isEmpty()
{
    return top == -1; // 运用了判断符==来返回布尔值
}

// 入栈
void push(int value)
{
    if (isFull())
    {
        printf("栈已满，无法入栈、\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}
// 出栈,并返回出去的元素
int pop()
{
    if (isEmpty())
    {
        printf("此栈本来就没有元素，谈何出栈\n");
        return -1; // 出栈失败
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);

    printf("出栈：%d\n", pop());

    return 0;
}
