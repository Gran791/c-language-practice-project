#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
	char in[1000];
	cout << "输入一段字符："; 
	cin >> in;
	cout << "这段字符的长度为：" << strlen(in);
	return 0;
 } 
