#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义目标矩阵和模式矩阵的大小
#define TARGET_ROW 4
#define TARGET_COL 5
#define PATTERN_ROW 2
#define PATTERN_COL 3

// 定义目标矩阵和模式矩阵
char target[TARGET_ROW][TARGET_COL] = {
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'q', 'r', 's', 't'}};

char pattern[PATTERN_ROW][PATTERN_COL] = {
    {'g', 'h', 'i'},
    {'l', 'm', 'n'}};

// 定义一个二维数组，用来存储模式矩阵每一行的next数组
int next[PATTERN_ROW][PATTERN_COL];

// 构造next数组的函数，参数为模式串和其长度
void build_next(char *pattern, int len, int *next)
{
    // 初始化第一个位置为-1
    next[0] = -1;
    // 定义两个指针i和j，分别指向当前位置和最长相同前后缀的末尾位置
    int i = 0, j = -1;
    // 循环直到i达到len - 1
    while (i < len - 1)
    {
        // 如果j等于-1，或者当前位置的字符等于最长相同前后缀的下一个字符
        if (j == -1 || pattern[i] == pattern[j])
        {
            // 同时向后移动i和j，并将j的值赋给next[i]
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            // 否则，将j回退到next[j]的位置
            j = next[j];
        }
    }
}

// 使用KMP算法在目标串中查找模式串的函数，参数为目标串、模式串和各自的长度
int kmp(char *target, char *pattern, int t_len, int p_len)
{
    // 定义两个指针i和j，分别指向目标串和模式串的当前位置
    int i = 0, j = 0;
    // 循环直到i达到t_len或者j达到p_len
    while (i < t_len && j < p_len)
    {
        // 如果j等于-1，或者当前位置的字符相等
        if (j == -1 || target[i] == pattern[j])
        {
            // 同时向后移动i和j
            i++;
            j++;
        }
        else
        {
            // 否则，将j回退到next[j]的位置
            j = next[j];
        }
    }
    // 如果j达到p_len，则说明找到了匹配，返回i - j作为匹配的起始位置
    if (j == p_len)
    {
        return i - j;
    }
    // 否则，返回-1表示没有找到匹配
    return -1;
}

// 在二维字符串矩阵中查找另一个二维字符串矩阵的函数，返回匹配的起始行号和列号，如果没有找到匹配，则返回-1
void find_pattern(int *row, int *col)
{
    // Preprocess the pattern matrix, construct a next array for each row, and store it in a two-dimensional array
    for (int i = 0; i < PATTERN_ROW; i++)
    {
        build_next(pattern[i], PATTERN_COL, next[i]);
    }

    // Initialize two variables row and col, representing the target matrix
    *row = -1;
    *col = -1;

    // Loop through the target matrix
    for (int i = 0; i < TARGET_ROW - PATTERN_ROW + 1; i++)
    {
        for (int j = 0; j < TARGET_COL - PATTERN_COL + 1; j++)
        {
            int flag = 1;
            // Loop through the pattern matrix
            for (int x = 0; x < PATTERN_ROW; x++)
            {
                // Use KMP to match each row
                if (kmp(target[i + x] + j, pattern[x], TARGET_COL - j, PATTERN_COL) == -1)//疑难点
                {
                    flag = 0;
                    break;
                }
            }
            // If all rows match, return the starting row and column
            if (flag)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main()
{
    int row, col;
    find_pattern(&row, &col);
    if (row != -1 && col != -1)
    {
        printf("Pattern found at (%d, %d)\n", row, col);
    }
    else
    {
        printf("Pattern not found\n");
    }
    return 0;
}

/*void build_next(char*pattern,int p,int *next){
  int len=0;//字符前面与后缀相同的字符个数
  pattern[0]=0;

  for(int i=1;i<p;i++){//每一个ii对应一个next[i]
    while(len>0&&pattern[i]!=pattern[len]){
     // 如果当前字符不匹配，且最长匹配前缀后缀长度大于0，则回到上一个最长匹配前缀后缀的位置
      len=next[len-1];//现在我和你不匹配，那就看看上一次的最长匹配位置//也就是说如果活化的ABA的下一个和当前的D不匹配,就去看活化的AB的下一个(也就是A)是否和它匹配
    }

    if(pattern[i]==pattern[len]){
     len++;
    }
    next[i]=len;//最后确定next[i]的值
  }
}

*/