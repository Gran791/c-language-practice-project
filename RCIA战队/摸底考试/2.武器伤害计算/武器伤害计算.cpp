#include <iostream>

using namespace std;
int main()
{
	int player_power, weapon_real_max_power;
	cout << "������ҵ�������";
	cin >> player_power;
	weapon_real_max_power = 256 * (player_power + 100) / 100;
	cout << "����ʵ������˺���" << weapon_real_max_power << endl;
	system("pause");
}
