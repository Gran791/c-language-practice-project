#include <iostream>  
#include <vector>  
#include <iomanip>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;


void Guess(int m, int n)
{
	cout << "��²�һ��1-99��������";
	cin >> m;
	if (m == n)
		cout << "�¶��ˣ�";
	else
	{
		cout << "�´��ˣ�";
		if (m > n)
			cout << "��´��ˣ�";
		else 
			cout << "���С�ˣ�";
		cout << "����һ�ΰ�" << endl;
		Guess(m, n);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int b = rand() % 100; //�������ֵ
	//LOG(b);
	int a = 0;
	Guess(a, b);
	std::cin.get();
}
