#include <iostream>  
#include <vector>  
#include <iomanip>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;

str Word[10] = { "H","e","l","l","o","W","o","r","l","d" };
str* ptr_Word = Word;

void Adjust()
{
	str temp[5];
	str* ptr_temp = temp;
	for (int i = 0; i < sizeof Word / 80; i++)
	{
		*(ptr_temp + i) = *(ptr_Word + i);
		*(ptr_Word + i) = *(ptr_Word + 5 + i);
	}
	for (int j = 5; j < sizeof Word / 40; j++)
	{
		*(ptr_Word + j) = *(ptr_temp + j - 5);
	}

}

int main()
{
	Adjust();
	//你的代码,不一定要使用函数
	for (int i = 0; i < sizeof Word / 40; i++)
	{
		cout << *(Word + i);
	}

	std::cin.get();
}