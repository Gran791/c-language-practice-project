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
	uniform_int_distribution<> dis(0, 2);
	int x = dis(gen)%3;
	string choice;
	int c = 0;
	cout << "请选择（石头/剪刀/布）: " ;
	cin >> choice;
	if (choice == "石头") 
		c = 0;
	else if (choice == "剪刀")
		c = 1;
	else if (choice == "布")
		c = 2;

	if (x == 0)
		cout << "PC选择了：石头" << endl;
	else if (x == 1)
		cout << "PC选择了：剪刀" << endl;
	else
		cout << "PC选择了：布" << endl;
	if ((c == 0 && x == 1)||(c == 1 && x == 2)||(c == 2 && x == 0))
		cout << "游戏结果：你赢了！" << endl;
	else if ((c == 1 && x == 0)||(c == 2 && x == 1)||(c == 0 && x == 2))
		cout << "游戏结果：你输了！" << endl;
	else
		cout << "游戏结果：平局！" << endl;
}
