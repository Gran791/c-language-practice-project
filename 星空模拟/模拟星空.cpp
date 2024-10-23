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
	uniform_int_distribution<> n(0, 3);//�Ƿ������ǣ�1Ϊ�У�
	uniform_int_distribution<> m(1, 3);//���ǵ����ȣ�1Ϊ����

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
	printf("\n���ǵ�����Ϊ��%d\n", count);
	return 0;
}
