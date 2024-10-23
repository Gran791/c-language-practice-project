#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);

	int arr[10];
	cout << "随机数组为：" << endl;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = dis(gen);
		cout << arr[i] << " ";
	}

	int tem[10];
	int ou = 0, ji = 9;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
		{
			tem[ou] = arr[i];
			ou++;
		}
		else
		{
			tem[ji] = arr[i];
			ji--;
		}
	}
	cout << endl << "处理后为：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << tem[i] << " ";
	}
}