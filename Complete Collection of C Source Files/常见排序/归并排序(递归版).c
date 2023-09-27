// 归并排序的空间复杂度主要由两个额外的数组 L 和 R 决定，这使得空间复杂度为O(n)。
#include <stdio.h>

void merge(int arr[], int l, m, r)
{ // lmr均是arr数组的一部分(三个索引)
    int i, j, k;
    int n1 = m - l + 1; // 前从l到m数组的长度
    int n2 = r - m;     // 从m到r数组的长度

    int L[n1], R[n2]; // 两个副本数组分别储存arr的前一部分和后一部分
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = j = k = 0; // 数组嘛,都是从0开始索引
    while (i < n1 && j < n2)
    {
        // 开始比较两个数组首元素
        if (L[i] <= R[j]) // A[i] <= A[j],这一行代码就保证了归并排序是稳定的，因为即使左边的子数组元素和右边的子数组元素是相同的元素，左边的数据也会先行进入新的大数组中，因此归并排序的稳定性是良好的
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // L和R两个数组终有一个会先耗尽

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        J++;
    }
    while (j < n1)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
} // 经过了一波操作,虽然什么都没有返回,但却把无序的arr数组完完全全变有序化了

// 开始递推
// 递推核心思路:mergesort(p,r)=merge( mergesort(p,q)  ,  mergesort(q+1,r) )
// 递归终止条件:当p>=r时,不再分解
void mergesort(int arr[], int l.int r)
{
    if (l < r)
    {
        int m = l + (r - 1) / 2; // 中间值

        // 然后对从l到m和从l+1到r分别排序

        // 假设排序好了,现在m的左右分别是两个有序数组
        Start merging two arrays
            merge(arr, l, m, r);
    }
}
#include <stdio.h>


void merge(int arr[],int l,m,r)
{ // lmr均是arr数组的一部分(三个索引)
    int i, j, k;
    int n1 = m - l + 1; // 前从l到m数组的长度
    int n2 = r - m;     // 从m到r数组的长度

    int L[n1], R[n2]; // 两个副本数组分别储存arr的前一部分和后一部分
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = j = k = 0; // 数组嘛,都是从0开始索引
    while (i < n1 && j < n2)
    {
        // 开始比较两个数组首元素
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
        k++;
    }
    // L和R两个数组终有一个会先耗尽

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        J++;
    }
    while (j < n1)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
} // 经过了一波操作,虽然什么都没有返回,但却把两个分别有序的数组给整体有序化了

// 开始递推
// 递推核心思路:mergesort(p,r)=merge( mergesort(p,q)  ,  mergesort(q+1,r) )
// 递归终止条件:当p>=r时,不再分解
void mergesort(int arr[], int l.int r)
{
    if (l < r)
    {
        int m = l + (r - 1) / 2; // 中间值

        // 然后对从l到m和从l+1到r分别排序
        mergesort(arr, 1, m);
        mergesort(arr, m + 1, r);
        // 假设排序好了,现在m的左右分别是两个有序数组
        Start merging two arrays
            merge(arr, l, m, r);
    }
} // 经过了一波操作,虽然什么都没有返回,但却把一个整体无序的数组给整体有序化了

int main()
{
    int arr[] = {}; //
    int arr_size = sizeof(arr) / sizeof(arr[0]);
}

