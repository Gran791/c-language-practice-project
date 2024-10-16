#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;

void test(int *p)
{
	//*p实际是arr数组的地址
	cout << "test函数接受数组地址：" << p << endl;
	*(p + 1) = 0; // p + 1 = &arr[1] 修改数组
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int *p = arr;
	cout << "主函数数组地址：" << p << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	test(p); //将p（arr数组）传递给test函数
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
}

