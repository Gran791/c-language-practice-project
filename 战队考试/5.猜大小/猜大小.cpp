#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std; 

int input()
{
	int n = 0;
	cout << "猜一下：";
	cin >> n;
	return n;
}

int main()
{
	srand((unsigned)time(NULL));
	int rd = rand() % 100; //生成随机数rd
	int in = 0;
	
	while (in != rd)
	{
		in = input();
		if (in > rd) cout << "大了" << endl;
		else if (in < rd) cout << "小了" << endl;
	}
	cout << endl << "猜对了！这个数是" << rd << endl;

}
