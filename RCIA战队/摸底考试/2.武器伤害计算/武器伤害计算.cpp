#include <iostream>

using namespace std;
int main()
{
	int player_power, weapon_real_max_power;
	cout << "输入玩家的力量：";
	cin >> player_power;
	weapon_real_max_power = 256 * (player_power + 100) / 100;
	cout << "武器实际最大伤害：" << weapon_real_max_power << endl;
	system("pause");
}
