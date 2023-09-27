#include <stdio.h>
#include <stdbool.h>

int knapsack(int weight[], int n, int w)
{
    bool states[n][w + 1];//不超过背包的最大数量十kg，0-10一共十一个数
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            states[i][j] = false;
        }
    }

    states[0][0] = true;
    if (weight[0] <= w)
    {
        states[0][weight[0]] = true;
    }

    for (int i = 1; i < n; ++i)
    {
        /*如果上一个物品的状态 states[i-1][j] 是 true，则当前物品也可以选择不放入背包，因此 states[i][j] 被设置为 true。

        如果上一个物品的状态 states[i-1][j] 是 true，并且将当前物品放入背包后不会超过背包的承重量，则 states[i][j + weight[i]] 被设置为 true，表示可以选择放入当前物品。*/
        for (int j = 0; j <= w; ++j)
        {
            if (states[i - 1][j])
            {
                states[i][j] = true;
            }
        }

        for (int j = 0; j <= w - weight[i]; ++j)
        {
            if (states[i - 1][j])
            {
                states[i][j + weight[i]] = true;
            }
        }
    }

    for (int i = w; i >= 0; --i)//先看看十kg是否存在，再看看9kg是否存在
    {
        if (states[n - 1][i])
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    int weight[] = {2, 2, 6, 5, 4};
    int n = sizeof(weight) / sizeof(weight[0]);//n是物品的个数
    int w = 10;//w是背包限制的重量
    int maxWeight = knapsack(weight, n, w);
    printf("最大可装载重量为：%d\n", maxWeight);
    return 0;
}
