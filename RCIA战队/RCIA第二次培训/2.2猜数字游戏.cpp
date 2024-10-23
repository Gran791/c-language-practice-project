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

	cout << "猜一猜1到10之间的秘密数字： ";  //1
	cin >> guess;
	if (guess == rand)
	{
		cout << "猜对了！" << endl;
	}
	else
	{
		cout << "猜一猜1到10之间的秘密数字： ";  //2
		cin >> guess;
		if (guess == rand)
		{
			cout << "恭喜你，猜对了！" << endl;
		}
		else
		{
			cout << "猜一猜1到10之间的秘密数字： ";  //3
			cin >> guess;
			if (guess == rand)
			{
				cout << "恭喜你，猜对了！" << endl;
			}
			else
			{
				cout << "猜一猜1到10之间的秘密数字： ";  //4
				cin >> guess;
				if (guess == rand)
				{
					cout << "恭喜你，猜对了！" << endl;
				}
				else
				{
					cout << "猜一猜1到10之间的秘密数字： ";  //5
					cin >> guess;
					if (guess == rand)
					{
						cout << "恭喜你，猜对了！" << endl;
					}
					else
					{
						cout << "都猜错了，游戏结束！" << endl;
					}
				}
			}
		}
	}
}
