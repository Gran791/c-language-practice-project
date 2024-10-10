#include <iostream>
#include <stdlib.h>
#include <time.h>
#define full_hp 100

using namespace std;

void out(int p1_att, int p1_hp, int p2_att, int p2_hp)
{
	cout << "******************" << endl << "玩家1本回合攻击力为：" << p1_att << " 剩余血量为：" << p1_hp << endl; 
	cout << "玩家2本回合攻击力为：" << p2_att << " 剩余血量为：" << p2_hp << endl << "*******************" << endl; 
	getchar();
}

int main()
{
	int p1_att, p2_att; 
	int p1_hp = full_hp, p2_hp = full_hp;
	while (p1_hp > 0 && p2_hp > 0)
	{
		srand((unsigned)time(NULL));
		p1_att = rand() % 11 + 5;
		p2_att = rand() % 11 + 5;
		out(p1_att, p1_hp, p2_att, p2_hp);
		p1_hp -= p2_att;
		p2_hp -= p1_att;
	}
	out(p1_att, p1_hp, p2_att, p2_hp);
	
	cout << "Game Over!" << endl;
	
	if (p1_hp > 0) cout << "玩家1血量：" << p1_hp << "  玩家2血量：" << p2_hp << "  玩家1获胜" << endl; 
	else if (p2_hp > 0) cout << "玩家1血量：" << p1_hp << "  玩家2血量：" << p2_hp << "  玩家2获胜" << endl; 
	else if (p1_att > p2_att) cout << "玩家1血量：" << p1_hp << "  玩家2血量：" << p2_hp << "  玩家1获胜" << endl; 
	else cout << "玩家1血量：" << p1_hp << "  玩家2血量：" << p2_hp << "  玩家2获胜" << endl; 

 } 
