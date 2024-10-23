 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <random>
#include <time.h>
#include <string>
#include <windows.h>

//周期80秒  红0-30 绿30-75 黄75-80
using namespace std;


int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> n(0, 79);//随机路口初始值
	
	int seconds[9];
	for (int i = 0; i < 9; i++)
	{
		seconds[i] = n(gen);
	}

	for (int i = 0; ; i++)  //设定时间
	{
		//判断路口状态（status）
		for (int j = 0; j < 9; j++)
		{
			if (seconds[j] <= 30)  //红灯
				printf("路口%d：\033[0;41;30m红灯\033[0m    %d\n", j + 1, 31 - seconds[j]);
			else if (seconds[j] <= 75)  //绿灯
				printf("路口%d：\033[0;42;30m绿灯\033[0m    %d\n", j + 1, 76 - seconds[j]);
			else if (seconds[j] <= 80 && seconds[j] % 2 == 0)  //黄灯
				printf("路口%d：\033[0;43;30m黄灯\033[0m\n", j + 1);
			else if (seconds[j] <= 80 && seconds[j] % 2 == 1)  //黄灯(闪烁)
				printf("路口%d：\033[0;;37m黄灯\033[0m\n", j + 1);
			else
			{
				printf("路口%d：\033[0;;37m黄灯\033[0m\n", j + 1);
				seconds[j] = 0;
			}
		}
		//更新路口时间
		for (int j = 0; j < 9; j++)
			seconds[j]++;
		printf("\n程序已运行%d秒，愿世上无BUG，阿门\n", i);
		Sleep(1000);
		system("cls");
	}
}
