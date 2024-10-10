#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "请输入物体A质量：";
	cin >> a; 
	cout << "请输入物体B质量：";
	cin >> b; 
	cout << "请输入物体C质量：";
	cin >> c;
	
	if (a > c)
	{
		if (a > b) cout << "A最重";
		else if (a == b) cout << "A与B并列最重";
		else cout << "B最重"; 
	} 
	else if (a == c)
	{
	 	if (a > b) cout << "A与C并列最重";
	 	else if (a == b) cout << "A、B、C一样重";
	 	else cout << "B最重"; 
	}
	else
	{
	 	if (c > b) cout << "C最重";
		else if (c == b) cout << "B与C并列最重"; 
		else cout << "B最重";
	}
}
