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
	//构造函数
	student(int no, int sc)
	{
		name += "李华";
		if (no + '1' == ':') //第十个姓名
			name += "10";
		else
			name += no + '1';
		name += "号";
		score = sc;
	}
	//获取分数函数
	int GetScore()
	{
		return score;
	}
	//获取姓名函数
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
		grade += stu[i].GetScore(); // 总分计算
		for (int j = 0; j < 9 - i; j++)
		{
			if (stu[j].GetScore() > stu[j + 1].GetScore())
				swap(stu[j], stu[j + 1]);
		}
	}
	cout << "学生平均分是 " << grade / 10 << endl;
	cout << "最高分是 " << stu[9].GetName() << "，他的分数是 " << stu[9].GetScore() << endl;
	cout << "最低分是 " << stu[0].GetName() << "，他的分数是 " << stu[0].GetScore() << endl;
	std::cin.get();
}