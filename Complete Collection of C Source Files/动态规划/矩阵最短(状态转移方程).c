// 不论十转义方程还是转移表,都可以用回溯或回溯加memo解决
// 回溯可以直观提供递归树
// 状态方程可以直观提供递归逻辑:       min_dist(i, j) = w[i][j] + min(min_dist(i, j-1), min_dist(i-1, j))
// 都可以为递归表服务

#include <stdio.h>

int matrix[4][4] = {{1, 3, 5, 9}, {2, 1, 3, 4}, {5, 2, 6, 7}, {6, 8, 4, 3}};
int n = 4;
int memo[4][4]; //

int minDist(int i, int j)
{ // 递归效果：求到达matrix[i][j]的最短路径
    if (i == 0 && j == 0)
        return matrix[0][0];
    if (memo[i][j] > 0)
        return memo[i][j]; // 就是如果minDist[i][j]已经计算过了，就不再递归算了，直接返回它的值

    int minleft;
    if (j >= 1)
    {
        minleft = minDist(i, j - 1);
    }
    int minup;
    if (i >= 1)
        minup = minDist(i - 1, j);

    int currentMindist = matrix[i][j] + ((minleft < minup) ? minleft : minup);
    memo[i][j] = currentMindist; // 把到matrix[i][j]的最短路径记录下来
    return currentMindist;
}

int main()
{
    // 先把全局变量memo全部初始化为0，因为刚开始每个状态都还没有被计算
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = 0;
        }
    }
    int result = minDist(n - 1, n - 1);
    printf("最小距离为：%d\n", result);
    return 0;
}