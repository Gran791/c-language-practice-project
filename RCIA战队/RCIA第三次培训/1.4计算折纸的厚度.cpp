#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
	double aim = 8848000.0;
	double thickness = 0.08; //��λmm
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
	cout << "��ʱֽ�ĺ�ȴﵽ��" << thickness/1000 << "��" << endl;
	cout << "����" << count << "�κ�ֽ�ĺ�ȴﵽ���������ĸ߶�" << endl;
}
