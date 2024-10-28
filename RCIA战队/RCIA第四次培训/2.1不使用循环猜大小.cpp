#include <iostream>  
#include <vector>  
#include <iomanip>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;


void Guess(int m, int n)
{
	cout << "请猜测一个1-99的整数：";
	cin >> m;
	if (m == n)
		cout << "猜对了！";
	else
	{
		cout << "猜错了，";
		if (m > n)
			cout << "你猜大了！";
		else 
			cout << "你猜小了！";
		cout << "再试一次吧" << endl;
		Guess(m, n);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int b = rand() % 100; //创建随机值
	//LOG(b);
	int a = 0;
	Guess(a, b);
	std::cin.get();
}
