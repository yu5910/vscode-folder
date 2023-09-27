//核心：将物品的价值密度用快速排序函数排序

#include <stdio.h>

#define N 5 // 一共有5种类型的物品

// 背包容量
#define W 10

// 定义物品的结构体
struct Item
{
    int weight;
    int value;
};

// 快速排序函数...

void quickSort(struct Item arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high].value / arr[high].weight;
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            int j_density = arr[j].value / arr[j].weight;
            if (j_density >= pivot)
            {
                i++;
                // 交换 arr[i] 和 arr[j]
                struct Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // 交换 arr[i+1] 和 arr[high]
        struct Item temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        // 递归排序左半部分和右半部分
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    // 物品数组
    struct Item items[] = {{2, 6}, {2, 3}, {6, 5}, {5, 4}, {4, 6}};
    int n = sizeof(items) / sizeof(items[0]);

    // 对物品按价值密度进行排序
    quickSort(items, 0, n - 1);

    printf("选择的物品：\n");
    int current_weight = 0;
    int current_value = 0;

    for (int i = 0; i < n; i++)
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
