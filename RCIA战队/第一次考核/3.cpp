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
	int in;
	cout << "ÊäÈë:";
	cin >> in;
	if (in < 10)
		cout << in << " is less than 10" << endl;
	else if (in < 100)
		cout << in << " is less than 100" << endl;
	else if (in < 1000)
		cout << in << " is less than 1000" << endl;
	else
		cout << in << " is greater than or equal to 1000" << endl;

	return 0;
}