#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct Node
{
    int data;
    struct Node *next;
};

// 创建新节点
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
// 在链表尾部追加节点
// 在创建新节点的时候，可以使用一个辅助函数appendNode(struct Node** head, int data)，用于在链表的尾部添加一个新节点。这样可以避免每次都手动修改指针域，也可以简化代码的可读性。
void appendNode(struct Node *head, int data)
{
    struct Node *node = newNode(data);
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = node;
    }
}
// 反转链表
struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev; // 实现翻转
        prev = current;
        current = next;
    }

    return prev;
}

// 打印链表
void printList(struct Node *head)
{ // 尽管 head 指针已经在 main 函数中声明了，但函数声明中仍然需要包含 struct Node* ，以便明确指定函数的返回类型。这有助于其他开发人员更容易理解代码，以及在后续的代码维护和扩展中更加方便。
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data); // 加一个空格更优雅
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    // 创建链表并插入节点
    /*struct Node *head = newNode(1); // 需要注意的是，在这段代码中，虽然head是main函数中的局部变量，但通过将head作为参数传递给其他函数，可以在其他函数中访问和修改head指针所指向的链表。这是因为通过参数传递，可以将局部变量的值传递给其他函数，使得其他函数可以操作该局部变量所指向的数据。
     head->next = newNode(2);
     head->next->next = newNode(3);
     head->next->next->next = newNode(4);*/

    struct Node *head = NULL; // 可以先让头为空，因为我设置了，如果为空，他会自动变成头部
    for (int i = 0; i <= 2; i++)
    {
        appendNode(head, i);
    }

    printf("原始链表: ");
    printList(head);

    // 反转链表
    head = reverseList(head);

    printf("反转后的链表: ");
    printList(head);

    return 0;
}


