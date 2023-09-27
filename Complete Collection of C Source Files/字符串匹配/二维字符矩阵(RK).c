#include <stdio.h>
#include <stdlib.h> //分配内存

// 定义模式矩阵和目标矩阵
#define target_row 4
#define target_col 5
#define pattern_row 2
#define pattern_col 3
char target[target_row][target_col] = {
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'q', 'r', 's', 't'},
};
char pattern[pattern_row][pattern_col] = {
    {'g', 'h', 'i'},
    {'l', 'm', 'n'}};

#define k 26           // 确定了字符的范围便于哈希值字符转数字且没有重复
#define MOD 1000000007 // 防止int放不下这个哈希值
int power[k];          // 定义一个数组把26的0-26次幂都存下来
// 开始预处理
power[0] = 1; // 因为k的0次方=1；
for (int i = 1; i < k; i++)
{
    power[i] = (power[i - 1] * k) % MOD;
}

// 开始设计一个能够计算矩阵哈希值的函数
int hash(char matrix[][pattern_cow], int row, int col)//先确定数组的类型，是
{
    // 因为要对矩阵的每一个元素累加求和，所已先初始化hash值为0，后面再累加
    int h = 0; // 先遍历每一行，再遍历每一列
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            h = (h + (matrix[i][j] - 'a' + 1) * power(i * col + j)) % MOD; // 加一保证了最小为1
        }
    }
    return h;
}

// 下面开始在目标矩阵中查找patern矩阵，并返回目标矩阵首元素的指针（也就是目标矩阵的名称）
int find_pattern(int *startrow, int *startcol)
{
    // 先计算MOD的hash
    int pattern_hash = hash(pattern, pattern_row, pattern_col);
    // 再次定义一个row与col（可变的类似于current），用于表示两矩阵现在正在比较的位置
    int row = 0;
    int col = 0;
    // 计算当前子矩阵的哈希值
    int sub_hash = 0;
    // 开始逐个扫描子矩阵
    while (row <= target_row - pattern_row)
    { // 后面又会用到一个贼秒的思路，就是，大家都知道最后的row++会进入while的下一层循环，但是如果最后来一个col++，那会怎么样呢，惊喜的是，它还会再来一遍本row的循环

        // 前面的每一行向右移动会得到数个子矩阵，先基于第一个子矩阵，前后子矩阵存在迭代关系
        // 不过属实有点好高鹜了，因为你莲子矩阵还没找到在哪呢，就想求职了
        if (col == 0)
        {
            sub_hash = hash(target + row, pattern_row, pattern_col); // 太秒了，考察了指针的运算，指针加一，家的是一个指针指向类型的大小
        }
        else
        { // 否则就递归计算本行的下一个矩阵
            for (int i = 0; i < pattern_row; i++)
            { // 秒不科研的一个循环，不过我就不写啦，理解思想就可，这个代码对我代码能力的提升也不大，对代码数学计算提升倒是可能有
                sub_hash = (sub_hash - (target[row + i][col - 1] - 'a' + 1) * power[i * pattern_col]) % MOD;
                sub_hash = (sub_hash * k + (target[row + i][col + pattern_col - 1] - 'a' + 1) * power[(i + 1) * pattern_col - 1]) % MOD;
            }
            // 这波子矩阵hash算下来后，如果hash为<0,再加上MOD
            if (sub_hash < 0)
            {
                sub_hash += MOD;
            }
        }
        // 前面终于计算完了sub_pattern的hash
        // 毕竟是纯村在散列表中，hash值相同后，还需要进一步比较每个元素是否相同
        if (sub_hash == pattern_hash)
        {
            int flag = 1; // 定义一个标志变量，假设匹配成功
            for (int i = 0; i < pattern_row; i++)
            {
                if (flag == 0)
                {
                    break;
                }
                for (int j = 0; j < pattern_col; j++)
                {
                    if (pattern[i][j] != (target[row + i][row + j]))
                    {
                        flag = 0;
                        break;
                    }
                }
            } // 胫过一波逐个元素的检验，如果flage还是1，那就达标
            if (flag == 1)
            {
                *startrow = row;
                *startcol = col;
                return;
            }
        }
        // 当然也肯能很遗憾，
        col++; // 进入本行的下一个子矩阵
        if (col > target_col - pattern - col)
        { // 表明本行遍历完毕，换行咯
            row++;
            col = 0;
        }
    }
    // 如果前面的return命令没有被执行，南无就会来到这里
    *startcol = -1;
    *startrow = -1; // 表明失败咯
    return;
}

int main()
{
    // 定义两个变量，用来储存find_pattern的结果
    int row, col;
    find_pattern(&row, &col); // 很好，把row和col的指针传过去，使得main内的变量可以被改变

    if (row == -1 && col == -1)
    {
        printf("没有找到匹配\n");
    }
    else
    {
        printf("找到匹配，起始位置为(%d, %d)\n", row, col);
    }
    return 0;
}