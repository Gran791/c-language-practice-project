#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	float p, n;
	float i, l, f;
	cout << "������������Ҫ��õ�Ǯ��";
	cin >> f;
	cout << "������������Ǯ��" ;
	cin >> p;
	cout << "���������ʣ�";
	cin >> i;
	cout << "Ҫ���������" ;
	for (n = 0;; n++)
	{
		float money = p * pow(1 + i, n);
		if (money >= f)
		{
			cout << n;
			break;
		}
	}
}

