#include <iostream>  
#include <random>
#include <time.h>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;

class student
{
public:
	student()
	{}
	//���캯��
	student(int no, int sc)
	{
		name += "�";
		if (no + '1' == ':') //��ʮ������
			name += "10";
		else
			name += no + '1';
		name += "��";
		score = sc;
	}
	//��ȡ��������
	int GetScore()
	{
		return score;
	}
	//��ȡ��������
	str GetName()
	{
		return name;
	}
private:
	str name;
	int score;
};

int main()
{
	student stu[10];
	int grade = 0;
	srand((unsigned)time(NULL));
	//����ʵ����
	for (int i = 0; i < 10; i++)
	{
		int b = rand() % 100; //�������ֵ
		stu[i] = student(i, b);
	}
	cout << "������10��studentʵ����" << endl;
	//ð������
	for (int i = 0; i < 10; i++)
	{
		grade += stu[i].GetScore(); // �ּܷ���
		for (int j = 0; j < 9 - i; j++)
		{
			if (stu[j].GetScore() > stu[j + 1].GetScore())
				swap(stu[j], stu[j + 1]);
		}
	}
	cout << "ѧ��ƽ������ " << grade / 10 << endl;
	cout << "��߷��� " << stu[9].GetName() << "�����ķ����� " << stu[9].GetScore() << endl;
	cout << "��ͷ��� " << stu[0].GetName() << "�����ķ����� " << stu[0].GetScore() << endl;
	std::cin.get();
}