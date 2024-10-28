#include <iostream>  
#include <vector>  
#include <iomanip>

using namespace std;

 float ExponetialFuction(float a, int b)
{
    float result = 1;
    for (int i = 0; i < b; i++)
    {
        result = result * a;
    }
    return result;
}

int main()
{
    float a, c;
    int b;
    cout << "请输入底数：";
    cin >> a;
    cout << "请输入指数：";
    cin >> b;
    c = ExponetialFuction(a, b);
    cout << a << "^" << b << "=" << c << endl;
    return 0;
}