//运行失败了，以后有时间再改bug吧
#include <stdio.h>

// 先把n个人的n个成绩全部储存到一个长长的数组中，数组第n个元素的值就是第n个同学的成绩
int examscores[] = {89, 78, 92, 86, 90, 85, 88, 82, 91};
int n = sizeof(examscores) / sizeof(examscores[0]); // 表示有n个同学
// 寻找成绩中的最大成绩
int max = examscores[0];
for (int i = 1; i < n; ++i)
{
    if (max < examscores[i])
    {
        max = examscores[i];
    }
}
int min;
// 好，现在得到了最大了，
int c[max - min + 1];
for (int i = 0; i < max - min + 1; i++)
{
    c[i] = 0; // 这一步非常关键，把计数数组内的所有各个成绩（桶）的桶内物质变成0
}
// 开始向每个桶抛人
for (int i = 0; i < n; i++)
{
    ++c[examscores[i]];
}
// 但是现在每个桶内只是各自的数量，不满足，桶的人数等于本桶加上前面桶的个数之和
for (int i = 1; i < max - min + 1; i++)
{
    c[i] = c[i - 1] + c[i];
}
// 好，桶也做好了，填满了，开始向一个空的n个元素的数组填人
int r[n]; // 先创建一个副本空数组
for (i = 0; i < n; i++)
{
    index = c[examscores[i]]; // 得到第一个同学再桶中的索引
    --c[examscores[i]];
    r[index - 1] = examscores[i];
}
// 现在这个副本数组已经完全是我所需要的排序，但是，我的木的是修改原数组，所以我需要把副本数组拷贝给原始数组
for (int i = 0; i < n; i++)
{
    examscores[i] = c[i];
}
// 经过上面的操作已经完全更新了examscores数组，下面再封装成函数就ok了
void printlist(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n%d", arr[i]);
    }
}

int main()
{
    printlist(examscores, n);
    return 0;
}
