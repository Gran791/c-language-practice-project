#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int month;
	cout << "请输入月份：";
	cin >> month;
	cout << month << "月对应的季节是：";
	if (month >= 1 && month <= 2 || month == 12)
		printf("冬季\n");
	else if (month >= 3 && month <= 5)
		printf("春季\n");
	else if (month >= 6 && month <= 8)
		printf("夏季\n");
	else if (month >= 9 && month <= 11)
		printf("秋季\n");

}