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
    cout << "�����������";
    cin >> a;
    cout << "������ָ����";
    cin >> b;
    c = ExponetialFuction(a, b);
    cout << a << "^" << b << "=" << c << endl;
    return 0;
}