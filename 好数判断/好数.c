#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int N, sum = 0, p = 1;
	printf("计算1到N有多少个好数，请输入N: ");
	scanf("%d",&N);

	for (p; p <= N; p++)
	{
		int i = p, num = 1, s = 0, good = 1;
		
		if (i == 0)
		{
			sum++;
		}
		else
		{
			while (i != 0)
			{
				s = i % 10; 
				if (s % 2 == 1 && num % 2 == 1);
				else
				{
					if (s % 2 == 0 && num % 2 == 0);
					else if (p != 1)
					{
						good = 0;
					}
				}
				
				i /= 10;
				num++;
			}
			
			if (good == 1)
			{
				sum++;
			}
		}
	}
	printf("1 到 %d 共有 %d 个好数", N, sum);
	getchar(); 
	getchar(); 
	return 0;
}
