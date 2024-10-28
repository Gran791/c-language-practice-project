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
        if (!((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z')) || i == 0)//��Ӣ��
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
    cout << "��������: ";
    getline(std::cin, words);

    LOG("����: " << Inversion(words))
        std::cin.get();
}

