#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;

void test(int *p)
{
	//*pʵ����arr����ĵ�ַ
	cout << "test�������������ַ��" << p << endl;
	*(p + 1) = 0; // p + 1 = &arr[1] �޸�����
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int *p = arr;
	cout << "�����������ַ��" << p << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	test(p); //��p��arr���飩���ݸ�test����
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
}

