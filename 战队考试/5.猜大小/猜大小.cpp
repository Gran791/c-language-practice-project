#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std; 

int input()
{
	int n = 0;
	cout << "��һ�£�";
	cin >> n;
	return n;
}

int main()
{
	srand((unsigned)time(NULL));
	int rd = rand() % 100; //���������rd
	int in = 0;
	
	while (in != rd)
	{
		in = input();
		if (in > rd) cout << "����" << endl;
		else if (in < rd) cout << "С��" << endl;
	}
	cout << endl << "�¶��ˣ��������" << rd << endl;

}
