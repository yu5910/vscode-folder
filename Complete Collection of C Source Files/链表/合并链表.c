#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    static ListNode dummy;
    ListNode *current = &dummy;

    while (l1 && l2)
    {
        current->next = (l1->val > l2->val) ? l2 : l1;
        (l1->val < l2->val) ? (l1 = l1->next) : (l2 = l2->next);
        current = current->next;
    }
    current->next = l1 ? l1 : l2;

    return dummy.next;
}

ListNode *creatNode(int val)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode)
    {
        newNode->val = val;
        newNode->next = NULL;
    }
    else
    {
        return NULL;
    }

    return newNode;
}

void freeList(ListNode *current)
{
    while (current)
    {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}
int main()
{
    ListNode *l1 = creatNode(1);
    l1->next = creatNode(2);
    l1->next->next = creatNode(4);

    ListNode *l2 = creatNode(3);

    ListNode *mergedList = mergeTwoLists(l1, l2);
    while (mergedList != NULL)
    {
        printf("%d\n", mergedList->val);
        mergedList = mergedList->next;
    }
    freeList(mergedList);

    return 0;
}
