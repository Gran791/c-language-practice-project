#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
	string pswd = "Rcia123.";
	string input;
	int trys = 3;
	while (trys != 0)
	{
		cout << "请输入密码: ";
		cin >> input;
		if (input == pswd)
		{
			cout << "密码正确，欢迎进入系统!" << endl;
			break;
		}
		else if (trys != 1)
		{
			cout << "密码错误，还有 " << trys - 1 << " 次尝试机会." << endl;
			trys--;
		}
		else
		{
			cout << "密码错误，尝试次数已用尽." << endl;
			return 0;
		}
	}
}