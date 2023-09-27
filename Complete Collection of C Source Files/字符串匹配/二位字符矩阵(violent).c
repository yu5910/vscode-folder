//瑕疵一:没有进一步精确限制遍历的范围
//遗憾一:没有找到具体的位置

//核心:找到target中的于pattern匹配的sub_target的首元素

#include <stdio.h>
#define TARGET_ROW 4
#define TARGET_COL 5
#define PATTERN_ROW 2
#define PATTERN_COL 3

int patternMatch(char target[TARGET_ROW][TARGET_COL], char pattern[PATTERN_ROW][PATTERN_COL])
{
    for (int i = 0; i <= TARGET_ROW - PATTERN_ROW; i++)
    {
        for (int j = 0; j <= TARGET_COL - PATTERN_COL; j++)
        {
            int flag = 1;
            for (int x = 0; x < PATTERN_ROW; x++)
            {
                for (int y = 0; y < PATTERN_COL; y++)
                {
                    if (target[i + x][j + y] != pattern[x][y])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (flag)
                return 1; // pattern found
        }
    }
    return 0; // pattern not found
}

int main()
{
    char target[TARGET_ROW][TARGET_COL] = {
        {'a', 'b', 'c', 'd', 'e'},
        {'f', 'g', 'h', 'i', 'j'},
        {'k', 'l', 'm', 'n', 'o'},
        {'p', 'q', 'r', 's', 't'}};

    char pattern[PATTERN_ROW][PATTERN_COL] = {
        {'g', 'h', 'i'},
        {'l', 'm', 'n'}};

    int result = patternMatch(target, pattern);
    if (result == 1)
        printf("Pattern found!\n");
    else
        printf("Pattern not found!\n");

    return 0;
}
