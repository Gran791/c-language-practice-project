#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <random>
#include <time.h>
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

void isMax(int r, int g, int b)
{
	if (r+g+b == 8)
		cout << r << "   " << g << "   " << b << endl;
}

int main(int argc, char* argv[])
{
	cout << "r   " << "g   " << "b" << endl;
	int count_r = 0, count_g, count_b;
	int red = 3, green = 3, blue = 6;

	for (int i = 0; i <= red; i++)
	{
		count_g = 0;
		for (int j = 0; j <= green; j++)
		{
			count_b = 0;
			for (int k = 0; k <= blue; k++)
			{
				isMax(i, j, k);
			}
		}
	}
	
	
}