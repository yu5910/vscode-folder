#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100 // 栈是无限长，但数组是有限的

typedef struct Stack
{
    char items[MAX_SIZE]; // 不是很理解，怎么必须要填值,而且是最大值，传入的数组可不一定这莫大
    int top;
} Stack;

// 初始化栈
void init(Stack *stack)
{
    stack->top = -1;
    memset(stack->items, 0, sizeof(stack->items)); // 使用 memset 函数将数组元素设置为 0
                                                   // 不能再结构体内部初始化成员的值，只能另设初始化函数
}

// 检查是否为空，是否满了
bool isEmpty(Stack *stack) { return stack->top == -1; }
bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1; // 数组型栈真是不占优势
}

// 出栈
char pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        char poppedItem = stack->items[stack->top];
        stack->top--;
        return poppedItem; // 你这出栈也没有真正意义上删除啊,没有链表严谨
                           // 答案把这一步直接放入中括号里，也可行？
    }
    else
    {
        return '\0'; // 操，转义也就算了，怎么还单引号
    }
}

// 入栈
bool push(Stack *stack, char item)
{
    if (!isFull(stack))
    {
        stack->items[++stack->top] = item; // 此时栈顶以上的值还是我初始化的那些p
    return true;
    }
    else
    {
        printf("Stack is full. Cannot push %c\n", item);
        return false;
    }
}

// 检查是否匹配
bool areBracketsBalanced(const char *expression)
{
    Stack stack; // 直接创建一个结构体好处是不用再分配内存
    init(&stack);

    for (int i = 0; expression[i] != '\0';
         i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(&stack, expression[i]);
        }
        else
        { // 此处否则的时候是否会自动对其对应的如果取反
            if (isEmpty(&stack))
            {
                return false;           // 直接结束整个函数
            }                           // 此处的否则似乎可有可无，不过有的时候报了错
            char topchar = pop(&stack); // 不管匹配不匹配都要把它给弄出来的
            if (!(expression[i] == topchar))
            {
                return false; // 括号不匹配
            }
        }
    } // 操先这样吧，
      // 真是操了
    return true;
}
int main()
{
    const char *expression = "{[()]}";
    if (areBracketsBalanced(expression))
    {
        printf("% s is balanced\n", expression);
    }
    else
    {
        printf("%s is not balanced\n", expression);
    }

    return 0;
}
