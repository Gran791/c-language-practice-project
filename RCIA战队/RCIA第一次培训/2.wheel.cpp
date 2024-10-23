#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	float a = 3.1415 / 4,b=a;
	int vx,vy;
	cout << "ÇëÊäÈëVx:";
	cin >> vx;
	cout << "ÇëÊäÈëVy:";
	cin >> vy;
	int l=0,w=0;
	float va = -vx * cos(b) + vy * cos(a) + l*w;
	float vb = -vx * cos(b) - vy * cos(a) + l*w;
	float vc = vx * cos(b) - vy * cos(a) + l*w;
	float vd = vx * cos(b) + vy * cos(a) + l*w;

	cout << "Va = " << va << endl;
	cout << "Vb = " << vb << endl;
	cout << "Vc = " << vc << endl;
	cout << "Vd = " << vd;
}

