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
		cout << "����������: ";
		cin >> input;
		if (input == pswd)
		{
			cout << "������ȷ����ӭ����ϵͳ!" << endl;
			break;
		}
		else if (trys != 1)
		{
			cout << "������󣬻��� " << trys - 1 << " �γ��Ի���." << endl;
			trys--;
		}
		else
		{
			cout << "������󣬳��Դ������þ�." << endl;
			return 0;
		}
	}
}