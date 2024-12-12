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
	for (int i = 0; i < 4; i++)
	{
		int j = 2 * i + 1;
		for (int m = 0; m < j; m++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 2; i >= 0; i--)
	{
		int j = 2 * i + 1;
		for (int m = j - 1; m >= 0; m--)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}