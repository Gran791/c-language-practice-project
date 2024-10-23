#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <iostream>
#include <string.h>
#include <random>

using namespace std;


void fuction()
{
	char pswd[100];
	cout << "请输入密码：";
	cin >> pswd;
	int capital = 0, lowercse = 0, sign = 0, number = 0;
	for (int i = 0; i < strlen(pswd); i++)
	{
		if (pswd[i] >= 'A' && pswd[i] <= 'Z')
			capital++;
		else if (pswd[i] >= 'a' && pswd[i] <= 'z')
			lowercse++;
		else if (pswd[i] >= '0' && pswd[i] <= '9')
			number++;
		else if (pswd[i] >= '!' && pswd[i] <= '/')
			sign++;
	}
	if (strlen(pswd) < 8)
	{
		cout << "密码太短";
	}
	else if (capital > 0 && lowercse > 0 && sign > 0 && number > 0)
	{
		cout << "密码强度很高，包含大写字母、小写字母、数字和特殊字符";
	}
	else if (capital > 0 && lowercse > 0)
	{
		cout << "密码强度中等，包含大写字母和小写字母";
	}
	else
	{
		cout << "密码强度较低，没有包含大写字母或小写字母";
	}
	cout << endl;
}

int main()
{
	while (1)
		fuction();
}
