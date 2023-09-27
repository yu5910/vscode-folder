#include <stdio.h>

// 交换两个元素的值，（用指针控制变量）因为你想要在函数内修改全局的数组额，而不是副本数组，所以要用指针，
// 而且整个快排和归并的思想都是直接修改原数组
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 开始从基准元素分割某数组的一个子数组，并返回基准元素的索引
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //
    int i = low - 1;       // 刚开始在最低位low的前一位，这样的化，每当j查到一个小于基准的数，i就右移一位，并把那个小数，与i索引的数交换。
    // i每次向前移动的时候，都会移动到大树上，因为它已经被j遍历时检索过l
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // 最后，i的下一位就是分界点
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 快速排序函数，：思想：对基准点左右的数组分别排序
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    { // 这是后面一直递归的终止条件
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1); // 终于明白原来为什么要从数组中截取了。还是截取好一些
        quickSort(arr, pivot, high);
    }
}

int main()
{
    int arr[] = {1, 8, 7, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    quickSort(arr, 0, n - 1);
    printf("\n排序后的函数：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}