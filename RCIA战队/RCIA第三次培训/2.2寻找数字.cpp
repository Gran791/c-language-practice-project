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
	cout << "����һ���ַ�����";
	getline(cin, input);
	int n;
	cout << "����һ��������";1
	cin >> n;
	while (n < 0 || n > 9)
	{
		cout << "����������������룺";
		cin >> n;
	}
	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == n + '0')
			count++;
	}
	cout << "����" << n << "���ַ����г�����" << count << "��";
}
