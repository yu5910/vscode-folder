#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int value;
    struct ListNode *next;
} Node;

// 创造一个有内存有变量的节点
Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value; // 还不知道value可不可以作为变量
    node->next = NULL;
    return node;
}

// 用一个创建链表的函数
Node *createList(int (*arr)[], int size)
{
    if (size == 0)
    {
        return NULL;
    }
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = head;
    head->value = (*arr)[0];
    for (int i = 1; i <= size - 1; i++)
    {
        Node *node = createNode((*arr)[i]);
        tail->next = node;
        tail = node;
    }
    return head;
}
/*
Node*createList(int*values,in size){  //后来传入的参数是数组的名字和数组的长度
if(size==0){return NULL;}
Node *head=malloc();
head->value=values[0];//这一步很奇怪，从这一看出指向数组首元素的指针也是数组名
head->next=NULL;
}
*/

Node *findMiddleNode(Node *head)
{ // 这里的参数是创建的链表的首元素地址
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    int arr[] = {1, 3, 4, 5};
    int(*Arr)[] = &arr;
    int size = sizeof(arr) / sizeof(arr[1]);

    Node *head = createList(&arr, size);
    Node *middleNode = findMiddleNode(head);

    if (middleNode)
    {
        printf("链表的中间节点是：%d\n", middleNode->value);
    }
    else
    {
        printf("链表为空\n");
    }

    // 别忘了释放链表内存
    while (head)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}