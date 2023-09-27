// 链表结点定义
struct ListNode
{
    int val;                                // 结点的值
    ListNode *next;                         // 指向下一个结点的指针
    ListNode(int x) : val(x), next(NULL) {} // 构造函数
};

// 链表实现二分查找函数，参数为头结点head和目标值target
// 返回值为目标值在链表中的索引，如果不存在则返回-1
int binary_search(ListNode *head, int target)
{
    // 定义快慢指针
    ListNode *fast = head;
    ListNode *slow = head;
    // 定义左右边界索引
    int left = 0;
    int right = 0;
    // 计算链表长度
    while (fast != NULL)
    {
        fast = fast->next;
        right++;
    }
    // 循环条件为左右边界不相交
    while (left <= right)
    {
        // 计算中间结点的索引
        int mid = (left + right) / 2;
        // 移动慢指针到中间结点
        for (int i = left; i < mid; i++)
        {
            slow = slow->next;
        }
        // 如果中间结点的值等于目标值，返回索引
        if (slow->val == target)
        {
            return mid;
        }
        // 如果中间结点的值小于目标值，舍弃左半部分链表，将左边界移动到中间结点的右边
        else if (slow->val < target)
        {
            left = mid + 1;
            slow = slow->next;
        }
        // 如果中间结点的值大于目标值，舍弃右半部分链表，将右边界移动到中间结点的左边
        else
        {
            right = mid - 1;
            // 将慢指针重置为头结点，重新遍历左半部分链表
            slow = head;
        }
    }
    // 如果循环结束还没有找到目标值，返回-1
    return -1;
}
