#include <iostream>  
#include <random>
#include <time.h>
#include <vector>
#include <string>
#include <ctype.h>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;

str Inversion(str in)
{
    vector<str> arr;
    str temp;
    for (int i = 0; i < in.size(); i++)
    {
        if (ispunct(in[i])) // ·ûºÅ
        {
            str t;
            t = in[i];
            arr.push_back(temp);
            temp = "";
            arr.push_back(t);
        }
        else if (in[i] == 32) // ¿Õ¸ñ
        {
            arr.push_back(temp);
            temp = "";
            arr.push_back(" ");
        }
        else //ÆÕÍ¨×Ö·û
        {
            temp += in[i];
        }
    }
    arr.push_back(temp);
    str out;
    for (int i = arr.size() - 1; i >= 0; i--)
        out += arr.at(i);
    return out;
}

int main()
{
    str words;
    cout << "ÊäÈëÎÄ×Ö: ";
    getline(std::cin, words);

    LOG("µ¹ÖÃ: " << Inversion(words))
        std::cin.get();
}
