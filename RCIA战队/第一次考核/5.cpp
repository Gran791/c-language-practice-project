#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <ctime>
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

string RandomWord(int num)
{
    srand(static_cast<unsigned int>(time(0)));
    string Word = "";
    int randomNumber;
    for (int i = 0; i < num; i++)
    {
        if (rand() % 2 == 1)
        {
            int randomNumber = rand() % 26;
            Word += 'A' + char(randomNumber);
        }
        else
        {
            randomNumber = rand() % 9;
            Word += to_string(randomNumber);
        }
    }

    return Word;
}

string Arr_str[50];
int Arr_num[50];

void Classify(string Word)
{
    //第一、二小问
    int str_c = 0, num_c = 0;
    for (int i = 0; i < Word.length();)
    {
        if (Word[i] >= 'A' && Word[i] <= 'Z')//字母
        {
            int j = i;
            string str;
            while (Word[j] >= 'A' && Word[j] <= 'Z')//连续字母
                j++;
            for (int n = i; n < j; n++)
            {
                str += Word[n];
            }
            Arr_str[str_c] = str;//赋值
            str_c++;//下标自增
            i = j;
        }
        else//数字
        {
            int m = i;
            string num_s;
            while (Word[m] >= '0' && Word[m] <= '9')//连续数字
                m++;
            for (int n = i; n < m; n++)
            {
                num_s += Word[n];
            }
            int num;
            sscanf(num_s.c_str(), "%d", &num);//string转int
            Arr_num[num_c] = num;//赋值
            num_c++;//下标自增
            i = m;
        }


    }
}

int main()
{
    string word = RandomWord(60);
    cout << word << endl;
    cout << endl;

    Classify(word);

    cout << "数据中包含的字符串:" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << Arr_str[i] << " ";
    }
    cout << endl;
    cout << "数据中包含的数字:" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << Arr_num[i] << " ";
    }
    return 0;
}