#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int num, price;
	float discount;
	cout << "�����빺��Χ���������������";
	cin >> num;
	cout << "������Χ���ۣ�Ԫ����";
	cin >> price;
	cout << "�ۿۣ�";
	if (num >= 10)
	{
		cout << "5��";
		discount = 0.5;
	}
	else if (num >= 7)
	{
		cout << "6��";
		discount = 0.6;
	}
	else if (num >= 4) 
	{
		cout << "7��";
		discount = 0.7;
	}
	else if (num >= 1)
	{
		cout << "8��";
		discount = 0.8;
	}
	cout << endl << "ʵ����" << num * price * discount << endl;
}