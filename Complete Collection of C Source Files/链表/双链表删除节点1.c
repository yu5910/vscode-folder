// 因为关键是让指针到达被删除元素的前一个元素,所以之前才会通过种种遍历进行定量计算,而接下来的快慢双指针则是专注于定位,而不专注于索引

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} Node;

Node *createNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

Node *removeNthFromEnd(Node *head, int n)
{
    // 先建立哨兵
    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->next = head;

    Node *fast = dummy;
    Node *slow = dummy;

    for (int i = 0; i <= n + 1; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    Node *newHead = dummy->next;
    free(dummy);
    return newHead;
}

int main()
{
    // 创建一个长度为10的链表
    Node *head = NULL;

    for (int i = 1; i <= 10; i++)
    {
        Node *node = createNode(i);
        if (i > 1)
        {
            node->next = head;
        }
        head = node;
    }

    Node *newHead = removeNthFromEnd(head, 2);
    Node *current = newHead;
    for (int i = 1; i <= 9; i++)
    {

        printf("%d\n", current->val);

        current = current->next;
    }
    return 0;
}