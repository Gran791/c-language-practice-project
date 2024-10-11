#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long n;

    printf("Enter n: ");
    scanf_s("%lld", &n);

    for (int i = n - 1; i > 0; i--) //计算阶乘
        n *= i;

    printf("n! = %lld\n", n);

    int count = 0;
    while (n % 10 == 0) //计算末尾0的个数
    {
        count++;
        n /= 10;
    }

    printf("n!末尾0的个数为：%d", count);
    system("pause");
    return 0;
}