#include <stdio.h>
#define N 5  // 一共有5种类型的物品
#define W 10 // the restricted item weight

int w[N] = {2, 2, 6, 5, 4}; // 各类型物品的分别的重量（weight
int v[N] = {6, 3, 5, 4, 6}; // 各物品的价值
int x[N];                   // 当前解，是一群01组合，物品要末被选要末没有被选中
int bestx[N];               // 最优解
int maxv = 0;               // 最大价值存在maxn种，并初始化为0
int cw = 0;
int cv = 0; // 当前的价值和重量

void backtrack(int i)
{ // i为几，就先处理第几层，刚开始i=1，就是先处理第一层，
    if (i >= N)
    {
        // 如果在递归的过程中到达了终点
        if (cv > maxv)
        {
            maxv = cv;
            for (int j = 0; j < N; j++)
            {
                bestx[j] = x[j];
            }
        }
        return; // 退出当前的backtrack（i+1),继续执行backtrack（i)的下一步（回溯）：清除本选项操作，backtrack[i】有两个选项，此时backtrack[i]的一个选项执行完毕，，执行另一个选项，并清楚另一个选项的的结果后,即另一个选项也执行完毕后，相当于是backtrack[i-1]的一个选项执行完毕，清楚本backtrack[i-1】的结果，执行另一个backtrack【i-1】
    }
    else
    {
        for (int j = 0; j <= 1; j++)
        {
            //(o-1选择)
            cw += w[i] * j; // 这个*j非常巧妙
            cv += v[i] * j;
            x[i] = j;
            if (cw <= W)
            {
                backtrack(i + 1); // 就是如果执行本层后，还有重量盈余，就执行下一层，如果没有盈余，说明本层的质量过大，就清楚本层的加质量操作
            }
            cw -= w[i] * j; // 百花：清除了本层的操作（不管本层加没加重量，还是*j的妙用）
            cv -= v[i] * j; // 抽象叫法：回溯
        }
    }
}

int main()
{
    backtrack(0);
    printf("最大价值为：%d\n", maxv);
    printf("最优解为：");
    for (int i = 0; i < N; i++)
    {
        printf("%d", bestx[i]);
    }
    printf("\n");
    return 0;
}