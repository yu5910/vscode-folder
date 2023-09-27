#include <stdio.h>

int mindistdp(int matrix[4][4], int n)
{                     // 传入一个矩阵及其对应的行数列数
    int states[4][4]; // 已经有了一个矩阵，那这个几乎完全相同的矩阵是肝肾呢
    // 是用来记录状态的，记录每一个子问题的状态（也就是每个子问题的最优解）
    int sum = 0; // 就是将sum的 值存入到states里
    for (int j = 0; j < n; j++)
    {
        // 第一行和第一列的最优状态很容易确定
        sum += matrix[0][j];
        states[0][j] = sum;
    }
    sum = 0; // 第一行把基准状态值确定好后，将sum归零，用来计算第一列
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][0];
        states[i][0] = sum;
    }

    // 有了基准状态就很容易求后面的状态了，就完全是填充状态表的thing
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            states[i][j] = matrix[i][j] + ((states[i][j - 1] < states[i - 1][j]) ? states[i][j - 1] : states[i - 1][j]);
        }
    }
    return states[n - 1][n - 1];
}
int main()
{
    // 先直接用数组定义矩阵
    int matrix[4][4] = {{1, 3, 5, 9}, {2, 1, 3, 4}, {5, 2, 6, 7}, {6, 8, 4, 3}};
    int n = 4; // 要一共向下向右多少次（行数，列数）

    int result = mindistdp(matrix, n); //
    printf("最小距离为：%d\n", result);
    return 0;
}