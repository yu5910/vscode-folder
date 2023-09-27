#include <stdio.h>
#include <stdlib.h>

// 结构体定义物品
typedef struct
{
    int weight;
    int value;
} Item;

// 比较函数，针对两个数组元素进行比较，返回正值或负值（结构体）（整数）（字符）
int cmp(const void *a, const void *b)//值不可修改，因此可以作为完全的比较函数，不用担心比较的过程中意外被修改
{
    Item *ia = (Item *)a;
    Item *ib = (Item *)b;

    double density_a = (double)ia->value / ia->weight;
    double density_b = (double)ib->value / ib->weight;

    if (density_b < density_a)
    {
        return -1;
    }
    else if (density_b > density_a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double knapSack(Item items[], int n, int w)
{
    // 使用qsort函数对 items数组 按密度排序
    qsort(items, n, sizeof(Item), cmp); // 注意这四个参数

    // 开始贪心
    int current_weight = 0;   // 定义当前背包内的质量,初始为0
    double current_value = 0; // 当前的价值
    // 遍历所有物品,把每个物品都加进去
    for (int i = 0; i < n; i++)
    {
        if (current_weight + items[i].weight <= w)
        { // 加入当前物品后是否仍然小于背包质量
            current_weight += items[i].weight;
            current_value += items[i].value;
        }
        else
        { // 如果加入当前物品会超过背包容量，只加入部分
            int remain = w - current_weight;
            current_value += items[i].value * ((double)remain / items[i].weight); // 注意两个整数相除回自动截取小数部分,所以要double强制转化
            break;
        }
    }
    return current_value;
};

int main()
{
    int w = 10;                                    // 背包的总质量
    Item arr[] = {{10, 60}, {20, 100}, {30, 120}}; // 物品数组，每个元素都是一个Item结构体的值
    int n = sizeof(arr) / sizeof(arr[0]);          // 物品的数量
    double best_value = knapSack(arr, n, w);

    printf("最大价值为：%.2f", best_value); //%f这是打印浮点数,%.2f这是浮点数有两位
    return 0;
}
