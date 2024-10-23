#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);
	
	int list[9];

	cout << "随机数为：";
	for (int i = 0; i < 9; i++)
	{
		list[i] = dis(gen);
		cout << list[i] << "\t";
	}

	int alt[9] = { 0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 9; i++) //遍历list  i
	{
		for (int p = 0; p < 9; p++) //遍历alt  p
		{
			if (list[i] >= alt[p]) 
			{
				for (int j = 7; j >= p; j--) //将元素往后移
				{
					alt[j + 1] = alt[j];
				}
				alt[p] = list[i]; //插入alt中
				break; //跳出alt的遍历
			}
		}
	}

	cout << endl << "排列后为：";
	for (int n = 8; n >= 0; n--) //突然发现题目要求的是从小到大，懒得改只能这样写了
	{
		cout << alt[n] << "\t";
	}
	cout << endl;
	system("pause");
}
