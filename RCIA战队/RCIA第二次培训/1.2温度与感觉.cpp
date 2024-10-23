#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int temp;
	cout << "请输入今天的平均温度：";
	cin >> temp;
	cout << "今天平均气温为" << temp << "度，户外感觉";
	if (temp <= -15)
	{
		cout << "icy" << endl;
	}
	else if (temp <= -5)
	{
		cout << "chilly" << endl;
	}
	else if (temp <= 8)
	{
		cout << "cold" << endl;
	}
	else if (temp <= 18)
	{
		cout << "cool" << endl;
	}
	else
	{
		cout << "warm" << endl;
	}
}