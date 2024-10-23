#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <random>

#define X 30
#define Y 15

using namespace std;

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> n(0, 3);//是否有星星（1为有）
	uniform_int_distribution<> m(1, 3);//星星的亮度（1为亮）

	int x = 0, y = 0, count = 0;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			int isStar = n(gen);
			int lightness = m(gen);
			if (isStar == 1)
			{
				if (lightness == 1)
				{
					printf(" * ");
					count++;
				}
				else
				{
					printf(" . ");
					count++;
				}
			}
			else
			{
				printf("   ");
			}
		}
		printf(" |\n");
	}
	printf("\n星星的数量为：%d\n", count);
	return 0;
}
