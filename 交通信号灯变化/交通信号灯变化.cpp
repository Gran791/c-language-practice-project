#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <random>
#include <time.h>
#include <string>

//周期80秒  红0-30 绿30-75 黄75-80
using namespace std;

void out()
{

}

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> n(0, 79);//随机路口初始值
	
	int cr1 = n(gen);
	int cr2 = n(gen);
	int cr3 = n(gen);
	int cr4 = n(gen);
	int cr5 = n(gen);
	
	int seconds[5] = { cr1, cr2, cr3, cr4, cr5 };
	int status[5] = { 0 };  //红灯1 绿灯2 黄灯3
	int temp[5] = { 0 };

	for (int i = 0; i < 600; i++)  //设定时间
	{
		//判断路口状态（status）
		for (int j = 0; j < 5; j++)
		{
			if (seconds[j] <= 30)  //红灯
			{
				//printf("第%d个路口：红灯\n", j + 1);
				status[j] = 1;
			}
			else if (seconds[j] <= 75)  //绿灯
			{
				//printf("第%d个路口：绿灯\n", j + 1);
				status[j] = 2;
			}
			else if (seconds[j] <= 80)  //黄灯
			{
				//printf("第%d个路口：黄灯\n", j + 1);
				status[j] = 3;
			}
			else
				seconds[j] = 0;
		}
		//更新路口时间
		for (int j = 0; j < 5; j++)
			seconds[j]++;
		//判断路口状态（temp）
		for (int j = 0; j < 5; j++)
		{
			if (seconds[j] <= 30)  //红灯
			{
				//printf("第%d个路口：红灯\n", j + 1);
				temp[j] = 1;
			}
			else if (seconds[j] <= 75)  //绿灯
			{
				//printf("第%d个路口：绿灯\n", j + 1);
				temp[j] = 2;
			}
			else if (seconds[j] <= 80)  //黄灯
			{
				//printf("第%d个路口：黄灯\n", j + 1);
				temp[j] = 3;
			}
		}
		//判断路口状态更新（temp与seconds）
		for (int j = 0; j < 5; j++)
		{
			if (status[j] != temp[j])
			{
				string pre, post;
				if (temp[j] == 1)  //转红灯
				{
					pre = "\033[0;43;30m黄灯\033[0m";
					post = "\033[0;41;30m红灯\033[0m";
				}
				else if (temp[j] == 2)
				{
					pre = "\033[0;41;30m红灯\033[0m";
					post = "\033[0;42;30m绿灯\033[0m";
				}
				else if (temp[j] == 3)
				{
					pre = "\033[0;42;30m绿灯\033[0m";
					post = "\033[0;43;30m黄灯\033[0m";
				}

				printf("[第%d秒]第%d个路口：%s 转 %s\n", i, j + 1, pre.c_str(), post.c_str());
				
			}
		}
	}
}
