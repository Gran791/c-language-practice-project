#include <iostream>  
#include <random>
#include <time.h>
#include <vector>
#include <string>
#define LOG(x) std::cout<<x<<std::endl;
#define str std::string

using namespace std;

str Inversion(str in)
{
    str out;
    int s_old, s_new;
    s_old = s_new = in.size();
    for (int i = in.size() - 1; i >= 0; i--)
    {
        if (!((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z')) || i == 0)//非英文
        {
            if (i == 0)
                s_new = -1;
            else
                s_new = i;
            out.append(in.substr(s_new + 1, s_old - s_new - 1));
            if (i != 0)
                out += in[i];
            s_old = i;
        }
    }
    return out;
}

int main()
{
    str words;
    cout << "输入文字: ";
    getline(std::cin, words);

    LOG("倒置: " << Inversion(words))
        std::cin.get();
}

