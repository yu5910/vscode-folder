#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{ // 又忘了typedef
    int data;
    struct Node *next;
} Node;

// 交换两个指针的成员的值，但两个指针的关系还是不变
void swapNodes(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// 开始了
Node *bubbleSort(Node *head)
{
    int swapped; //
    Node *currentnode;
    Node *rhead = NULL; // 定义一个右部头节点（已冒泡到最右部的节点）,第一次冒泡的时候右头部确实为空

    if (head == NULL)
    {
        return NULL;
    }

    do
    {
        swapped = 0;        // 将每一轮的交换次数都初始化为0
        currentnode = head; // 这个是实际的头部，从实际的头部开始冒泡，直到右头部,这个头部指针是早已定好的,指向首元素,只不过再怎么改变改变的都是头部指针所指向变量(变量地址)的值,并不会改变其所指向的变量.比如原来指向a变量,不可能让它变成指向b变量.只能改变a变量的值.
        while (currentnode->next != rhead)
        {
            if (currentnode->data > currentnode->next->data)
            {
                swapNodes(currentnode, currentnode->next);
                swapped = 1; // 表示在这一轮中存在交换
            }
            currentnode = currentnode->next;
        }
        rhead = currentnode;
    } while (swapped); // 直到需要冒泡的次数变成0时，便是最后一轮的冒泡
    return head;
}

// 在链表的头部从左往右插入新节点,但这种做法，使得头不再是头
/*void push (Node*head,int data){
  Node*new_node=(Node*)malloc(sizeof(Node));
  new_node->data=data;
  head->next=new_node;
  head=head->next;*/
/*这里的head只是一个副本,并不会影响已经定义好为NULL的head
void push(Node*head,int data){
  Node*node=(Node*)malloc(sizeof(Node));
  node->data=data;
  node->next=head;
  head=node;
  //这种做法还有一个好处，就是就算把头节点初始化为NULL，他也会被自动排到末尾
  return;
}*/
void push(Node **head_def, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = *head_def;
    *head_def = node;
    return;
}

void printlist(Node *node)
{
    while (node)
    { // 指针存在就是指针不为空,无需*指针
        printf("%d\n", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    push(&head, 64);
    push(&head, 34);
    push(&head, 54);
    push(&head, 44);
    push(&head, 14);

    bubbleSort(head);
    printlist(head);
    return 0;
}