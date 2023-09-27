//直接调用qsort库函数

#include <stdio.h>
#include <stdlib.h> // 包括 qsort 函数的头文件

#define N 5  // 一共有5种类型的物品
#define W 10 // 背包的容量

// 定义物品的结构体
struct Item
{
    int weight;
    int value;
};

// 比较函数，用于 qsort 函数排序
int compare(const void *a, const void *b)
{
    double density_a = ((double)(((struct Item *)a)->value)) / ((struct Item *)a)->weight;
    double density_b = ((double)(((struct Item *)b)->value)) / ((struct Item *)b)->weight;

    if (density_a < density_b)
    {
        return 1;
    }
    else if (density_a > density_b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // 物品数组
    struct Item items[N] = {{2, 6}, {2, 3}, {6, 5}, {5, 4}, {4, 6}};

    // 对物品按价值密度进行降序排序
    qsort(items, N, sizeof(struct Item), compare);

    int current_weight = 0;
    int current_value = 0;

    printf("选择的物品：\n");
    for (int i = 0; i < N; i++)
    {
        if (current_weight + items[i].weight <= W)
        {
            printf("物品%d（重量：%d，价值：%d）\n", i + 1, items[i].weight, items[i].value);
            current_weight += items[i].weight;
            current_value += items[i].value;
        }
    }

    printf("最大总价值：%d\n", current_value);

    return 0;
}
