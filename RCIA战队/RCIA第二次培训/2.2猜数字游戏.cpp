#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <iostream>
#include <string.h>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);

	int rand = dis(gen);
	int guess = 0,wrong = 0;

	cout << "��һ��1��10֮����������֣� ";  //1
	cin >> guess;
	if (guess == rand)
	{
		cout << "�¶��ˣ�" << endl;
	}
	else
	{
		cout << "��һ��1��10֮����������֣� ";  //2
		cin >> guess;
		if (guess == rand)
		{
			cout << "��ϲ�㣬�¶��ˣ�" << endl;
		}
		else
		{
			cout << "��һ��1��10֮����������֣� ";  //3
			cin >> guess;
			if (guess == rand)
			{
				cout << "��ϲ�㣬�¶��ˣ�" << endl;
			}
			else
			{
				cout << "��һ��1��10֮����������֣� ";  //4
				cin >> guess;
				if (guess == rand)
				{
					cout << "��ϲ�㣬�¶��ˣ�" << endl;
				}
				else
				{
					cout << "��һ��1��10֮����������֣� ";  //5
					cin >> guess;
					if (guess == rand)
					{
						cout << "��ϲ�㣬�¶��ˣ�" << endl;
					}
					else
					{
						cout << "���´��ˣ���Ϸ������" << endl;
					}
				}
			}
		}
	}
}
