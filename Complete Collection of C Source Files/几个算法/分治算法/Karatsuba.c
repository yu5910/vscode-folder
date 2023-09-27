#include <stdio.h>
#include <math.h>

// Karatsuba算法
long long karatsuba(long long x, long long y, int n)
{
    if (n == 1)
    {
        return x * y;
    }

    int m = n / 2;
    long long a = x / (long long)pow(10, m);
    long long b = x % (long long)pow(10, m);
    long long c = y / (long long)pow(10, m);
    long long d = y % (long long)pow(10, m);

    long long ac = karatsuba(a, c, m);
    long long bd = karatsuba(b, d, m);
    long long ad_bc = karatsuba((a + b), (c + d), m) - ac - bd;

    return ac * (long long)pow(10, 2 * m) + ad_bc * (long long)pow(10, m) + bd;
}

int main()
{
    long long x, y;
    printf("Enter two numbers to multiply: ");
    scanf("%lld %lld", &x, &y);

    int n = log10(x) + 1; // 获取数字的位数
    long long result = karatsuba(x, y, n);

    printf("Result of multiplication: %lld\n", result);
    return 0;
}
