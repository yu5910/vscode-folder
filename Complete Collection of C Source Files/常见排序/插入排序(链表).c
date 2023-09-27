#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct Node
{
    int data;
    struct Node *next;
};

// 大戏开始
void insertSort(struct Node **head_ref)
{
    struct Node *sorted = NULL;       // 已排序得头节点,从前往后,头不变,创建一个current_sorted变量来移动
    struct Node *current = *head_ref; // 未排序的当前节点,向右移动,初始化为链表的头节点

    while (current)
    {
        // 要处理current这个节点了,先把与它有关联的下一个节点保存下来
        struct Node *next = current->next;

        if (sorted->data >= current->data)
        {
            // 如果已排序的头比当前节点大,那就好说,直接让当前节点成为新头
            current->next = sorted;
            sorted = current;
        }
        else
        {
            // 哪有这末好的事,开始遍历已排序节点把,看看它适合插在谁的后面
            struct Node *current_sorted = sorted;

            while (current_sorted->data < current->data)
            {
                current_sorted = current_sorted->next;
            }
            // 找到位置了,开始插入(链表比较简单,就是中间一断的事)
            current->next = current_sorted->next;
            current_sorted->next = current;
        }
        current = next; // 在全局变量下可以通过改变指向的地址来改变指向的变量
    }
    *head_ref = sorted; // 可以用二级指针来更新头指针
}