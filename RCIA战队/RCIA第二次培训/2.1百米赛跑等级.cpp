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
	cout << "�������Ա�M/F����";
	cin >> gender;
	Sleep(2000); 
	cout << "��������׳ɼ����룩��";
	cin >> grade;
	cout << "��ĵȼ��ǣ�";
	if (gender == 'F' || gender == 'f')
	{
		if (grade > 16)
			cout << "���ϸ�";
		else if (grade > 14)
			cout << "�ϸ�";
		else
			cout << "����";
	}
	if (gender == 'M' || gender == 'm')
	{
		if (grade > 15)
			cout << "���ϸ�";
		else if (grade > 13)
			cout << "�ϸ�";
		else
			cout << "����";
	}
}
