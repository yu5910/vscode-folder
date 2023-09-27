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

    for (int i = 0; expression[i] != '\0'; i++)
    {
        switch (expression[i])
        {
        case '(':
        case '[':
        case '{':
            push(&stack, expression[i]);
            break; // 操，break不是直接跳出整个循环了吗

        case ')':
            if (isEmpty(&stack) || pop(&stack) != '(')
                return false; //因为只有一行输出语句，所以可以省流大括号
            break;
        case ']':
            if (isEmpty(&stack) || pop(&stack) != '[')
                return false;
            break;
        case '}':
            if (isEmpty(&stack) || pop(&stack) != '{')
                return false;
            break;
        }
    }
    return isEmpty(&stack);
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
