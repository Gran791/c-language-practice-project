#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long n;

    printf("Enter n: ");
    scanf_s("%lld", &n);

    for (int i = n - 1; i > 0; i--) //����׳�
        n *= i;

    printf("n! = %lld\n", n);

    int count = 0;
    while (n % 10 == 0) //����ĩβ0�ĸ���
    {
        count++;
        n /= 10;
    }

    printf("n!ĩβ0�ĸ���Ϊ��%d\n", count);
    system("pause");
    return 0;
}
