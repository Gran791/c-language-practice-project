 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <random>
#include <time.h>
#include <string>
#include <windows.h>

//����80��  ��0-30 ��30-75 ��75-80
using namespace std;


int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> n(0, 79);//���·�ڳ�ʼֵ
	
	int seconds[9];
	for (int i = 0; i < 9; i++)
	{
		seconds[i] = n(gen);
	}

	for (int i = 0; ; i++)  //�趨ʱ��
	{
		//�ж�·��״̬��status��
		for (int j = 0; j < 9; j++)
		{
			if (seconds[j] <= 30)  //���
				printf("·��%d��\033[0;41;30m���\033[0m    %d\n", j + 1, 31 - seconds[j]);
			else if (seconds[j] <= 75)  //�̵�
				printf("·��%d��\033[0;42;30m�̵�\033[0m    %d\n", j + 1, 76 - seconds[j]);
			else if (seconds[j] <= 80 && seconds[j] % 2 == 0)  //�Ƶ�
				printf("·��%d��\033[0;43;30m�Ƶ�\033[0m\n", j + 1);
			else if (seconds[j] <= 80 && seconds[j] % 2 == 1)  //�Ƶ�(��˸)
				printf("·��%d��\033[0;;37m�Ƶ�\033[0m\n", j + 1);
			else
			{
				printf("·��%d��\033[0;;37m�Ƶ�\033[0m\n", j + 1);
				seconds[j] = 0;
			}
		}
		//����·��ʱ��
		for (int j = 0; j < 9; j++)
			seconds[j]++;
		printf("\n����������%d�룬Ը������BUG������\n", i);
		Sleep(1000);
		system("cls");
	}
}
