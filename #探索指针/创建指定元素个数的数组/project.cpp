#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;

void test(int *p)
{

}

int main()
{
	int n;
	printf("��������Ĵ�С��");
	scanf("%d", &n);
	int *arr;
	arr = (int*)malloc(n * sizeof(int)); //��������Ĵ�С�����ڴ�
	for (int i = 0; i < n; i++)
	{
		printf("�������%d��Ԫ�أ�", i);
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr); //�ͷ��ڴ�
	return 0;
}

