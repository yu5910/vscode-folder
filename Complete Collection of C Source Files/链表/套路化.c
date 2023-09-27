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
//仅仅交换两个指针对应节点的值
void swap(struct Node *current,struct Node *minNode){
    int temp;
    temp = current->data;
    current->data = minNode->data;
    minNode->data = temp
}
//同时交换连接关系
void swaps(struct Node *current, struct Node *minNode)
{
    // 假设有两个节点 current 和 minNode 需要交换
    struct Node *tempNext = current->next; // 保存 current 的下一个节点
    current->next = minNode->next;         // 更新 current 的下一个节点为 minNode 的下一个节点
    minNode->next = tempNext;              // 更新 minNode 的下一个节点为原来的 current 的下一个节点

    // 然后交换节点的数据值
    int tempData = current->data;
    current->data = minNode->data;
    minNode->data = tempData;
}