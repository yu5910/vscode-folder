#include <stdio.h>
#define MAX_DEPTH 20 // 定义最大递归深度
int memo[MAX_DEPTH]; // 散列表用于保存已经计算过的f（k)的值；

// 初始化散列表，所有的值设置为-1，表示未计算过
void initmemo()
{
    for (int i = 0; i < MAX_DEPTH; i++)
    {
        memo[i] = -1;
    }
}

// 计算n个台阶的走法总数（带递归深度和散列表）
int countwayswithdepthAndmemo(int n, int depth)
{
    if (depth >= MAX_DEPTH)
    {
        return 0; // 如果递归深度达到了最大值，则返回-1，表示程序失败了
    }
    if (n <= 1)
    {
        return 1;
    }
    if (memo[n] != -1)
    {                   // 说明此时fn已经被储存起来了
        return memo[n]; // 避免重复运算
    }

    int ways = countwayswithdepthAndmemo(n - 1, depth + 1) + countwayswithdepthAndmemo(n - 2, depth + 1);
    memo[n] = ways; // 把这一步求得的f（n)保存进memo（n）里
    return ways;
}

int main()
{
    int n;
    printf("请输入要计算的台阶数 n: \n"); // 这一步是真秒啊
    scanf("%d", &n);

    if (n < 0)
    {
        printf("台阶数不能未负数。\n");
    }
    else
    {
        initmemo();
        int ways = countwayswithdepthAndmemo(n, 0);         // 在参数部分就初始化递归深度
        printf("走%d个台阶的不同走法总数是:%d\n", n, ways); // 好家伙,全是逗号
    }

    return 0;
}
