//此代码有bug,懒得修了
// 难点：给你一个数，你说它是几位数；
// 给你一个数，你给我把他的十位的数据给单独取出来
// 核心：个位，十位，百位分别满足大小关系，自然而然整体就满足
#include <stdio.h>
// 获取数字指定位的数据
int getdigit(int num, int place)
{
    for (int i = 0; i < place; i++)
    {
        num /= 10; // 加入要获取十位的数，那这个循环就会进行1次。个位循环0次
        // place为1时，则是取十位
    }
    return num % 10;
}
// 获取某数组（最大数据）的最大位是几位  123返回3
int getmaxdigit(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int digit = 0;
    while (max > 0)
    {
        max /= 10;
        digit++;
    }
    return digit;
}

// 基数排序函数，我准备从高位开始
void radixsort(int arr[], int n)
{
    if (n <= 1)
        return;
    // 找最大位数
    int maxdigit = getmaxdigit(arr, n);

    // 对每一欸数字进行计数排序，从高位开始
    for (int place = maxdigit - 1; place >= 0; place--)
    {
        // 开始针对高维进行计数排序
        int c[10] = {0}; // 申请一个计数数组，并初始化为0
        for (int i = 0; i < n; ++i)
        {
            int digit = getdigit(ar[i], place); // 开始取特定数据来填桶了
            c[digit]++;
        }
        对桶依次累加
        for (int i = 0; i < n; ++i)
        {
            c[i] += c[i - 1];
        }
    }
} // 难点：给你一个数，你说它是几位数；
// 给你一个数，你给我把他的十位的数据给单独取出来
// 核心：个位，十位，百位分别满足大小关系，自然而然整体就满足
#include <stdio.h>
// 获取数字指定位的数据
int getdigit(int num, int place)
{
    for (int i = 0; i < place; i++)
    {
        num /= 10; // 加入要获取十位的数，那这个循环就会进行1次。个位循环0次
        // place为1时，则是取十位
    }
    return num % 10;
}
// 获取某数组（最大数据）的最大位是几位  123返回3
int getmaxdigit(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int digit = 0;
    while (max > 0)
    {
        max /= 10;
        digit++;
    }
    return digit;
}

// 基数排序函数，我准备从高位开始
void radixsort(int arr[], int n)
{
    if (n <= 1)
        return;
    // 找最大位数
    int maxdigit = getmaxdigit(arr, n);

    // 对每一欸数字进行计数排序，从高位开始
    for (int place = maxdigit - 1; place >= 0; place--)
    {
        // 开始针对高维进行计数排序
        int c[10] = {0}; // 申请一个计数数组，并初始化为0
        for (int i = 0; i < n; ++i)
        {
            int digit = getdigit(ar[i], place); // 开始取特定数据来填桶了
            c[digit]++;
        }
        对桶依次累加
        for (int i = 0; i < n; ++i)
        {
            c[i] += c[i - 1];
        }
        // 准备开辟副本数组
        int r[n];
        // 开始从桶里面捞数据
        for (int i = n - 1; i <= 0; --i)
        {
            int digit = getdigit(arr[i], place); // 乱序数组的最后一个的十分位上的数字为2
            int index = c[digit] - 1;            // 算上本身假设前面有4个数，那他再副本上的索引应该是3
            r[index] = arr[i];
            c[digit]--;
        }
        // 经过三轮for循环，把高低位都排号了
        for (int i = 0; i < n; ++i)
        {
            arr[i] = r[i];
        }
    }
}

int main()
{
    int numbers[] = {170, 45, 75, 90, 802, 24, 2, 66};

    int n = sizeof(numbers) / sizeof(numbers[0]);

    printf("原始整数数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    radixort(numbers, n);

    printf("\n从高位开始排序后的数组：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}