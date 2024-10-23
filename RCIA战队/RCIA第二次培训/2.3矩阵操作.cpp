#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <iostream>
#include <string.h>
#include <random>

using namespace std;


int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);

    //创建随机数组
	int arr[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = dis(gen);
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	//排序最大值并且输入到max数组中
	int temp[5],max[5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			temp[j] = arr[i][j];

		for (int t = 0; t < 4; t++)
		{
			if (temp[t] > temp[t + 1])
				swap(temp[t], temp[t + 1]);
		}

		max[i] = temp[4];
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == max[i])
				swap(arr[i][j], arr[i][i]);
		}
	}

	//max 数组排序
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4-i; j++)
		{
			if (max[j] > max[j + 1])
				swap(max[j], max[j + 1]);
		}
	}

	//输出
	cout << "------------------------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		swap(max[i], arr[i][i]);
		for (int j = 0; j < 5; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

