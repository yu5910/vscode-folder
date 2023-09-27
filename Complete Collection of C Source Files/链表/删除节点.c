#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *createNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 因为要删除某一个节点,而我们需多次用到头节点,为了防止删除了它,就创建一个永不会被删除的虚拟头节点
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = (ListNode *)malloc(sizeof(ListNode));
    dummy->next = head;
    // 我要找到要删除节点的位置,但是倒数,所以需要便利获得总长度,再次便利,找到要删的前一个位置
    int length = 0;
    ListNode *current = head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    int targetPos = length - n + 1;
    current = head;
    for (int i = 0; i < targetPos - 2; i++)
    {
        current = current->next;
    }
    ListNode *temp = current->next;
    current->next = current->next->next;
    free(temp);

    // 返回新头
    ListNode *newHead = (dummy->next);
    free(dummy);
    return newHead;
}
int main()
{
    // 创建一个长度为10的链表
    ListNode *head = NULL;

    for (int i = 1; i <= 10; i++)
    {
        ListNode *node = createNode(i);
        if (i > 1)
        {
            node->next = head;
        }
        head = node;
    }

    ListNode *newHead = removeNthFromEnd(head, 2);
    ListNode *current = newHead;
    for (int i = 1; i <= 9; i++)
    {

        printf("%d\n", current->val);

        current = current->next;
    }
    return 0;
}