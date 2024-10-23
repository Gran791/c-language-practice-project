#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	char gender;
	float grade;
	cout << "请输入性别（M/F）：";
	cin >> gender;
	Sleep(2000); 
	cout << "请输入百米成绩（秒）：";
	cin >> grade;
	cout << "你的等级是：";
	if (gender == 'F' || gender == 'f')
	{
		if (grade > 16)
			cout << "不合格";
		else if (grade > 14)
			cout << "合格";
		else
			cout << "优秀";
	}
	if (gender == 'M' || gender == 'm')
	{
		if (grade > 15)
			cout << "不合格";
		else if (grade > 13)
			cout << "合格";
		else
			cout << "优秀";
	}
}
