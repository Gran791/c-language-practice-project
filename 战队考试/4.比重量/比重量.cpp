#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "����������A������";
	cin >> a; 
	cout << "����������B������";
	cin >> b; 
	cout << "����������C������";
	cin >> c;
	
	if (a > c)
	{
		if (a > b) cout << "A����";
		else if (a == b) cout << "A��B��������";
		else cout << "B����"; 
	} 
	else if (a == c)
	{
	 	if (a > b) cout << "A��C��������";
	 	else if (a == b) cout << "A��B��Cһ����";
	 	else cout << "B����"; 
	}
	else
	{
	 	if (c > b) cout << "C����";
		else if (c == b) cout << "B��C��������"; 
		else cout << "B����";
	}
}
