#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int error()
{
	printf("��������\n");
	exit(2);
}

int main()
{
	//���벿��
	long number1, number2;

	printf("�������һ������");
	scanf("%ld", &number1);

	printf("������ڶ�������");
	scanf("%ld", &number2);


	//�ж���ת������
	char str1[10] = { 0 };

	for (int i = 0; number1 != 0; i++)
	{
		str1[i] = number1 % 10;
		if (str1[i] != 0 && str1[i] != 1)
		{
			error();
		}
		number1 /= 10;
	}

	char str2[10] = { 0 };

	for (int i = 0; number2 != 0; i++)
	{
		str2[i] = number2 % 10;
		if (str2[i] != 0 && str2[i] != 1)
		{
			error();
		}
		number2 /= 10;
	}


	//���㲿��
	char plus[11] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		if (plus[i] == 2)
		{
			plus[i] = 0;
			plus[i + 1] ++;
		}

		plus[i] += str1[i];

		if (plus[i] == 2)
		{
			plus[i] = 0;
			plus[i + 1] ++;
		}

		plus[i] += str2[i];

		if (plus[i] == 2)
		{
			plus[i] = 0;
			plus[i + 1]++;
		}
	}


	//�������
	printf("�����");
	for (int i = 10; i != -1; i--)
	{
		printf("%d", plus[i]);
	}
	
	printf("\n");
	system("pause"); 
	return 0;
}
