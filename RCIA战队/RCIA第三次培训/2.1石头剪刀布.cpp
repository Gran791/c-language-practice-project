#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 2);
	int x = dis(gen)%3;
	string choice;
	int c = 0;
	cout << "��ѡ��ʯͷ/����/����: " ;
	cin >> choice;
	if (choice == "ʯͷ") 
		c = 0;
	else if (choice == "����")
		c = 1;
	else if (choice == "��")
		c = 2;

	if (x == 0)
		cout << "PCѡ���ˣ�ʯͷ" << endl;
	else if (x == 1)
		cout << "PCѡ���ˣ�����" << endl;
	else
		cout << "PCѡ���ˣ���" << endl;
	if ((c == 0 && x == 1)||(c == 1 && x == 2)||(c == 2 && x == 0))
		cout << "��Ϸ�������Ӯ�ˣ�" << endl;
	else if ((c == 1 && x == 0)||(c == 2 && x == 1)||(c == 0 && x == 2))
		cout << "��Ϸ����������ˣ�" << endl;
	else
		cout << "��Ϸ�����ƽ�֣�" << endl;
}
