#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <ctime>
#include<iostream>
#include<string>
#include<time.h>
#include <conio.h>
using namespace std;

//1=road 2=wall 3=jump
int map_game[5][5] =
{
	{1,1,1,2,2},
	{1,2,1,1,2},
	{1,1,3,2,1},
	{1,2,2,1,1},
	{1,3,2,2,1}
};

void display(int px, int py)
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (x == px && y == py)
				cout << "\033[0;42;30mMe\033[0m\t";
			else if (x == 4 && y == 4)
				cout << "\033[0;43;30mGold\033[0m\t";
			else if (map_game[y][x] == 1)
				cout << "Road\t";
			else if (map_game[y][x] == 2)
				cout << "Wall\t";
			else if (map_game[y][x] == 3)
				cout << "Jump\t";
		}
		cout << endl << endl;
	}
}

int isMovable(int x, int y)
{
	if (map_game[y][x] == 1 || map_game[y][x] == 3)
		return 1;
	else
		return 0;
}

int isJumpable(int x, int y, char decide)
{
	if (map_game[y][x] == 3)
	{
		switch (decide)
		{
		case 'w':
			if (isMovable(x, y - 2))
				return 1;
			break;
		case 's':
			if (isMovable(x, y + 2))
				return 1;
			break;
		case 'a':
			if (isMovable(x - 2, y))
				return 1;
			break;
		case 'd':
			if (isMovable(x + 2, y))
				return 1;
			break;
		default:
			break;
		}
	}
	return 0;
}

int main()
{
	int px = 0, py = 0;
	while (px != 4 || py != 4)
	{
		system("cls");
		display(px, py);
		cout << "Move(W,A,S,D): ";
		char move;
		move = getch(); 
		//cin >> move;
		switch (move)
		{
		case 'w':
		{
			if (isMovable(px, py - 1))
				py--;
			if (isJumpable(px, py, 'w'))
				py -= 2;
			break;
		}
		case 's':
		{
			if (isMovable(px, py + 1))
				py++;
			if (isJumpable(px, py, 's'))
				py += 2;
			break;
		}
		case 'a':
			if (isMovable(px - 1, py))
				px--;
			if (isJumpable(px, py, 'a'))
				px -= 2;
			break;
		case 'd':
		{
			if (isMovable(px + 1, py))
				px++;
			if (isJumpable(px, py, 'd'))
				px += 2;
			break;
		}
		default:
			break;
		}
	}
	system("cls");
	display(px, py);
	cout << "You Win!!!" << endl;
}
