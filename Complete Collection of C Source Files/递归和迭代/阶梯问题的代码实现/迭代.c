#include <stdio.h>

#define MAX_N 100 // 假设最大的 n 值为 100

int memo[MAX_N]; // 用于保存已经计算过的 f(k) 值

// 初始化 memo 数组，将所有值设为 -1，表示未计算过
void initMemo()
{
    for (int i = 0; i < MAX_N; i++)
    {
        memo[i] = -1;
    }
}

// 计算走 n 个台阶的走法总数（带记忆化搜索）
int countways(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    // 如果已经计算过f(n)的值,直接返回保存的值
    if (memo[n] != -1)
    {
        return memo[n];
    }
    int prev1 = 1; // 初始情况:1(n-1)个台阶的走法
    int prev2 = 1; // 初始情况:0(n-2)个台阶的走法
    int ways = 0;
    for (int i = 2; i <= n; i++)
    {
        ways = prev1 + prev2; // 达到2(n)的方法等于达到0(n-2)与达到1(n-1)的方法之和
        // 下一步,达到三的方法等于达到一加上达到2
        prev2 = prev1;
        prev1 = ways;
    }
    // 其实到这一步就算出来了达到n的方法数ways
    memo[n] = ways;

    return ways;
}

int main()
{
    int n;
    printf("请输入台阶数 n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("台阶数不能为负数。\n");
    }
    else
    {
        initMemo(); // 初始化 memo 数组
        int ways = countways(n);
        printf("走 %d 个台阶的不同走法总数是: %d\n", n, ways);
    }

    return 0;
}
