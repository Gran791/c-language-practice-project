#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	float p,n;
	float i,l,f;
	cout << "请输入最终想要获得的钱：";
	cin >> f;
	cout << "请输入想存入的钱：" ;
	cin >> p;
	cout << "请输入利率：";
	cin >> i;
	cout << "要存的年数：" ;
	n = (f-p)/(p*i);
	cout << n;
}

