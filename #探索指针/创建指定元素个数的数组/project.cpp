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
	printf("输入数组的大小：");
	scanf("%d", &n);
	int *arr;
	arr = (int*)malloc(n * sizeof(int)); //按照输入的大小申请内存
	for (int i = 0; i < n; i++)
	{
		printf("请输入第%d个元素：", i);
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr); //释放内存
	return 0;
}

