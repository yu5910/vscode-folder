//// 二分查找函数，参数为有序数组arr，数组长度len，目标元素target
// 返回值为目标元素在数组中的索引，如果不存在则返回-1
int binary_search(int arr[], int len, int target)
{
    // 定义左右边界指针
    int left = 0;
    int right = len - 1;
    // 循环条件为左右边界不相交
    while (left <= right)
    {
        // 计算中间元素的索引
        int mid = left + ((right - left) >> 1);
        // 如果中间元素等于或者大于目标元素，判断是否是第一个
        if (arr[mid] >= target)
        {
            // 如果是第一个或者前一个元素小于目标元素，返回索引
            if (mid == 0 || arr[mid - 1] < target)
            {
                return mid;
            }
            // 否则舍弃右半部分数组，将右边界移动到中间元素的左边
            else
            {
                right = mid - 1;
            }
        }
        // 如果中间元素小于目标元素，舍弃左半部分数组，将左边界移动到中间元素的右边
        else
        {
            left = mid + 1;
        }
    }
    // 如果循环结束还没有找到目标元素，返回-1
    return -1;
}



//下面这种思路狠就狠在，哪怕中间值是所要找的值，它也要继续向左逼，直到在左半区全是不符合要求的元素，这时候左指针稍微向右移动一位就是所求的第一个满足条件的元素

// 二分查找函数，参数为有序数组arr，数组长度len，目标元素target
// 返回值为目标元素在数组中的索引，如果不存在则返回-1
int binary_search(int arr[], int len, int target)
{
    // 定义左右边界指针
    int left = 0;
    int right = len - 1;
    // 循环条件为左右边界不相交
    while (left <= right)
    {
        // 计算中间元素的索引
        int mid = left + ((right - left) >> 1);
        // 如果中间元素等于目标元素，直接返回索引
        if (arr[mid] == target)
        {
            return mid;
        }
        // 如果中间元素小于目标元素，舍弃左半部分数组，将左边界移动到中间元素的右边
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        // 如果中间元素大于目标元素，舍弃右半部分数组，将右边界移动到中间元素的左边
        else
        {
            right = mid - 1;
        }
    }
    // 如果循环结束后，左边界没有越界，并且左边界对应的元素大于或等于目标元素，返回索引
    if (left < len && arr[left] >= target)
    {
        return left;
    }
    // 否则返回-1
    else
    {
        return -1;
    }
}
