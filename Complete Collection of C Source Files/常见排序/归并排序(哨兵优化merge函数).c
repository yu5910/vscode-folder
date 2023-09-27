#include <stdio.h>
#include <limits.h>//插入一个极限的数字

void merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1 + 1], R[n2 + 1];
    // 开始赋值,但最后一个元素单独赋值为最大值
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    L[n1] = INT_MAX; // 左数组的哨兵
    R[n2] = INT_MAX; // 右数组的哨兵

    int i = 0, j = 0;
    // 把两个子数组一步到位合并到arr[left,right]
    for (int k = left; k <= right; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
    // 经过上面这一波循环比较排序,两个数组都不会耗光,都会剩下一个INT_MAX
}