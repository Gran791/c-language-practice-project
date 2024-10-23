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
		cout << "猜一个1到10的数字:";
		cin >> guess;
		if (guess > random_number)
		{
			cout << "太大了!再试一次" << endl;
			count++;
		}
		else if(guess < random_number)
		{
			cout << "太小了!再试一次" << endl;
			count++;
		}
		if (count == 3)
		{
			cout << "你猜了3次了，游戏结束" << endl;
			return 0;
		}
	}
	cout << "猜对了!" << endl;
}