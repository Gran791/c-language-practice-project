#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <iostream>
#include <random>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	string input;
	cout << "输入一个字符串：";
	getline(cin, input);
	int n;
	cout << "输入一个整数：";1
	cin >> n;
	while (n < 0 || n > 9)
	{
		cout << "输入错误，请重新输入：";
		cin >> n;
	}
	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == n + '0')
			count++;
	}
	cout << "整数" << n << "在字符串中出现了" << count << "次";
}
