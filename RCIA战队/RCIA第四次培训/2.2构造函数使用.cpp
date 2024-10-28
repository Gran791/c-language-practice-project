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
	student(int na, int sc)
	{
		name = na;
		score = sc;
	}
	int GetScore()
	{
		return score;
	}
	int GetNo()
	{
		return name;
	}
private:
	int name;
	int score;
};

int main()
{
	student stu[10];
	int grade = 0;
	srand((unsigned)time(NULL));
	//创建实例组
	for (int i = 0; i < 10; i++)
	{
		int b = rand() % 100; //创建随机值
		stu[i] = student(i, b);
	}
	cout << "已生成10个student实例组" << endl;
	//冒泡排序
	for (int i = 0; i < 10; i++)
	{
		grade += stu[i].GetScore();
		for (int j = 0; j < 9 - i; j++)
		{
			if (stu[j].GetScore() > stu[j + 1].GetScore())
				swap(stu[j], stu[j + 1]);
		}
	}
	cout << "平均分是 " << grade / 10 << endl;
	cout << "最高分是 " << "李华" << stu[9].GetNo() << "号，他的分数是 " << stu[9].GetScore() << endl;
	cout << "最低分是 " << "李华" << stu[0].GetNo() << "号，他的分数是 " << stu[0].GetScore() << endl;
	std::cin.get();
}
