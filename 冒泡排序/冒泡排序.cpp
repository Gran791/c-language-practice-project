#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	// 请在此输入您的代码
	int cup, teapot, want;
	scanf("%d %d %d", &cup, &teapot, &want);
	char inf[1000] = { '0' };
	int num[1000] = { 0 };
	scanf("%s", inf);
	int d = 0;
	for (int i = 0; inf[i] != '0'; i++)
	{
		if (inf[i] != ' ');
		{
			num[d] = inf[i] - '0';
		}
	}

	for (int i = 0; num[i] != 0; i++)
	{
		for (int j = 0; num[j + 1] != 0; j++)
		{
			if (num[j] > num[j + 1])
			{
				swap(num[j], num[j + 1]);
			}
		}
	}


	return 0;
}
