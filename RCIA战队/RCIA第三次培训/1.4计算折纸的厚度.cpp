#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
	double aim = 8848000.0;
	double thickness = 0.08; //单位mm
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		thickness *= 2;
		count++;
		if (thickness >= aim)
		{
			break;
		}
	}
	cout << "此时纸的厚度达到了" << thickness/1000 << "米" << endl;
	cout << "对折" << count << "次后，纸的厚度达到珠穆朗玛峰的高度" << endl;
}
