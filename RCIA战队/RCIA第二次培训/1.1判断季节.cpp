#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int month;
	cout << "�������·ݣ�";
	cin >> month;
	cout << month << "�¶�Ӧ�ļ����ǣ�";
	if (month >= 1 && month <= 2 || month == 12)
		printf("����\n");
	else if (month >= 3 && month <= 5)
		printf("����\n");
	else if (month >= 6 && month <= 8)
		printf("�ļ�\n");
	else if (month >= 9 && month <= 11)
		printf("�＾\n");

}