#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int temp;
	cout << "����������ƽ���¶ȣ�";
	cin >> temp;
	cout << "����ƽ������Ϊ" << temp << "�ȣ�����о�";
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