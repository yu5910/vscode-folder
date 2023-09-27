// 插入排序本质就是扑克牌的插入,将未排序的第一个元素插入到已排序的元素中
// 而且数组实现的关键是如何把已排序的部分在插入之前全部向右移动一位,而且不会对整体产生影响

#include <stdio.h>
void insertSort(int arr[], int n)
{ // 数组元素的个数
    int i, key, j;
    // i的作用是遍历未排序元素,并记录未排序的开头存到key中,它的初始状态是第二个元素,因为假设第一个元素已经排好了
    // j的作用是遍历已排序元素,并记录已排序元素的结尾,从后往前依次与key比较
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1; // 已排序元素的末尾

        // 开始将比key大的元素向右移动
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // 到这一步,j不变,变得是arr[j]得值
            j--;                 //
        }
        arr[j + 1] = key;
    }
}