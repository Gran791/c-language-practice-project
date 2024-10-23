#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);
	int random_number = dis(gen);
	int guess = 0, count = 0;;
	
	while (guess != random_number)
	{
		cout << "��һ��1��10������:";
		cin >> guess;
		if (guess > random_number)
		{
			cout << "̫����!����һ��" << endl;
			count++;
		}
		else if(guess < random_number)
		{
			cout << "̫С��!����һ��" << endl;
			count++;
		}
		if (count == 3)
		{
			cout << "�����3���ˣ���Ϸ����" << endl;
			return 0;
		}
	}
	cout << "�¶���!" << endl;
}