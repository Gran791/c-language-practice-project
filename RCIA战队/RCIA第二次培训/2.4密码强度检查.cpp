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
	cout << "���������룺";
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
		cout << "����̫��";
	}
	else if (capital > 0 && lowercse > 0 && sign > 0 && number > 0)
	{
		cout << "����ǿ�Ⱥܸߣ�������д��ĸ��Сд��ĸ�����ֺ������ַ�";
	}
	else if (capital > 0 && lowercse > 0)
	{
		cout << "����ǿ���еȣ�������д��ĸ��Сд��ĸ";
	}
	else
	{
		cout << "����ǿ�Ƚϵͣ�û�а�����д��ĸ��Сд��ĸ";
	}
	cout << endl;
}

int main()
{
	while (1)
		fuction();
}
