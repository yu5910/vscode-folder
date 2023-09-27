#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    // 老规矩,i确定已排序(未排序的第一个),j追踪未排序并遍历出最小的那个

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i; // 假设第一个元素就是最小的
        for (j = i + 1; j < n; j++)
        {
            // 找到比这个假设的最小值还小的索引就更新索引,就这样,不断更新,找到最小的
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // 把刚刚找到的未排序区的最小值与未排序区的第一个交换
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}