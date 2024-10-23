#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	float weight, height;
	cout << "请输入你的身高(m):";
	cin >> height;
	cout << "请输入你的体重(kg):" ;
	cin >> weight;
	float bmi = weight / (height * height);
	cout << "你的BMI为：" << bmi;
}

