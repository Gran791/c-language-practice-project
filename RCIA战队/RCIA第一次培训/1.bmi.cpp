#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	float weight, height;
	cout << "������������(m):";
	cin >> height;
	cout << "�������������(kg):" ;
	cin >> weight;
	float bmi = weight / (height * height);
	cout << "���BMIΪ��" << bmi;
}

