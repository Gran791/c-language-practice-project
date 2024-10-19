#include <stdio.h>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);
	int arr[8];
	printf("随机数为: ");
	for (int i = 0; i < 8; i++)
	{
		arr[i] = dis(gen);
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	printf("冒泡排序后: ");
	for (int i = 7; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
}