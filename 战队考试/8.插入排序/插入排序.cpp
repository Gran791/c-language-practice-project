#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);
	
	int list[9];

	cout << "�����Ϊ��";
	for (int i = 0; i < 9; i++)
	{
		list[i] = dis(gen);
		cout << list[i] << "\t";
	}

	int alt[9] = { 0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 9; i++) //����list  i
	{
		for (int p = 0; p < 9; p++) //����alt  p
		{
			if (list[i] >= alt[p]) 
			{
				for (int j = 7; j >= p; j--) //��Ԫ��������
				{
					alt[j + 1] = alt[j];
				}
				alt[p] = list[i]; //����alt��
				break; //����alt�ı���
			}
		}
	}

	cout << endl << "���к�Ϊ��";
	for (int n = 8; n >= 0; n--) //ͻȻ������ĿҪ����Ǵ�С�������ø�ֻ������д��
	{
		cout << alt[n] << "\t";
	}
	cout << endl;
	system("pause");
}
