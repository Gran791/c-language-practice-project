#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 1; i < 11; i++)
	{
		int total = 0;
		int num = 1;
		for (int j = 1; j <= i; j++)
		{
			num *= j;
		}
		cout << i << "!= " << num << endl;
	}
}