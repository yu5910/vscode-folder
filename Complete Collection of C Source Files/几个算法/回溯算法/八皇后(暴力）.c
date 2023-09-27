#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define maxn 11

int count = 0;
int n, P[maxn], hashTable[maxn] = {0};

void generateP(int index);

bool isSafe(int row, int col)
{
    for (int prevRow = 1; prevRow < row; prevRow++)
    {
        if (P[prevRow] == col || abs(prevRow - row) == abs(P[prevRow] - col))
        {
            return false;
        }
    }
    return true;
}

void printSolutions()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", P[i]);
    }
    printf("\n");
}

void generateP(int row)
{
    if (row > n)
    {
        count++;
        // Uncomment the following line to print all solutions
        // printSolutions();
        return;
    }
    for (int col = 1; col <= n; col++)
    {
        if (isSafe(row, col))
        {
            P[row] = col;
            generateP(row + 1);
            P[row] = 0; // Reset for backtracking
        }
    }
}

int main()
{
    n = 8;
    generateP(1);
    printf("%d\n", count);
    return 0;
}
