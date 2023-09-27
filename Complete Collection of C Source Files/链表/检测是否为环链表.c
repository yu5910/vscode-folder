#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

bool hasCycle(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next; // 操,易错点,涉及到了next->next,所以next也不能为空

        if (slow == fast)
        {
            return true; // 指针相遇,结束循环
        }
    }
    return false; // 当然,也不一定一直循环下去
}
// 先写size函数,因为要在creatCycleLinkedList函数调用size
int size(int (*ptr)[5])
{
    int length = 0;
    int *p;
    p = (int *)ptr;
    while (*p)
    {
        // 如何把一个指向数组的指针转化成一个指向数组首元素的指针
        length++;
        p++;
    }
    return length;
}

Node *creatCycleLinkedList(int (*ptr)[5])
{
    Node *head = NULL;
    Node *tail = NULL;
    int len = size(ptr); // 假设✌已经获取到了数组长度了

    for (int i = 0; i < len; i++)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = (*ptr)[i];
        node->next = head;
        head = node;
        // 如何才能把tail节点,接到第一个循环,而不会进入其他循环
        if (tail == NULL)
        {
            tail = node;
        }
    }
    if (tail != NULL)
    {
        tail->next = head; // 首尾相连,创环结束!
    }
    return head; // 操,忘了返回了
}

// 操,怎么根据数组数组指针获取数组长度啊
// 你要是创建数组的时候当然可以立刻获得,比如:
//  int arr[5]={};
//  size=sizeof(arr)/sizeof(arr[0]);
// 但现在创造的数组远在天边啊(main里)
// 真是操了

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int(*ptr)[5] = &arr;
    Node *head = creatCycleLinkedList(ptr);
    bool result = hasCycle(head); // 指向循环链表的本质还是指向一个Node,别怕

    if (result)
    {
        printf("链表中存在环.\n");
    }
    else
    {
        printf("链表中不存在环.\n");
    }

    // 释放循环链表的内存(因为动态分配了内存,而列表是系统自动分配的,会自动释放)
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current); //
        current = next;
    }
}