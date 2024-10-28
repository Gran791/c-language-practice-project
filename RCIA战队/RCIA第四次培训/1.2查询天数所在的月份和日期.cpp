#include <iostream>  
#include <vector>  
#include <iomanip>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;

struct Year2024
{
	int Days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int YearDay = 366;
	int GetMonth(int day)
	{
		int temp = 0;
		for (int i = 0; i < 12; i++)
		{
			if (day > temp)
				temp += Days[i];
			else
				return i;
		}
	}
	int GetDay(int day)
	{
		for (int i = 0; i < 12; i++)
		{
			if (day > Days[i])
				day -= Days[i];
			else
				return day;
		}
	}
};

int main()
{
	Year2024 NewYear;
	int days;
	cout << "请输入一个天数:";
	cin >> days;
	if (days <= 0 || days > NewYear.YearDay)
	{
		LOG("输入天数有误");
	}
	else
	{
		LOG("2024年的第" << days << "天在 " << NewYear.GetMonth(days) << "月" << NewYear.GetDay(days) << "日");
	}

	std::cin.get();
}
