#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <vector>

using namespace std;

int main()
{
	int zhizhu, qingting, chan;
	//³á°ò
	for (int i = 0; i <= 20; i++)//chan
	{
		for (int j = 0; j <= (20 - i)/2; j++)//qingting
		{
			if(i*6+j*6+(18-i-j)*8==118 && i + 2*j == 20)
			{
				cout << "Ö©Öë£º" << 18 - i - j << "¸ö" << endl;
				cout << "òßòÑ£º" << j << "¸ö" << endl;
				cout << "²õ£º" << i << "¸ö" << endl;
				cout << endl;
			}

		}
	}
	return 0;
}