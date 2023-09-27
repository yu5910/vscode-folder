#include <stdio.h>
#include <stdlib.h>

// 链表节点的结构体定义
struct Node
{
    int data;
    struct Node *next;
};

// 创建新节点的函数
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// 正戏开始
void selectionSort(struct Node *head)
{
    struct Node *current = head; // 逐渐刷好学生(初始为NULL),它是坏学生的第一个(要被后面的最小值交换的)
    struct Node *minNode;

    while (current != NULL)
    {
        minNode = current;
        struct Node *innerCurrent = current->next; // 从坏学生的第一个(好学生最后一个的next)开始遍历

        while (innerCurrent != NULL)
        {
            if (innerCurrent->data < minNode->data)
            {
                minNode = innerCurrent;
            }
            innerCurrent = innerCurrent->next; // 向下一个移动,对应while
        }
        // 经过上面循环找到了最小值,并且被minNode索引
        // 开始交换
        int temp;
        temp = current->data;
        current->data = minNode->data;
        minNode->data = temp
    }
}