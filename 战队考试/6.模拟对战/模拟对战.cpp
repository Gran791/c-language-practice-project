#include <iostream>
#include <stdlib.h>
#include <time.h>
#define full_hp 100

using namespace std;

void out(int p1_att, int p1_hp, int p2_att, int p2_hp)
{
	cout << "******************" << endl << "���1���غϹ�����Ϊ��" << p1_att << " ʣ��Ѫ��Ϊ��" << p1_hp << endl; 
	cout << "���2���غϹ�����Ϊ��" << p2_att << " ʣ��Ѫ��Ϊ��" << p2_hp << endl << "*******************" << endl; 
	getchar();
}

int main()
{
	int p1_att, p2_att; 
	int p1_hp = full_hp, p2_hp = full_hp;
	while (p1_hp > 0 && p2_hp > 0)
	{
		srand((unsigned)time(NULL));
		p1_att = rand() % 11 + 5;
		p2_att = rand() % 11 + 5;
		out(p1_att, p1_hp, p2_att, p2_hp);
		p1_hp -= p2_att;
		p2_hp -= p1_att;
	}
	out(p1_att, p1_hp, p2_att, p2_hp);
	
	cout << "Game Over!" << endl;
	
	if (p1_hp > 0) cout << "���1Ѫ����" << p1_hp << "  ���2Ѫ����" << p2_hp << "  ���1��ʤ" << endl; 
	else if (p2_hp > 0) cout << "���1Ѫ����" << p1_hp << "  ���2Ѫ����" << p2_hp << "  ���2��ʤ" << endl; 
	else if (p1_att > p2_att) cout << "���1Ѫ����" << p1_hp << "  ���2Ѫ����" << p2_hp << "  ���1��ʤ" << endl; 
	else cout << "���1Ѫ����" << p1_hp << "  ���2Ѫ����" << p2_hp << "  ���2��ʤ" << endl; 

 } 
