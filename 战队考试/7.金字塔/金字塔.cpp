#include <iostream>

using namespace std;

int main()
{
	int floor; //floor��-1�� Ҳ���������м��Ԫ�����
	cout << "�����������";
	cin >> floor;
	
	int length = floor * 2 - 1;
	char pyramid[length];
	pyramid[floor - 1] = '*';
	
	for (int now_floor = 0; now_floor < floor; now_floor++)
	{
		pyramid[floor - now_floor - 1] = '*';
		pyramid[floor + now_floor - 1] = '*';
		
		for (int i = 0; i < length; i++)
		{
			if (pyramid[i] != '*') cout << ' ';
			else cout << pyramid[i];
		}
		
		cout << endl;
	 } 
	 
	 system("pause"); 
}
