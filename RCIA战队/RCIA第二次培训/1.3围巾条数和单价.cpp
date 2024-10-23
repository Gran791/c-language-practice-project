#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int num, price;
	float discount;
	cout << "请输入购买围巾的数量（条）：";
	cin >> num;
	cout << "请输入围巾单价（元）：";
	cin >> price;
	cout << "折扣：";
	if (num >= 10)
	{
		cout << "5折";
		discount = 0.5;
	}
	else if (num >= 7)
	{
		cout << "6折";
		discount = 0.6;
	}
	else if (num >= 4) 
	{
		cout << "7折";
		discount = 0.7;
	}
	else if (num >= 1)
	{
		cout << "8折";
		discount = 0.8;
	}
	cout << endl << "实交金额：" << num * price * discount << endl;
}